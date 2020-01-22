#include "move.h"

int compare_moves(struct move* mov1, struct move* mov2)
{
	return mov1->magic == mov2->magic && compare_positions(&mov1->pos, &mov2->pos);
}

