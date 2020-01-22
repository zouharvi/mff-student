#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "solution.h"
#include "level.h"
#include "position.h"
#include "global.h"
#include <unistd.h>

struct level old_pos;
int sokx;
int soky;
int box;
int tmpbox;
int tobox;
int tosokx;
int tosoky;

int queue_sok[4*LVLSIZE*LVLSIZE];
int queue_box[4*LVLSIZE*LVLSIZE];
int len[4*LVLSIZE*LVLSIZE];
int prev[4*LVLSIZE*LVLSIZE];
char seq[4*LVLSIZE*LVLSIZE][256];
int mov[LVLSIZE][LVLSIZE][4];

static void add_moves_between_two_positions(struct solution* sol, struct position* to);
static void calculate_push(struct position* to);
static void reachable_for_solution();
static int get_to(int x, int y, char* store);
static void put_push_to_sol(int index, struct solution* sol);

void create_solution(struct solution* sol, struct move* last_move) // creates solution from last move
{
	if (last_move->parent != 0)
		create_solution(sol, last_move->parent);
	else
	{
		set_position(&last_move->pos);	
		memcpy(&old_pos, &lvl, sizeof(struct level));
		return;
	}	

	add_moves_between_two_positions(sol, &last_move->pos);		
}

void write_solution(struct solution* sol)
{
	for (int i = 0; i < sol->length; i++)
		putchar(sol->move[i]);
	putchar('\n');
}

void write_solution_to_file(struct solution* sol, FILE* file)
{
	for (int i = 0; i < sol->length; i++)
		fputc(sol->move[i], file);
	fputc('\n', file);
}

int check_solution(struct solution* sol, struct level* level, int animate)
{
	memcpy(&old_pos, level, sizeof(struct level));

	if (animate)
		print_level(&old_pos);
	for (int i = 0; i < sol->length; i++)
	{
		char m = sol->move[i];
		int dir;
		switch (m)
		{
			case 'l':
			case 'L': dir = 0; break;
			case 'd':
			case 'D': dir = 1; break;
			case 'r':
			case 'R': dir = 2; break;
			case 'u':
			case 'U': dir = 3; break;
			default: return 0;
		}

		int x = old_pos.sx+movesx[dir];
		int y = old_pos.sy+movesy[dir];
		if (m > 'Z')
		{
			if (is_walkable(old_pos.f[y][x]))
			{
				old_pos.sx = x;
				old_pos.sy = y;
			}
			else
			{
				printf("%d: can't do a move '%c'\n", i, m);
				print_level(&old_pos);
				return 0;
			}
		}
		else
		{
			int xto = old_pos.sx+2*movesx[dir];
			int yto = old_pos.sy+2*movesy[dir];
			if (has_box_on(old_pos.f[y][x]) && is_pushable(old_pos.f[yto][xto]))
			{
				old_pos.f[y][x] = remove_box(old_pos.f[y][x]);
				old_pos.f[yto][xto] = put_box(old_pos.f[yto][xto]);
				old_pos.sx = x;
				old_pos.sy = y;
			}
			else
			{
				printf("%d: can't do a move '%c'\n", i, m);
				print_level(&old_pos);
				return 0;
			}
		}
		if (animate)
		{
			usleep(m > 'Z' ? 100000 : 150000);
			print_level(&old_pos);
		}
	}

	for (int y = 0; y < old_pos.height; y++)
		for (int x = 0; x < old_pos.width; x++)
		{
			if (has_unplaced_box_on(old_pos.f[y][x]) || has_empty_goal_on(old_pos.f[y][x]))
			{
				printf("level is not finished!\n");
				print_level(&old_pos);
				return 0;
			}
		}

	if (animate)
	{
		char str[] = "LEVEL SOLVED!";
		for (int i = 0; i < 13; i++)
		{
			putchar(str[i]);
			fflush(stdout);
			if (str[i] != ' ')
				usleep(150000);
		}
		putchar('\n');
		usleep(400000);
	}

	return 1;
}

