/*
 * televent.h - Custom Telemetry events. 
 *
 * $Id: televent.h,v 1.1 2002/06/05 12:49:42 casey Exp $
 *
 */

#ifndef __TELEVENT_H
#define __TELEVENT_H

 class TelDataEvent : public QCustomEvent
 {
 public:
   TelDataEvent(char * data) :
     QCustomEvent(909194), d(data) {};
   char* GetData() { return d; }
 private:
   char* d;
 };

#endif // __PICEVENT_H
