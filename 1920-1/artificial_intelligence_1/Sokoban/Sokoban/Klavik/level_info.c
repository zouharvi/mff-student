#include "level_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "level.h"
#include "global.h"

static int is_in_lvl(int x, int y);
static void add_outside_walls(); // we add walls outside, to the fields unreachable by Sokoban
static void remove_dead_ends(); // remove fields surrounded by three walls
static void set_field_numbers(); // set field numbers
static void count_boxes_and_goals();
static void calculate_magic_numbers(); // calculate magic numbers for fields
static void calculate_distances(); // calculate distances of all pair of squares
static void set_dead_fields_and_goal_distances(); // we set dead field for which any place is unreachable and calculate goal distances
static void find_articulations();
static int level_components();
static void calculate_tunnels();

static void copy_to_info();

static struct level_info tmp_info;
static int art[MAXFIELDS]; // 1 - for an articulation

void preprocess_level() // precalculate everything for the full_board
{
	add_outside_walls();
	remove_dead_ends();
	count_boxes_and_goals();
	calculate_magic_numbers();
	set_field_numbers(); 
	calculate_distances();
	set_dead_fields_and_goal_distances();
	copy_to_info();
#ifdef USE_TUNNELS
	find_articulations();
	calculate_tunnels();
#endif
}

unsigned int magic_for_sokoban(int x, int y)
{
	unsigned int magic = tmp_info.magic[y][x];
	return magic << 16 + magic >> 16;
}

static int is_in_lvl(int x, int y)
{
	return x >= 0 && x < lvl.width && y >= 0 && y < lvl.height;
}

static void add_outside_walls() // we add walls outside, to the fields unreachable by Sokoban
{
	memset(reachable, 0, sizeof(int)*LVLSIZE*LVLSIZE);

	reachable[lvl.sy][lvl.sx] = 1;
	int first = 0; int last = 1;
	search_queue[0] = genpos(lvl.sx,lvl.sy);
	while (first < last)
	{
		int x = xpos(search_queue[first]);
		int y = ypos(search_queue[first++]);
		
		for (int i = 0; i < 4; i++)
		{
			int x2 = x+movesx[i];
			int y2 = y+movesy[i];
			if (is_in_lvl(x2,y2) && !is_wall(lvl.f[y2][x2]) && !reachable[y2][x2])
			{
				reachable[y2][x2] = 1;
				search_queue[last++] = x2*LVLSIZE+y2;
			}
		}
	}

	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			if (!reachable[y][x])
			{
				if (has_empty_goal_on(lvl.f[y][x]) || has_unplaced_box_on(lvl.f[y][x]))
					solvable = 0;
				lvl.f[y][x] = set_wall();
			}
}

static void remove_dead_ends() // remove fields surrounded by three walls
{
	int has_dead_end;
	do
	{
		has_dead_end = 0;

		for (int y = 1; y < lvl.height-1; y++)
		{
			for (int x = 1; x < lvl.width-1; x++) 
			{
				if (has_goal_on(lvl.f[y][x]) || is_wall(lvl.f[y][x]))
					continue;

				int num_walls = 0;
				for (int i = 0; i < 4; i++)
				{
					if (is_wall(lvl.f[y+movesy[i]][x+movesx[i]]))
						num_walls++;
				}
				if (num_walls < 3)
					continue;

				if (has_box_on(lvl.f[y][x]))
					solvable = 0;
				if (lvl.sx == x && lvl.sy == y) // TODO: modify the solution
				{
					int dir = 0;
					for (; dir < 4; dir++)
						if (!is_wall(lvl.f[y+movesy[dir]][x+movesx[dir]]))
							break;
					int x2 = x+movesx[dir]; int y2 = y+movesy[dir];
					int x3 = x+2*movesx[dir]; int y3 = y+2*movesy[dir];
					lvl.sx = x2;					
					lvl.sy = y2;
					lvl_sol.move[lvl_sol.length++] = (has_box_on(lvl.f[y2][x2]) ? "LDRU" : "ldru")[dir];
					if (has_box_on(lvl.f[y2][x2]))
					{
						if (is_pushable(lvl.f[y3][x3]))
						{
							lvl.f[y2][x2] = remove_box(lvl.f[y2][x2]);
							lvl.f[y3][x3] = put_box(lvl.f[y3][x3]);
						}
						else
							solvable = 0;
					}
				}
				lvl.f[y][x] = set_wall();
				has_dead_end = 1;
			}
		}		
	}
	while (has_dead_end);
}

