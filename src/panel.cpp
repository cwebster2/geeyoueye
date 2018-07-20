/*
 * panel.cpp -- Implementation of PanelWidget
 *              Displays telemetry data in an easily understandable
 *              Format.
 *
 * $Id: panel.cpp,v 1.31 2002/06/06 12:23:50 casey Exp $
 * 
 */

#include <qlabel.h>
#include <qstring.h>
#include <math.h>

#ifndef M_PI  // math.h doesnt define pi on windows
#define M_PI 3.14159265358979323846
#endif

#include "panel.h"

PanelWidget::PanelWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setMinimumSize(200,120);
   //setMaximumSize(960,600);
   resize(width(),width()/3);
   heading = 0;
   vz = 0;
   roll = 0;
   pitch = 0;
   altitude = 0;
   tach = 0;
   alt10 = 0;
   alt1 = 0;
   speed = 0;
   changemask = CG_ALL;
   setWFlags(Qt::WRepaintNoErase);

   updator = new QTimer(this);
   connect(updator, SIGNAL(timeout()), SLOT(callUpdate()));
   updator->start(50);
}

void PanelWidget::setAlt(float alt)
{
   int t10, t100;
   if (altitude != alt)
   {
      altitude = alt;
      t10 = (int)altitude/10;
      t100 = (int)altitude/100;
      alt1 = altitude - (t10*10);
      alt10 = (altitude/10) - (t100*10);
      changemask |= CG_ALT;
   }
}

void PanelWidget::setTach(float tch)
{
   if (tach != tch)
   {
      tach = tch;
      changemask |= CG_RPM;
   }
}

void PanelWidget::setHeading(float hdg)
{
   if (heading != ((int)hdg % 360))
   {
      heading = (int)hdg % 360;
      changemask |= CG_HDG;
   }
}

void PanelWidget::setRoll(float deg)
{
   if (roll != (int)deg)
   {
      roll = (int)deg;
      changemask |= CG_AF;
   }
}

void PanelWidget::setPitch(float deg)
{
   if (pitch != (int)deg)
   {
      pitch = (int)deg;
      changemask |= CG_AF;
   }
}

void PanelWidget::setASI(float v)
{
   if (speed != v)
   {
      speed = v;
      changemask |= CG_IAS;
   }
}

void PanelWidget::setVSI(float vs)
{
   if (vz != vs)
   {
      vz = vs;
      changemask |= CG_VSI;
   }
}

void PanelWidget::callUpdate()
{
   if (changemask)
      update();
}

QSize PanelWidget::sizeHint()
{
   return QSize(width(), width()/3);
}

void PanelWidget::resizeEvent(QResizeEvent *)
{
   changemask = CG_ALL;
   bbuf.resize(size());
   bbuf.fill(Qt::black);
   //qDebug("Resize Event");
}

void PanelWidget::paintEvent(QPaintEvent *)
{
   //qDebug("Paint Event.  Mask = %02X", changemask);
   setUpdatesEnabled(FALSE);
   QPainter p;
   p.begin(&bbuf,this);
   //p.setWindow(0,0,1500,600);
   p.setWindow(0,0,900,600);
   p.setBrush(Qt::black);
   if (changemask & CG_BCK)
      DrawBackground(p);
   if (changemask & CG_HDG)
   {
      p.save();
      p.translate(450,450);
      DrawHeading(p);
      p.restore();
   }
   if (changemask & CG_VSI)
   {
      p.save();
      p.translate(750,450);
      DrawVSI(p);
      p.restore();
   }
   if (changemask & CG_ALT)
   {
      p.save();
      p.translate(750,150);
      DrawAlt(p);
      p.restore();
   }
   if (changemask & CG_AF)
   {
      p.save();
      p.translate(450,150);
      DrawAF(p);
      p.restore();
   }  
   if (changemask & CG_IAS)
   {
      p.save();
      p.translate(150,150);
      DrawASI(p);
      p.restore();
   }  
   if (changemask & CG_RPM)
   {
      p.save();
      p.translate(150,450);
      DrawRPM(p);
      p.restore();
   }  

   changemask = 0;
   p.end();
   //bbuf.save("panel.dbg.jpg", "JPEG");
   bitBlt(this, 0, 0, &bbuf);
   setUpdatesEnabled(TRUE);
}


void PanelWidget::DrawBackground(QPainter &p)
{
   bbuf.fill(Qt::black);
   p.save();
   p.translate(150,150);
   DrawASIBack(p);
   p.translate(0,300);
   DrawRPMBack(p);
   p.translate(300,-300);
   DrawAFBack(p);
   p.translate(300,0);
   DrawAltBack(p);
   p.translate(0,300);
   DrawVSIBack(p);
   //p.translate(450, -150);
   //DrawGPSBack(p);
   p.restore();
}

