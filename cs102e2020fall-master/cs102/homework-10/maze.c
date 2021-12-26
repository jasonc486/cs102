#include <stdio.h>
#include "maze.h"
#include "file.h"

static room_t maze[10][10];
static int location_x;
static int location_y;

int is_treasure(int x, int y)
{
    return maze[y][x].wall;
}

void build_treasure(int x, int y)
{
    maze[x][y].wall = 2;
}

void clear_maze()
{
    set_location_x(0);
    for(int i = 0; i < 10; i++ ) 
    {
        for(int j = 0; j < 10; j++)
        {
            maze[i][j].wall=0;
        }
    }
}

int is_wall(int x, int y)
{
    return maze[y][x].wall;
}

void build_wall(int x, int y)
{
    maze[x][y].wall = 1;
}

void clear_wall(int x, int y)
{
    maze[y][x].wall = 0;
}

//Location
void set_location_x(int x)
{
    location_x = x;
}

void set_location_y(int y)
{
    location_y = y;
}

int get_location_x()
{
    return location_x;
}

int get_location_y()
{
    return location_y;
}

int onTreasure()
{
    return(is_treasure(get_location_x(), get_location_y()));
}
//Print
void print_maze()
{
    for(int i = 0; i < 10; i++ ) 
    {
        for(int j = 0; j < 10; j++)
        {
            if((is_wall(i, j) == 0) && ((i != location_x) || (j != location_y)))
            {
                fprintf( stdout, ". ");
            }
            else if((i == get_location_x()) && (j == get_location_y()))
            {
                fprintf(stdout, "x ");
            }
            else if((is_wall(i,j) == 1))
            {
                fprintf(stdout, "##");
            }
            else if(((is_treasure(i, j) == 2)))
            {
                fprintf(stdout, "T ");
            }
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}

void move_down()
{
    int locatex = get_location_x();
    int locatey = get_location_y();
    if((locatex != 9) &&
        is_wall(locatex + 1, locatey) != 1)
    {
        set_location_x(locatex + 1);
    }
}

void move_up()
{
    int locatex = get_location_x();
    int locatey = get_location_y();
    if((locatex != 0) &&
        is_wall(locatex - 1, locatey) != 1)
    {
        set_location_x(locatex - 1);
    }
}

void move_right()
{
    int locatex = get_location_x();
    int locatey = get_location_y();
    if((locatey != 9) &&
        is_wall(locatex, locatey + 1) != 1)
    {
        set_location_y(locatey + 1);
    }
}

void move_left()
{
    int locatex = get_location_x();
    int locatey = get_location_y();
    if((locatey != 0) &&
        is_wall(locatex, locatey - 1) != 1)
    {
        set_location_y(locatey - 1);
    }
}

