#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "deadlock_table.h"

// TODO: deadlocks are working incorrectly, if Sokoban is inside deadlock (starting position??) - solve it somehow
// TODO: check deadlocks in xsokoban01

static void inicialize_static_deadlocks();
static void add_static_deadlocks();
static void forbidden_pattern(int w, int h, char* pattern);
static void forbidden_pattern_with_symmetries(int w, int h, char* pattern);

static void echo_dead_positions();
static void echo_dead_position(struct position* pos);

void calculate_static_deadlocks()
{
	inicialize_static_deadlocks();
	add_static_deadlocks();
#ifdef WRITE_TO_STDOUT
	echo_dead_positions();
#endif
}

int test_static_deadlocks(struct position* pos, int fn) // test deadlocks on updated field fn
{
	for (int i = 0; i < static_deadlocks_count[fn]; i++)
	{
		if (is_subposition(pos, &static_deadlocks[fn][i]))
		{
#ifdef WRITE_TO_STDOUT
			printf("STATIC DEADLOCK: fn = %d, index = %d, position ignored\n\n", fn, i);
#endif										
			return 1;
		}
	}
	return 0;
}

static void inicialize_static_deadlocks()
{
	for (int i = 0; i < MAXFIELDS; i++)
		static_deadlocks_count[i] = 0;
}

// pattern language:
// ? - matches anything
// # - matches a wall
// $ - a forbidden box position
// x - not a goal

static void add_static_deadlocks()
{
	if (info.num_boxes >= 2)
	{
		forbidden_pattern_with_symmetries(2,2,"#$#$"); // two boxes aside the wall
		forbidden_pattern_with_symmetries(3,3,"?###x$#$?"); // two boxes in a corner
		forbidden_pattern_with_symmetries(2,3,"?#$$#?"); // two unmoveable boxes
	}

	if (info.num_boxes >= 3)
	{
		forbidden_pattern_with_symmetries(2,2,"#$$$"); // three boxes and a wall
		forbidden_pattern_with_symmetries(3,4,"####x$#x$#$?"); // three boxes around the corner
		forbidden_pattern_with_symmetries(3,3,"?$#$$?#??"); // S shaped deadlock
	}
	
	if (info.num_boxes >= 4)
	{
		forbidden_pattern(2,2,"$$$$"); // four boxes
		forbidden_pattern_with_symmetries(3,4,"??#?$$$$?#??"); // S shaped deadlock
		forbidden_pattern_with_symmetries(3,3,"?$$#x$#$?"); // D shape
	}
}

static struct position new_deadlock;

static void mirrorV(int w, int h, char* pattern, char* result);
static void mirrorH(int w, int h, char* pattern, char* result);
static void transpose(int w, int h, char* pattern, char* result);

static void forbidden_pattern_with_symmetries(int w, int h, char* pattern)
{
	char new_pattern[64];
	char new_pattern2[64];
	char new_pattern3[64];

	forbidden_pattern(w, h, pattern); // id
	mirrorV(w, h, pattern, new_pattern); // mirror V
	forbidden_pattern(w, h, new_pattern);
	mirrorH(w, h, pattern, new_pattern2); // mirror H
	forbidden_pattern(w, h, new_pattern2);
	mirrorH(w, h, new_pattern, new_pattern2); // rotate 180
	forbidden_pattern(w, h, new_pattern2);

	
	// the same for transposed
	transpose(w, h, pattern, new_pattern3);
	forbidden_pattern(h, w, new_pattern3); // id
	mirrorV(h, w, new_pattern3, new_pattern); // mirror V
	forbidden_pattern(h, w, new_pattern);
	mirrorH(h, w, new_pattern3, new_pattern2); // mirror H
	forbidden_pattern(h, w, new_pattern2);
	mirrorH(h, w, new_pattern, new_pattern2); // rotate 180
	forbidden_pattern(h, w, new_pattern2);
}

static void mirrorV(int w, int h, char* pattern, char* result)
{
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			result[x+y*w] = pattern[w-x-1+y*w];
	result[w*h] = '\0';
}

static void mirrorH(int w, int h, char* pattern, char* result)
{
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			result[x+y*w] = pattern[x+(h-y-1)*w];	
	result[w*h] = '\0';
}

static void transpose(int w, int h, char* pattern, char* result)
{
	for (int y = 0; y < w; y++)
		for (int x = 0; x < h; x++)
			result[x+y*h] = pattern[y+x*w];	
	result[w*h] = '\0';
}

static void forbidden_pattern(int w, int h, char* pattern)
{
	for (int y = 0; y <= lvl.height - h; y++)
	{
		for (int x = 0; x <= lvl.width - w; x++)
		{
			int ok = 1; int not_goals = 0;
			for (int y2 = 0; y2 < h; y2++)
			{
				for (int x2 = 0; x2 < w; x2++)
				{
					char pat = pattern[x2+y2*w];
			
					switch (pat)
					{
				   	case '?': break;
					case '#': if (!is_wall(lvl.f[y+y2][x+x2]))
								ok = 0;
							  break;
					case 'x': if (has_goal_on(lvl.f[y+y2][x+x2]))
								ok = 2;
							  break;
					case '$': if (!is_box_placeable(lvl.f[y+y2][x+x2]))
								ok = 3;
	    					  else if (!has_goal_on(lvl.f[y+y2][x+x2]))
								not_goals++;
							  break;
					}
				}
			}

			if (ok == 1 && not_goals > 0)
			{
				clean_position(&new_deadlock);
				for (int y2 = 0; y2 < h; y2++)
				{
					for (int x2 = 0; x2 < w; x2++)
					{
						if (pattern[x2+y2*w] == '$')
							add_box_of_position(&new_deadlock, info.fn[y+y2][x+x2]);
					}
				}
				
				// add this position to all deadlock tables
				int ok = 1;
				for (int y2 = 0; y2 < h; y2++)
				{
					for (int x2 = 0; x2 < w; x2++)
					{
						if (pattern[x2+y2*w] == '$')
						{
							int fn = info.fn[y+y2][x+x2];
							for (int i = 0; i < static_deadlocks_count[fn]; i++)
								if (is_subposition(&new_deadlock, &static_deadlocks[fn][i]))
									ok = 0;
						}
					}
				}
				
				if (!ok)
					continue;
				for (int y2 = 0; y2 < h; y2++)
				{
					for (int x2 = 0; x2 < w; x2++)
					{
						if (pattern[x2+y2*w] == '$')
						{
							int fn = info.fn[y+y2][x+x2];
							memcpy(&static_deadlocks[fn][static_deadlocks_count[fn]++], &new_deadlock, sizeof(struct position));
						}
					}
				}
			}
		}
	}
}

static void echo_dead_positions()
{
	struct position original;
	get_position(&original);
	printf("Field numbers:\n");
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_wall(lvl.f[y][x]))
				printf(" # ");
			else if (lvl.f[y][x] == 'x')
				printf(" x ");
			else
				printf(" %02d", info.fn[y][x]);
		}
		printf("\n");
	}
	printf("\nSTATIC DEADLOCKS:\n\n");

	for (int i = 0; i < info.num_fields; i++)
	{
		if (static_deadlocks_count[i] > 0)
			printf("Forbidden positions for field %d:\n", i);
		for (int j = 0; j < static_deadlocks_count[i]; j++)
		{
			set_position(&static_deadlocks[i][j]);
			print_level(&lvl);
		}
	}
	printf("\n------------------\n");
	set_position(&original);
}

static void echo_dead_position(struct position* pos)
{
	struct position original;
	get_position(&original);
	set_position(pos);
	print_level(&lvl);
	set_position(&original);
}