void PanelWidget::DrawHeading(QPainter &p)
{

   //p.setBrush(Qt::black);
   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   // Heading info
   p.drawEllipse(-100,-100,200,200); 

   int i, angle, len; 
   QString s;
   for (i=0; i<72; i++)
   {
      angle = (5*i) % 360;
      
      if (!(angle % 90))  // Cardinal Direction
         len = 0;
      else if (!(angle % 30)) // 30 deg interval
         len = 135;
      else if (!(angle % 10))
         len = 120;
      else 
         len = 110;

      p.save();
      p.rotate(((angle-heading)%360));
      
      if (len)
         p.drawLine(0, 100, 0, len); 
      else 
      {
         switch (angle) {
            case 0:
            case 360: s.sprintf("N"); break;
            case 90: s.sprintf("E"); break;
            case 180: s.sprintf("S"); break;
            case 270: s.sprintf("W"); break;
         }
         p.setFont(QFont("courier", 24, QFont::Bold));
         p.setPen(Qt::yellow);
         p.drawText(-20, -140,40,40, Qt::AlignCenter, s);
      }
      p.restore();
      p.setFont(QFont("courier", 45));
      s.sprintf("%d\xB0",heading);
      p.drawText(-70,-70,140,140, Qt::AlignCenter, s);
      QPointArray pa;
      pa.putPoints(0,3, 0,-90, 10,-80, -10,-80);
      p.setBrush(Qt::white);
      p.setPen(Qt::white);
      p.drawPolygon(pa);
   }
}

void PanelWidget::DrawRPM(QPainter &p)
{
   p.setBrush(Qt::black);
   p.drawEllipse(-100,-100,200,200);
   QPointArray pa;
   p.save();
   p.rotate(((tach/1000.0)*30.0)-150);
   pa.putPoints(0,4, 0,0, 17,-80, 0,-100, -17,-80);
   p.setBrush(Qt::white);
   p.setPen(Qt::black);
   p.drawPolygon(pa);
   p.restore();
}

void PanelWidget::DrawASI(QPainter &p)
{
   float rot;
   p.setBrush(Qt::black);
   p.drawEllipse(-100,-100,200,200);
   QPointArray pa;
   p.save();

   rot = speed*3.5;
   if (rot > 315) rot = 315;
   p.rotate(rot);

   pa.putPoints(0,4, 0,0, 17,-80, 0,-100, -17,-80);
   p.setBrush(Qt::white);
   p.setPen(Qt::black);
   p.drawPolygon(pa);
   p.restore();
}

void PanelWidget::DrawGPS(QPainter &p)
{
}

void PanelWidget::DrawVSI(QPainter &p)
{
   float angle, tvsi;
   QPointArray pa;
   int sign = 1;

   p.setBrush(Qt::black);
   p.drawEllipse(-100,-100,200,200);

   if (vz < 0)
      sign = -1;

   if (fabs(vz) <= 5)
      angle = 270+(18*vz);
   else if (fabs(vz) <= 10)
   {
      tvsi = vz - 5*sign;
      angle = 270+90*sign+(14*tvsi);
   }
   else if (fabs(vz) < 20)
   {
      tvsi = vz - 10*sign;
      angle = 270+160*sign+(1*tvsi);
   }
   else 
      angle = 90;

   p.save();
   p.rotate(angle+180);
   // Ones hand
   pa.putPoints(0,4, 0,0, 17,80, 0,100, -17,80);
   p.setBrush(Qt::white);
   p.setPen(Qt::black);
   p.drawPolygon(pa);
   p.restore();
}

void PanelWidget::DrawAlt(QPainter &p)
{
   p.setBrush(Qt::black);
   p.drawEllipse(-100,-100,200,200);
   p.save();
   p.rotate(alt10*36+180);
   // Tens Hand
   QPointArray pa;
   pa.putPoints(0,4, 0,0, 25,60, 0,90, -25,60);
   p.setBrush(Qt::white);
   p.setPen(Qt::black);
   p.drawPolygon(pa);
   p.restore();

   p.save();
   p.rotate(alt1*36+180);
   // Ones hand
   pa.putPoints(0,4, 0,0, 17,80, 0,100, -17,80);
   p.setBrush(Qt::white);
   p.setPen(Qt::black);
   p.drawPolygon(pa);
   p.restore();
}

void PanelWidget::DrawAF(QPainter &p)
{
   p.save();
   p.rotate(roll);
   p.setPen(Qt::black);
   if (abs(pitch) > 90) 
   {
      p.save();
      p.rotate(180);
   }
   //sky
   p.setBrush(Qt::blue);
   p.drawChord(-120, -120, 240, 240, -pitch*16, 180*16+(pitch*32));
   //ground
   p.setBrush(Qt::green);
   p.drawChord(-120, -120, 240, 240, -pitch*16, -180*16+(pitch*32));
   if (abs(pitch) > 90) 
      p.restore();
   QPointArray pa;
   pa.putPoints(0,3, 0,-120, -15,-90, 15,-90);
   p.setBrush(Qt::white); 
   p.drawPolygon(pa);
   p.setPen(Qt::black);
   // pitch scale
   p.drawLine(-20,10, 20,10);
   p.drawLine(-40,21, 40,21);
   p.drawLine(-20,31, 20,31);
   p.drawLine(-40,41, 40,41);
   p.drawLine(-20,51, 20,51);
   p.drawLine(-40,60, 40,60);
   p.drawLine(-20,69, 20,69);
   p.drawLine(-40,77, 40,77);
   p.drawLine(-20,-10, 20,-10);
   p.drawLine(-40,-21, 40,-21);
   p.drawLine(-20,-31, 20,-31);
   p.drawLine(-40,-41, 40,-41);
   p.drawLine(-20,-51, 20,-51);
   p.drawLine(-40,-60, 40,-60);
   p.drawLine(-20,-69, 20,-69);
   p.drawLine(-40,-77, 40,-77);
   p.restore();
   p.drawLine(-50,0, -25,0);
   p.drawLine(-25,0, 0,25);
   p.drawLine(0,25, 25,0);
   p.drawLine(25,0, 50,0);
}

