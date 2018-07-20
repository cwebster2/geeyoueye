/*
 * $Id: tweak.h,v 1.15 2002/02/11 14:40:56 casey Exp $
 */

#ifndef __TWEAK_H
#define __TWEAK_H

 #include <qwidget.h>
 #include <qslider.h>
 #include <qlineedit.h>
 #include <qvgroupbox.h>
 #include <qcombobox.h>
 #include <qstatusbar.h>
 #include <qlabel.h>
 #include <qpushbutton.h>
 #include <qtimer.h>

 #include "net.h"

 #define S_C 0  /* xxx00 */
 #define S_P 1  /* xxx01 */
 #define S_I 2  /* xxx10 */
 #define S_D 3  /* xxx11 */

 #define G_R 0  /* 000xx */
 #define G_P 4  /* 001xx */
 #define G_H 8  /* 010xx */
 #define G_X 12 /* 011xx */
 #define G_Y 16 /* 100xx */
 #define G_Z 20 /* 101xx */

 #define SLIDER(x) (x & 0x03)
 #define GROUP(x)  ((x>>2) & 0x07)

 #define MODE_STATE	1
 #define MODE_SET	2

 class TweakWidget : public QWidget
 {
 Q_OBJECT

 public:
   TweakWidget(int group, QString displayname, QWidget *parent=0, char * name=0);
   pidval getAll();
 public slots:
   void newValue();
   void setAll(pidval);
 private:
   pidval local;
   int group;
   QLineEdit *edits[5];
 };

 class TweakWindow : public QWidget
 {
 Q_OBJECT

 public:
   TweakWindow(QWidget *parent=0, char * name=0);
 public slots:
   void newDataAvailable(int);
   void goPressed();
   void countdown();
   void newButton();
   void resetButton();
   void loadButton();
   void sendButton();
   void saveState();
   void loadSet(const QString&);
   void newSet();
   void changeMode();
 signals:
   void Packet(int,const char*,int);
   void Packet(int);
 private:
   void newStateGroup(QString);
   void newState(QString);
   void loadStateGroup(QString);
   void loadState(QString);
   void loadState(int);
   void saveStateGroup();
   void sendState(int);
   void sendNextState(int, float);
   void sendStateGroup(QString);
   void sendStateGroupState(QString, int);
   void sendStateIndex(int);
   void sendNextStateIndex(int,float);
   void updateStateFromSliders();
   new_tweak_pkt fillTweakPacket(QString set, int state);
   void Next(int, float);
   void Now(int);

   TweakWidget *roll;
   TweakWidget *heading;
   TweakWidget *pitch;
   TweakWidget *x;
   TweakWidget *y;
   TweakWidget *z;
   QComboBox *prf;
   QStatusBar *status;
   QLabel *curstate;
   QComboBox *nextstate;
   QComboBox *editstate;
   QLineEdit *nexttime;
   QPushButton *go;
   QTimer *time;
   QPushButton *newst;
   QPushButton *reset;
   QPushButton *load;
   QPushButton *send;
   QPushButton *save;
   QLabel *ceditstate;
   QString currentset;
   int currentstateindex;
   QString currenteditstate;
   int currenteditindex;
   QString currentstate;
   int mode;
   int smodeopt;
   int ssmodeopt;
   QPopupMenu *modemenu;
   
   new_tweak_pkt state;
 };

#endif // __TWEAK_H
