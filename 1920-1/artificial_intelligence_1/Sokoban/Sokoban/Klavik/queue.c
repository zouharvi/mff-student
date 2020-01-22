#include "queue.h"
#include "allocator.h"

struct queue* create_queue_node(void* element)
{
	struct queue* tmp = malloc_node();
	tmp->e = element;
	return tmp;
}

void append_queue_node(struct queue* node, struct queue* after) // adds node next to after
{
	node->next = after->next;
	after->next = node;
}

struct queue* remove_queue_node(struct queue* before) // removes node next to "before" from queue and returns it
{
	struct queue* tmp = before->next;
	before->next = before->next->next;
	return tmp;
}

int is_queue_empty(struct queue* head)
{
	return !head->next;
}
