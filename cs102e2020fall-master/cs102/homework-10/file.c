#include <stdio.h>
#include "file.h"
#include "maze.h"

char scratch[1024];

void load(char* filename)
{
    clear_maze();
    FILE* file;
    file = fopen(filename, "r");
    if( file != NULL)
    {
        while (fgets(scratch, 1024, file) != NULL)
        {
            int wallTempx = -1;
            int wallTempy = -1;
            int emptyTempx = -1;
            int emptyTempy = -1;
            int Tresx;
            int Tresy;
            int numFoundWall = sscanf(scratch, "WALL %d %d", &wallTempx, &wallTempy);
            int numFoundEmpty = sscanf(scratch, "EMPTY %d %d", &emptyTempx, &emptyTempy);
            int numFoundTreasure = sscanf(scratch, "TREASURE %d %d", &Tresx, &Tresy);
            int locatorx;
            int locatory;
            int locationNumFoundx = sscanf(scratch, "X %d", &locatorx);
            int locationNumFoundy = sscanf(scratch, "Y %d", &locatory);
            //fprintf(stdout, "%d", wallTemp);
            if (numFoundWall == 2)
            {
                build_wall(wallTempx, wallTempy);
            }
            if (locationNumFoundx == 1)
            {
                set_location_y(locatorx);
            }
            if (locationNumFoundy == 1)
            {
                set_location_x(locatory);
            }
            if (numFoundEmpty == 2)
            {
                clear_wall(emptyTempx, emptyTempy);
            }
            if (numFoundTreasure == 2)
            {
                build_treasure(Tresx, Tresy);
            }
        }
        fclose(file);
    }
}

void save(char* wfilename)
{
    FILE* writeme = fopen(wfilename,"w");
    if(writeme != NULL)
    {
        fprintf(writeme, "X %d\n", get_location_y());
        fprintf(writeme, "Y %d\n", get_location_x());
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if( (writeme != NULL) && (is_treasure(i, j) == 2)) 
            {
                fprintf(writeme, "TREASURE %d %d\n", j, i);
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if( (writeme != NULL) && (is_wall(i, j) == 1)) 
            {
                fprintf(writeme, "WALL %d %d\n", j, i);
            }
        }
    }
    fclose(writeme);
}
