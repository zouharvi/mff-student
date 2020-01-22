#include "allocator.h"
#include <stdlib.h>

#define QUEUE_CHUNK 65536
#define MOVE_CHUNK 65536

struct move* alloc_moves = 0; // allocated moves
int last_move = MOVE_CHUNK;
struct move freed_moves;

struct queue* alloc_nodes = 0; // allocated nodes 
int last_node = QUEUE_CHUNK;
struct queue freed_nodes;

void inicialize_allocator()
{
	freed_moves.parent = 0;
	freed_nodes.next = 0;
}

struct queue* malloc_node()
{
	if (last_node < QUEUE_CHUNK)
		return &alloc_nodes[last_node++];
	else
	{
#ifdef REUSE_MEMORY
		if (freed_nodes.next != 0)
		{
			struct queue* tmp = freed_nodes.next;
			freed_nodes.next = freed_nodes.next->next;
			return tmp;
		}
		else
		{
#endif
			alloc_nodes = malloc(sizeof(struct queue)*QUEUE_CHUNK);
			last_node = 1;
			return alloc_nodes;
#ifdef REUSE_MEMORY
		}
#endif
	}
}

void free_node(struct queue* q)
{
#ifdef REUSE_MEMORY
	q->next = freed_nodes.next;
	freed_nodes.next = q;
#endif
}

struct move* malloc_move()
{
	if (last_move < MOVE_CHUNK)
		return &alloc_moves[last_move++];
	else
	{
#ifdef REUSE_MEMORY
		if (freed_moves.parent == 0)
		{
			struct move* tmp = freed_moves.parent;
			freed_moves.parent = freed_moves.parent->parent;
			return tmp;
		}
		else
		{
#endif
			alloc_moves = malloc(sizeof(struct move)*MOVE_CHUNK);
			last_move = 1;
			return alloc_moves;
#ifdef REUSE_MEMORY
		}
#endif
	}
}

void free_move(struct move* mov)
{
#ifdef REUSE_MEMORY
	mov->parent = freed_moves.parent;
	freed_moves.parent = mov;
#endif
}
