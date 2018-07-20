/*
 * ap.h -- Definition of APWidget
 *
 * $Id: ap.h,v 1.7 2002/07/21 01:28:12 casey Exp $
 *
 */

#ifndef __AP_H
#define __AP_H

 #include <qwidget.h>
 #include <qlineedit.h>
 #include <qlabel.h>
 #include <qpixmap.h>
 #include <qstring.h>
 #include <qtimer.h>
 #include <qdialog.h>

 struct DMS
 {
   int D;
   int M;
   float S;
 };

 class WPTWidget : public QWidget
 {
 Q_OBJECT

 public:
   WPTWidget(QWidget *parent=0, const char *name="Waypoint");
   void setPos(DMS newlat, DMS newlon, float newalt);
   void setLat(DMS newlat);
   void setLon(DMS newlon);
   void setAlt(float newalt);
 private:
   QString s;
   QLabel *lat;
   QLabel *lon;
   QLabel *alt;
 };

 class MapPointDialog : public QDialog
 {
 Q_OBJECT
 public:
   MapPointDialog(QWidget *parent = 0, char* name = 0);
 public slots:
   virtual void accept();
   virtual void reject();
 signals:
   void newCoord(DMS,DMS);
 };

 class MapPoint 
 {
 public:
  MapPoint() {}
  void setLat(DMS dms) { lat = dms; calcMap(); }
  void setLon(DMS dms) { lon = dms; calcMap(); }
  void setCoord(DMS dmslat, DMS dmslon) { lon = dmslon; lat = dmslat; calcMap(); }
  void setLat(int D, int M, float S);
  void setLon(int D, int M, float S);
  void getDialog();
  DMS Lat() { return lat; }
  DMS Lon() { return lon; }
  int mapLat() { return maplat; }
  int mapLon() { return maplon; }
 private:
  void calcMap();
  DMS lat;
  DMS lon;
  int maplat;
  int maplon;
 };

 class MapWidget : public QWidget
 {
 Q_OBJECT

 public:
   MapWidget(QWidget *parent=0, const char *name=0);
   void updateLat(DMS y) { current.setLat(y); };
   void updateLon(DMS x) { current.setLon(x); };
 public slots:
   void callUpdate() { update(); };
 protected:
   virtual void resizeEvent(QResizeEvent*);
   virtual void paintEvent(QPaintEvent *);
 private:
   void drawCurPos(QPainter &p);
   void drawBasePos(QPainter &p);
   void drawGrid(QPainter &p);
   void drawWaypts(QPainter &p);
   QPixmap bbuf;
   QTimer *updator;
   MapPoint current;
   MapPoint wpts[10];
   MapPoint base;
   int cx, cy;
   int xlen, ylen;
   int shortside;
   int zoom;
   int minx, maxx, miny, maxy;
   int dotsize;
   int gridinterval;
   int gridwidth;
 };

 class APWidget : public QWidget
 {
   Q_OBJECT

 public:
   APWidget(QWidget *parent=0, const char *name=0);
 public slots:
   void curX(float);
   void curY(float);
   void curZ(float);
 private:
   MapWidget *map;
   WPTWidget *curpos;
   WPTWidget *curwpt;
   WPTWidget *next;
 };

#endif // __AP_H
