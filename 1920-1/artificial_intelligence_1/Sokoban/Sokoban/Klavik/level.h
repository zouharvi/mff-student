#ifndef SOKOBAN_CORE_LEVEL
#define SOKOBAN_CORE_LEVEL

#define LVLSIZE 64

struct level // Sokoban level
{
	char f[LVLSIZE][LVLSIZE]; // fields of the level
	int sx, sy; // the position of Sokoban
	int width, height; // the size of the level	
	struct level* next_level; // pointer to next level in list, or NULL
};

struct level* load_xsb_levels(char* filename); // load levels from a xsb file
void clean_level(struct level* lvl);
void print_level(struct level* lvl);

// field testings
int is_wall(char ch);
int is_dead(char ch); // equals 'x'?
int is_walkable(char ch); // sokoban can walk on it?
int is_pushable(char ch); // box can be pushed on it immediately?
int is_box_placeable(char ch); // box can be pushed on it ever?
int has_box_on(char ch);
int has_goal_on(char ch);
int has_unplaced_box_on(char ch);
int has_empty_goal_on(char ch);

// field modifications
char put_box(char ch);
char remove_box(char ch);
char set_wall();
char set_dead_field();

// field conversions for input/output
int is_field(char ch); // is a input character a field?
char put_sok(char ch);

// conversions between linear and two-dimensional position
int genpos(int x, int y);
int xpos(int pos);
int ypos(int pos);

// neighbours of the field (for the breath-first search)
extern const int movesx[8];
extern const int movesy[8];


#endif
