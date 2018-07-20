/*
 * vision.h -- Definition of MainWindow
 *
 * $Id: vision.h,v 1.2 2002/06/05 12:49:42 casey Exp $
 *
 */

#ifndef __MAIN_H
#define __MAIN_H

 #include <qmainwindow.h>
 #include <qlayout.h>
 #include <qsocketnotifier.h>
 #include <qsocketdevice.h>
 #include <qsocket.h>
 #include <qtimer.h>

 #include "debug.h"
 #include "tcppic.h"

 #ifdef HAVE_CONFIG_H
    #include "config.h"
 #endif

 class MainWindow : public QMainWindow
 {
   Q_OBJECT

public:
   MainWindow(QWidget *parent=0, const char *name=0);
   ~MainWindow();
public slots:
   void toggleDebug();
   void setStat1(QString s);
   void about();
   void aboutqt();
   void picformats();
private:
   void setupMenu();
   void setupStat();
   void saveSettings();
   DebugWindow *dw;
   TCPPic *tcppic;

   QLabel *stat1;
   QPopupMenu *display;

   bool showdebug;
   int debugopt;
 };

#endif // __MAIN_H
