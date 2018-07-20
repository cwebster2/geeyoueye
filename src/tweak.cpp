/*
 * $Id: tweak.cpp,v 1.19 2002/02/11 14:40:56 casey Exp $
 */

#include <qlayout.h>
#include <qhgroupbox.h>
#include <qvgroupbox.h>
#include <qvbox.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qvalidator.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qsettings.h>
#include <qinputdialog.h>
#include <qgrid.h>
#include <qmessagebox.h>

#include "tweak.h"

TweakWindow::TweakWindow(QWidget *parent, char *name)
	: QWidget(parent,name)
{

  setCaption("Tweak Window.  doot");

  QMenuBar *menu = new QMenuBar(this);

  QStringList profiles;
  QSettings *settings = new QSettings;
  profiles = settings->subkeyList("/geeyoueye/tweakwidget");
  delete settings;
 
  prf = new QComboBox();
  prf->insertStringList(profiles);
  connect(prf, SIGNAL(activated(const QString&)), SLOT(loadSet(const QString&)));

  QPopupMenu *loadmenu = new QPopupMenu(this);
  loadmenu->insertItem(prf);
  
  QPopupMenu *statesetmenu = new QPopupMenu(this);
  statesetmenu->insertItem("New StateSet", this, SLOT(newSet()));
  statesetmenu->insertItem("Load StateSet", loadmenu);

  modemenu = new QPopupMenu(this);
  smodeopt = modemenu->insertItem("State Mode (Clientside data)", this, SLOT(changeMode()));
  ssmodeopt = modemenu->insertItem("StateSet Mode (Serverside data)", this, SLOT(changeMode()));

  menu->insertItem("StateSets", statesetmenu);
  menu->insertItem("Modes", modemenu);

  QGridLayout *top = new QGridLayout(this,3,4);
  top->setMenuBar(menu);

  QVGroupBox * trans = new QVGroupBox("State Stuff",this);
  top->addMultiCellWidget(trans,0,1,0,0);
  QVBox * vboxt = new QVBox(trans);
  vboxt->setSpacing(5);
  QGrid * grida = new QGrid(2,vboxt);

  new QLabel("Current State:", grida);
  curstate = new QLabel(grida);
  new QLabel("Next State:", grida);
  nextstate = new QComboBox(grida);
  
  QHBox * hbox1 = new QHBox(vboxt);
  new QLabel("in", hbox1);
  nexttime = new QLineEdit(hbox1);
  new QLabel("seconds", hbox1);

  go = new QPushButton("Transition", vboxt);
  connect(go, SIGNAL(clicked()), SLOT(goPressed()));

  QHBox * div = new QHBox(vboxt);
  div->setFrameStyle(QFrame::HLine | QFrame::Sunken);
  div->setLineWidth(2);
  div->setMidLineWidth(1);

  new QLabel("State Being Edited",vboxt);
  ceditstate = new QLabel(vboxt);

  QGrid *buttongrid = new QGrid(2,vboxt);
  reset = new QPushButton("Reset", buttongrid);
  save = new QPushButton("Save", buttongrid);
  send = new QPushButton("Send", buttongrid);

  connect(reset, SIGNAL(clicked()), SLOT(resetButton()));
  connect(save, SIGNAL(clicked()), SLOT(saveState()));
  connect(send, SIGNAL(clicked()), SLOT(sendButton()));

  QHBox * div1 = new QHBox(vboxt);
  div1->setFrameStyle(QFrame::HLine | QFrame::Sunken);
  div1->setLineWidth(2);
  div1->setMidLineWidth(1);

  editstate = new QComboBox(vboxt);

  QGrid *buttongrid1 = new QGrid(2,vboxt);
  load = new QPushButton("Load", buttongrid1);
  newst = new QPushButton("New", buttongrid1);

  connect(load, SIGNAL(clicked()), SLOT(loadButton()));
  connect(newst, SIGNAL(clicked()), SLOT(newButton()));
  
  roll = new TweakWidget(G_R, "Roll", this);
  top->addWidget(roll,0,1);
  pitch = new TweakWidget(G_P, "Pitch", this);
  top->addWidget(pitch,0,2);
  heading = new TweakWidget(G_H, "Heading", this);
  top->addWidget(heading,0,3);
  x = new TweakWidget(G_X, "X", this);
  top->addWidget(x,1,1);
  y = new TweakWidget(G_Y, "Y", this);
  top->addWidget(y,1,2);
  z = new TweakWidget(G_Z, "Z", this);
  top->addWidget(z,1,3);

  status = new QStatusBar(this);
  status->setFixedHeight(status->height());
  top->addMultiCellWidget(status,2,2,0,3);
  status->message("TweakWindow constructed, but not initialized to do anything");

  QString lastset;
  QSettings * savedvalues;
  savedvalues = new QSettings;
  lastset = savedvalues->readEntry("/geeyoueye/tweakwidget/Current", "ERROR");
  delete savedvalues;

  mode = MODE_STATE;
  modemenu->setItemChecked(smodeopt, TRUE);
  modemenu->setItemChecked(ssmodeopt, FALSE);
  
  if (lastset == "ERROR")
  {
     bool ok;
     lastset = QString::null;
     do
     {
       ok = FALSE;
       lastset = QInputDialog::getText(tr("New StateSet"),tr("There are no StateSets defined, please create one.\nStateSet name?"), QLineEdit::Normal, QString::null, &ok, this);
     }
     while (!ok || lastset.isEmpty() || lastset.isNull());
     newStateGroup(lastset);
  }
  else 
    loadStateGroup(lastset);
}

