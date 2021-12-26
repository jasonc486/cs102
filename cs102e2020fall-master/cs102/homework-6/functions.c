#include <stdio.h>
#include "functions.h"
/*
* Jason Chen
* CS102 Fall 2020
* Homework 6
* 10-06-2020
*/
void reverseString( char* string )
{
    int len = stringLength(string) - 1;
    for(int i = 0; i <= len / 2; i++)
    {
        char temp = string[i];
        string[i] = string[len-i];
        string[len-i] = temp;
    }
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
