#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "level.h"
#include "level_info.h"
#include "position.h"
#include "global.h"
#include "allocator.h"
#include "solving_routine.h"
#include "deadlock_table.h"

void print_binary(unsigned int x);

int main(char argc, char* argv[])
{
	srand(time(0));
	inicialize_allocator();

	if (argc < 2)
	{
		printf("usage: solver level_file [output_file]\n");
		return 1;
	}

	struct level* levels = load_xsb_levels(argv[1]);
	struct level* last = levels;
	int count = 1;
	
	FILE* solutions = NULL; 
	if (argc > 2)
	{
		if (!(solutions = fopen(argv[2], "wt")))
		{
			printf("cannot open file %s!\n", argv[2]);
			return 0;
		}
	}
	
	while (last != NULL)
	{
		printf("Level %d:\n", count);
		memcpy(&lvl, last, sizeof(struct level));
		solvable = 1;
		lvl_sol.length = 0;
		preprocess_level();
		calculate_static_deadlocks();
		print_level(&lvl);

		if (!solvable)
			printf("NO SOLUTION!\n");
		else
		{
			try_solve_level();
			if (solvable)
				if (!check_solution(&lvl_sol, last,0))
					solvable = 0;

			if (solutions != NULL)
			{
				if (solvable)
					write_solution_to_file(&lvl_sol, solutions);
				else
					fprintf(solutions, "NO SOLUTION!\n");
			}
		}


		last = last->next_level;
		count++;
	}
	return 0;
}

void print_binary(unsigned int x)
{
	unsigned int div = 1 << 31;
	for (int i = 0; i < 32; i++)
	{
		printf("%d", x / div);
		x %= div;
		div /= 2;
	}
}
