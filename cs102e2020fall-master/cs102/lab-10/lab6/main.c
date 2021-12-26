#include <stdio.h>
#include "maze.h"

int main( int argc, char** argv ) 
{
    clear_maze();
    build_wall(3);
    set_location_x(2);
    print_maze();
    
    move_left();
    print_maze();

    move_right();
    print_maze();

    move_right();
    print_maze();

    fprintf(stdout, "\n");
    return 0;
}

