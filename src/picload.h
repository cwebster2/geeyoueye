/*
 * $Id: picload.h,v 1.8 2002/06/05 12:49:42 casey Exp $
 */

#ifndef __PICLOAD_H
#define __PICLOAD_H

 #include <qthread.h>
 #include <qobject.h>
 #include <qimage.h>
 #include <qserversocket.h>

 #include "net.h"

 class PicThread : public QObject, public QThread
 {
 Q_OBJECT
 public:
   PicThread(QObject*, QObject*, int);
   virtual void run();
 private:
   QObject *tcppic;
   QObject *parent;
   int fd;
 };

 class PicLoad : public QServerSocket
 {
   Q_OBJECT
   
 public:
   PicLoad(QObject *parent = 0, const char *name = 0);
   ~PicLoad();
   void newConnection(int);
 signals:
   void status(QString);
 private:
   QObject *tcppic;
   PicThread *pt;
 protected:
   virtual void customEvent(QCustomEvent *e);
 };

#endif // PICLOAD_H
