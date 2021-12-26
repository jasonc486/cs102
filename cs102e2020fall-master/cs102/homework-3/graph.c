#include<stdio.h>
int main(int argc, char **argv)
{
   fprintf(stdout, "Jason Chen\n");
   fprintf(stdout, "cs-102-e\n");
   fprintf(stdout, "Prof. Cusack\n");
   // a = number of letters in first name; max 10
   int a = 5;
   // b = number of letters in last name; max 10
   int b = 4;
   // c = any number 1-10
   int c = 8;
   // d = 1/2 c and >= 3; acts as h
   int d = c / 2;
   fprintf(stdout, "x, y, yprime, ysum\n");
   int ysum = 0;
   // range: -100 to +100
   int x = -100;
   while(x <= 100)
   {
     int  y = a * ( x * x * x) - b * (x * x) + c * x;
     // yLess is y(x-d)
     int  yLess = (a * ((x-d) * (x-d) * (x-d)) -
                   b * ((x-d) * (x-d)) + c * (x-d));
     int yprime = (y - yLess) / d;
     int yint = ((y + yLess) / 2) * d;
     ysum += yint;
     fprintf(stdout, "%d, %d, %d, %d\n", x, y, yprime, ysum);
     x += d;
   }
   return 0;
}