void TweakWindow::goPressed()
{
  int timedly = nexttime->text().toInt();
  if (timedly < 1)
  {
     status->message("Minimum delay is 1 second", 2000);
     return;
  }
  time = new QTimer(this);
  nexttime->setReadOnly(TRUE);
  go->setEnabled(FALSE);
  connect(time, SIGNAL(timeout()), SLOT(countdown()));
  Next(nextstate->currentItem(), (float) timedly);
  time->start(1000);
}

void TweakWindow::countdown()
{
  int newtime = nexttime->text().toInt()-1;
  nexttime->setText(QString().setNum(newtime));
  if (newtime <= 0)
  {
    time->stop();
    delete time;
    curstate->setText(nextstate->currentText());
    nexttime->setReadOnly(FALSE);
    go->setEnabled(TRUE);
  }
}

void TweakWindow::newSet()
{
  bool ok;
  QString lastset;
  switch (QMessageBox::information( this, "StateSet", "Are you sure you wish to create a new StateSet?", "Yes", "No", 0, 0, 1))
  {
    case 0: // The user clicked the Yes again button or pressed Enter
      bool ok;
      lastset = QString::null;
      do
      {
        ok = FALSE;
        lastset = QInputDialog::getText(tr("New StateSet"),tr("Please choose a name for your StateSet.\nStateSet name?"), QLineEdit::Normal, QString::null, &ok, this);
      } while (!ok || lastset.isEmpty() || lastset.isNull());
      newStateGroup(lastset);

      break;
    case 1: // The user clicked the No or pressed Escape
      return;
      break;
  }
}

void TweakWindow::loadSet(const QString &whichone)
{
  switch (QMessageBox::information( this, "StateSet", "Are you sure you wish to load the StateSet "+whichone+"?", "Yes", "No", 0, 0, 1))
  {
    case 0: // The user clicked the Yes again button or pressed Enter
      loadStateGroup(whichone);
      break;
    case 1: // The user clicked the No or pressed Escape
      return;
      break;
  }
}

