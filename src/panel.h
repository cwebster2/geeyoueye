/*
 * panel.h -- Definition of PanelWidget
 *
 * $Id: panel.h,v 1.19 2002/06/06 12:23:50 casey Exp $
 *
 */

#ifndef __PANEL_H
#define __PANEL_H

 #include <qwidget.h>
 #include <qpainter.h>
 #include <qpixmap.h>
 #include <qtimer.h>
 
 #define CG_IAS 0x0001
 #define CG_AF  0x0002
 #define CG_ALT 0x0004
 #define CG_VOR 0x0008
 #define CG_HDG 0x0010
 #define CG_VSI 0x0020
 #define CG_RPM 0x0040
 #define CG_GAS 0x0080
 #define CG_GPS 0x0100
 #define CG_BCK 0x0200
 #define CG_ALL 0x02FF

 class PanelWidget : public QWidget
 {
   Q_OBJECT

 public:
   PanelWidget(QWidget *parent=0, const char *name=0);
 public slots:
   void setHeading(float hdg);
   void setRoll(float deg);
   void setPitch(float deg);
   void setAlt(float alt);
   void setTach(float tch);
   void setASI(float v);
   void setVSI(float vs);
   void callUpdate();
 private:
   void DrawHeading(QPainter &p);
   void DrawVSI(QPainter &p);
   void DrawAlt(QPainter &p);
   void DrawAF(QPainter &p);
   void DrawASI(QPainter &p);
   void DrawRPM(QPainter &p);
   void DrawGPS(QPainter &p);

   void DrawBackground(QPainter &p);
   void DrawAltBack(QPainter &p);
   void DrawAFBack(QPainter &p);
   void DrawVSIBack(QPainter &p);
   void DrawASIBack(QPainter &p);
   void DrawRPMBack(QPainter &p);
   void DrawGPSBack(QPainter &p);
   float vz;
   int heading;
   int roll;
   int pitch;
   float alt1;
   float alt10;
   float altitude;
   float tach;
   int changemask;
   float speed;
   QPixmap bbuf;
   QTimer *updator;
 protected:
   virtual void resizeEvent(QResizeEvent*);
   virtual void paintEvent(QPaintEvent *);
   virtual QSize sizeHint();
 };

#endif // __PANEL_H

