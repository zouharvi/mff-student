Notes for the Linear Programming and Combinatorical Optimization exam by Hans Raj Tiwary at MFF

# part A

## 1

### integer program
maximize c^Tx
subject to Ax <= b, x >= 0, x \in Z^n

### linear program
maximize c^Tx
subject to Ax <= b, x >= 0, x \in R^n

### objective function
c^Tx

### feasible solution
x_0 such that Ax_0 <= b, x_0 >= 0

### optimum solution
x_0 such that it is feasible and c^Tx_0 = max c^tx, x feasible

### bounded/unbounded
LP is bounded if the system of inequalities forms a closed region
if exists a feasible solution, then exits optimal feasible solution (bounded)
exists feasible solution of arbitrary value (unbounded)

### LP relaxation of an IP
we drop the Z^n constraint

## 2

### convex, conic hull
convex definitions:
- minimal convex cover set containing X (non-negative coefficients, sum to 1)
- intersection of all convex sets containing X
- set of all convex combinations of points in X

conic hull:
- minimal conical cover set containing X (non-negative coeffiecients)

affine combination:
- sum to 1

### polyhedron
- intersection of finitely many half-spaces (inequalities)
- x <= A

### polotype
bounded polyhedron

### valid inequality
x such that Ax <= b

### k-dimensional face, edge, vertex
- it is a face F if it has a dimension of k and there exists c, z such that c^Tx = z for all x \in F and c^Tx < z for all x \in P - F (supporting hyperplane)
- edge is 1 dimensional face
- vertex is 0 dimensional face
- empty set is a face with dimension -1
- facet is n-1 dimensional face (of n dimensional polyhedron)

### pointed polehedron
polyhedron with at least one vertex

## 3

### Minkowsky-Weyl theorem
equivalence:
- P is a polyhedron (exists A, b: P = {x| Ax <= b}) bounded
- P = conv(v_1, v_2, .., v_n)
  (+ conic(r_1, r_2, .., r_m) for unbounded) 

## 4

### extreme point
- X \in polyhedra P is an extreme point iff each line segment completely in P containing X has X as an endpoint
- X \notin conv(P - X)

### basis
indicies of column space of A such that the given submatrix of A is not singular

### feasible basis
is a basis such that there exists a basic feasible solution

### basic feasible solution
assignment of basis variables (other zeroes) such that Ax <= b

## 5

### dual of an LP
derived from the primal LP
each variable becomes a constraint
each constraint becomes a variable in the dual LP
if in canonical form, then
from each inequality (<=) y_i >= 0
from each x_i (x_i >= 0) new inequality >=

from Ax <= b, max c^Tx, x >= 0
get A^Ty >= c, min b^Ty, y >= 0

### weak duality theorem
max primary LP, min dual LP
for any solution of max LP x_0 and min LP y_0
c^Tx_0 <= b^Ty_0

### strong duality theorem
for primary LP (P) and dual LP (D) exactly one eventuality will be true:
1. neither (P) nor (D) have a feasible solution
2. (P) is unbounded, (D) has no feasible solution
3. (P) has no feasible solution, (D) is unbounded
4. (D) and (P) have both feasible solutions and also optimal x*, y* and c^Tx* = b^Ty*

### Farkas Lemma @
exactly one of the following statements is true:
1. there exists x such that Ax <= b and x >= 0
2. there exists y such that A^Ty >= 0 and b^Ty < 0, y >= 0

## 6

### cutting planes ?
Cutting plane method
We round the RHS in case LHS is all integral with integral coefficients

### subtour elimination
for each subset S without a starting position s
sum y_e <= sum x_e - 1
this forces the program to search for only one cycle, not multiple (subtours)
K_3, K_3 would never satisfy this, but C_6 yes

## 7

### matching polotype
every vertex meets at most one other vertex (perfect iff exactly one)
forall i \in V, forall (i, j) \in E:  \sum y_ij <= 1 (=)

### spanning tree polotype
\sum x_e = n-1, e \in E
\sum x_e <= |U| - 1 , e \in E[U], U \subset V, |U| >= 2 
x_e >= 0

### matroid polotype @
matroid polotype:
- convex hull of indicators, P = conv({e_i | i \in [n]})\
matroid:
- 1. empty set \in I
- 2. if X \subseteq Y and Y \in I, then X \in I
- 3. if X, Y \in I and |Y| < |X|, then \exists e \in X-Y, Y\cup {e} \in I

## 8

### koenigs theorem (matching vs. vertex cover)
if G is bipartite, then the cardinality of the maximum matching is equal to the cardinality of the minimum vertex cover

## 9

### total unimodularity
unimodular, if the matrix has det(A) = +-1
totally unimodular if each square submatrix of B has det(B) = 0,+-1

