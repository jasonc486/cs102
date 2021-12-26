#include <stdio.h>
/*
* Jason Chen
* CS102 Fall 2020
* Lab 3
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
        for (int i = 1; i < argc; i++)
        {
            fprintf(stdout, "%s ", argv[i]);
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
