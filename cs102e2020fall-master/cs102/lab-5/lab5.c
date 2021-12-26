#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "lab5func.h"
/*
* Sean Cusack
* CS102 Fall 2020
* Lab3
* 09-29-2020
*/

int main( int argc, char **argv )
{
    srand48(getpid());
    int x[5][5];
    int y[5][5];
    fill(x);
    print(x);
    fill(y);
    print(y);
    return 0;
}


