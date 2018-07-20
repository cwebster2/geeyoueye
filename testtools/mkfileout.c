#include <stdio.h>

int main(int argc, char **argv)
{
   int fts, tme, i, icur;
   float ftt, cur;
   FILE *out;

   out = fopen("file.out", "a");
   //fts = atoi(argv[1]);
   tme = atoi(argv[1]) * 20; // time in ticks
   //icur= atoi(argv[3]); // start height

   //ftt = (float)fts/(float)20;  //ft per tick
   //cur = (float)icur;
   //printf("%d ft for %d ticks, %f ft steps\n", fts, tme, ftt);
   for (i=0; i<tme; i++) 
   {
      //printf("Loop: time %d, step %f\n", i, cur);
      fprintf(out, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n" ,i,i,i,i,i,i,i,i,i,i);
      //cur += ftt;
   }
   fclose(out);
   return 0;
}
