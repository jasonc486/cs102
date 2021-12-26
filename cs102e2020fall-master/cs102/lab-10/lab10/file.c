#include <stdio.h>
#include "file.h"
#include "maze.h"

char scratch[1024];

void load(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    if( file != NULL)
    {
        while (fgets(scratch, 1024, file) != NULL)
        {
            int wallTemp = -1;
            int emptyTemp = -1;
            int numFoundWall = sscanf(scratch, "WALL %d", &wallTemp);
            int numFoundEmpty = sscanf(scratch, "EMPTY %d", &emptyTemp);
            //fprintf(stdout, "%d", wallTemp);
            if (wallTemp != -1)
            {
                build_wall(wallTemp);
            }

            if (emptyTemp != -1)
            {
                clear_wall(emptyTemp);
            }
        }
        fclose(file);
    }
}

void save(char* wfilename)
{
    FILE* writeme = fopen(wfilename,"w");
    for(int i = 0; i < 10; i++)
    {
        if( (writeme != NULL) && (is_wall(i) == 1)) 
        {
            fprintf(writeme, "WALL %d\n", i);
        }
    }
    fclose(writeme);
}
