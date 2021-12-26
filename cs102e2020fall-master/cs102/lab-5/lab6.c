#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "lab6func.h"
/*
* Sean Cusack
* CS102 Fall 2020
* Lab6
* 09-29-2020
*/

int main( int argc, char **argv )
{
    srand48(getpid());
    int x[5][5];
    int y[5][5];
    int z[5][5];
    fill(x);
    fill(y);
    add(x, y, z);
    print(x);
    print(y);
    print(z);
    return 0;
}


