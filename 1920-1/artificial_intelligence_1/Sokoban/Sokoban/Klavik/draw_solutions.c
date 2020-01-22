#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "level.h"
#include "solution.h"
#include "global.h"

int main(char argc, char* argv[])
{
	srand(time(0));

	if (argc < 3)
	{
		printf("usage: solver level_file solution_file\n");
		return 1;
	}

	struct level* levels = load_xsb_levels(argv[1]);
	struct level* last = levels;

	FILE* solutions; 
	if (!(solutions = fopen(argv[2], "rt")))
		return 0;

	int count = 1;
	while (last != NULL)
	{
		printf("Level %d:\n", count);
		print_level(last);

		fgets(lvl_sol.move, MAXSOLUTION, solutions);
		lvl_sol.length = strlen(lvl_sol.move)-1;
		if (lvl_sol.move[0] == 'N')
		{
			printf("NO SOLUTION!\n");
			return 0;
		}
		else
			check_solution(&lvl_sol, last, 1);

		last = last->next_level;
		count++;
	}
	return 0;
}
