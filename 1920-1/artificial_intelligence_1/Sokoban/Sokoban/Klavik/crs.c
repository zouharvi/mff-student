#include <stdio.h>
#include <limits.h>
#include "crs.h"
#include "global.h"

int corral_count;
int unfinished_goal[MAXFIELDS]; // a goal is empty or a box is unplaced
int is_pi_corral[MAXFIELDS];
int corral_size[MAXFIELDS]; // number of boxes on the border of the corral
int reachable_start[LVLSIZE][LVLSIZE];

static void calculate_reachable_squares(); // calculate reachable squares and boxes
static void calculate_areas();
static void run_reachable_bfs(int x, int y, int value);
static void find_corrals();
static void run_corral_bfs(int x, int y, int value);
static int pi_corrals_check();
static void prune_position_by_pi_corral(int corral_num);

void initialize_crs()
{
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			reachable_start[y][x] = 0;
		
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			if (is_wall(lvl.f[y][x]))
				reachable_start[y][x] = -1;
}

void calculate_position()
{
	calculate_reachable_squares();
#ifdef USE_PI_CORRALS
	find_corrals();
	int prune = pi_corrals_check();
	if (prune)
		prune_position_by_pi_corral(prune);
#endif
}

static void calculate_reachable_squares() // calculate reachable squares and create box list
{
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			reachable[y][x] = reachable_start[y][x];
	reachable[lvl.sy][lvl.sx] = 1;
	box_count = 0;

	int first = 0; int last = 1;
	search_queue_x[0] = lvl.sx;
	search_queue_y[0] = lvl.sy;
	while (first < last)
	{
		int x = search_queue_x[first];
		int y = search_queue_y[first++];
		
		for (int i = 0; i < 4; i++)
		{
			int x2 = x+movesx[i];
			int y2 = y+movesy[i];
			if (reachable[y2][x2] == 0)
			{
				if (!has_box_on(lvl.f[y2][x2]))
				{
					search_queue_x[last] = x2;
					search_queue_y[last++] = y2;
					reachable[y2][x2] = 1;
				}
				else
				{
					boxx[box_count] = x2;
					boxy[box_count++] = y2;
				}
			}
		}
	}
}

static void find_corrals()
{
	corral_count = 2;
	for (int b = 0; b < box_count; b++)
	{
		int x = boxx[b];
		int y = boxy[b];

		if (reachable[y][x] == 0)
			run_corral_bfs(x,y,corral_count++);
		else
			corral_size[reachable[y][x]]++;
	}
}

static void run_corral_bfs(int x, int y, int value)
{
	unfinished_goal[value] = 0;
	corral_size[value] = 1;

	int first = 0; int last = 1;
	search_queue_x[0] = x;
	search_queue_y[0] = y;
	reachable[y][x] = value;
	while (first < last)
	{
		x = search_queue_x[first];
		y = search_queue_y[first++];
		
		for (int i = 0; i < 4; i++)
		{
			int x2 = x+movesx[i];
			int y2 = y+movesy[i];
			if (reachable[y2][x2] == 0)
			{
				reachable[y2][x2] = value;
				search_queue_x[last] = x2;
				search_queue_y[last++] = y2;

				if (has_unplaced_box_on(lvl.f[y2][x2]) || has_empty_goal_on(lvl.f[y2][x2]))
					unfinished_goal[value] = 1;
			}
		}
	}
}

static int pi_corrals_check()
{
	for (int i = 2; i < corral_count; i++)
		is_pi_corral[i] = 1;
	for (int b = 0; b < box_count; b++)
	{
		int x = boxx[b];
		int y = boxy[b];

		for (int i = 0; i < 2; i++)
		{
			int xa = x+movesx[i]; int ya = y+movesy[i];
			int xb = x+movesx[i+2]; int yb = y+movesy[i+2];

			if (reachable[ya][xa] == 1 && reachable[yb][xb] == 1)
				is_pi_corral[reachable[y][x]] = 0;
		}
	}

	int min = 0;
	corral_size[0] = INT_MAX;
	for (int i = 2; i < corral_count; i++)
		if (is_pi_corral[i] && unfinished_goal[i] && corral_size[i] < corral_size[min])
			min = i;
	return min;
}

static void prune_position_by_pi_corral(int corral_num)
{
#ifdef WRITE_TO_STDOUT
	printf("Prunning by PI-corral %d...\n", corral_num);
#endif
	int last = 0;
	for (int i = 0; i < box_count; i++)
	{
		int x = boxx[i];
		int y = boxy[i];
		if (reachable[y][x] == corral_num)
		{
			boxx[last] = boxx[i];
			boxy[last++] = boxy[i];
		}			
	}
	box_count = corral_size[corral_num];
}

static void calculate_areas()
{
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			reachable[y][x] = 0;

	run_reachable_bfs(lvl.sx, lvl.sy, 1);
	int value = 2;
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			if (reachable[y][x] == 0 && is_walkable(lvl.f[y][x]))
				run_reachable_bfs(x,y,value++);
}

static void run_reachable_bfs(int x, int y, int value)
{
	int first = 0; int last = 1;
	search_queue_x[0] = x;
	search_queue_y[0] = y;
	while (first < last)
	{
		x = search_queue_x[first];
		y = search_queue_y[first++];
		
		for (int i = 0; i < 4; i++)
		{
			int x2 = x+movesx[i];
			int y2 = y+movesy[i];
			if (reachable[y2][x2] == 0 && is_walkable(lvl.f[y2][x2]))
			{
				reachable[y2][x2] = value;
				search_queue_x[last] = x2;
				search_queue_y[last++] = y2;
			}
		}
	}
}

