#include<stdio.h>
int main(int argc, char **argv)
{
   int x = 0;
   fprintf(stdout, "x, y\n");
   while(x <= 200)
   {
     int  y = 1 + x * x;
     fprintf(stdout, "%d, %d\n", x, y);
     x += 2;
   }
   return 0;
}

