#include <stdio.h>
/*
* Jason Chen
* CS102 Fall 2020
* Lab 2b
* 10-06-2020
*/
int main( int argc, char** argv )
{
    for (int i = 1; i < argc; i++)
    {
        fprintf(stdout, "%s ", argv[i]);
    }
    fprintf(stdout, "\n");
    return 0;
}