void TweakWindow::changeMode()
{
  if (mode == MODE_STATE)
  {
    // entering set mode;
    mode = MODE_SET;
    modemenu->setItemChecked(smodeopt, FALSE);
    modemenu->setItemChecked(ssmodeopt, TRUE);
    sendStateGroup(currentset);
  }
  else
  {
    // sentering state mode
    emit Packet(TWK_FLUSH_DEF);
    mode = MODE_STATE;
    modemenu->setItemChecked(smodeopt, TRUE);
    modemenu->setItemChecked(ssmodeopt, FALSE);
  }
}

void TweakWindow::newStateGroup(QString name)
{

  QSettings *pref = new QSettings();

  QStringList keys = pref->subkeyList("/geeyoueye/tweakwidget/");
  for (QStringList::Iterator it = keys.begin(); it != keys.end(); ++it)
  {
    if ((*it) == name)
    {
      QMessageBox::information( this, "Create StateSet error", "StateSet name already exists, aborting creation." );
      delete pref;
      return;
    }
  }
  pref->writeEntry("/geeyoueye/tweakwidget/Current", name);
  delete pref;
  editstate->clear();
  nextstate->clear();
  currentset=name;
  prf->insertItem(currentset);

  QString set;
  bool ok;
  set = QString::null;
  do
  {
    ok = FALSE;
    set = QInputDialog::getText(tr("New State"),tr("You must define at least one state for your StateSet.\nPlease choose a name for the initial state."), QLineEdit::Normal, QString::null, &ok, this);
  }
  while (!ok || set.isEmpty() || set.isNull());
  newState(set);

  pref = new QSettings();
  pref->writeEntry("/geeyoueye/tweakwidget/"+currentset+"/Current", set);
  delete pref;
}

void TweakWindow::newState(QString name)
{
  /* Creates new state in current stategroup
   */

  int i, states = 0;
  char *values[] = { "R", "P", "H", "X", "Y", "Z" };
  QSettings *pref = new QSettings();
  QString stname;
  QStringList keys = pref->subkeyList("/geeyoueye/tweakwidget/"+currentset);
  for (QStringList::Iterator it = keys.begin(); it != keys.end(); ++it)
  {
    states++;
    stname = pref->readEntry("/geeyoueye/tweakwidget/"+currentset+(*it)+"/Name");
    if (stname == name)
    {
      QMessageBox::information( this, "Create state error", "State name already exists, aborting creation." );
      delete pref;
      return;
    }

  }
  currenteditindex = states;
  currenteditstate = name;
  QString key = "/geeyoueye/tweakwidget/"+currentset+"/";
  key += QString().sprintf("%d",currenteditindex);
  qDebug("newState() - key = "+key);
  qDebug("newState() - currenteditindex = %d",currenteditindex);
  qDebug("newState() - currentset = "+currentset);
  qDebug("newState() - currenteditstate = "+currenteditstate);
  pref->writeEntry(key+"/Name", currenteditstate);
  for (i=0; i<6; i++)
  {
     state.val[i].C = 0;
     state.val[i].P = 0;
     state.val[i].I = 0;
     state.val[i].D = 0;
     state.val[i].S = 0;
     pref->writeEntry(key+"/"+values[i]+"/C", state.val[i].C);
     pref->writeEntry(key+"/"+values[i]+"/P", state.val[i].P);
     pref->writeEntry(key+"/"+values[i]+"/I", state.val[i].I);
     pref->writeEntry(key+"/"+values[i]+"/D", state.val[i].D);
     pref->writeEntry(key+"/"+values[i]+"/S", state.val[i].S);
  }
  delete pref;
  roll->setAll(state.val[0]);
  pitch->setAll(state.val[1]);
  heading->setAll(state.val[2]);
  x->setAll(state.val[3]);
  y->setAll(state.val[4]);
  z->setAll(state.val[5]);
  nextstate->insertItem(QString().sprintf("%d - ",currenteditindex)+currenteditstate);
  editstate->insertItem(QString().sprintf("%d - ",currenteditindex)+currenteditstate,currenteditindex);
  editstate->setCurrentItem(currenteditindex);
  ceditstate->setText(QString().sprintf("%d - ", currenteditindex) + currenteditstate);
}

