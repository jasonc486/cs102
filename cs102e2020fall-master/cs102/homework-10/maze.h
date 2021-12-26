void clear_maze();

int is_wall(int x, int y);
void build_wall(int x, int y);
void clear_wall(int x, int y);

int is_treasure(int x, int y);
void build_treasure(int x, int y);

void set_location_x(int x);
int get_location_x();

void set_location_y(int y);
int get_location_y();

void print_maze();

void move_right();
void move_left();
void move_up();
void move_down();

int onTreasure();

typedef struct 
{ 
    int wall; 
} room_t;

