#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>

struct packet_hdr
{
  uint8_t opcode;
  uint32_t len;
};

struct tcp_register
{
  uint8_t opcode;
  uint32_t len;
  uint32_t ip;
};

struct tcp_deregister
{
  uint8_t opcode;
  uint32_t len;
  uint32_t ip;
};

#define SLIDER(x) (x & 0x03)
#define GROUP(x)  ((x>>2) & 0x07)

struct tweak_pkt
{
  uint8_t opcode;
  uint32_t len;
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
};

struct bare_tweak_pkt
{
  struct pidval val[6];
};

struct new_tweak_pkt
{
  uint8_t opcode;
  uint32_t len;
  struct pidval val[6];
};

struct tweak_delay_pkt
{
  uint8_t opcode;
  uint32_t len;
  float delay;
  struct bare_tweak_pkt tweak_pkt;
};

struct tweak_state_pkt
{
  uint8_t opcode;
  uint32_t len;
  int statenumber;
  struct bare_tweak_pkt statedata;
};

struct tweak_index_pkt
{
  uint8_t opcode;
  uint32_t len;
  int newstate;
};

struct tweak_delay_index_pkt
{
  uint8_t opcode;
  uint32_t len;
  int newstate;
  float delay;
};


void childserv(int s)
{
  struct packet_hdr pkt;
  struct packet_hdr def;
  struct tcp_register tcpr;
  struct tcp_deregister tcpdr;
  struct tweak_pkt tweak;
  struct new_tweak_pkt new_tweak;
  struct tweak_delay_pkt dly_pkt;
  struct tweak_state_pkt state_pkt;
  struct tweak_index_pkt index_pkt;
  struct tweak_delay_index_pkt index_dly_pkt;

  int ret, i;

  printf("START CHILDSERV\n");
  for (;;)
  {
    recv(s, (void*)&pkt, sizeof(pkt), MSG_PEEK);
    switch(pkt.opcode)
    {
      case 0x10: 
        ret = recv(s, (void*)&tcpr, sizeof(tcpr), 0);
        printf("TCP REGISTER PACKET\n");
        printf("PACKET OPCODE:      %d\n", tcpr.opcode);
        printf("PACKET LENGTH:      %d\n", tcpr.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("REGISTERED IP     : %X\n", tcpr.ip);
        break;
      case 0x12: 
        ret = recv(s, (void*)&tcpdr, sizeof(tcpdr), 0);
        printf("TCP DEREGISTER PACKET\n");
        printf("PACKET OPCODE:      %d\n", tcpdr.opcode);
        printf("PACKET LENGTH:      %d\n", tcpdr.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
	printf("CHILDSERV EXITING\n");
	exit(0);
        break;
      case 0x1F: 
        ret = recv(s, (void*)&tweak, sizeof(tweak), 0);
        printf("TWEAK PACKET\n");
        printf("PACKET OPCODE:      %d\n", tweak.opcode);
        printf("PACKET LENGTH:      %d\n", tweak.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("RAW SLIDER:         %d\n", tweak.slider);
        printf("SLIDER VALUE:       %f\n", tweak.sliderval);
        printf("SLIDER GROUP:       %d\n", GROUP(tweak.slider));
        printf("SLIDER NUMBER:      %d\n", SLIDER(tweak.slider));
        break;
      case 0x20:
        ret = recv(s, (void*)&new_tweak, sizeof(new_tweak), 0);
        printf("NEW TWEAK PACKET\n");
        printf("PACKET OPCODE:      %d\n", new_tweak.opcode);
        printf("PACKET LENGTH:      %d\n", new_tweak.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
	for (i=0; i<6; i++)
	{
	  printf("INDEX %d ",i);
	  printf("C:  %f ", new_tweak.val[i].C);
	  printf("P:  %f ", new_tweak.val[i].P);
	  printf("I:  %f ", new_tweak.val[i].I);
	  printf("D:  %f ", new_tweak.val[i].D);
	  printf("S:  %f\n", new_tweak.val[i].S);
	}
	break;
      case 0x21:
        ret = recv(s, (void*)&dly_pkt, sizeof(dly_pkt), 0);
        printf("TWEAK DELAY PACKET\n");
        printf("PACKET OPCODE:      %d\n", dly_pkt.opcode);
        printf("PACKET LENGTH:      %d\n", dly_pkt.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("DELAY IN SECONDS  : %f\n", dly_pkt.delay);
	for (i=0; i<6; i++)
	{
	  printf("INDEX %d ",i);
	  printf("C:  %f ", dly_pkt.tweak_pkt.val[i].C);
	  printf("P:  %f ", dly_pkt.tweak_pkt.val[i].P);
	  printf("I:  %f ", dly_pkt.tweak_pkt.val[i].I);
	  printf("D:  %f ", dly_pkt.tweak_pkt.val[i].D);
	  printf("S:  %f\n", dly_pkt.tweak_pkt.val[i].S);
	}
	break;
      case 0x22:
        ret = recv(s, (void*)&state_pkt, sizeof(state_pkt), 0);
        printf("STATE DEFINITION PACKET\n");
        printf("PACKET OPCODE:      %d\n", state_pkt.opcode);
        printf("PACKET LENGTH:      %d\n", state_pkt.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("STATE INDEX NUMBER: %d\n", state_pkt.statenumber);
	for (i=0; i<6; i++)
	{
	  printf("INDEX %d ",i);
	  printf("C:  %f ", state_pkt.statedata.val[i].C);
	  printf("P:  %f ", state_pkt.statedata.val[i].P);
	  printf("I:  %f ", state_pkt.statedata.val[i].I);
	  printf("D:  %f ", state_pkt.statedata.val[i].D);
	  printf("S:  %f\n", state_pkt.statedata.val[i].S);
	}
	break;
      case 0x23:
        ret = recv(s, (void*)&index_pkt, sizeof(index_pkt), 0);
        printf("CHANGE TO INDEX PACKET\n");
        printf("PACKET OPCODE:      %d\n", index_pkt.opcode);
        printf("PACKET LENGTH:      %d\n", index_pkt.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("STATE INDEX NUMBER: %d\n", index_pkt.newstate);
	break;
      case 0x24:
        ret = recv(s, (void*)&index_dly_pkt, sizeof(index_dly_pkt), 0);
        printf("CHANGE TO INDEX WTH DELAYPACKET\n");
        printf("PACKET OPCODE:      %d\n", index_dly_pkt.opcode);
        printf("PACKET LENGTH:      %d\n", index_dly_pkt.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
        printf("STATE INDEX NUMBER: %d\n", index_dly_pkt.newstate);
        printf("DELAY IN SECONDS:   %f\n", index_dly_pkt.delay);
	break;
      case 0x25:
        ret = recv(s, (void*)&def, sizeof(def), 0);
        printf("FLUSH STATE SET\n");
        printf("PACKET OPCODE:      %d\n", def.opcode);
        printf("PACKET LENGTH:      %d\n", def.len);
        printf("ACTUAL READ LENGTH: %d\n", ret);
	break;
      default: 
	printf("default hit, other packet received\n");
	printf("UNKNOWN OPCODE:     %d\n", pkt.opcode);
	printf("CHILDSERV EXITING\n");
	exit(0);
    }
  }
}

int main()
{
   int s,cs;
   struct sockaddr_in sin;
   fd_set rd;
   int ret;

   s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   printf("SOCKET CREATED\n");
   
   sin.sin_addr.s_addr = INADDR_ANY;
   sin.sin_port = htons(9096);
   sin.sin_family = AF_INET;

   bind(s, (struct sockaddr*) &sin, sizeof(sin));
   printf("SOCKET BOUND\n");
   listen(s, 5);
   printf("SOCKET LISTENING\n");

   for (;;)
   {
     for (;;)
     {
       FD_ZERO(&rd);
       FD_SET(s, &rd);
       printf("BEFORE SELECT\n");
       ret = select(s+1, &rd, NULL, NULL, NULL);
       if (ret == EINTR)
         continue;
       printf("AFTER SELECT\n");
       if ((FD_ISSET(s, &rd)) && (ret > 0))
       {
	  printf("GOT CONNECT\n");
          cs = accept(s, 0, 0);
          if (cs < 0)
	    exit(1);
 	  break;
       }
     }
     if (fork() == 0) /* child */
     {
        close(s);
	childserv(cs);
	exit(0);
     }
     else
       if (cs)
         close(cs);
  }
}