void PanelWidget::DrawRPMBack(QPainter &p)
{
   QPointArray pa;
   int i;

   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   p.setPen(Qt::black);
   p.setBrush(Qt::green);
   p.drawPie(-130,-130, 260, 260, -120*16, -270*16);
   p.setBrush(Qt::red);
   p.drawPie(-130,-130, 260, 260, -30*16, -30*16);

   p.setBrush(Qt::black);
   p.drawEllipse(-120,-120, 240, 240);

   p.setBrush(Qt::white);
   pa.putPoints(0,4, 5,100, 5,139, -5,139, -5,100);
   p.save();
   p.rotate(30);
   p.drawPolygon(pa);
   p.restore();
   pa.putPoints(0,4, 5,100, 5,139, -5,139, -5,100);
   p.save();
   p.rotate(-30);
   p.drawPolygon(pa);
   p.restore();

   p.setPen(Qt::green);
   p.save();
   p.rotate(240);
   for (i=0; i<8; i++)
   {
      p.drawLine(-1,-130, -1,-110);
      p.drawLine(0,-130, 0,-110);
      p.drawLine(1,-130, 1,-110);
      p.rotate(30);
   }
   p.setPen(Qt::red);
   p.drawLine(-1,-130, -1,-110);
   p.drawLine(0,-130, 0,-110);
   p.drawLine(1,-130, 1,-110);
   p.restore();

   p.setBrush(Qt::black);
}

void PanelWidget::DrawASIBack(QPainter &p)
{
   QPointArray pa;
   int i;

   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   p.setPen(Qt::black);
   p.setBrush(Qt::green);
   p.drawPie(-130,-130, 260, 260, 90*16, -315*16);
   p.setBrush(Qt::black);
   p.drawEllipse(-120,-120, 240, 240);

   p.setBrush(Qt::red);
   pa.putPoints(0,4, 5,100, 5,139, -5,139, -5,100);
   p.save();
   p.rotate(135);
   p.drawPolygon(pa);
   p.restore();

   p.setPen(Qt::green);
   p.save();
   for (i=0; i<21; i++)
   {
      p.drawLine(-1,-130, -1,-110);
      p.drawLine(0,-130, 0,-110);
      p.drawLine(1,-130, 1,-110);
      p.rotate(15);
   }
   p.restore();

   p.setBrush(Qt::black);
}

void PanelWidget::DrawGPSBack(QPainter &p)
{
   p.setPen(Qt::white);

   p.drawRect(-290,-290,580,580);
}

void PanelWidget::DrawVSIBack(QPainter &p)
{
   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   int i, angle, scale, len; 
   QString s;
   for (i=-15; i<=20; i++)
   {
      if (abs(i) <= 5)
         angle = 270+(18*i);
      else if (abs(i) <= 10)
         angle = 270+(18*(i/abs(i))+(14*i));
      else if (abs(i) == 15)
         angle = 90+(10*(i/abs(i)));
      else if (abs(i) == 20)
         angle = 90;
      else 
         continue;

      switch (i) {
         case -5 :
         case 5 :
         case 10:
         case -10:
         case 20 :
         case 0 : scale = 1; len = 100; break;
         default: scale = 0; len = 120;
      }
      p.save();
      p.rotate(angle+180);
      p.drawLine(0, 140, 0, len); 
      p.restore();
   }
}

void PanelWidget::DrawAltBack(QPainter &p)
{
   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   int i, len; 
   QString s;
   for (i=0; i<100; i++)
   {
      if (!(i % 10)) 
         len = 100;
      else if (!(i % 5)) 
         len = 120;
      else 
         len = 130;

      p.save();
      p.rotate((float)(3.6f * i)+180);
      p.drawLine(0, 140, 0, len); 
      p.restore();
   }
}

void PanelWidget::DrawAFBack(QPainter &p)
{
   p.setPen(Qt::white);
   p.drawEllipse(-140,-140,280,280);

   int i; 
   QString s;
   int angles[] = { -90, -60, -45, -30, -20, -10, 0, 10, 20, 30, 45, 60, 90 };
   for (i=0; i<13; i++)
   {
      p.save();
      p.rotate(angles[i]+180);
      p.drawLine(0, 120, 0, 140); 
      p.restore();
   }
}
