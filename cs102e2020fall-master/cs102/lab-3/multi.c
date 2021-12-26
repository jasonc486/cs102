#include<stdio.h>
int main(int argc, char **argv)
{
   int i = 1;
   int multiple = 0;
   int more = 0;
   fprintf(stdout, "multiple,more\n");
   while(i <= 10)
   {
     multiple = i * 13;
     more = multiple + 5;
     fprintf(stdout, "%d, %d\n", multiple, more);
     i = i + 1;
   }
   return 0;
}

