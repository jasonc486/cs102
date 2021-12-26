#include <stdio.h>
#include "maze.h"
#include "file.h"
char filename[1024];

int main(int argc, char** argv ) 
{
    char filename[1024] = "hw.txt";
    if(argc == 2)
    {
        load(argv[1]);
    }
    else
    {
        fprintf(stdout, "invalid argument count\n");
        //load(filename);
    }
    //build_wall(3);
    //set_location_x(2);
    print_maze();
    char scratchpad[1024];
    //fprintf(stdout, "%s", argv[1]);
    fprintf( stdout, "this will read a line that you type, until you hit ENTER or CTRL-C or CTRL-C:\n" );
    //load(filename);
    print_maze();
    char writeFilename[1024];
    char loadFilename[1024];
    int locatorx;
    int locatory;
    save(writeFilename);
    while(fgets(scratchpad, 1024, stdin ) != NULL )
    {
        int wallTempx, wallTempy;
        int emptyTempx, emptyTempy;
        int treasuryx, treasuryy;
        fprintf(stdout, "read line: %s", scratchpad );
        fprintf(stdout, "\n");
        //Load and Save
        int SaveNumFound = sscanf(scratchpad, "save %s", writeFilename);
        int locationNumFoundx = sscanf(scratchpad, "x %d", &locatorx);
        int locationNumFoundy = sscanf(scratchpad, "y %d", &locatory);
        int LoadNumFound = sscanf(scratchpad, "load %s", loadFilename);
        int numTreasure = sscanf(scratchpad, "treasure %d %d", &treasuryx, &treasuryy);
        int numWall = sscanf(scratchpad, "wall %d %d", &wallTempx, &wallTempy);
        int numEmpt = sscanf(scratchpad, "empty %d %d", &emptyTempx, &emptyTempy);
        if(SaveNumFound == 1)
        {
            fprintf(stdout, "writefilename: %s\n", writeFilename );
            save(writeFilename);
        }
        if(numTreasure == 2)
        {
            build_treasure(treasuryx, treasuryy);
        }
        if(numWall == 2)
        {
            build_wall(wallTempx, wallTempy);
        }
        if(numEmpt == 2)
        {
            clear_wall(emptyTempy, emptyTempx);
        }
        if(locationNumFoundx == 1)
        {
            set_location_y(locatorx);
        }
        if(locationNumFoundy == 1)
        {
            set_location_x(locatory);
        }
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
        else if(scratchpad[0] == 'u')
        {
            move_up();
        }
        else if(scratchpad[0] == 'd')
        {
            move_down();
        }
        print_maze();
        if(onTreasure() == 2)
        {
            fprintf(stdout, "YOU WIN!\n");
            break;
        }
    }
    return 0;
}

