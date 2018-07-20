/*
 * main.c -- Implementation of the Main Widget
 *           and Application
 *
 * $Id: missionctl.cpp,v 1.3 2002/06/06 12:23:50 casey Exp $
 *
 */

#include <qapplication.h>  
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qcolor.h>
#include <qmenubar.h>
#include <qstatusbar.h>
#include <qpopupmenu.h>
#include <qsplitter.h>
#include <qinputdialog.h>
#include <qhostaddress.h>
#include <qstyle.h>
#include <qsgistyle.h>
#include <qmotifstyle.h>
#include <qcdestyle.h>
#include <qplatinumstyle.h>
#include <qwindowsstyle.h>
#include <qmotifplusstyle.h>
//#include <qaquastyle.h>
#include <qmessagebox.h>
#include <qimage.h>
#include <qstrlist.h>
#include <qmutex.h>
#include <qsettings.h>
#include <qhbox.h>

#include "missionctl.h"

DebugWindow *qdw;
QMutex qDebugLock; //qtDebugHook can be called from multiple threads

static void qtDebugHook(QtMsgType, const char *msg)
{
   qDebugLock.lock();
   if (qdw)
      qdw->guiDebug(msg);
   qDebugLock.unlock();
}

MainWindow::MainWindow(QWidget *parent, const char *name)
	: QMainWindow(parent, name)
{
   setMinimumSize(640,480);
   setMaximumSize(1600,1200);

   dw = new DebugWindow(NULL);
   qdw = dw;
   ::qInstallMsgHandler(qtDebugHook);
   setupMenu();
   setupStat();

   QHBox *box = new QHBox(this);
   setCentralWidget(box);
   udp = new UDPMaster(box, "UDP Master Class");
   
   //shl = new ShellWidget(left);
   //
   tw = new TweakWindow(NULL);
   connect(tw, SIGNAL(Packet(int,const char*,int)), this, SLOT(sendPacket(int, const char*, int)));
   connect(tw, SIGNAL(Packet(int)), this, SLOT(sendPacket(int)));
   ww = new WatchWindow(NULL);
   apdata = new APWidget(NULL);
   connect(udp, SIGNAL(newX(float)), apdata, SLOT(curX(float)));
   connect(udp, SIGNAL(newY(float)), apdata, SLOT(curY(float)));
   connect(udp, SIGNAL(newZ(float)), apdata, SLOT(curZ(float)));

   controlactive = 0;
   scontrol = new QSocket(this);
   
   bytetot = 0;
   byteold = 0;
   pkttot = 0;
   pktold = 0;
   statctr = new QTimer(this);
   connect(statctr, SIGNAL(timeout()), this, SLOT(thptstats()));
   statctr->start(1000);
   // REstor window status
   // geometry before show :)
   bool ok = TRUE;
   int x,y,w,h;
   QSettings settings;
   x = settings.readNumEntry("/geeyoueye/MainWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/MainWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/MainWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/MainWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      this->setGeometry(x,y,w,h);
   ok = TRUE;
   x = settings.readNumEntry("/geeyoueye/TweakWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/TweakWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/TweakWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/TweakWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      tw->setGeometry(x,y,w,h);
   ok = TRUE;
   x = settings.readNumEntry("/geeyoueye/DebugWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/DebugWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/DebugWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/DebugWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      dw->setGeometry(x,y,w,h);
   ok = TRUE;
   x = settings.readNumEntry("/geeyoueye/WatchWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/WatchWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/WatchWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/WatchWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      ww->setGeometry(x,y,w,h);
   ok = TRUE;
   x = settings.readNumEntry("/geeyoueye/APWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/APWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/APWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/APWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      apdata->setGeometry(x,y,w,h);

   if (showtweak)
      tw->show();
   if (showdebug)
      dw->show();
   if (showwatch)
      ww->show();
   if (showap)
      apdata->show();
}

void MainWindow::saveSettings()
{
   QSettings s;
   QRect geo;
   // get window geometry to save
   geo = this->geometry();
   s.writeEntry("/geeyoueye/MainWindow/y", geo.top());
   s.writeEntry("/geeyoueye/MainWindow/x", geo.left());
   s.writeEntry("/geeyoueye/MainWindow/w", geo.width());
   s.writeEntry("/geeyoueye/MainWindow/h", geo.height());
   geo = tw->geometry();
   s.writeEntry("/geeyoueye/TweakWindow/y", geo.top());
   s.writeEntry("/geeyoueye/TweakWindow/x", geo.left());
   s.writeEntry("/geeyoueye/TweakWindow/w", geo.width());
   s.writeEntry("/geeyoueye/TweakWindow/h", geo.height());
   geo = ww->geometry();
   s.writeEntry("/geeyoueye/WatchWindow/y", geo.top());
   s.writeEntry("/geeyoueye/WatchWindow/x", geo.left());
   s.writeEntry("/geeyoueye/WatchWindow/w", geo.width());
   s.writeEntry("/geeyoueye/WatchWindow/h", geo.height());
   geo = dw->geometry();
   s.writeEntry("/geeyoueye/DebugWindow/y", geo.top());
   s.writeEntry("/geeyoueye/DebugWindow/x", geo.left());
   s.writeEntry("/geeyoueye/DebugWindow/w", geo.width());
   s.writeEntry("/geeyoueye/DebugWindow/h", geo.height());
   geo = apdata->geometry();
   s.writeEntry("/geeyoueye/APWindow/y", geo.top());
   s.writeEntry("/geeyoueye/APWindow/x", geo.left());
   s.writeEntry("/geeyoueye/APWindow/w", geo.width());
   s.writeEntry("/geeyoueye/APWindow/h", geo.height());

   // get window state
   s.writeEntry("/geeyoueye/TweakWindow/state", !(tw->isHidden()));
   s.writeEntry("/geeyoueye/DebugWindow/state", !(dw->isHidden()));
   s.writeEntry("/geeyoueye/WatchWindow/state", !(ww->isHidden()));
   s.writeEntry("/geeyoueye/APWindow/state", !(apdata->isHidden()));
   // need to destructivly close other top level windows so they die
   // properly and call thier destructors
}

MainWindow::~MainWindow()
{
   saveSettings();
   tw->close(TRUE);
   dw->close(TRUE);
   ww->close(TRUE);
   apdata->close(TRUE);
}

void MainWindow::setupMenu()
{
   menuBar()->setSeparator( QMenuBar::InWindowsStyle );
   QPopupMenu* popup = new QPopupMenu( this );
   datamenu = new QPopupMenu(this);
   display = new QPopupMenu(this); //declared in .h for checkmarks
   QPopupMenu *qstyle = new QPopupMenu(this);
   QPopupMenu *help = new QPopupMenu(this);

   popup->insertItem( "&Quit", qApp, SLOT(quit()) );

   conopt = datamenu->insertItem("Connect to Reporter", this, SLOT(startconnect()));
   disopt = datamenu->insertItem("Disconnect to Reporter", this, SLOT(endconnect()));
   telopt = datamenu->insertItem("Send Telemetry Data", this, SLOT(toggletel()));
   velopt = datamenu->insertItem("Send Velocity Data", this, SLOT(togglevel()));
   datamenu->insertItem("Force Signal Connect", this, SLOT(sigcon()));

   datamenu->setCheckable(TRUE);
   datamenu->setItemEnabled(disopt, FALSE);
   datamenu->setItemEnabled(telopt, FALSE);
   datamenu->setItemEnabled(velopt, FALSE);


//   airopt = display->insertItem("Aircraft Picture Feed", this, SLOT(toggleAir()));
//   gndopt = display->insertItem("Ground Picture Feed", this, SLOT(toggleGnd()));
   apopt = display->insertItem("GPS/Flight Plan Window", this, SLOT(toggleAP()));
   display->insertSeparator();
   tweakopt = display->insertItem("Tweak Window", this, SLOT(toggleTweak()));
   watchopt = display->insertItem("Watch Window", this, SLOT(toggleWatch()));
   display->insertSeparator();
   debugopt = display->insertItem("Debug Window", this, SLOT(toggleDebug()));
   display->setCheckable(TRUE);
//   showair = showgnd = TRUE;
//   display->setItemChecked(airopt, showair);
//   display->setItemChecked(gndopt, showgnd);

   QSettings setting;
   showtweak = setting.readBoolEntry("/geeyoueye/TweakWindow/state");
   showdebug = setting.readBoolEntry("/geeyoueye/DebugWindow/state");
   showwatch = setting.readBoolEntry("/geeyoueye/WatchWindow/state");
   showap = setting.readBoolEntry("/geeyoueye/APWindow/state");
   display->setItemChecked(tweakopt, showtweak);
   display->setItemChecked(debugopt, showdebug);
   display->setItemChecked(watchopt, showwatch);
   display->setItemChecked(apopt, showap);


   qstyle->insertItem("QWindow", this, SLOT(setQWS()));
   qstyle->insertItem("SGI", this, SLOT(setQSGIW()));
   qstyle->insertItem("Motif+", this, SLOT(setQMW()));
   qstyle->insertItem("Motif", this, SLOT(setQMPW()));
   qstyle->insertItem("CDE", this, SLOT(setQCDEW()));
   qstyle->insertItem("Platinum", this, SLOT(setQPW()));
//   qstyle->insertItem("Aqua", this, SLOT(setQAW()));

   help->insertItem("Supported Picture Formats", this, SLOT(picformats()));
   help->insertSeparator();
   help->insertItem("&About", this, SLOT(about()));
   help->insertItem("About &Qt", this, SLOT(aboutqt()));
   
   menuBar()->insertItem( "&File", popup );
   menuBar()->insertItem("D&ata", datamenu);
   menuBar()->insertItem("&Display", display);
   menuBar()->insertItem("&Style", qstyle);
   menuBar()->insertSeparator();
   menuBar()->insertItem("&Help", help);
}

void MainWindow::setupStat()
{
   stat1 = new QLabel(statusBar());
   stat1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   stat1->setFixedHeight( stat1->sizeHint().height() );
   stat1->setAlignment( AlignVCenter | AlignLeft );
   stat2 = new QLabel(statusBar());
   stat2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   stat2->setFixedHeight( stat1->sizeHint().height() );
   stat2->setAlignment( AlignVCenter | AlignLeft );

   apstat = new QLabel(statusBar());
   apstat->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   apstat->setFixedHeight( stat1->sizeHint().height() );
   apstat->setAlignment( AlignVCenter | AlignLeft );

   gpstat = new QLabel(statusBar());
   gpstat->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   gpstat->setFixedHeight( stat1->sizeHint().height() );
   gpstat->setAlignment( AlignVCenter | AlignLeft );

   statusBar()->addWidget(stat1, 1, TRUE);
   statusBar()->addWidget(apstat, 0, TRUE);
   statusBar()->addWidget(gpstat, 0, TRUE);
   statusBar()->addWidget(stat2, 0, TRUE);

   stat1->setText("Geeyoueye loaded !!!!!!!");

}

int main(int argc, char** argv) 
{
   QApplication a(argc, argv);
   MainWindow main;

   //main->setGeometry(100,100,200,120);
   a.setMainWidget(&main);
   main.show();
   return a.exec();
}

void MainWindow::sendPacket(int opcode)
{
   char *buf = new char[sizeof(packet_hdr)];
   packet_hdr * ph = (packet_hdr*)buf;
   ph->opcode=opcode;
   ph->len = sizeof(packet_hdr);

   qDebug("SEND OPCODE 0x%X", ph->opcode);
   qDebug("SEND LENGTH %d", ph->len);
   // SEND packet on control connection :)
   scontrol->writeBlock((const char*)buf, ph->len);

   delete buf;
}

void MainWindow::sendPacket(int opcode, const char *data, int len)
{
   char *buf = new char[len+sizeof(packet_hdr)];
   //memset(buf, 0, len+sizeof(packet_hdr));
   packet_hdr * ph = (packet_hdr*)buf;
   //qDebug("BUF  addr 0x%X", buf);
   //qDebug("PH   addr 0x%X", ph);
   //qDebug("DATA addr 0x%X", buf+sizeof(packet_hdr));

   ph->opcode=opcode;
   ph->len = len+sizeof(packet_hdr);
   memcpy(buf+sizeof(packet_hdr), data, len);
   qDebug("SEND OPCODE 0x%X", ph->opcode);
   qDebug("SEND LENGTH %d", ph->len);
   // SEND packet on control connection :)
   scontrol->writeBlock((const char*)buf, ph->len);

   delete buf;
}

void MainWindow::startconnect()
{
   QString ipaddr;
   bool ok = FALSE;

   ipaddr = QInputDialog::getText(tr("Enter IP of telemetry reporting server"), 
   	tr("IP"), QLineEdit::Normal, "localhost", &ok, this);
   	//tr("IP"), QString::null, &ok, this);

   if (ok && !ipaddr.isEmpty())
   {
   
     scontrol->connectToHost(ipaddr,CONTROLPORT);

     /// connect to host emits hostFound, then connected when stuff happens.
     connect(scontrol, SIGNAL(connected()), this, SLOT(hostconnect()));
     connect(scontrol, SIGNAL(hostFound()), this, SLOT(hostdone()));
     stat1->setText("Control Connection Initialized");
   }
   else
   {
      QMessageBox::warning(this, tr("Error..."), tr("Invalid Name"));
   }
}

void MainWindow::hostdone()
{
   stat1->setText("Control Connection Host Lookup completed");
}

void MainWindow::hostconnect()
{
   tcp_register tcpr;

   tcpr.opcode = REGISTER;
   tcpr.len = sizeof(tcp_register);
   //tcpr.ip = 0x7f000001;
   tcpr.ip = scontrol->address().ip4Addr();
   sendPacket(REGISTER, (const char*)&tcpr.ip, 4);
   //scontrol->writeBlock((const char*)&tcpr, tcpr.len);
   stat1->setText("Control Connection Registered");
   //td = new TelData();
   ttel = 0;
   tvel = 0;
   datamenu->setItemEnabled(conopt, FALSE);
   datamenu->setItemEnabled(disopt, TRUE);
   datamenu->setItemEnabled(telopt, TRUE);
   datamenu->setItemEnabled(velopt, TRUE);
   controlactive = 1;
}

void MainWindow::sigcon()
{
}

void MainWindow::endconnect()
{
   //tcp_deregister tcpr;

   //tcpr.opcode = DEREGISTER;
   //tcpr.len = sizeof(tcp_register);
   //tcpr.ip = 0x7f000001;
   //scontrol->writeBlock((const char*)&tcpr, tcpr.len);
   sendPacket(DEREGISTER);
   stat1->setText("Control Connection Deegistered");
   //delete td;
   //td->end();
   disconnect(scontrol,0,0,0);
   //disconnect(td,0,0,0);
   scontrol->close();
   //delete td;
   ttel = 0;
   tvel = 0;
   datamenu->setItemChecked(telopt, FALSE);
   datamenu->setItemChecked(velopt, FALSE);
   datamenu->setItemEnabled(conopt, TRUE);
   datamenu->setItemEnabled(disopt, FALSE);
   datamenu->setItemEnabled(telopt, FALSE);
   datamenu->setItemEnabled(velopt, FALSE);
   controlactive = 0;
}

void MainWindow::toggletel()
{
   int tt;

   if (ttel) // turn off
   {
      datamenu->setItemChecked(telopt, FALSE);
      ttel = 0;
      tt = TELOFF;
   }
   else  //turn on
   {
      datamenu->setItemChecked(telopt, TRUE);
      ttel = 1;
      tt = TELON;
   }
   sendPacket(tt);
}

void MainWindow::togglevel()
{
   int tt;

   if (tvel) // turn off
   {
      datamenu->setItemChecked(velopt, FALSE);
      tvel = 0;
      tt = VELOFF;
   }
   else  //turn on
   {
      datamenu->setItemChecked(velopt, TRUE);
      tvel = 1;
      tt = VELON;
   }
   sendPacket(tt);
}

void MainWindow::toggleAP()
{
   if (showap)
   {
      apdata->hide();
      display->setItemChecked(apopt, FALSE);
   }
   else
   {
      apdata->show();
      display->setItemChecked(apopt, TRUE);
   }
   showap = !showap;
}

void MainWindow::toggleDebug()
{
   if (showdebug)
   {
      dw->hide();
      display->setItemChecked(debugopt, FALSE);
   }
   else
   {
      dw->show();
      display->setItemChecked(debugopt, TRUE);
   }
   showdebug = !showdebug;
}

void MainWindow::toggleWatch()
{
   if (showwatch)
   {
      ww->hide();
      display->setItemChecked(watchopt, FALSE);
   }
   else
   {
      ww->show();
      display->setItemChecked(watchopt, TRUE);
   }
   showwatch = !showwatch;
}

void MainWindow::toggleTweak()
{
   if (showtweak)
   {
      tw->hide();
      display->setItemChecked(tweakopt, FALSE);
   }
   else
   {
      tw->show();
      display->setItemChecked(tweakopt, TRUE);
   }
   showtweak = !showtweak;
}

void MainWindow::setStat1(QString s)
{
   stat1->setText(s);
}

void MainWindow::setStat2(QString s)
{
   stat2->setText(s);
}

void MainWindow::setapstat(QString s)
{
   apstat->setText(s);
}

void MainWindow::setgpstat(QString s)
{
   gpstat->setText(s);
}

void MainWindow::setQWS()
{
   //QApplication::setStyle(new QWindowsStyle); 
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
void MainWindow::setQSGIW()
{
   //QApplication::setStyle(new QSGIStyle); 
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
void MainWindow::setQMW()
{
   //QApplication::setStyle(new QMotifStyle);
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
void MainWindow::setQMPW()
{
   //QApplication::setStyle(new QMotifPlusStyle);
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
void MainWindow::setQCDEW()
{
   //QApplication::setStyle(new QCDEStyle);
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
void MainWindow::setQPW()
{
   //QApplication::setStyle(new QPlatinumStyle); 
   QMessageBox::warning(this, tr("Error..."), tr("Disabled"));
}
//void MainWindow::setQAW()
//{
//   QApplication::setStyle(new QAquaStyle); 
//}

void MainWindow::about()
{
   QMessageBox::about(this, PACKAGE " " VERSION, PACKAGE " Version " VERSION 
                      "\n" "Remote Telemtry and Command Console\n");
}

void MainWindow::aboutqt()
{
   QMessageBox::aboutQt(this, PACKAGE);
}
                      
void MainWindow::thptstats()
{
   // Calculate network throughput
   QString s;
   int bdiff = (bytetot - byteold);
   int pdiff = (pkttot - pktold);
   byteold = bytetot;
   pktold = pkttot;
   s.sprintf("%d bytes total, %d bytes/s, %d packets/s", bytetot, bdiff, pdiff);
   stat2->setText(s);
}

void MainWindow::picformats()
{
   QStrList formats = QImageIO::inputFormats();
   QStrListIterator it(formats);

   QString format;
   QString all;
   while((format = it.current()) != 0)
   {
      ++it;
      all += format;
      //QMessageBox::information(this, "Supported Image Formats", *format );
      all += "\n";
   }
   QMessageBox::information(this, "Supported Image Formats", all );
}
