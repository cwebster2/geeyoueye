/*
 * ap.cpp -- Implementation of APWidget
 *
 * $Id: ap.cpp,v 1.8 2002/07/21 01:28:12 casey Exp $
 *
 */


#include <qlabel.h>
#include <qlayout.h>
#include <qhbox.h>
#include <qvbox.h>
#include <qvgroupbox.h>
#include <qgrid.h>
#include <qpainter.h>
#include <qlayout.h>
#include <qvbox.h>
#include <qpushbutton.h>

#include "ap.h"

void MapPoint::setLat(int D, int M, float S)
{
  lat.D = D;
  lat.M = M;
  lat.S = S;

  calcMap();
}

void MapPoint::setLon(int D, int M, float S)
{
  lon.D = D;
  lon.M = M;
  lon.S = S;

  calcMap();
}

void MapPoint::calcMap()
{
  maplat = maplon = 0;
  maplat = lat.D * 1000000;
  maplon = lon.D * 1000000;
  maplat += lat.M * 10000 * 5 / 3;
  maplon += lon.M * 10000 * 5 / 3;
  maplat += (int)(lat.S * 100 * 5 / 3);
  maplon += (int)(lon.S * 100 * 5 / 3);
}

void MapPoint::getDialog()
{
  
}

MapPointDialog::MapPointDialog(QWidget *parent, char* name)
	: QDialog(parent,name)
{
  QGridLayout *top = new QGridLayout(this, 4, 5);
  top->addMultiCellWidget(new QLabel("New Waypoint",this),0,3,0,0);

  QVBox *vbox = new QVBox(this);
  QPushButton *ok = new QPushButton("OK", vbox);
  QPushButton *nok = new QPushButton("Cancel", vbox);
  top->addMultiCellWidget(vbox,0,3,4,4);

  connect(ok, SLOT(clicked()), this, SIGNAL(accept()));
  connect(nok, SLOT(clicked()), this, SIGNAL(reject()));
}

void MapPointDialog::accept()
{
  done(QDialog::Accepted);
}

void MapPointDialog::reject()
{
  done(QDialog::Rejected);
}


APWidget::APWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   //setMinimumSize(200,120);
   //setMaximumSize(200,200);

   QGridLayout *main = new QGridLayout(this,2,2);
   main->setColStretch(1,0);
   main->setColStretch(0,100);
   main->setRowStretch(0,0);
   main->setRowStretch(1,100);

   QHBox *box = new QHBox(this);
   main->addWidget(box,0,0);
   new QLabel("Zoom", box);

   map = new MapWidget(this);
   main->addWidget(map,1,0);

   QVBox *side = new QVBox(this);
   //main->addWidget(side,0,0);
   main->addMultiCellWidget(side,0,1,1,1);

   curpos = new WPTWidget(side, "Position");
   curwpt = new WPTWidget(side, "Waypoint");
   next = new WPTWidget(side, "Next Wpt");
    
}

void APWidget::curX(float coord)
{
  DMS dms;
  dms.D = 97;
  dms.M = 30;
  dms.S = coord;
  curpos->setLon(dms);
  map->updateLon(dms);
}

void APWidget::curY(float coord)
{
  DMS dms;
  dms.D = 31;
  dms.M = 30;
  dms.S = coord;
  curpos->setLat(dms);
  map->updateLat(dms);
}

void APWidget::curZ(float coord)
{
  curpos->setAlt(coord);
}

WPTWidget::WPTWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
  QBoxLayout *main = new QHBoxLayout(this);
  QGroupBox *group = new QVGroupBox(name, this);
  main->addWidget(group);
  QGrid *box = new QGrid(2,group);
  new QLabel("Lat", box);
  lat = new QLabel("000",box);
  new QLabel("Lon", box);
  lon = new QLabel("000",box);
  new QLabel("Alt", box);
  alt = new QLabel("000",box);
}

void WPTWidget::setPos(DMS newlat, DMS newlon, float newalt)
{
   lat->setText(s.setNum(newlat.D)+"o "+s.setNum(newlat.M)+"\" "+s.setNum(newlat.S)+"\'");
   lon->setText(s.setNum(newlon.D)+"o "+s.setNum(newlon.M)+"\" "+ s.setNum(newlon.S)+"\'");
   alt->setText(s.setNum(newalt));
}

