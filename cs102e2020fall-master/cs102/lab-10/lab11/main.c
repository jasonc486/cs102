#include <stdio.h>
#include "maze.h"
#include "file.h"
char filename[1024];

int main( int argc, char** argv ) 
{
    char filename[1024] = "test.maze";
    clear_maze();
    build_wall(3);
    set_location_x(2);
    print_maze();
    char scratchpad[1024];
    fprintf( stdout, "this will read a line that you type, until you hit ENTER or CTRL-C or CTRL-C:\n" );
    clear_maze();
    load(filename);
    print_maze();
    char writeFilename[1024];
    char loadFilename[1024];
    save(writeFilename);
    while(fgets(scratchpad, 1024, stdin ) != NULL )
    {
        int wallTemp = -1;
        int emptyTemp = -1;
        fprintf(stdout, "read line: %s", scratchpad );
        fprintf(stdout, "\n");
        //Load and Save
        int SaveNumFound = sscanf(scratchpad, "save %s", writeFilename);
        if(SaveNumFound == 1)
        {
            fprintf(stdout, "writefilename: %s\n", writeFilename );
            save(writeFilename);
        }
        int LoadNumFound = sscanf(scratchpad, "load %s", loadFilename);
        if(LoadNumFound == 1)
        {
            fprintf(stdout, "%s \n", loadFilename);
            load(loadFilename);
        }

        if(scratchpad[0] == 'l' && scratchpad[1] != 'o')
        {
            move_left();
        }
        else if(scratchpad[0] == 'r')
        {
            move_right();
        }
        print_maze();
    }
    return 0;
}

