#ifndef SOKOBAN_SOLVER_GLOBAL
#define SOKOBAN_SOLVER_GLOBAL

#include "level.h"
#include "level_info.h"
#include "position.h"
#include "hashtable.h"
#include "deadlock_table.h"
#include "queue.h"
#include "solution.h"

#define MAXDISTANCE 10000

// list of global variables of the solver
extern struct level lvl;
extern struct level_info info;
extern struct move root;
extern struct hashtable hash;
extern struct solution lvl_sol;

extern struct queue move_queue[MAXDISTANCE];
extern int current_distance;

// static deadlocks
extern struct position static_deadlocks[MAXFIELDS][MAXSTATICDEADLOCKS];
extern int static_deadlocks_count[MAXSTATICDEADLOCKS];

extern int search_queue[LVLSIZE*LVLSIZE]; 
extern int search_queue_x[MAXFIELDS]; 
extern int search_queue_y[MAXFIELDS]; 

extern int reachable[LVLSIZE][LVLSIZE];
extern int boxx[MAXFIELDS];
extern int boxy[MAXFIELDS];
extern int box_count;

extern int solvable; // 0/1
extern struct move* solution; 

extern const int movesx[8];
extern const int movesy[8];

// global constants
//#define WRITE_TO_STDOUT
#define WRITE_PROGRESS
#define DEALOCATE_MEMORY
#define REUSE_MEMORY

#define USE_PI_CORRALS
#define USE_TUNNELS

#endif // SOKOBAN_SOLVER_GLOBAL
