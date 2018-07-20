/*
 * $Id: udpmaster.h,v 1.4 2002/06/06 12:23:50 casey Exp $
 */

#ifndef __UDPMASTER_H
#define __UDPMASTER_H

 #include <qwidget.h>
 #include <qtimer.h>

 #include "data.h"
 #include "panel.h"
 #include "teldata.h"

 class UDPMaster : public QWidget
 {
 Q_OBJECT

 public:
   UDPMaster(QWidget *parent=0, const char* name=0);
 signals:
   void newRoll(float);
   void newPitch(float);
   void newHeading(float);
   void newX(float);
   void newY(float);
   void newZ(float);
   //void newVx(float);
   //void newVy(float);
   void newSpeed(float);
   void newVz(float);
   void newTach(float);
 protected:
   virtual void customEvent(QCustomEvent *e);
 private:
   void teldata(net_data *td);

   DataWidget *data;
   PanelWidget *panel;
   TelData *td;
 };

#endif // __UDPMASTER_H
