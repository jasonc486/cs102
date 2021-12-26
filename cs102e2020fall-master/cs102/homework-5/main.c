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

int main( int argc, char **argv )
{
    srand48(getpid());
    int arr1[8][12];
    int arr2[12][8];
    int arr3[12][12];
    fill8x12(arr1);
    fill12x8(arr2);
    cross(arr1, arr2, arr3);
    print8x12(arr1);
    print12x8(arr2);
    print12x12(arr3);
    return 0;
}


