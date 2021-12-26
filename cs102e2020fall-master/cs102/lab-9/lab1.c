#include <stdio.h>
int main( int argc, char **argv )
{
    char scratchpad[1024];
    fprintf(stdout, "%d \n", argc);
     if(argc == 1)
    {
    fprintf(stdout, "no arguments found! \n");
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            fprintf(stdout, "%s ", argv[i]);
        }
        fprintf(stdout, "\n");
    }
    return 0;
    //fprintf( stdout, "this will read a line that you type, until you hit ENTER or CTRL-C or CTRL-C:\n" );
    /*if( fgets( scratchpad, 1024, stdin ) != NULL )
    {
        fprintf( stdout, "read line: %s", scratchpad );
    }
    */
    return 0;
}