## 10

### independence systems
the empty set is independent, every subset of an independent set is independent (from matroid definition)

### matroids - axiomatic
(E,I \subseteq 2^E), previous matroid definition

### matroids - greedy
output: maximal indepdendent set in matroid
start with empty set
add heaviest (if possible)
repeat

### matroids - rank
r: 2^E -> R, r(S) = max {|Y|: Y \subseteq S & Y \in I(M)}

### properties of the rank function
rank function is always non-negative integer 0 <= r <= S
r(X) <= r(Y), X \subseteq Y
r(X\cap Y) + r(X\cup Y) <= r(X) + r(Y)

### submodular functions ?

## 11

### simplex method
pivoting
substitution
simplex tableau
cost function evaluation

### ellipsoid method
E_0 is an elipsoid containing P
c^Tx <= c^Ta_k such that P \subseteq {x: c^Tx <= c^Ta_k} (if not possible, then a_k \in P)
E_{k+1} is a minimum volume elipsoid containing E_k \cap {x: c^Tx <= c^Ta_k}
[explanation](http://math.mit.edu/~goemans/18433S09/ellipsoid.pdf)

# part B

## Definietly on the exam:

### Given an LP and a feasible solution prove that it is a basic feasible solution by identifying the corresponding basis. ?
We select some columns from the table (submatrix must not be singular)

### Write the Simplex Tableu corresponding to a given basic feasible solution. ?
Gausian elimination with basis elements having diagonal 1

### Describe and execute a pivoting step w.r.t. a given basic feasible solution and an objective function ?

### Decide if a solution is optimal or not using the Simplex Tableu. ?

### Write an IP formulation for the matching/perfect matching problem

### Write the dual of a given LP in a prescribed format.

## Subset on the exam

### Describe how to find an initial basic feasible solution for an arbitrary LP in standard (equational) form.

### Write an IP formulation for the matching/perfect matching problem.
forall i \in V, \sum y_ij = 1, (ij) \in E

### Prove that the LP relaxation of the standard IP for matching/perfect matching is integral for bipartite graphs. ?

### Provide a 2-approximation algorithm for Vertex Cover via IP relaxation and LP rounding. ?
We relax with rouding x_i >= 1/2 => 1, x_i < 1/2 => 0
Assume \sum w_i, i \in C is optimal, x_i >= 1/2 for all i \in C
\sum w_i, i \in C <= \sum w_i 2x_i, i \in C = 2 \sum w_i x_i, i \in [n] <= 2opt
[explanation p4](http://theory.stanford.edu/~trevisan/cs261/lecture07.pdf)

### Prove the max-flow min-cut theorem via LP duality
Construct dual to max-flow
[explanation](https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem)

### Prove Koenigs theorem via LP duality
primary: ()
max \sum x_i, i \in E
forall v in V: \sum x_i <= 1, i ~ v, i \in E
x_i \in {0,1}

dual: (vertex cover)
min \sum y_i, i \in V
forall (i, j) \in E: y_i + y_j >= 1
y_i \in {0, 1}

relaxation holds due to total unimodularity
[explanation](http://www.princeton.edu/~amirali/Public/Teaching/ORF523/S16/ORF523_S16_Lec6_gh.pdf)


### Prove that the incidence matrix of a bipartite graph is Totally Unimodular.
By induction. Holds for 1x1, now suppose it holds for (k-1)x(k-1), then if we add another edge and vertex (column+row), then
- it has either a column of zeroes, hence det = 0
- or contains one 1, so the determinant is +-1*smaller det
[explanation](https://theory.stanford.edu/~jvondrak/MATH233B-2017/lec3.pdf)

### Prove that a polyhedron described by a TU matrix and integral right hand side is integral.
[explanation p5](http://www.princeton.edu/~amirali/Public/Teaching/ORF523/S16/ORF523_S16_Lec6_gh.pdf)

### Prove that a given set of inequalities is valid for a given polytope. (Only the inequalities/polytopes that appear in some exercise sheet). ?

### Derive a given set of inequalities for a given polytope as cutting planes of the corresponding IP. (Only from exercise sheets) ?

### Describe how to separate over Subtour Elimination inequalities in polynomial time. ?
[explanation](http://www.cse.chalmers.se/~ptr/disopt8-2015.pdf)

### Prove that an independence system is a matroid if and only if the greedy algorithm produces correct result for all non-negative objective functions. ?

### Prove that the rank function of a matroid is submodular. ?
[Submodular function](https://en.wikipedia.org/wiki/Submodular_set_function)
[Proof p7](http://www-math.mit.edu/~goemans/18433S09/matroid-notes.pdf)