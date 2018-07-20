#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rphs_data 
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


int main(int argc, char **argv)
{
   int sock, ret;
   struct rphs_data rphs;
   struct sockaddr_in sin;
   char temp[50];
   FILE *infile;
   infile = fopen("file.out", "r");
   sock = socket(AF_INET, SOCK_DGRAM, 0x11);
   sin.sin_family = AF_INET;
   sin.sin_addr.s_addr = inet_addr("127.0.0.1");
   sin.sin_port = htons(9095);

   do 
   {
      ret = fscanf(infile,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f*c", &rphs.yaw, &rphs.pitch, 
                   &rphs.roll, &rphs.x, &rphs.y, &rphs.z, &rphs.vx, &rphs.vy, &rphs.vz, &rphs.tach);
      rphs.opcode=1;
      rphs.len = sizeof(rphs);
      sendto(sock, &rphs, sizeof(rphs), 0, (struct sockaddr*)&sin, sizeof(sin));
      usleep(50000);
   }
   while (ret > 0);
   perror("fscanf");
   close(sock);
   fclose(infile); 

   return 0;   
}
