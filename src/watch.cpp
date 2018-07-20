/*
 * $Id: watch.cpp,v 1.2 2001/11/26 12:09:46 casey Exp $
 */

#include <qlabel.h>
#include <qlayout.h>
#include <qvbox.h>

#include "watch.h"

WatchWindow::WatchWindow(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setCaption("Watch Window");

   QGridLayout *top = new QGridLayout(this,0,0);
   top->setSpacing(5);
   top->setMargin(5);

   active = new QListView(this);
   active->addColumn("Variable");
   active->addColumn("Value");
   top->addWidget(active,0,0);
   inactive = new QListView(this);
   inactive->addColumn("Variables");
   top->addWidget(inactive,0,2);

   QVBox *vbox = new QVBox(this);
   add = new QPushButton("<--", vbox);
   deleteb = new QPushButton("-->", vbox);
   top->addWidget(vbox,0,1);
}