static void count_boxes_and_goals()
{
	int boxes = 0; int goals = 0;

	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (has_box_on(lvl.f[y][x]))
				boxes++;
			if (has_goal_on(lvl.f[y][x]))
				goals++;
		}
	}
	if (goals != boxes)
		solvable = 0;
	else
		tmp_info.num_boxes = boxes;
}

static void set_field_numbers() // set field numbers
{
	int num = 0;
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			if (!is_wall(lvl.f[y][x]))
			{
				tmp_info.fn[y][x] = num;
				tmp_info.fpos[num++] = genpos(x,y);
			}
	tmp_info.num_fields = num;
	if (num >= MAXFIELDS)
	{
		printf("TOO MANY FIELDS!\n");
		solvable = 0;
	}
}

static void calculate_magic_numbers() // calculate magic numbers for fields
{
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
			tmp_info.magic[y][x] = rand();
}

static void calculate_distances() // calculate distances of all pair of squares
{
	for (int source = 0; source < tmp_info.num_fields; source++)
	{
		int a = ypos(tmp_info.fpos[source]);
		int b = xpos(tmp_info.fpos[source]);
		int first = 0, last = 1;
		search_queue[0] = genpos(b,a);
		for (int i = 0; i < tmp_info.num_fields; i++)
			tmp_info.pd[source][i] = INT_MAX;
		tmp_info.pd[source][source] = 0;
			
		while (first < last)
		{
			int x = xpos(search_queue[first]);
			int y = ypos(search_queue[first++]);
			int dist = tmp_info.pd[source][tmp_info.fn[y][x]];
		
			for (int i = 0; i < 4; i++)
			{
				int xsok = x+movesx[i]; int ysok = y+movesy[i];
				int xto = x+movesx[i+2]; int yto = y+movesy[i+2];
				int target = tmp_info.fn[yto][xto];
				if (!is_wall(lvl.f[ysok][xsok]) && !is_wall(lvl.f[yto][xto]) && tmp_info.pd[source][target] == INT_MAX)
				{
					tmp_info.pd[source][target] = dist + 1;
					search_queue[last++] = genpos(xto,yto);
				}
			}
		}
	}
}

static void set_dead_fields_and_goal_distances() // we set dead field for which any place is unreachable and calculate goal distances
{
	for (int source = 0; source < tmp_info.num_fields; source++)
	{
		tmp_info.gd[source] = INT_MAX;
		for (int target = 0; target < tmp_info.num_fields; target++)
		{
			int x = xpos(tmp_info.fpos[target]);
			int y = ypos(tmp_info.fpos[target]);
			if (has_goal_on(lvl.f[y][x]))
			{
				if (tmp_info.pd[source][target] < tmp_info.gd[source])
					tmp_info.gd[source] = tmp_info.pd[source][target];
			}
		}

		if (tmp_info.gd[source] == INT_MAX)
			lvl.f[ypos(tmp_info.fpos[source])][xpos(tmp_info.fpos[source])] = set_dead_field();
	}
}