void WPTWidget::setLat(DMS newlat)
{
   lat->setText(s.setNum(newlat.D)+"o "+s.setNum(newlat.M)+"\" "+ s.setNum(newlat.S)+"\'");
}

void WPTWidget::setLon(DMS newlon)
{
   lon->setText(s.setNum(newlon.D)+"o "+s.setNum(newlon.M)+"\" "+ s.setNum(newlon.S)+"\'");
}

void WPTWidget::setAlt(float newalt)
{
   alt->setText(s.setNum(newalt));
}

MapWidget::MapWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
  setMinimumSize(200,200);
  setWFlags(Qt::WRepaintNoErase);
  bbuf.resize(size());
  bbuf.fill(Qt::black);

  //cx=0;
  //cy=0;
  cx=97300000;
  cy=31300000;
  //cy=97300000;
  //cx=31300000;
  shortside=2000000;
  zoom=1;
  gridinterval=50;

  updator = new QTimer(this);
  connect(updator, SIGNAL(timeout()), SLOT(callUpdate()));
  updator->start(500);
}

void MapWidget::resizeEvent(QResizeEvent *)
{
  int ww,wh;
  ww = size().width();
  wh = size().height();
  bbuf.resize(size());

  if (ww <= wh)  // height is bigger
  {
    xlen = shortside;
    ylen = (xlen * wh) / ww;
  }
  else  //width is bigger
  {
    ylen = shortside;
    xlen = (xlen * ww) / wh;
  }
  dotsize = (int)(((float)xlen/(float)ww) * 10); //10 pixels wide
  gridwidth = (int)(((float)xlen/(float)ww) *1 );
  gridinterval = 1000000;
  minx = cx - (xlen/2);
  maxx = cx + (xlen/2);
  miny = cy - (ylen/2);
  maxy = cy + (ylen/2);

  ///*
  qDebug("shortside - %d", shortside);
  qDebug("xlen - %d", xlen);
  qDebug("ylen - %d", ylen);
  qDebug("minx - %d", minx);
  qDebug("maxx - %d", maxx);
  qDebug("miny - %d", miny);
  qDebug("maxy - %d", maxy);
  qDebug("cx - %d", cx);
  qDebug("cy - %d", cy);
  qDebug("ww - %d", ww);
  qDebug("wh - %d", wh);
  qDebug("dotsize - %d", dotsize);
  qDebug("gridinterval - %d", gridinterval);
  qDebug("gridwidth - %d", gridwidth);
  //*/
}

void MapWidget::paintEvent(QPaintEvent *)
{
  setUpdatesEnabled(FALSE);
  bbuf.fill(Qt::black);
  QPainter p;
  p.begin(&bbuf, this);
  //p.setWindow(0,0,600,600);
  p.setWindow(minx,maxy,maxx-minx,miny-maxy);
  drawGrid(p);
  drawBasePos(p);
  drawWaypts(p);
  drawCurPos(p);
  p.end();
  bitBlt(this, 0, 0, &bbuf);
  setUpdatesEnabled(TRUE);
}

void MapWidget::drawCurPos(QPainter &p) 
{
  p.setPen(Qt::green);
  p.setBrush(Qt::green);
  p.drawEllipse((int)current.mapLon()-(dotsize/2),(int)current.mapLat()-(dotsize/2),dotsize,dotsize);
  p.setBrush(Qt::black);
}

void MapWidget::drawBasePos(QPainter &p) {}

void MapWidget::drawGrid(QPainter &p) 
{
  QPen pen = p.pen();
  p.setPen(QPen(Qt::yellow, gridwidth));
  int i;
  for(i=cx; i<maxx; i+=gridinterval)
  {
    p.drawLine(cx+i,miny,cx+i,maxy);
    p.drawLine(cx-i,miny,cx-i,maxy);
  }
  for(i=cy; i<maxy; i+=gridinterval)
  {
    p.drawLine(minx, cy+i,maxx,cy+i);
    p.drawLine(minx, cy-i,maxx,cy-i);
  }
  p.setPen(pen);
}

void MapWidget::drawWaypts(QPainter &p) {}

