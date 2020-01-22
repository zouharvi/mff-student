#include "global.h"
#include "hashtable.h"
#include "allocator.h"
#include <stdlib.h>
#include <string.h>

void initialize_hash()
{
	hash.count = 0;
	memset(hash.data, 0, HASHSIZE*sizeof(struct move*));
}

void clean_hash()
{
	for (int i = 0; i < HASHSIZE; i++)
	{
		if (hash.data[i] != 0)
			free_move(hash.data[i]);
	}
}

int add_to_hashtable(struct move* mov) // return 0 if hashtable already contains mov
{
	unsigned int pos = mov->magic;
	while (hash.data[pos % HASHSIZE] != 0)
	{
		if (compare_moves(mov, hash.data[pos % HASHSIZE]))
			return 0; // TODO: add replacing parent in the tree, if distance is shorter?
		else
			pos++;
	}
	hash.data[pos % HASHSIZE] = mov;
	hash.count++;
	return 1;
}
