/*
 * pic.c -- Implementation of PicWidget
 *
 * $Id: pic.cpp,v 1.13 2002/06/04 09:48:58 casey Exp $
 *
 */

#include <qlabel.h>
#include <qlayout.h>
#include <qthread.h>
#include <qapplication.h>

#include "pic.h"

PicWindow::PicWindow(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
  setCaption(name);
  QBoxLayout *boxlayout = new QBoxLayout(this, QBoxLayout::Down); 
  pic = new PicWidget(this, name);
  boxlayout->addWidget(pic);
}

PicWidget::PicWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setMinimumSize(320,240);
   setMaximumSize(640,480);

   setWFlags(Qt::WRepaintNoErase); 
   pic = new QImage("testpic.jpg");

}

void PicWidget::newPic(QImage *newpic)
{
   QString s;
//   qDebug("PicWidget::newPic(QImage*)");
   pic = newpic;
   s.sprintf("(%dx%d)", pic->width(), pic->height());
   emit stat2(s);
   qDebug(s);
   update();
}

void PicWidget::newPic(char *data, int len)
{
   //QString s;
//   qDebug("PicWidget::newPic(char*, int)");
   //char fmt[10]; fmt[0]='\0';
   //emit stat2("PicWidget gets a Pic !");
   if (pic->loadFromData((uchar*)data+8, (int)len-8, NULL))
   {
     //if (fmt)
     //  s.sprintf("fmt: %s(%dx%d)", fmt, pic->width(), pic->height());
     //else
     //s.sprintf("(%dx%d)", pic->width(), pic->height());
     qDebug("(%dx%d)", pic->width(), pic->height());
     //emit stat2(s);
   }
   else
     //emit stat2("Unsupported Pic Format");
     qDebug("Unsupported pic format");
   delete [] data;
   update();
}


void PicWidget::paintEvent(QPaintEvent *)
{
   setUpdatesEnabled(FALSE);
   //resize(pic->size());
   //bitBlt(this,0,0,pic);
   QPainter p(this);
   p.setWindow(0,0,pic->width(),pic->height());
   p.drawImage(0,0,*pic);
   setUpdatesEnabled(TRUE);
}
