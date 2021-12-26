#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*
* Sean Cusack
* CS102 Fall 2020
* Lab3
* 09-29-2020
*/
void fill(int array[10]);
void print(int array[10]);
int main( int argc, char **argv )
{
    srand48(getpid());
    int x[10];
    fill(x);
    print(x);
    return 0;
}
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

