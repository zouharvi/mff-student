#ifndef SOKOBAN_SOLVER_LEVEL_INFO
#define SOKOBAN_SOLVER_LEVEL_INFO

#include "level.h"

#define MAXFIELDS 128

struct level_info // level with other precalculated things
{
	int fn[LVLSIZE][LVLSIZE]; // field numbers
	unsigned int magic[LVLSIZE][LVLSIZE]; // codes for boxes
	int num_fields; // total number of fields
	int num_boxes; // total number of boxes/goals
	int fpos[MAXFIELDS]; // positions of fields
	int pd[MAXFIELDS][MAXFIELDS]; // push distances
	int gd[MAXFIELDS]; // goal distances for fast heuristic
	int tunnel[MAXFIELDS]; // 0 - no tunnel, 1 - vertical tunnel, 2 - horizontal tunnel; TODO: maybe further use for auto-storing??
	int tunnel_goals[MAXFIELDS][2]; 
	int tunnel_distance[MAXFIELDS][2];
};
	
void preprocess_level(); // precalculate everything for the board
unsigned int magic_for_sokoban(int x, int y); // calculate magic code for sokoban

#endif // SOKOBAN_SOLVER_LEVEL_INFO
