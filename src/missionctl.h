/*
 * main.h -- Definition of MainWindow
 *
 * $Id: missionctl.h,v 1.2 2002/06/05 12:49:42 casey Exp $
 *
 */

#ifndef __MAIN_H
#define __MAIN_H

 #include <qmainwindow.h>
 #include <qlayout.h>
 #include <qsocketnotifier.h>
 #include <qsocketdevice.h>
 #include <qsocket.h>

 #include "shell.h"
 #include "ap.h"
 #include "net.h"
 #include "tweak.h"
 #include "debug.h"
 #include "watch.h"
 #include "udpmaster.h"

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
   void sendPacket(int);
   void sendPacket(int, const char*, int);
   void startconnect();
   void endconnect();
   void hostdone();
   void hostconnect();
   void sigcon();
   void toggletel();
   void togglevel();
   void toggleTweak();
   void toggleDebug();
   void toggleWatch();
   void toggleAP();
   void setStat1(QString s);
   void setStat2(QString s);
   void setapstat(QString s);
   void setgpstat(QString s);
   void setQWS();
   void setQSGIW();
   void setQCDEW();
   void setQMW();
   void setQMPW();
   void setQPW();
//   void setQAW();
   void about();
   void aboutqt();
   void thptstats();
   void picformats();
private:
   void setupMenu();
   void setupStat();
   void saveSettings();
   ShellWidget *shl;
   APWidget *apdata;
   TweakWindow *tw;
   DebugWindow *dw;
   WatchWindow *ww;
   UDPMaster *udp;

   QSocket *scontrol;
   QLabel *stat1;
   QLabel *stat2;
   QLabel *apstat;
   QLabel *gpstat;
   QPopupMenu *display;
   QPopupMenu *datamenu;

   unsigned int bytetot;
   unsigned int byteold;
   unsigned int pkttot;
   unsigned int pktold;
   QTimer *statctr;
   bool ttel;
   bool tvel;
   bool showtweak;
   bool showdebug;
   bool showwatch;
   bool showap;
   int watchopt;
   int tweakopt;
   int debugopt;
   int apopt;
   int telopt;
   int velopt;
   int conopt;
   int disopt;
   int airopt;
   int gndopt;
   int controlactive;
 };

#endif // __MAIN_H
