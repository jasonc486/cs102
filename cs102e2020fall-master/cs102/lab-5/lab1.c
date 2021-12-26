#include <stdio.h>
/*
* Sean Cusack
* CS102 Fall 2020
* Lab0
* 09-29-2020
*/
int main( int argc, char **argv )
{
	int x[10];
	for(int i = 0; i < 10; i++)
	{
		x[i] = 5;
	}
	for(int i = 0; i < 10; i++)
	{
		fprintf(stdout, "%d\n", x[i]);
	}
return 0;
}
