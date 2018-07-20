/*
 * data.c -- Implementation of DataWidget
 *           Displays raw telemetry data.
 *
 * $Id: data.cpp,v 1.11 2002/06/06 12:23:50 casey Exp $
 *
 */

#include <qlabel.h>
#include <qlayout.h>

#include "data.h"

DataWidget::DataWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setMinimumSize(200,200);
   setMaximumSize(300,400);

   roll = new QLabel(this);
   pitch = new QLabel(this);
   yaw = new QLabel(this);
   alt = new QLabel(this);
   gpsx = new QLabel(this);
   gpsy = new QLabel(this);
   gpsz = new QLabel(this);
   tach = new QLabel(this);
   vz = new QLabel(this);
   vxy = new QLabel(this);
   QLabel *label[10];
   label[0] = new QLabel("Roll",this);
   label[1] = new QLabel("Pitch",this);
   label[2] = new QLabel("Yaw", this);
   label[3] = new QLabel("Alt AGL", this);
   label[4] = new QLabel("GPS X:", this);
   label[5] = new QLabel("GPS Y:", this);
   label[6] = new QLabel("GPS Z:", this);
   label[7] = new QLabel("Tach", this);
   label[8] = new QLabel("Airspeed", this);
   label[9] = new QLabel("V. Speed", this);

   QGridLayout *grid = new QGridLayout(this, 0, 0, 0);
   //s = new QString();
   int i;

   for (i=0; i<10; i++)
      grid->addWidget(label[i],i,0);

   // Load initial values into data
   s.setNum(0.0);
   roll->setText(s.latin1());
   grid->addWidget(roll,0,1);
   pitch->setText(s.latin1());
   grid->addWidget(pitch,1,1);
   yaw->setText(s.latin1());
   grid->addWidget(yaw,2,1);
   alt->setText(s.latin1());
   grid->addWidget(alt,3,1);
   gpsx->setText(s.latin1());
   grid->addWidget(gpsx,4,1);
   gpsy->setText(s.latin1());
   grid->addWidget(gpsy,5,1);
   gpsz->setText(s.latin1());
   grid->addWidget(gpsz,6,1);
   tach->setText(s.latin1());
   grid->addWidget(tach,7,1);
   vxy->setText(s.latin1());
   grid->addWidget(vxy,8,1);
   vz->setText(s.latin1());
   grid->addWidget(vz,9,1);
}

DataWidget::~DataWidget()
{
//   delete roll;
//   delete pitch;
}

void DataWidget::setHeading(float hdg)
{
 //  active.lock();
   //yaw->setText(s.sprintf("%f\xB0", hdg));
   yaw->setText(s.setNum(hdg));
 //  active.unlock();
}

void DataWidget::setRoll(float deg)
{
  // active.lock();
   //roll->setText(s.sprintf("%f\xB0", deg));
   roll->setText(s.setNum(deg));
  // active.unlock();
}

void DataWidget::setPitch(float deg)
{
  // active.lock();
   //pitch->setText(s.sprintf("%f\xB0", deg));
   pitch->setText(s.setNum(deg));
  // active.unlock();
}

void DataWidget::setX(float coord)
{
  // active.lock();
   gpsx->setText(s.setNum(coord));
  // active.unlock();
}

void DataWidget::setY(float coord)
{
  // active.lock();
   gpsy->setText(s.setNum(coord));
  // active.unlock();
}

void DataWidget::setZ(float coord)
{
  // active.lock();
   gpsz->setText(s.setNum(coord));
   alt->setText(s.setNum(coord));
  // active.unlock();
}

void DataWidget::setTach(float coord)
{
  // active.lock();
   tach->setText(s.setNum(coord));
  // active.unlock();
}

void DataWidget::setSpeed(float v)
{
   vxy->setText(s.setNum(v));
}

void DataWidget::setVz(float z)
{
   vz->setText(s.setNum(z));
}

