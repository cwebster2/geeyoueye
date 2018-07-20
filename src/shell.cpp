/*
 * shell.c -- Definition of ShellWidget
 *
 * $Log: shell.cpp,v $
 * Revision 1.3  2001/11/12 05:41:50  casey
 * data update
 *
 * Revision 1.2  2001/10/19 18:52:53  casey
 * Put RCS tags in project files.
 *
 *
 */

#include <qlabel.h>

#include "shell.h"

ShellWidget::ShellWidget(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setMinimumSize(200,80);
   setMaximumSize(640,480);

   QLabel *lbl = new QLabel("Shell Widget", this);
   lbl->setGeometry(62,40,175,30);
   lbl->setFont(QFont("Times", 10, QFont::Bold));

   //connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

