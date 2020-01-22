# Agents
- agent = architecture + program
- agent function
- performance measure
- rational agent

## Types
### Table-driven agent
### Simple reflex agent
### Model-based reflex agent
### Goal-based agent
### Utility-based agent
### General learning agent

## Environment
- TODO properties

### Representation
- atomic representation
- factored representation
- structured representation

# Problems
- Consists of:
- - Initial state
- - Possible actions (successor function)
- - Goal test (is a state a goal state?)
- - Path cost (similar to performance measure)
- Abstraction of world states and actions. The abstraction should be __valid__ and __useful__.


## Problem solving
1. Goal formulation
2. Problem formulation
3. Problem solving
4. Solution execution

# Uninformed state search
- Algorithm __Tree search__
- Informed (blind) / uninformed (heuristic) search
- Criteria:
- - Completeness
- - Optimality
- - Time and space complexity (branching factor, depth, path length)

## State space search
- Start in the initial state
- Check whether it's a goal state
- Expand the state if not
- Select a next state using a search strategy
- Node has:
- - current world state
- - link to its parent
- - action leading from parent to the current state
- - cost of path from root to node $g(n)$
- - depth (from root)
- __Fringe__ a set of nodes not yet expanded (but to be expanded)

## BFS
- All nodes at a given depth expanded
- Always expand the shallowest node (using FIFO)
- Time complexity for a goal at depth $d$ is $O(b^{d+1})$
- Space complexity ditto
- Is complete, but not optimal (shallowest may not be the optimal solution)

## Uniform cost search
- Modified BFS
- Always expand lowest path cost
- Complete if all cost is bounded by $\epsilon > 0$
- Time and space complexity $O(b^{1+C^*/\epsilon})$

## DFS
- Expand the deepest node (LIFO)
- Not complete nor optimal
- Time complexity $O(b^m)$, where $m$ is the maximum depth
- Space complexity $O(bm)$

## Depth-limited search
- Completeness can be fixed by adding a depth boundary

## Iterative deepening
- We run depth-limited search multiple times, increasing the limit
- Space complexity $O(bd)$
- Time complexity $O(b^d)$ (geometry sum)

## Bidirectional search
- Two frontiers
- Space complexity $O(B^{d/2})$

## Backward search
- Sometimes a good idea, but we need a reverse successor function

## Partial information
- no sensors -> belief states
- non-deterministic actions -> expected value
- unknown actions -> exploration

# Informed state search
- looking for the shortest path
- we need a function $h(n)$ to estimate the length of the cheapest path to a goal state

## Greedy best first search
- always choose the state with the lowest $h$ value from the fringe
- not optimal, not complete

## A*
- choose by lowest $f(n) = g(n) + h(n)$
- admissible heuristic (always underestimate)
- monotonous/consistent heuristic ()

### Monotonous heuristic is admissible
- TODO Proof

### $f$ of monotonous heuristic is non-decreasing
- TODO Proof

### A* tree search is optimal for admissible heuristics
- TODO Proof

### A* graph search is optimal for monotonous heuristics
- TODO Proof

### IDA*
- iterative deepening A*
- search limit by $f(n)$ instead of depth
- for next iteration we use the smallest $f(n)$, which was over the limit

### Recursive best first search
- TODO

### Simplified memory bounded A*
- when memory is full, drop the worst leaf node (highest f-value)

### Heuristics performance
- effective branching factor - TODO
- dominance: $h_2$ dominates $h_1$ iff $\forall n: h_2(n)\ge h_1(n)$
- - $h_2$ always expands less or equal nodes

### Misc heuristics
- admissible heuristics can always be constructed (problem relaxation, or $o$)
- pattern database - TODO

# Local search
- we do local search
- we try to find the state itself

## Hill climbing
- not complete, because HC never makes a downhill move
- random walk is complete

### Environment
- local optimum
- ridges
- plateaux

### Methods
- stochastic HC
- - move chosen at random with probabilities dependent on goodness of neighbour
- first choice HC
- - choose first better than current neighbour
- random restart HC 
- - run HC multiple times, pick max (close to GA)
- simulated annealing
- - combination of random walk and HC
- - decreasing temperature
- - if it increases the state, then good
- - also allowed to worsen the state, but only with some probability related to the temperature $e^{\delta/T}$