static void find_articulations()
{
	for (int i = 0; i < MAXFIELDS; i++)
		art[i] = 0;

	for (int i = 0; i < info.num_fields; i++)
	{
		int x = xpos(info.fpos[i]);
		int y = ypos(info.fpos[i]);

		char ch = lvl.f[y][x];
		if (has_goal_on(ch))
			continue;
		lvl.f[y][x] = '#';
		art[i] = (level_components() > 1);
		lvl.f[y][x] = ch;
	}

#ifdef WRITE_TO_STDOUT
	printf("Articulations:\n");
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (!is_box_placeable(lvl.f[y][x]) || art[info.fn[y][x]] == 0)
				putchar(lvl.f[y][x]);
			else
				putchar('A');
		}
		printf("\n");
	}
#endif
}

static int level_components()
{
	memset(reachable, 0, sizeof(int)*LVLSIZE*LVLSIZE);

	int com = 1;
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (!is_wall(lvl.f[y][x]) && reachable[y][x] == 0)
			{
				reachable[y][x] = com;
				
				int first = 0; int last = 1;
				search_queue[0] = genpos(x,y);
				while (first < last)
				{
					int x = xpos(search_queue[first]);
					int y = ypos(search_queue[first++]);
					
					for (int i = 0; i < 4; i++)
					{
						int x2 = x+movesx[i];
						int y2 = y+movesy[i];
						if (!is_wall(lvl.f[y2][x2]) && !reachable[y2][x2])
						{
							reachable[y2][x2] = com;
							search_queue[last++] = genpos(x2,y2);
						}
					}
				}
				com++;
			}
		}
	}
	return com - 1;
}

static void calculate_tunnels()
{
#ifdef WRITE_TO_STDOUT
	printf("Creating tunnels:\n");
#endif

	for (int i = 0; i < MAXFIELDS; i++)
		info.tunnel[i] = 0;

	// setup tunnel flags
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_box_placeable(lvl.f[y][x]) && !has_goal_on(lvl.f[y][x]))
			{
				for (int i = 0; i < 2; i++)
				{
					if (is_wall(lvl.f[y+movesy[i]][x+movesx[i]]) &&
						is_wall(lvl.f[y+movesy[i+2]][x+movesx[i+2]]))
						info.tunnel[info.fn[y][x]] = i+1;
				}
			}
		}
	}

	// setup horizontal tunnels
	for (int y = 0; y < lvl.height; y++)
	{
		int x1,x2,leftend,rightend,leftart,fn,distance;
		for (int x = 0; x < lvl.width; )
		{
			x1 = x;
			while (is_box_placeable(lvl.f[y][x]) && info.tunnel[info.fn[y][x]] == 2)
				x++;
			x2 = x-1;
			if (x2 < x1)
			{
				x++;
				continue;
			}
			distance = x2-x1+1;
			fn = info.fn[y][x1];
			
			// left-end
			leftart = 0;
			if (is_box_placeable(lvl.f[y][x1-1]))
			{
				if (art[info.fn[y][x1-1]] && art[fn]) // articulation end => additional push
				{
					leftend = is_box_placeable(lvl.f[y][x1-2]) ? info.fn[y][x1-2] : -1;
					leftart = 1;
					distance++;
				}
				else
					leftend = info.fn[y][x1-1];
			}
			else // dead-end
				leftend = -1;
			
			// right-end
			if (is_box_placeable(lvl.f[y][x2+1]))
			{
				if (art[info.fn[y][x2+1]] && art[fn]) // articulation end => additional push
				{
					rightend = is_box_placeable(lvl.f[y][x2+2]) ? info.fn[y][x2+2] : -1;
					distance++;
				}
				else
					rightend = info.fn[y][x2+1];
			}
			else // dead-end
				rightend = -1;

			if (distance == 1)
			{
				info.tunnel[fn] = 0;
				continue;
			}
#ifdef WRITE_TO_STDOUT
			printf("adding horizontal tunnel: %d<=(%d-%d,%d)=>%d (fn = %d)\n", leftend, x1, x2, y, rightend, fn);
#endif
			for (int xc = x1; xc <= x2; xc++)
			{
				int f = info.fn[y][xc];
				info.tunnel_goals[f][1] = leftend;
				info.tunnel_goals[f][0] = rightend;

				info.tunnel_distance[f][1] = xc-x1+leftart+1;
				info.tunnel_distance[f][0] = distance+1-info.tunnel_distance[f][1];
			}
		}
	}
	
	// setup vertical tunnels
	for (int x = 0; x < lvl.width; x++)
	{
		int y1,y2,topend,botend,topart,fn,distance;
		for (int y = 0; y < lvl.height;)
		{
			y1 = y;
			while (is_box_placeable(lvl.f[y][x]) && info.tunnel[info.fn[y][x]] == 1)
				y++;
			y2 = y-1;
			if (y2 < y1)
			{
				y++;
				continue;
			}
			distance = y2-y1+1;
			fn = info.fn[y1][x];
			
			// top-end
			topart = 0;
			if (is_box_placeable(lvl.f[y1-1][x]))
			{
				if (art[info.fn[y1-1][x]] && art[fn]) // articulation end => additional push
				{
					topend = is_box_placeable(lvl.f[y1-2][x]) ? info.fn[y1-2][x] : -1;
					topart = 1;
					distance++;
				}
				else
					topend = info.fn[y1-1][x];
			}
			else // dead-end
				topend = -1;
			
			// right-end
			if (is_box_placeable(lvl.f[y2+1][x]))
			{
				if (art[info.fn[y2+1][x]] && art[fn]) // articulation end => additional push
				{
					botend = is_box_placeable(lvl.f[y2+2][x]) ? info.fn[y2+2][x] : -1;
					distance++;
				}
				else
					botend = info.fn[y2+1][x];
			}
			else // dead-end
				botend = -1;

			if (distance == 1)
			{
				info.tunnel[fn] = 0;
				continue;
			}
#ifdef WRITE_TO_STDOUT
			printf("adding vertical tunnel: %d ^ (%d,%d-%d) v %d (fn = %d)\n", topend, x, y1, y2, botend, fn);
#endif
			for (int yc = y1; yc <= y2; yc++)
			{
				int f = info.fn[yc][x];
				info.tunnel_goals[f][0] = topend;
				info.tunnel_goals[f][1] = botend;
				
				info.tunnel_distance[f][0] = yc-y1+topart+1;
				info.tunnel_distance[f][1] = distance+1-info.tunnel_distance[f][0];
			}
		}
	}
	

