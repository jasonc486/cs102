#include <stdio.h>
/*
* Jason Chen
* CS102 Fall 2020
* Lab 5b
* 10-06-2020
*/
int stringLength(char* string);
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
            fprintf(stdout, "%s %d ", argv[i], stringLength(argv[i]));
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
int stringLength(char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}
