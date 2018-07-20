/*
 * $Id: teldata.h,v 1.5 2002/06/05 12:49:42 casey Exp $
 */

#ifndef __TELDATA_H
#define __TELDATA_H

 #include <qthread.h>
 #include <qobject.h>
 #include <qsocketdevice.h>

 #include "net.h"

 class TelData : public QObject, public QThread
 {
   Q_OBJECT
   
 public:
   TelData(QObject *parent = 0, const char *name = 0);
 public slots:
   void end();
 protected:
   virtual void run();
 private:
   void teldata(net_data*);
   QObject *notify;
   QSocketDevice *s;
   float yaw;
   float pitch;
   float roll;
   float x;
   float y;
   float z;
   float tach;
   float vx;
   float vy;
   float vz;
   bool done;
 };


#endif // __TELDATA_H