#ifdef WRITE_TO_STDOUT
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (info.tunnel[info.fn[y][x]] == 0)
				putchar(lvl.f[y][x]);
			else
				putchar(info.tunnel[info.fn[y][x]] == 1 ? '|' : '-');
		}
		putchar('\n');
	}
	putchar('\n');
#endif
}

static void copy_to_info()
{
	int num = 0;
	for (int i = 0; i < tmp_info.num_fields; i++)
	{
		int x = xpos(tmp_info.fpos[i]);
		int y = ypos(tmp_info.fpos[i]);
		if (is_dead(lvl.f[y][x]))
			continue;
		info.fn[y][x] = num;
		info.fpos[num++] = tmp_info.fpos[i];
	}
	info.num_fields = num;
	info.num_boxes = tmp_info.num_boxes;
	memcpy(info.magic, tmp_info.magic, sizeof(unsigned int)*LVLSIZE*LVLSIZE);

	for (int i = 0; i < info.num_fields; i++)
	{
		int x1 = xpos(info.fpos[i]); int y1 = ypos(info.fpos[i]);
		for (int j = 0; j < info.num_fields; j++)
		{
			int x2 = xpos(info.fpos[j]); int y2 = ypos(info.fpos[j]);
			info.pd[i][j] = tmp_info.pd[tmp_info.fn[y1][x1]][tmp_info.fn[y2][x2]];
		}
		info.gd[i] = tmp_info.gd[tmp_info.fn[y1][x1]];
	}
}