static void add_moves_between_two_positions(struct solution* sol, struct position* to)
{
	calculate_push(to);
	tmpbox = box;
	int x = xpos(info.fpos[tmpbox]);
	int y = ypos(info.fpos[tmpbox]);
	old_pos.f[y][x] = remove_box(old_pos.f[y][x]);

	int first = 0;
	int last = 0;
	for (int y = 0; y < lvl.height; y++) 
		for (int x = 0; x < lvl.width; x++)
			for (int i = 0; i < 4; i++)
				mov[y][x][i] = 0;

	reachable_for_solution();
	x = xpos(info.fpos[box]);
	y = ypos(info.fpos[box]);
	for (int i = 0; i < 4; i++)
	{
		int xto = x+movesx[i+2];
		int yto = y+movesy[i+2];
		if (reachable[y+movesy[i]][x+movesx[i]] >= 0 && is_pushable(old_pos.f[yto][xto]))
		{
			len[last] = get_to(x+movesx[i],y+movesy[i],seq[last]);
			seq[last][len[last]++] = "RULD"[i];
			queue_sok[last] = genpos(x,y);
			queue_box[last] = info.fn[yto][xto];
			prev[last++] = -1;
			mov[yto][xto][i] = 1;
			//printf("\t(%d, %d, %d) - '%s'\n", xpos(queue_sok[last-1]), ypos(queue_sok[last-1]), queue_box[last-1], seq[last-1]);
		}
	}

	//printf("(%d, %d, %d) => (%d, %d, %d)\n", sokx, soky, box, tosokx, tosoky, tobox);
	
	while (last > first)
	{
		sokx = xpos(queue_sok[first]);
		soky = ypos(queue_sok[first]);
		box = queue_box[first];
		x = xpos(info.fpos[box]);
		y = ypos(info.fpos[box]);
		if (box == tobox) // && sokx == tosokx && soky == tosoky)
			break;
		reachable_for_solution();

		for (int i = 0; i < 4; i++)
		{
			int xto = x+movesx[i+2];
			int yto = y+movesy[i+2];
			if (reachable[y+movesy[i]][x+movesx[i]] >= 0 && mov[yto][xto][i] == 0 && is_pushable(old_pos.f[yto][xto]))
			{
				len[last] = get_to(x+movesx[i],y+movesy[i],seq[last]);
				seq[last][len[last]++] = "RULD"[i];
				queue_sok[last] = genpos(x,y);
				queue_box[last] = info.fn[yto][xto];
				prev[last++] = first;
				mov[yto][xto][i] = 1;			
			}
		}
		first++;
	}

	if (last <= first)
	{
		printf("Error while creating solution!\n");
		print_level(&old_pos);
		printf("\t=> (%d, %d, %d, %d)\n", tosokx, tosoky, xpos(info.fpos[tobox]), ypos(info.fpos[tobox]));
	}
	else
		put_push_to_sol(first, sol);

	x = xpos(info.fpos[tobox]);
	y = ypos(info.fpos[tobox]);
	old_pos.f[y][x] = put_box(old_pos.f[y][x]);
	old_pos.sx = sokx;
	old_pos.sy = soky;
}

static void calculate_push(struct position* to)
{
	int j = 0, i = 0;
	unsigned int tmp = to->b[0];
	for (int f = 0; f < info.num_fields; f++)
	{
		int x = xpos(info.fpos[f]);
		int y = ypos(info.fpos[f]);

		if (has_box_on(old_pos.f[y][x]) != tmp % 2)
		{
			if (tmp % 2)
				tobox = f;
			else
				box = f;
		}
		tmp /= 2;

		if (i++ >= 31)
		{
			j++;
			tmp = to->b[j];
			i = 0;
		}
	}
	tosokx = xpos(to->s);
	tosoky = ypos(to->s);
	sokx = old_pos.sx;
	soky = old_pos.sy;
}

static void reachable_for_solution()
{
	for (int y = 0; y < old_pos.height; y++)
		for (int x = 0; x < old_pos.width; x++)
			reachable[y][x] = is_walkable(old_pos.f[y][x]) ? -1 : -2;
	reachable[ypos(info.fpos[box])][xpos(info.fpos[box])] = -2;

	int first = 0;
	search_queue_x[0] = sokx;
	search_queue_y[0] = soky;
	reachable[soky][sokx] = 0;
	int last = 1;

	while (last > first)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = search_queue_x[first] + movesx[i];
			int y = search_queue_y[first] + movesy[i];

			if (reachable[y][x] == -1)
			{
				reachable[y][x] = i+2;
				search_queue_x[last] = x;
				search_queue_y[last++] = y;
			}
		}
		first++;
	}
}

static int get_to(int x, int y, char* store)
{
	int l;
	if (reachable[y][x] != 0)
		l = get_to(x+movesx[reachable[y][x]],y+movesy[reachable[y][x]],store);
	else
		return 0;

	store[l] = "ldru"[reachable[y][x]-2];
	return l+1;
}
	
static void put_push_to_sol(int index, struct solution* sol)
{
	if (prev[index] != -1)
		put_push_to_sol(prev[index],sol);

	for (int i = 0; i < len[index]; i++)
		sol->move[sol->length+i] = seq[index][i];
	sol->length += len[index];
}
