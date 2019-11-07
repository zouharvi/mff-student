#include "global.h"

// global variables of the solver
struct level lvl;
struct level_info info;
struct move root;
struct hashtable hash;
struct solution lvl_sol;

struct queue move_queue[MAXDISTANCE];
int current_distance;

struct position static_deadlocks[MAXFIELDS][MAXSTATICDEADLOCKS];
int static_deadlocks_count[MAXSTATICDEADLOCKS];

int search_queue[LVLSIZE*LVLSIZE]; 
int search_queue_x[MAXFIELDS]; 
int search_queue_y[MAXFIELDS]; 

int reachable[LVLSIZE][LVLSIZE];
int boxx[MAXFIELDS];
int boxy[MAXFIELDS];
int box_count;

int solvable = 1; // 0/1
struct move* solution = 0; 

const int movesx[8] = {-1,0,1,0,-1,0,1,0};
const int movesy[8] = {0,1,0,-1,0,1,0,-1};