## Local beam search
- keep track of $k$ states
- generate all successors, but take $k$ best
- not identical to running $k$ restarts of HC in parallel (we drop unfruitful paths)
- lack of diversity can be solved by stochastic local beam search (very much like GA)

## Genetic algorithms
- population, every state is a string over a finide alphabet (DNA)
- fitness function
- crossover, mutation
- offsprings

## Online search
- useful for agents executing actions
- assume that agents can test a goal state and can recognize a visited state
- TODO
- DFS seems obvious for this task, as the agent can only expand states it physically occupies
- HC is an online algorithm, but restarts can't be used

# Constrain satisfaction
- variables, variable domains, constraints
- state (partial assignment of values to variables)
- consistent state (does not violate any constraint)
- complete state (every variable assigned)
- goal (complete consistent state)
- sometimes we also have an objective function we try to maximize
- can be solved by a declarative approach and a general constraint solver

## Search algorithms
- initial state (empty assignment)
- applicable actions (assignment of value to variable with no violation of any constraint)
- the goal (complete consistent state)
- max depth $n$ (number of variables), so we can safely use DFS
- order of assignment not important

## Backtracking efficiency
- try good values first
- do hard to assign variables first (first-fail)
- deduce extra information by constraint propagation

## Variable heuristics
- most restricted (smallest domain) variable first (dom heuristic)
- most constrained (participation in constraints) variable first (deg heuristic)
- succeed-first (use value which hopefully belongs to the solution, e.g. restricts other variables less)

## Forward checking
- after assigning a value we can check future constraints (constraints between the current variable and not-yet instantiated variables)
- constraint check = remove values violating the constraint
- constraint propagation/look ahead (we can check the constraints even between the future variables)
- technicall by maintaining consistency of constraints 
- Algorithm AC-3 TODO
- stronger k-consistency TODO
- global constraints TODO

# Games
- zero-sum
- min, max players
- alpha beta pruning TODO
- horizon effect TODO

## Improvements
- singular extension
- forward pruning
- transposition tables

## Stochastic games
- expected minimax
- also chance nodes along with min and max nodes

# Knowledge representation
- knowledge base + queries
- we may have to infere new facts from the KB to answer the query
- "possible models"
- propositional variables, propositional formulas
- entailment
- sound and complete algorithm

## Inference methods
- model checking
- - truth table enumeration
- - we generate all the models and check their validity (generate and test)
- - all KB model must also be a model of the query
- inference rules
- - application of inference rules
- query $\alpha$ is entailed by KB if $KB \wedge \not \alpha$ is unsatisfiable (does not have amodel)

## Algorithms
- DPLL TODO
- WalkSAT TODO
- resolution algorithm
- - Horn clauses
- forward chaining
- backward chaining

# First-order logic
- constants, function symbols, terms
- atomic/complex sentences
- quantifiers

## Inference
- quantifiers -> skolemization (universal and existential instantiation)
- functions and variables -> unification (standardization apart)
- alternative would be grounding/propositionalization
- - instantiation of variable by all possible terms
- - we could have infinite amount of such variables

TODO

# Knowledge engineering
- query is a logical formula
- (not much) TODO

# Automated planning
- situation calculus
- possibility actions, effect axiom)
- we need a frame axiom (everything untouched remains intact) TODO
- projection task
- - what is the state after applying a given sequence of actions?
- planning task
- - which sequence of actions reaches a given state?

## Action
- actions are fully instantiated operator
- application result has an implicit frame axiom
- planning domain:
- - states
- - actions
- - transigion function

## Plan
- is a sequence of actions
- a solution plan for a problem has initial state and goal state as the final

## State-space planning
- forward search (progression)
- backward search (regression)

## Backward planning
- TODO:

## Plan-space planning
- start with an empty plan
- always have a partial plan
- we proceed by repairing flaws in a partial plan
- partially instantiated planning operators
- flaws: open goal, threat