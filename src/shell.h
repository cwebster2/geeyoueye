/*
 * shell.h -- Definition of ShellWidget
 *
 * $Log: shell.h,v $
 * Revision 1.2  2001/10/19 18:52:53  casey
 * Put RCS tags in project files.
 *
 *
 */

#ifndef __SHELL_H
#define __SHELL_H

 #include <qwidget.h>

 class ShellWidget : public QWidget
 {
   Q_OBJECT

 public:
   ShellWidget(QWidget *parent=0, const char *name=0);
 };

#endif // __SHELL_H
