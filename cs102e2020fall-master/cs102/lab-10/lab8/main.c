#include <stdio.h>
#include "maze.h"

int main( int argc, char** argv ) 
{
    clear_maze();
    build_wall(3);
    set_location_x(2);
    print_maze();
    char scratchpad[1024];
    fprintf( stdout, "this will read a line that you type, until you hit ENTER or CTRL-C or CTRL-C:\n" );



    while(fgets(scratchpad, 1024, stdin ) != NULL )
    {
        int wallTemp = -1;
        int emptyTemp = -1;
        fprintf(stdout, "read line: %s", scratchpad );
        fprintf(stdout, "\n");
        int numFoundWall = sscanf(scratchpad, "wall %d", &wallTemp);
        int numFoundEmpty = sscanf(scratchpad, "empty %d", &emptyTemp);

        if (wallTemp != -1)
        {
            build_wall(wallTemp);
        }

        if (emptyTemp != -1)
        {
            clear_wall(emptyTemp);
        }

        if(scratchpad[0] == 'l')
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