void TweakWindow::loadStateGroup(QString name) 
{
  /* Loads new stategroup and makes it current.  Sets up comboboxes
   * and sets the edited state
   */

  QSettings *pref = new QSettings();
  QString state = pref->readEntry("/geeyoueye/tweakwidget/"+name+"/Current");
  if (state == QString::null)
  {
    status->message("Error loading State Set "+name);
    return;
  }
  currentset = name;
  currentstateindex = 0;
  currenteditindex = 0;
  currentstate = QString::null;
  currenteditstate = QString::null;
  editstate->clear();
  nextstate->clear();
  pref->writeEntry("/geeyoueye/tweakwidget/Current", currentset);
  QStringList keys = pref->subkeyList("/geeyoueye/tweakwidget/"+currentset); 
  QString stname;
  int stnum;
  for (QStringList::Iterator it = keys.begin(); it != keys.end(); ++it)
  {
     stnum = (*it).toInt();
     stname = pref->readEntry("/geeyoueye/tweakwidget/"+currentset+"/"+(*it)+"/Name");
     nextstate->insertItem(QString().sprintf("%d - ",stnum)+stname);
     editstate->insertItem(QString().sprintf("%d - ",stnum)+stname,stnum);
  }
  delete pref;
  loadState(state);
}

void TweakWindow::loadState(QString name) 
{
  /* Overloaded function, translates name into an index number and passes
   * that to the loadState that does the actual work
   */

  QSettings *pref = new QSettings();
  QStringList keys = pref->subkeyList("/geeyoueye/tweakwidget/"+currentset); 
  int stnum;
  QString stname;
  for (QStringList::Iterator it = keys.begin(); it != keys.end(); ++it)
  {
     stnum = (*it).toInt();
     stname = pref->readEntry("/geeyoueye/tweakwidget/"+currentset+"/"+(*it)+"/Name");
     if (stname == name)
        break;
  }
  delete pref;
  loadState(stnum);
}

void TweakWindow::loadState(int name) 
{
  /* loads a state and makes it the currently edited state
   */

  int i;
  char *values[] = { "R", "P", "H", "X", "Y", "Z" };
  QSettings *pref = new QSettings();

  currenteditindex = name;
  currenteditstate = pref->readEntry("/geeyoueye/tweakwidget/"+currentset+"/"+QString().sprintf("%d/Name",currenteditindex));

  editstate->setCurrentItem(currenteditindex);
  ceditstate->setText(QString().sprintf("%d - ", currenteditindex) + currenteditstate);

  QString key = "/geeyoueye/tweakwidget/"+currentset+"/"+QString().sprintf("%d", currenteditindex);
  qDebug("loadState() - key = "+key);
  qDebug("loadState() - currenteditindex = %d",currenteditindex);
  qDebug("loadState() - currentset = "+currentset);
  qDebug("loadState() - currenteditstate = "+currenteditstate);
  pref->writeEntry(key+"/Name", currenteditstate);
  for (i=0; i<6; i++)
  {
     qDebug("loadState readEntry loop");
     state.val[i].C = pref->readDoubleEntry(key+"/"+values[i]+"/C");
     state.val[i].P = pref->readDoubleEntry(key+"/"+values[i]+"/P");
     state.val[i].I = pref->readDoubleEntry(key+"/"+values[i]+"/I");
     state.val[i].D = pref->readDoubleEntry(key+"/"+values[i]+"/D");
     state.val[i].S = pref->readDoubleEntry(key+"/"+values[i]+"/S");
  }
  delete pref;
  roll->setAll(state.val[0]);
  pitch->setAll(state.val[1]);
  heading->setAll(state.val[2]);
  x->setAll(state.val[3]);
  y->setAll(state.val[4]);
  z->setAll(state.val[5]);
}

