#ifndef SOKOBAN_SOLVER_MOVE
#define SOKOBAN_SOLVER_MOVE

#include "position.h"

#define HIBYTES (1<<16)

struct move
{
	unsigned int heuristic; // minimal distance from the goal + distance from start shifted 16
	struct move* parent;
	struct position pos; // for now, every move remember position of all boxes
	int magic;
};

int compare_moves(struct move* mov1, struct move* mov2);

#endif // SOKOBAN SOLVER_MOVE
