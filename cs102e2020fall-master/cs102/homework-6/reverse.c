#include <stdio.h>
#include "functions.h"
/*
* Jason Chen
* CS102 Fall 2020
* Homework 6
* 10-06-2020
*/
int main( int argc, char** argv )
{
    if(argc == 1)
    {
    fprintf(stdout, "no arguments found! \n");
    }
    else
    {
        for (int i = argc - 1; i > 0; i--)
        {
            reverseString(argv[i]);
            fprintf(stdout, "%s %d ", argv[i], stringLength(argv[i]));
        }
        fprintf(stdout, "\n");
    }
    return 0;
}

