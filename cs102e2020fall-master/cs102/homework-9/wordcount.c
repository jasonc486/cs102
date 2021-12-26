#include <stdio.h>
#include "functions.h"
#include <stdbool.h>
/*
* Jason Chen
* CS102 Fall 2020
* Homework 9
* 10-28-2020
*/
char filename[1024];
int main(int argc, char** argv)
{
    int i, string;
    char filename[1024] = "argv[i]";
    if(argc == 1)
    {
        fprintf(stdout, "no arguments found!");
        
    }
    else
    {
        for(i=1; i < argc; i++)
        {
            print_file(argv[i]);
        }
    }
    fprintf(stdout, "\n");
    return 0;
}


