/*
 * vision.c -- Implementation of the Main Widget
 *             and Application
 *
 * $Id: vision.cpp,v 1.2 2002/06/05 12:49:42 casey Exp $
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
#include <qmessagebox.h>
#include <qimage.h>
#include <qstrlist.h>
#include <qmutex.h>
#include <qsettings.h>
#include <qhbox.h>

#include "vision.h"

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
   
   tcppic = new TCPPic(this, "TCP Picture Class");
   connect(tcppic, SIGNAL(status(QString s)), SLOT(setStat1(QString s)));

   // REstor window status
   // geometry before show :)
   bool ok = TRUE;
   int x,y,w,h;
   QSettings settings;
   x = settings.readNumEntry("/geeyoueye/vision/MainWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/vision/MainWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/vision/MainWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/vision/MainWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      this->setGeometry(x,y,w,h);
   ok = TRUE;
   x = settings.readNumEntry("/geeyoueye/vision/DebugWindow/x", -1, &ok);
   y = settings.readNumEntry("/geeyoueye/vision/DebugWindow/y", -1);
   w = settings.readNumEntry("/geeyoueye/vision/DebugWindow/w", -1);
   h = settings.readNumEntry("/geeyoueye/vision/DebugWindow/h", -1);
   if (ok && (x>-1) && (w>-1) && (y>-1) && (h>-1))
      dw->setGeometry(x,y,w,h);
   ok = TRUE;

   if (showdebug)
      dw->show();
}

void MainWindow::saveSettings()
{
   QSettings s;
   QRect geo;
   // get window geometry to save
   geo = this->geometry();
   s.writeEntry("/geeyoueye/vision/MainWindow/y", geo.top());
   s.writeEntry("/geeyoueye/vision/MainWindow/x", geo.left());
   s.writeEntry("/geeyoueye/vision/MainWindow/w", geo.width());
   s.writeEntry("/geeyoueye/vision/MainWindow/h", geo.height());
   geo = dw->geometry();
   s.writeEntry("/geeyoueye/vision/DebugWindow/y", geo.top());
   s.writeEntry("/geeyoueye/vision/DebugWindow/x", geo.left());
   s.writeEntry("/geeyoueye/vision/DebugWindow/w", geo.width());
   s.writeEntry("/geeyoueye/vision/DebugWindow/h", geo.height());

   // get window state
   s.writeEntry("/geeyoueye/vision/DebugWindow/state", !(dw->isHidden()));
   // need to destructivly close other top level windows so they die
   // properly and call thier destructors
}

MainWindow::~MainWindow()
{
   saveSettings();
   dw->close(TRUE);
}

void MainWindow::setupMenu()
{
   menuBar()->setSeparator( QMenuBar::InWindowsStyle );
   QPopupMenu* popup = new QPopupMenu( this );
   display = new QPopupMenu(this);
   QPopupMenu *help = new QPopupMenu(this);

   popup->insertItem( "&Quit", qApp, SLOT(quit()) );

   display->insertSeparator();
   display->insertSeparator();
   debugopt = display->insertItem("Debug Window", this, SLOT(toggleDebug()));
   display->setCheckable(TRUE);

   QSettings setting;
   showdebug = setting.readBoolEntry("/geeyoueye/vision/DebugWindow/state");
   display->setItemChecked(debugopt, showdebug);

   help->insertItem("Supported Picture Formats", this, SLOT(picformats()));
   help->insertSeparator();
   help->insertItem("&About", this, SLOT(about()));
   help->insertItem("About &Qt", this, SLOT(aboutqt()));
   
   menuBar()->insertItem( "&File", popup );
   menuBar()->insertItem("&Display", display);
   menuBar()->insertSeparator();
   menuBar()->insertItem("&Help", help);
}

void MainWindow::setupStat()
{
   stat1 = new QLabel(statusBar());
   stat1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   stat1->setFixedHeight( stat1->sizeHint().height() );
   stat1->setAlignment( AlignVCenter | AlignLeft );

   statusBar()->addWidget(stat1, 1, TRUE);

   stat1->setText("Vision awaiting connection.");
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

void MainWindow::setStat1(QString s)
{
   stat1->setText(s);
}

void MainWindow::about()
{
   QMessageBox::about(this, PACKAGE " " VERSION, PACKAGE " Version " VERSION 
                      "\n" "Remote Vision system\n");
}

void MainWindow::aboutqt()
{
   QMessageBox::aboutQt(this, PACKAGE);
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
