#include "level.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int genpos(int x, int y) { return LVLSIZE*x+y; }
int xpos(int pos) { return pos / LVLSIZE; }
int ypos(int pos) { return pos % LVLSIZE; }

struct level* load_xsb_levels(char* filename) // load levels from a xsb file
{
	FILE* in;
	if (!(in = fopen(filename, "rt")))
		return NULL;
	
	char line[256];
	struct level* first;
	struct level* last;
	first = last = malloc(sizeof(struct level));
	clean_level(first);

	int linenum = 0, add_new_level = 0;
	int topp = 0, leftp = 0; // top and left paddings
	while (fgets(line, 256, in))
	{
		if (line[0] == '\n')
		{
			add_new_level = 1;
			continue;
		}
		if (is_field(line[0]))
		{
			if (add_new_level)
			{
				add_new_level = 0;
				last = last->next_level = malloc(sizeof(struct level));
				topp = leftp = linenum = 0;
				clean_level(last);
			}

			for (int i = 0; line[i] != '\n' && line[i]; i++)
			{
				if (line[i] == '@' || line[i] == '+')
				{
					last->sx = i; last->sy = linenum;
					line[i] = line[i] == '@' ? ' ' : '.';
				}
				last->f[linenum][i] = line[i];
				if (i >= last->width)
					last->width = i+1;
			}
			linenum++;
			if (linenum > last->height)
				last->height = linenum;
		}
		else
		{
			/*if (strncmp(line, "Author: ", 8) == 0) // author tag
			{
				strncpy(last->author, &line[8], 50);
				last->author[49] = '\0';
			}*/
		}
	}
	return first;
}

void clean_level(struct level* lvl)
{
	for (int i = 0; i < LVLSIZE; i++)
		for (int j = 0; j < LVLSIZE; j++)
			lvl->f[i][j] = 0;
}

void print_level(struct level* lvl)
{
	for (int y = 0; y < lvl->height; y++)
	{
		for (int x = 0; x < lvl->width; x++)
		{	
			putchar((y == lvl->sy && x == lvl->sx) ? put_sok(lvl->f[y][x]) : lvl->f[y][x]);
		}
		putchar('\n');
	}
	printf("\n\n");
}

// field testings
int is_wall(char ch)
{
	return ch == '#'; 
}

int is_dead(char ch) // equals 'x'?
{
	return ch == 'x';
}

int is_walkable(char ch) // sokoban can walk on it?
{
	return ch != '#' && !has_box_on(ch);
}

int is_pushable(char ch) // box can be pushed on it?
{
	return is_walkable(ch) && ch != 'x';
}

int is_box_placeable(char ch) // box can be pushed on it ever?
{
	return ch != '#' && ch != 'x';
}

int has_box_on(char ch)
{
	return ch == '$' || ch == '*';
}

int has_goal_on(char ch)
{
	return ch == '.' || ch == '*';
}

int has_unplaced_box_on(char ch)
{
	return ch == '$';
}

int has_empty_goal_on(char ch)
{
	return ch == '.';
}

// modify field
char put_box(char ch)
{
	switch (ch)
	{
		case ' ': return '$';
		case '.': return '*';
		default: return ch;
	}
}

char remove_box(char ch)
{
	switch (ch)
	{
		case '*': return '.';
		case '$': return ' ';
		default: return ch;
	}
}

char set_wall()
{
	return '#';
}

char set_dead_field()
{
	return 'x';
}

char put_sok(char ch)
{
	return has_goal_on(ch) ? '+' : '@';
}

// field conversions for input/output
int is_field(char ch)  // is a input character a field?
{
	return strchr(" #$.*@+", ch) != NULL;
}
