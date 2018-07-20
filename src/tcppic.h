/*
 * $Id: tcppic.h,v 1.4 2002/06/05 12:49:42 casey Exp $
 */

#ifndef __TCPPIC_H
#define __TCPPIC_H

 #include <qwidget.h>
 #include <qsocketdevice.h>
 #include <qsocketnotifier.h>
 #include <qimage.h>
 #include <qptrqueue.h>

 #include "picload.h"
 #include "pic.h"

 class TCPPic : public QWidget
 {
 Q_OBJECT

 public:
   TCPPic(QWidget *parent=0, const char* name=0);
 signals:
   void status(QString);
 private:
   QSocketDevice *s;
   QSocketNotifier *sn;
   PicLoad *pl;
   PicWindow *air;
   PicWindow *ground;
 protected:
   virtual void customEvent(QCustomEvent *e);
 };

#endif //__TCPPIC_H
