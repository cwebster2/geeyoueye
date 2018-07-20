/*
 * $Id: udpmaster.cpp,v 1.5 2002/06/06 12:23:50 casey Exp $
 */

#include <math.h>

#include <qlayout.h>

#include "udpmaster.h"
#include "televent.h"

UDPMaster::UDPMaster(QWidget *parent, const char* name)
	: QWidget(parent,name)
{
  QGridLayout *gbox = new QGridLayout(this, 1,2, 5);

  data = new DataWidget(this);
  panel = new PanelWidget(this);
  gbox->setColStretch(0,0);
  gbox->setColStretch(1,100);
  gbox->addWidget(data,0,0);
  gbox->addWidget(panel,0,1);
  td = new TelData(this);

  connect(this, SIGNAL(newHeading(float)), panel, SLOT(setHeading(float)));
  connect(this, SIGNAL(newRoll(float)), panel, SLOT(setRoll(float)));
  connect(this, SIGNAL(newPitch(float)), panel, SLOT(setPitch(float)));
  connect(this, SIGNAL(newZ(float)), panel, SLOT(setAlt(float)));
  connect(this, SIGNAL(newTach(float)), panel, SLOT(setTach(float)));
  connect(this, SIGNAL(newSpeed(float)), panel, SLOT(setASI(float)));
  connect(this, SIGNAL(newVz(float)), panel, SLOT(setVSI(float)));

  connect(this, SIGNAL(newHeading(float)), data, SLOT(setHeading(float)));
  connect(this, SIGNAL(newRoll(float)), data, SLOT(setRoll(float)));
  connect(this, SIGNAL(newPitch(float)), data, SLOT(setPitch(float)));
  connect(this, SIGNAL(newX(float)), data, SLOT(setX(float)));
  connect(this, SIGNAL(newY(float)), data, SLOT(setY(float)));
  connect(this, SIGNAL(newZ(float)), data, SLOT(setZ(float)));
  connect(this, SIGNAL(newTach(float)), data, SLOT(setTach(float)));
  connect(this, SIGNAL(newSpeed(float)), data, SLOT(setSpeed(float)));
  connect(this, SIGNAL(newVz(float)), data, SLOT(setVz(float)));
}

void UDPMaster::customEvent(QCustomEvent *e)
{
  if (e->type() == 909194)
  {
    TelDataEvent *te = (TelDataEvent*)e;
    teldata((net_data*)te->GetData());
  }
}

void UDPMaster::teldata(net_data *td)
{
  emit newHeading(td->yaw);
  emit newPitch(td->pitch);
  emit newRoll(td->roll);
  emit newX(td->x);
  emit newY(td->y);
  emit newZ(td->z);
  emit newTach(td->tach);
  emit newSpeed(sqrt(pow(td->vx,2)+pow(td->vy,2)+pow(td->vz,2)));
  emit newVz(td->vz);
  delete [] td;
}
