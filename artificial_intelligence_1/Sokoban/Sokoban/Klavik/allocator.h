#ifndef SOKOBAN_SOLVER_ALLOCATOR
#define SOKOBAN_SOLVER_ALLOCATOR

#include "queue.h"
#include "move.h"

void inicialize_allocator();

struct queue* malloc_node();
void free_node(struct queue* q);

struct move* malloc_move();
void free_move(struct move* mov);

#endif // SOKOBAN_SOLVER_ALLOCATOR

