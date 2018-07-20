/*
 * $Id: picload.cpp,v 1.10 2002/06/05 12:49:42 casey Exp $
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#include "picload.h"
#include "picevent.h"

extern int errno;

PicLoad::PicLoad(QObject *parent, const char *name)
	: QServerSocket(GUIPICPORT, 1, parent, name)
{
   tcppic = parent;
   pt = NULL;
}

void PicLoad::newConnection(int fd)
{
   if (pt)
   {
     close(fd);
     return;
   }
   pt = new PicThread(tcppic, this, fd);
   emit status("Remote Feed Connected");
}

void PicLoad::customEvent(QCustomEvent *e)
{
  bool check;
  if (e->type() == 909193)
  {
    qDebug("PicLoad::customEvent(): *** Time to end a threads life ***");
    PictureDoneEvent *pe = (PictureDoneEvent*)e;
    check = pt->wait(0);
//    qDebug("PicLoad::customEvent(): check=%d",check);
    delete pt;
    pt = NULL;
    emit status("Vision Awaiting Connection");
  }
}

PicLoad::~PicLoad()
{
}

PicThread::PicThread(QObject *reciever, QObject *killnotify, int socket)
{
  tcppic = reciever;
  parent = killnotify;
  fd = socket;
  //QThread::start();
  start();
}

void PicThread::run()
{
  QString qs;
  pic_header ph;
  int len, readtot, ret;
  char *data;

  qDebug("PicLoad::run(): *** START PicLoad ***");
  while (1) 
  {
//     qDebug("PicLoad::run(): *** START LOOP ***");
     readtot = 0;
     do
     {
        ret = recv(fd, (char*)&ph+readtot, sizeof(ph)-readtot, MSG_PEEK);
	if ((ret == -1) && (errno == EINTR))
	  continue;
	readtot += ret;
     } while ((ret >= 0) && (readtot < sizeof(ph)));
     if (ret < 0)
     {
        qDebug("      ERROR -- %d", ret);
	break;
     }
//     qDebug("PicLoad::run():       Read Header -- %d bytes", readtot);

     if (ph.opcode == 92)
        break;
//     qDebug("PicLoad::run(): Read Header");
     len = ph.len+8;
     data = new char[len];


     readtot = 0;
     do {
       ret = recv(fd, data+readtot, len-readtot, 0);
//       qDebug("PicLoad::run():       ERRNO -- %d", errno);
       if (ret < 0)
         perror("recv");
       if ((ret == -1) && (errno == EINTR))
	 ret=0;
       readtot += ret;
     } while ((ret >= 0) && (readtot < len));

     if (ret < 0)
     {
        qDebug("PicLoad::run():       ERROR -- %d", ret);
        qDebug("PicLoad::run():       ERRNO -- %d", errno);
	break;
     }
//     qDebug("PicLoad::run():       Read Body -- %d bytes", readtot);
//     qs.sprintf("Read %d Total Bytes", readtot);

     PictureEvent *pe = new PictureEvent(data);
     postEvent(tcppic, pe);
     
//     qDebug("PicLoad::run(): *** END LOOP ***");
  } 
  shutdown(fd, SHUT_RDWR);
  //::close(fd);
  qDebug("PicLoad::run(): *** END PicLoad ***");

  PictureDoneEvent *pd = new PictureDoneEvent();
  postEvent(parent, pd);
}

