#ifndef SOKOBAN_SOLVER_HASHTABLE
#define SOKOBAN_SOLVER_HASHTABLE

#include "move.h"

// magic prime number
#define HASHSIZE 16769023
#define HASHMAX HASHSIZE*9/10

// for now, a static hash table
struct hashtable
{
	struct move* data[HASHSIZE];	
	int count;
};

void initialize_hash();
void clean_hash();
int add_to_hashtable(struct move* mov); // return 0 if hashtable already contains mov

#endif // SOKOBAN_SOLVER_HASHTABLE
