#include <stdio.h>
int main( int argc, char **argv )
{
    for(int i = 0; i < 10; i++)
    {
	    fprintf(stdout, "Burn Disc \nEject Disc \n");
    }
    fprintf(stdout, "Eat An Onion \n");
    for(int j = 0; j < 10; j++)
    {
	    fprintf(stdout, "Burn Disc \nEject Disc \n");
    }
	return 0;
}

