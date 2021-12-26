#include <stdio.h>
#include "functions.h"
#include <stdbool.h>
/*
* Jason Chen
* CS102 Fall 2020
* Homework 9
* 10-28-2020
*/
char scratch[1024];
int print_file(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    int lineCount = 0;
    int byteCount = 0;
    int words = 0;
    if( file != NULL)
    {
        while (fgets(scratch, 1024, file) != NULL)
        {
            byteCount += stringLength(scratch);
            lineCount++;
            words += wordCount(scratch);
            //fprintf( stdout, "%s", scratch);
        }
        fclose(file);
    fprintf(stdout, "The file: %s contains %d lines, %d words, and %d bytes.",filename, lineCount, words, byteCount);
    }
    else
    {
        fprintf( stdout, "Error! Cannot read %s!", filename);
    }
}

int wordCount(char* string)
{
    int counter = 0;
    //int i = 0;
    bool prevWasSpace = false;
    for(int i = 0; i + 1 < stringLength(string); i++)
    {
        if (string[i+1] == ' ' && !prevWasSpace)
        {
            counter++;
            prevWasSpace = true;
        }
        if(string[i+1] != ' ')
        {
            prevWasSpace = false;
        }
        if(string[i+1] == '\n')
        {
            counter++;
        }
    }
    return counter;
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
