/*
 * $Id: debug.h,v 1.3 2002/02/11 14:40:56 casey Exp $
 */

#ifndef __DEBUG_H
#define __DEBUG_H

 #include <qwidget.h>
 #include <qmultilineedit.h>
 #include <qpushbutton.h>
 #include <qlineedit.h>
 #include <qcheckbox.h>
 #include <qfile.h>
 #include <qtextstream.h>

 class DebugWindow : public QWidget
 {
 Q_OBJECT

 public:
   DebugWindow(QWidget *parent=0, const char *name=0);
   ~DebugWindow();
 public slots:
   void guiDebug(QString&);
   void guiDebug(const char*);
   void clearPressed();
   void maxlinesChanged(const QString&);
   void browsePressed();
   void togglefile(bool);
 private:
   QMultiLineEdit *debugview;
   QPushButton *clear; 
   QLineEdit *lemaxlines;
   QLineEdit *lefilename;
   QCheckBox *cblogtofile;
   QPushButton *browsebutton;
   QFile *file;
   QTextStream *f;
   QString filename;
   int maxlines;
   bool logtofile;
 };

#endif // __DEBUG_H