void TweakWindow::newButton() 
{
  QString set;
  bool ok;
  set = QString::null;
  do
  {
    ok = FALSE;
    set = QInputDialog::getText(tr("New State"),tr("Please choose a name for the new state."), QLineEdit::Normal, QString::null, &ok, this);
  }
  while (!ok || set.isEmpty() || set.isNull());
  newState(set);
}

void TweakWindow::loadButton() 
{
  loadState(editstate->currentItem());
}

void TweakWindow::resetButton() 
{
  loadState(currenteditindex);
}

void TweakWindow::sendButton() 
{
  updateStateFromSliders();
  if (mode == MODE_STATE)
    emit Packet(NEW_TWEAK_PKT, (char*)&state, sizeof(state));
  else
  {
    tweak_state_pkt packet;
    packet.statedata = state;
    packet.statenumber = currenteditindex;
    emit Packet(TWK_STATE_DEF, (char*)&packet, sizeof(packet));
  }
  curstate->setText(ceditstate->text());
}

void TweakWindow::saveState() 
{
  int i;
  char *values[] = { "R", "P", "H", "X", "Y", "Z" };
  updateStateFromSliders();
  QSettings *pref = new QSettings();
  QString key = "/geeyoueye/tweakwidget/"+currentset+"/";
  key += QString().sprintf("%d",currenteditindex);
  qDebug("saveState() - key = "+key);
  qDebug("saveState() - currenteditindex = %d",currenteditindex);
  qDebug("saveState() - currentset = "+currentset);
  qDebug("saveState() - currenteditstate = "+currenteditstate);
  pref->writeEntry(key+"/Name", currenteditstate);
  for (i=0; i<6; i++)
  {
     pref->writeEntry(key+"/"+values[i]+"/C", state.val[i].C);
     pref->writeEntry(key+"/"+values[i]+"/P", state.val[i].P);
     pref->writeEntry(key+"/"+values[i]+"/I", state.val[i].I);
     pref->writeEntry(key+"/"+values[i]+"/D", state.val[i].D);
     pref->writeEntry(key+"/"+values[i]+"/S", state.val[i].S);
  }
  delete pref;
}

void TweakWindow::saveStateGroup() {}

new_tweak_pkt TweakWindow::fillTweakPacket(QString set, int state)
{
  int i;
  new_tweak_pkt local;
  char *values[] = { "R", "P", "H", "X", "Y", "Z" };
  QSettings *pref = new QSettings();

  QString key = "/geeyoueye/tweakwidget/"+set+"/"+QString().sprintf("%d", state);
  qDebug("fillTweakPacket() - key = "+key);
  for (i=0; i<6; i++)
  {
     local.val[i].C = pref->readDoubleEntry(key+"/"+values[i]+"/C");
     local.val[i].P = pref->readDoubleEntry(key+"/"+values[i]+"/P");
     local.val[i].I = pref->readDoubleEntry(key+"/"+values[i]+"/I");
     local.val[i].D = pref->readDoubleEntry(key+"/"+values[i]+"/D");
     local.val[i].S = pref->readDoubleEntry(key+"/"+values[i]+"/S");
  }
  delete pref;
  return local;
}

/* Now() - wrapper to sendState and sendStateIndex
 * Next() - wrapper to sendNextState and sendNextStateIndex
 */
void TweakWindow::Now(int ss)
{
  if (mode == MODE_STATE)
    sendState(ss);
  else
    sendStateIndex(ss);
}

void TweakWindow::Next(int ss, float delay)
{
  if (mode == MODE_STATE)
    sendNextState(ss,delay);
  else
    sendNextStateIndex(ss,delay);
}

/* sendState - sends state immedatly
 * sendNextState - sends state with a delay
 *
 * normal operation is to sendNextState with delay, and once delay is 
 * expired, sendState to make sure it takes effect
 */
