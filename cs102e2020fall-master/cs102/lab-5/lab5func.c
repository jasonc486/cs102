#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "lab5func.h"
void fill(int array[5][5])
{
for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int random = mrand48() % 50 + 50;
            array[i][j] = random;
        }
    }
}
void print(int array[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            fprintf(stdout, "%5d", array[i][j]);
        }
    fprintf(stdout, "\n");
    }
}
