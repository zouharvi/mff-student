#include "global.h"
#include "position.h"
#include "level.h"

// TODO: make functions set_position and get_position faster!!

void set_position(struct position* pos) // modifies the level according to the position
{
	int j = 0, i = 0;
	unsigned int tmp = pos->b[0];
	for (int f = 0; f < info.num_fields; f++)
	{
		int x = xpos(info.fpos[f]);
		int y = ypos(info.fpos[f]);

		lvl.f[y][x] = tmp % 2 ? put_box(lvl.f[y][x]) : remove_box(lvl.f[y][x]);
		tmp /= 2;

		if (i++ >= 31)
		{
			j++;
			tmp = pos->b[j];
			i = 0;
		}
	}
	lvl.sx = xpos(pos->s);
	lvl.sy = ypos(pos->s);
}

void get_position(struct position* pos) // reads the position from the level
{
	pos->s = genpos(lvl.sx, lvl.sy);
	for (int i = 0; i < POSITION_SIZE; i++)
		pos->b[i] = 0;

	int i = 0,j = 0;
	for (int y = 0; y < lvl.height; y++)
		for (int x = 0; x < lvl.width; x++)
		{
			if (is_wall(lvl.f[y][x]) || is_dead(lvl.f[y][x]))
				continue;
			pos->b[j] = pos->b[j] + (has_box_on(lvl.f[y][x]) << i);
			if (i++ >= 31)
			{
				i = 0;
				j++;
			}			
		}		
}

int compare_positions(struct position* pos1, struct position* pos2) // are positions equal?
{
	if (pos1->s != pos2->s) return 0;
	return compare_positions_without_sokoban(pos1,pos2);
}

int compare_positions_without_sokoban(struct position* pos1, struct position* pos2) // are positions equals except Sokoban?
{
	for (int i = 0; i < POSITION_SIZE; i++)
		if (pos1->b[i] != pos2->b[i])
			return 0;
	return 1;
}

int is_subposition(struct position* pos, struct position* sub) // tests whether it contains boxes at given places
{
	for (int i = 0; i < POSITION_SIZE; i++)
		if (sub->b[i] != (sub->b[i] & pos->b[i]))
			return 0;	
	return 1;	
}

void push_box(struct position* start, struct position* result, int from, int to, int xsok, int ysok)
{
	for (int i = 0; i < POSITION_SIZE; i++)
		result->b[i] = start->b[i];
	
	swap_box_of_position(result, from);
	swap_box_of_position(result, to);
	
	result->s = genpos(xsok, ysok);
}

void clean_position(struct position* pos)
{
	for (int i = 0; i < POSITION_SIZE; i++)
		pos->b[i] = 0;
}

void add_box_of_position(struct position* pos, int fn)
{
	pos->b[fn / 32] |= 1 << (fn % 32);
}

void remove_box_of_position(struct position* pos, int fn)
{
	pos->b[fn / 32] &= (~(1 << (fn % 32)));
}

void swap_box_of_position(struct position* pos, int fn)
{
	pos->b[fn / 32] ^= 1 << (fn % 32);
}

