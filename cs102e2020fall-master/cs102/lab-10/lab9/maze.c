#include <stdio.h>
#include "maze.h"

static room_t maze[10];
static int location_x;
char scratch[1024];

void clear_maze()
{
    for(int i = 0; i < 10; i++ ) 
    {
        maze[i].wall=0;
    }
}
int is_wall(int x)
{
    return maze[x].wall;
}
void build_wall(int x)
{
    maze[x].wall = 1;
}
void clear_wall(int x)
{
    maze[x].wall = 0;
}
//Location
void set_location_x(int x)
{
    location_x = x;
}
int get_location_x()
{
    return location_x;
}
//Print
void print_maze()
{
    for(int i = 0; i < 10; i++ ) 
    {
        if((is_wall(i) == 0) && (i != location_x))
        {
            fprintf( stdout, ". ");
        }
        else if(i == location_x)
        {
            fprintf(stdout, "x ");
        }
        else
        {
            fprintf(stdout, "##");
        }
    }
    fprintf(stdout, "\n");
}

void move_right()
{
    int locate = get_location_x();
    if((locate != 9) &&
        is_wall(locate + 1) != 1)
    {
        set_location_x(locate + 1);
    }
}
void move_left()
{
    int locate = get_location_x();
    if((locate != 0) &&
        is_wall(locate - 1) != 1)
    {
        set_location_x(locate - 1);
    }
}

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
            fprintf(stdout, "%d", wallTemp);
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
