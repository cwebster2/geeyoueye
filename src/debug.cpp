/*
 * $Id: debug.cpp,v 1.3 2002/02/11 14:40:56 casey Exp $
 */

#include <qlayout.h>
#include <qvgroupbox.h>
#include <qhbox.h>
#include <qhgroupbox.h>
#include <qlabel.h>
#include <qvalidator.h>
#include <qfiledialog.h>
#include <qmessagebox.h>

#include "debug.h"

DebugWindow::DebugWindow(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
   setCaption("Debug Window");
   maxlines=0;

   QGridLayout *top = new QGridLayout(this,0,0);

   QGroupBox *debuggroup = new QVGroupBox("Debug Output", this);

   debugview = new QMultiLineEdit(debuggroup);
   debugview->setReadOnly(TRUE);


   QHBox *hbox = new QHBox(debuggroup);
   hbox->setSpacing(10);
   clear = new QPushButton("Clear",hbox);
   QLabel *templabel = new QLabel(hbox);
   templabel->setText("Max Lines");
   lemaxlines = new QLineEdit(hbox);
   lemaxlines->setValidator(new QIntValidator(this));
   lemaxlines->setText("0");

   top->addWidget(debuggroup,0,0);

   QGroupBox *filegroup = new QHGroupBox("File Logging Options", this);
   QHBox *fhbox = new QHBox(filegroup);
   fhbox->setSpacing(10);
   QLabel *t2 = new QLabel("Log to File?", fhbox);
   cblogtofile = new QCheckBox(fhbox);
   cblogtofile->setChecked(FALSE);
   logtofile = FALSE;
   QLabel *t3 = new QLabel("Filename", fhbox);
   lefilename = new QLineEdit(fhbox);
   browsebutton = new QPushButton("Browse", fhbox);
   top->addWidget(filegroup,1,0);
   
   connect(clear, SIGNAL(clicked()), SLOT(clearPressed()));
   connect(browsebutton, SIGNAL(clicked()), SLOT(browsePressed()));
   connect(cblogtofile, SIGNAL(toggled(bool)), SLOT(togglefile(bool)));
   connect(lemaxlines, SIGNAL(textChanged(const QString&)), this, SLOT(maxlinesChanged(const QString&)));

   //qInstallMsgHandler(qtDebugHook);
}

DebugWindow::~DebugWindow()
{
  if (logtofile)
    togglefile(FALSE);
}

void DebugWindow::guiDebug(const char* msg)
{
   int lines;
   debugview->insertLine(msg);
   if (logtofile)
   {
     (*f) << msg << "\n";
     file->flush();
   }
   lines = debugview->numLines();
   if (maxlines > 0)
      while ((lines--)>maxlines)
         debugview->removeLine(0);
      
   debugview->setCursorPosition(lines,0);
}

void DebugWindow::guiDebug(QString &msg)
{
   int lines;
   debugview->insertLine(msg);
   if (logtofile)
   {
     (*f) << msg << "\n";
     file->flush();
   }
   lines = debugview->numLines();
   if (maxlines > 0)
      while ((lines--)>maxlines)
         debugview->removeLine(0);
      
   debugview->setCursorPosition(lines,0);
}

void DebugWindow::clearPressed()
{
   debugview->clear();
}

void DebugWindow::maxlinesChanged(const QString &n)
{
   maxlines = n.toInt();
   //maxlines = lemaxlines->text().toInt();
}

void DebugWindow::browsePressed()
{
  QString s = QFileDialog::getSaveFileName("/home", QString::null, this, "Log to File" "Choose a file to log to" );
  lefilename->setText(s);  
}

void DebugWindow::togglefile(bool write)
{
  logtofile = write;
  if (logtofile)
  {
    // open file for write
    lefilename->setEnabled(FALSE);
    browsebutton->setEnabled(FALSE);
    file = new QFile(lefilename->text());
    if (! file->open(IO_WriteOnly))
    {
       QMessageBox::warning(this, "Error opening file", "Could not open file:" + lefilename->text() + " for writing");
       delete file;
       lefilename->setEnabled(TRUE);
       browsebutton->setEnabled(TRUE);

       // if we dont block signals, the setChecked call emits the signal we 
       // are connected to, and all hell ensues.  particularly 
       // casey@caseybox:~/code/geeyoueye/src$ ./geeyoueye 
       // pure virtual method called
       // Aborted
       // casey@caseybox:~/code/geeyoueye/src$
       
       cblogtofile->blockSignals(TRUE);
       cblogtofile->setChecked(FALSE);
       logtofile = FALSE;
       cblogtofile->blockSignals(FALSE);
       return;
    }
    f = new QTextStream(file);
    qDebug("TextStream opened");
  }
  else
  {
    // close file
    if (f)
       delete f;
    if (file)
    {
       file->close();
       delete file;
    }
    lefilename->setEnabled(TRUE);
    browsebutton->setEnabled(TRUE);
    qDebug("TextStream closed");
  }
}

