#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "functions.h"
/*
* Jason Chen
* CS102 Fall 2020
* Homework 5
* 09-30-2020
*/
void fill8x12(int array[8][12])
{
for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            int random = mrand48() % 50 + 50;
            array[i][j] = random;
        }
    }
}

void fill12x8(int array[12][8])
{
for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            int random = mrand48() % 50 + 50;
            array[i][j] = random;
        }
    }
}

void print8x12(int array[8][12])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            fprintf(stdout, "%5d", array[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}

void print12x8(int array[12][8])
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            fprintf(stdout, "%5d", array[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}

void print12x12(int array[12][12])
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            fprintf(stdout, "%6d", array[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}

void cross(int array1[8][12], int array2[12][8], int array3[12][12])
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            int temp = 0;
            for(int k = 0; k < 8; k++)
            {
                temp += array1[k][j] * array2[i][k];    
                
            }
            array3[i][j] = temp;
        }
    }
}
