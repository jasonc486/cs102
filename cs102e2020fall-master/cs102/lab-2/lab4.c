#include <stdio.h>
int main( int argc, char **argv )
{
    for(int i = 0; i < 10; i++)
    {
	    fprintf(stdout, "Hello \n");
    }
    for(int j = 0; j < 10; j++)
    {
	    fprintf(stdout, "Goodbye \n");
    }
	return 0;
}

