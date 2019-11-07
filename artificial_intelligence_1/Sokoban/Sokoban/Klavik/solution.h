#ifndef SOKOBAN_SOLVER_SOLUTION
#define SOKOBAN_SOLVER_SOLUTION

#include <stdio.h>
#include "move.h"
#include "level.h"

#define MAXSOLUTION 10000

struct solution
{
	int length;
	char move[MAXSOLUTION]; // uldr for moves and ULDR for pushes
};

void create_solution(struct solution* sol, struct move* last_move); // creates solution
void write_solution(struct solution* sol);
void write_solution_to_file(struct solution* sol, FILE* file);
int check_solution(struct solution* sol, struct level* level, int animate);

#endif // SOKOBAN_SOLVER_SOLUTION
