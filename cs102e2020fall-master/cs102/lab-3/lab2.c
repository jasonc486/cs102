#include<stdio.h>
int main(int argc, char **argv)
{
   int x = 0;
   fprintf(stdout, "x, y, yprime\n");
   int h = 2;
   while(x <= 200)
   {
     int  y = 1 + x * x;
     int yprime = ((1 + x * x) - (1 + (x - h) * (x - h)))/h;
     fprintf(stdout, "%d, %d, %d\n", x, y, yprime);
     x += h;
   }
   return 0;
}

