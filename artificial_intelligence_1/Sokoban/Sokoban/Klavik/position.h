#ifndef SOKOBAN_SOLVER_POSITION
#define SOKOBAN_SOLVER_POSITION

// position is described by vectors of field numbers
// 0 - nothing, 1 - box on current field

#define POSITION_SIZE 4

struct position
{
	unsigned int b[POSITION_SIZE]; // vector for boxes
	int s; // x,y position
};

void set_position(struct position* pos); // on global level
void get_position(struct position* pos);

// compare functions
int compare_positions(struct position* pos1, struct position* pos2); // are positions equal?
int compare_positions_without_sokoban(struct position* pos1, struct position* pos2); // are positions equals except Sokoban?
int is_subposition(struct position* pos, struct position* sub); // tests whether it contains boxes at given places

void push_box(struct position* start, struct position* result, int from, int to, int xsok, int ysok);
void clean_position(struct position* pos);
void add_box_of_position(struct position* pos, int fn);
void remove_box_of_position(struct position* pos, int fn);
void swap_box_of_position(struct position* pos, int fn);

#endif // SOKOBAN_SOLVER_POSITION
