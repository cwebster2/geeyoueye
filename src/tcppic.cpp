/*
 * $Id: tcppic.cpp,v 1.4 2002/06/05 12:49:42 casey Exp $
 */

#include <qhbox.h>
#include <qhgroupbox.h>

#include "tcppic.h"
#include "picevent.h"
#include "net.h"

TCPPic::TCPPic(QWidget *parent, const char* name)
	: QWidget(parent, name)
{
  air = new PicWindow(NULL, "Air Picture Feed");
  ground = new PicWindow(NULL, "Ground Picture Feed");
  air->show();
  ground->show();

  pl = new PicLoad(this);
  connect(pl, SIGNAL(status(QString)), parent, SLOT(setStat1(QString)));
}

void TCPPic::customEvent(QCustomEvent *e)
{
  char *data;
  pic_header *ph;
  if (e->type() == 909192)
  {
    PictureEvent *pe = (PictureEvent*)e;
    data = pe->GetData();
    ph = (pic_header*)data;
    switch (ph->opcode) {
      case AIRPIC : air->newPic((char*)data, ph->len); break;
      case GNDPIC : ground->newPic((char*)data, ph->len); break;
    }
  }
}
