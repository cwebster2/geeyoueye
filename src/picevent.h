/*
 * picevent.h - Custom picture event. 
 *
 * $Id: picevent.h,v 1.1 2002/06/04 09:48:58 casey Exp $
 *
 */

#ifndef __PICEEVNT_H
#define __PICEVENT_H

 class PictureEvent : public QCustomEvent
 {
 public:
   PictureEvent(char * data) :
     QCustomEvent(909192), d(data) {};
   char* GetData() { return d; }
 private:
   char* d;
 };

 class PictureDoneEvent : public QCustomEvent
 {
 public:
   PictureDoneEvent() :
     QCustomEvent(909193) {};
 };

#endif // __PICEVENT_H
