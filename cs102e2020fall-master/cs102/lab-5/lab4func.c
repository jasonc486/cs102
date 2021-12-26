#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "lab4func.h"
void fill(int array[10])
{
for(int i = 0; i < 10; i++)
    {
        int random = mrand48() % 50 + 50;
        array[i] = random;
    }
}
void print(int array[10])
{
    for(int i = 0; i < 10; i++)
    {
    fprintf(stdout, "%d\n", array[i]);
    }
}
