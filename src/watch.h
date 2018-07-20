/*
 * $Id: watch.h,v 1.2 2001/11/26 12:09:46 casey Exp $
 */

#ifndef __WATCH_H
#define __WATCH_H

 #include <qwidget.h>
 #include <qlistview.h>
 #include <qpushbutton.h>

 class WatchWindow : public QWidget
 {
 Q_OBJECT

 public:
   WatchWindow(QWidget *parent=0, const char *name=0);
 private:
   QPushButton *add;
   QPushButton *deleteb;
   QListView *active;
   QListView *inactive;
 };

#endif // __Watch_H
