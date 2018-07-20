/*
 * data.h -- Definition of DataWidget
 *
 * $Id: data.h,v 1.8 2002/06/06 12:23:50 casey Exp $
 *
 */

#ifndef __DATA_H
#define __DATA_H

 #include <qwidget.h>
 #include <qlabel.h>
 #include <qmutex.h>

 class DataWidget : public QWidget
 {
   Q_OBJECT

 public:
   DataWidget(QWidget *parent=0, const char *name=0);
   ~DataWidget();
 public slots:
   void setHeading(float hdg);
   void setRoll(float deg);
   void setPitch(float deg);
   void setX(float coord);
   void setY(float coord);
   void setZ(float coord);
   void setTach(float rpm);
   void setSpeed(float v);
   void setVz(float z);
 private:
   QLabel *roll;
   QLabel *pitch;
   QLabel *yaw;
   QLabel *alt;
   QLabel *gpsx;
   QLabel *gpsy;
   QLabel *gpsz;
   QLabel *tach;
   QLabel *vz;
   QLabel *vxy;
   QString s;
   QMutex active;
 };


#endif // __DATA_H
