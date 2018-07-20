/*
 * $Id: net.h,v 1.12 2002/02/06 12:07:12 casey Exp $
 */

#ifndef __NET_H
#define __NET_H

 #include "config.h"

 #ifdef HAVE_STDLIB_H
  #include <stdint.h>
 #endif // HAVE_STDLIB_H
 #ifdef HAVE_SYS_TYPES_H
  #include <sys/types.h>
 #endif // HAVE_SYS_TYPES_H

 #define GUIPORT 9095
 #define GUIPICPORT 9098
 #define CONTROLPORT 9096

 #define AIRPIC 90
 #define GNDPIC 91

 #define NETDATA 	1
 #define REGISTER 	0x10
 #define DEREGISTER 	0x12
 #define TELON 		0x14
 #define TELOFF		0x15
 #define VELON		0x16
 #define VELOFF 	0x17
 #define GPS_COMMAND 	0x18
 #define RPHS_COMMAND 	0x19
 #define SERVO_COMMAND  0x1a
 #define MICRO_COMMAND 	0x1b
 #define SONAR_COMMAND  0x1c
 #define TACHO_COMMAND 	0x1d

 #define TWEAK_PKT	0x1F
 #define NEW_TWEAK_PKT	0x20
 #define TWK_DLY	0x21
 #define TWK_STATE_DEF	0x22
 #define TWK_INDEX	0x23
 #define TWK_INDEX_DLY	0x24
 #define TWK_FLUSH_DEF	0x25

 struct packet_hdr
 {
   uint8_t opcode;
   uint32_t len;
 };

 struct net_data
 {
   uint8_t opcode;
   uint32_t len;
	
   float yaw;
   float pitch;
   float roll;

   float x;
   float y;
   float z;

   float vx;
   float vy;
   float vz;

   float tach;
 };

 struct tcp_register
 {
   uint8_t opcode;
   uint32_t len;
   uint32_t ip;
 };

 struct tcp_data_on
 {
   uint8_t opcode;
   uint32_t len;
 };

 struct tcp_data_off
 {
   uint8_t opcode;
   uint32_t len;
 };

 struct tcp_toggle
 {
   uint8_t opcode;
   uint32_t len;
 };

 struct tcp_deregister
 {
   uint8_t opcode;
   uint32_t len;
   uint32_t ip;
 };

 struct pic_header
 {
   char opcode;
   uint32_t len;
 };
				 
struct rc_g2
{
   uint8_t opcode;
   uint32_t len;
   float leftV;
   float leftH;
   float rightV;
   float rightH;
   int b1;
   int b2;
   int b3;
};

struct net_telemetry_data
{
   uint8_t opcode;
   uint32_t len;
   float heading;
   float pitch;
   float roll;
   long long rphs_ts;
   float x;
   float y;
   float z;
   long long gps_ts;
   float tach;
   long long tach_ts;
   float sonar;
   long long sonar_ts;
};

struct raw_rphs_data
{
   uint8_t opcode;
   uint32_t len;
   float heading;
   float pitch;
   float roll;
   long long rphs_ts;
};

struct raw_gps_data
{
   uint8_t opcode;
   uint32_t len;
   float x;
   float y;
   float z;
   long long gps_ts;
};

struct raw_tach_data
{
   uint8_t opcode;
   uint32_t len;
   float tach;
   long long tach_ts;
};

struct raw_sonar_data
{
   uint8_t opcode;
   uint32_t len;
   float blah;
   long long sonar_ts;
};

struct tweak_pkt
{
  float sliderval;
  char slider;
};

struct pidval
{
  float C;
  float P;
  float I;
  float D;
  float S;
  pidval operator=(const pidval &data)
  { this->C = data.C;
    this->P = data.P;
    this->I = data.I;
    this->D = data.D;
    this->S = data.S;
    return *this;
  }
};

struct new_tweak_pkt
{
  pidval val[6];
};

struct tweak_delay_pkt
{
  float delay;
  new_tweak_pkt tweak_pkt;
};

struct tweak_state_pkt
{
  int statenumber;
  new_tweak_pkt statedata;
};

struct tweak_index_pkt
{
  int newstate;
};

struct tweak_delay_index_pkt
{
  int newstate;
  float delay;
};


#endif //__NET_H
