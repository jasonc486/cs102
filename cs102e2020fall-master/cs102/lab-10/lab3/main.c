#include <stdio.h>
void clear_maze();
int is_wall(int x);
void build_wall(int x);
void clear_wall(int x);
typedef struct 
{ 
    int wall; 
} room_t;

static room_t maze[10];

int main( int argc, char** argv ) 
{
    int location_x;
    location_x = 2;
    clear_maze();
    build_wall(3);
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
            fprintf( stdout, "##");
        }
    }
    fprintf(stdout, "\n");
    return 0;
}
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
