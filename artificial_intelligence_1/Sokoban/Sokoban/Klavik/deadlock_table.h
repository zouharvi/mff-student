#ifndef SOKOBAN_SOLVER_DEADLOCK_TABLE
#define SOKOBAN_SOLVER_DEADLOCK_TABLE

#define MAXSTATICDEADLOCKS 100

void calculate_static_deadlocks();
int test_static_deadlocks(struct position* pos, int fn); // test deadlocks on updated field fn

#endif // SOKOBAN_SOLVER_DEADLOCK_TABLE
