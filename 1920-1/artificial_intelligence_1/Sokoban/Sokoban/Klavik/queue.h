#ifndef SOKOBAN_SOLVER_QUEUE
#define SOKOBAN_SOLVER_QUEUE

struct queue
{
	struct queue* next;
	void* e;
};

struct queue* create_queue_node(void* element);
void append_queue_node(struct queue* node, struct queue* after); // adds node next to after
struct queue* remove_queue_node(struct queue* before); // removes node next to "before" from queue and returns it
int is_queue_empty(struct queue* head);

#endif // SOKOBAN_SOLVER_QUEUE
