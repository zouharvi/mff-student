#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "allocator.h"
#include "solving_routine.h"
#include "crs.h"
#include "solution.h"

static void inicialize_routine();
static void run_routine();
static void add_move(int x, int y, int from, int xto, int yto, int to, int pd);
static void clean_routine();

// output function, mainly for debugging purposes
static void echo_move(struct move* cur, struct move* next);
static void echo_reachable();
static void echo_areas();

#ifdef WRITE_PROGRESS
int posnum = 0;
#endif
struct move* new_move;
struct move* mov;

void try_solve_level()
{
	inicialize_routine();
	run_routine();
	clean_routine();
}

static void inicialize_routine()
{
	initialize_hash();
	initialize_crs();
	get_position(&root.pos);

	root.magic = 0;
	root.heuristic = 0; 
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (has_box_on(lvl.f[y][x]))
			{
				root.magic = root.magic ^ info.magic[y][x];
				root.heuristic += info.gd[info.fn[y][x]];
			}
		}
	}
	root.magic = root.magic ^ magic_for_sokoban(lvl.sx, lvl.sy);
	root.parent = 0;

	for (int i = 0; i < MAXDISTANCE; i++)
		move_queue[i].next = 0;
	current_distance = root.heuristic;
	move_queue[current_distance].next = create_queue_node(&root);
	add_to_hashtable(&root);
}

static void clean_routine()
{
#ifdef DEALOCATE_MEMORY
	clean_hash();
	/*printf("HASH is clean...\n");
	for (; current_distance < MAXDISTANCE; current_distance++)
	{
		if (current_distance % 1000 == 0)
			printf("current distance...\n");
		while (!is_queue_empty(&move_queue[current_distance]))
		{
			struct queue* node = remove_queue_node(&move_queue[current_distance]);
			free_node(node);
		}		
	}*/
#endif
	}

	static void run_routine()
	{
		new_move = malloc_move();
		for (; current_distance < MAXDISTANCE; current_distance++)
		{
			while (!is_queue_empty(&move_queue[current_distance]))
			{
				if (__builtin_expect(hash.count > HASHMAX,0))
				{
					solvable = 0;
					printf("HASH TOO FULL!\n");
					return 0;
				}

				struct queue* node = remove_queue_node(&move_queue[current_distance]);
				mov = (struct move*) node->e;
				free_node(node);
					
				set_position(&mov->pos);
#ifdef WRITE_PROGRESS
				posnum++;
				if (posnum % 50000 == 0)
					print_level(&lvl);
#endif
				
				calculate_position();
#ifdef WRITE_TO_STDOUT
				echo_areas();
				print_level(&lvl);
				printf("Current heuristic = %d\n", current_distance);
#endif

				if (mov->heuristic % HIBYTES == mov->heuristic / HIBYTES)
				{
					print_level(&lvl);
					printf("LEVEL SOLVED with %d pushes!\n", mov->heuristic / HIBYTES);

					create_solution(&lvl_sol, mov);
					write_solution(&lvl_sol);

					return;
				}

				for (int b = 0; b < box_count; b++)
				{
					int x = boxx[b];
					int y = boxy[b];
					int from = info.fn[y][x];

#ifdef USE_TUNNELS
					if (info.tunnel[from] == 0)
					{
#endif
						for (int i = 0; i < 4; i++)
						{
							int xsok = x+movesx[i]; int ysok = y+movesy[i];
							int xto = x+movesx[i+2]; int yto = y+movesy[i+2];
							if (reachable[ysok][xsok] == 1 && is_pushable(lvl.f[yto][xto]))
							{
								int to = info.fn[yto][xto];
								add_move(x,y,from,xto,yto,to,1);
							}
						}
#ifdef USE_TUNNELS
					}
					else
					{
#ifdef WRITE_TO_STDOUT
						printf("Using tunnel macro...\n");
#endif
						for (int i = 0; i < 2; i++)
						{
							int type = info.tunnel[from] == 1;
							int xsok = x+movesx[i*2 + type]; int ysok = y+movesy[i*2 + type];
							int to = info.tunnel_goals[from][i];
							if (to != -1)
							{
								int xto = xpos(info.fpos[to]); int yto = ypos(info.fpos[to]);
								if (reachable[ysok][xsok] == 1 && is_pushable(lvl.f[yto][xto]))
								{
									int pd = info.tunnel_distance[from][i];
#ifdef WRITE_TO_STDOUT
									printf("Tunnel: (%d,%d) =%d=> (%d,%d)\n", xsok, ysok, pd, xto, yto);
#endif
									add_move(x,y,from,xto,yto,to,pd);
								}
							}
						}						
					}
#endif
				}
#ifdef WRITE_TO_STDOUT
			printf("--------------------------------------------------------------\n\n");
#endif
		}
	}
}

// TODO: rewrite using hashtable in add_move function??
static void add_move(int x, int y, int from, int xto, int yto, int to, int pd)
{
	push_box(&mov->pos, &new_move->pos, from, to, x, y);
	new_move->magic = mov->magic ^ info.magic[y][x] ^ info.magic[yto][xto]
			^ magic_for_sokoban(lvl.sx,lvl.sy) ^ magic_for_sokoban(x,y);
	if (!test_static_deadlocks(&new_move->pos,to) && add_to_hashtable(new_move)) // this position is new
	{
#ifdef WRITE_TO_STDOUT
		echo_move(mov, new_move);
#endif
		new_move->parent = mov;
		new_move->heuristic = mov->heuristic + pd - info.gd[from] + info.gd[to] + HIBYTES*pd;
		append_queue_node(create_queue_node(new_move),&move_queue[new_move->heuristic % HIBYTES]); // TODO: add test for MAXDISTANCE??
		new_move = malloc_move();
	}
}

static void echo_move(struct move* cur, struct move* next)
{
	int pos = 0;
	int pos2 = 0;
	
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_wall(lvl.f[y][x]))
				putchar('#');
			else if (is_dead(lvl.f[y][x]))
				putchar('x');
			else
				putchar(((cur->pos.b[pos / 32] >> (pos++ % 32)) % 2) ?
						put_box(lvl.f[y][x]) : 
						(cur->pos.s == genpos(x,y) ? put_sok(lvl.f[y][x]) : lvl.f[y][x]));
		}
		printf(y == lvl.height / 2 ?
				"    -->    " :
				"           ");
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_wall(lvl.f[y][x]))
				putchar('#');
			else if (is_dead(lvl.f[y][x]))
				putchar('x');
			else
				putchar(((next->pos.b[pos2 / 32] >> (pos2++ % 32)) % 2) ?
						put_box(lvl.f[y][x]) : 
						(next->pos.s == genpos(x,y) ? put_sok(lvl.f[y][x]) : lvl.f[y][x]));
		}
		printf("\n");
	}
	printf("\n");
}

static void echo_reachable()
{
	printf("reachable squares:\n");
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (reachable[y][x] != -1)
				printf("%d", reachable[y][x]);
			else
				printf("#");
		}
		printf("\n");
	}
	printf("\n");
}

static void echo_areas()
{
	printf("areas:\n");
	for (int y = 0; y < lvl.height; y++)
	{
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_wall(lvl.f[y][x]))
				printf("#");
			else
				printf("%d", reachable[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
