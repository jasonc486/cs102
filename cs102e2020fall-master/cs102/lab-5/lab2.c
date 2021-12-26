#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*
* Sean Cusack
* CS102 Fall 2020
* Lab2
* 09-29-2020
*/
int main( int argc, char **argv )
{
    srand48(getpid());
    int x[10];
    for(int i = 0; i < 10; i++)
    {
        int random = mrand48() % 50 + 50;
        x[i] = random;
    }
    for(int i = 0; i < 10; i++)
    {
    fprintf(stdout, "%d\n", x[i]);
    }
return 0;
}
