#include<stdio.h>
int main(int argc, char **argv)
{
   int x = 0;
   fprintf(stdout, "x, y, yprime, yint, ysum\n");
   int h = 2;
   int ysum = 0;
   while(x <= 200)
   {
     int  y = 1 + x * x;
     int yprime = ((1 + x * x) - (1 + (x - h) * (x - h)))/h;
     int yint = (((1 + x * x ) + (1 + (x - h) * (x - h))) / 2) * h;
     ysum += yint;
     fprintf(stdout, "%d, %d, %d, %d, %d\n", x, y, yprime, yint, ysum);
     x += h;
   }
   return 0;
}