void TweakWindow::sendState(int ss) 
{
  new_tweak_pkt pkt = fillTweakPacket(currentset, ss);
  emit Packet(NEW_TWEAK_PKT, (char*)&pkt, sizeof(pkt));
}

void TweakWindow::sendNextState(int ss, float delay) 
{
  tweak_delay_pkt pkt;
  pkt.tweak_pkt = fillTweakPacket(currentset, ss);
  pkt.delay = delay;
  emit Packet(TWK_DLY, (char*)&pkt, sizeof(pkt));
}

/* these function are for set mode
 * sendStateGroup - sends each state in the set with an index value
 * sendStateGroupState - sends individual state with index value
 * sendStateIndex - sends state index (state data is serverside)
 * sendNextStateIndex - sends state index and delay
 *
 * normal operation is to send the state group up, then signal changes
 * by referencing the index number of the state.
 */
void TweakWindow::sendStateGroup(QString name) 
{
  emit Packet(TWK_FLUSH_DEF);
  QSettings *pref = new QSettings();
  QStringList keys = pref->subkeyList("/geeyoueye/tweakwidget/"+name); 
  QString stname;
  int stnum;
  for (QStringList::Iterator it = keys.begin(); it != keys.end(); ++it)
     sendStateGroupState(name,(*it).toInt());
  delete pref;
}

void TweakWindow::sendStateGroupState(QString name, int set) 
{
  tweak_state_pkt pkt;
  pkt.statedata = fillTweakPacket(name, set);
  pkt.statenumber = set;
  emit Packet(TWK_STATE_DEF, (char*)&pkt, sizeof(pkt));
}

void TweakWindow::sendStateIndex(int ss) 
{
  tweak_index_pkt pkt;
  pkt.newstate = ss;
  emit Packet(TWK_INDEX, (char*)&pkt, sizeof(pkt));
}

void TweakWindow::sendNextStateIndex(int ss,float delay) 
{
  tweak_delay_index_pkt pkt;
  pkt.newstate = ss;
  pkt.delay = delay;
  emit Packet(TWK_INDEX_DLY, (char*)&pkt, sizeof(pkt));
}

void TweakWindow::updateStateFromSliders() 
{
  state.val[0] = roll->getAll();
  state.val[1] = pitch->getAll();
  state.val[2] = heading->getAll();
  state.val[3] = x->getAll();
  state.val[4] = y->getAll();
  state.val[5] = z->getAll();
}

void TweakWindow::newDataAvailable(int) {}


TweakWidget::TweakWidget(int grp, QString displayname, QWidget *parent, char *name)
	: QWidget(parent,name)
{
  int i;
  char *values[] = { "C", "P", "I", "D", "S" };

  QBoxLayout *mainlayout = new QHBoxLayout(this);
  QGroupBox *rgroup = new QVGroupBox(displayname, this);
  mainlayout->addWidget(rgroup);
  QGrid *box = new QGrid(2,rgroup);

  for (i=0; i<5; i++)
  {
    new QLabel(values[i], box);
    edits[i] = new QLineEdit(box,values[i]);
    connect(edits[i], SIGNAL(textChanged(const QString&)), SLOT(newValue()));
  }

}

void TweakWidget::newValue()
{
  // until we can figure out how to tell which edit box signalled us, 
  // lets process them all

  //qDebug("getAll()");
  local.C = edits[0]->text().toFloat();
  local.P = edits[1]->text().toFloat();
  local.I = edits[2]->text().toFloat();
  local.D = edits[3]->text().toFloat();
  local.S = edits[4]->text().toFloat();
}

pidval TweakWidget::getAll()
{
  return local;
}

void TweakWidget::setAll(pidval data)
{
  //local = data;
  //qDebug("setAll()");
  edits[0]->setText(QString().setNum(data.C));
  edits[1]->setText(QString().setNum(data.P));
  edits[2]->setText(QString().setNum(data.I));
  edits[3]->setText(QString().setNum(data.D));
  edits[4]->setText(QString().setNum(data.S));
}

