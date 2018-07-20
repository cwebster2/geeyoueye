/*
 * pic.h -- Definition of PicWidget
 *
 * $Id: pic.h,v 1.11 2002/06/04 09:48:58 casey Exp $
 *
 */

#ifndef __PIC_H
#define __PIC_H

 #include <qwidget.h>
 #include <qimage.h>
 #include <qlabel.h>
 #include <qpainter.h>

 class PicWidget : public QWidget
 {
   Q_OBJECT

 public:
   PicWidget(QWidget *parent=0, const char *name=0);
 public slots:
   void newPic(QImage*);
   void newPic(char *data, int len);
 signals:
   void stat2(QString);
 private:
   QImage *pic;
 protected:
   virtual void paintEvent(QPaintEvent *);
 };

 class PicWindow : public QWidget
 {
   Q_OBJECT
 public:
   PicWindow(QWidget *parent=0, const char *name=0);
 public slots:
   void newPic(QImage* q) { pic->newPic(q); }
   void newPic(char *data, int len) { pic->newPic(data,len); }
 private:
   PicWidget *pic;
 };

#endif // __PIC_H
