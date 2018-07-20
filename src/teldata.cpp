/*
 * $Id: teldata.cpp,v 1.5 2002/06/05 12:49:42 casey Exp $
 */

#include "teldata.h"
#include "televent.h"

TelData::TelData(QObject *parent, const char *name)
	: QObject(parent, name)
{
   s = new QSocketDevice(QSocketDevice::Datagram);
   if (!s->bind(QHostAddress(), GUIPORT))
     qDebug("Telemetry Socket Bind Error");
   s->setAddressReusable(TRUE);
   notify=parent;
   QThread::start();
}

void TelData::end()
{
   done = 1;
}

void TelData::run()
{
  int ret;
  //net_data *td;
  packet_hdr *pkt;
  done = 0;
  char *off;
  while (!done)
  {
    off = new char[100];
    memset(off, 0, 100);
    ret = s->readBlock(off, 100);
    //bytetot += ret;
    //pkttot++;
    pkt = (packet_hdr*)off;
    switch (pkt->opcode) {
       case NETDATA:
	  //td = (net_data*)off;
	  //teldata(td);
	  TelDataEvent *te = new TelDataEvent(off);
	  postEvent(notify, te);
          break;
    }
    //qDebug("Read %d bytes from network", ret);
  }
  s->close();
}
