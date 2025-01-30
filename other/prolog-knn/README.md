# prolog-knn
Simple k-nearest neighbors algorithm (KNN) implementation in Prolog for points on the plane. It can be used to predict classes, average values and averages in multidimensional space.

# User Documentation
To run a K-NN algorithm with parameter K on some point P simply use `knn(K, P, Result)`, provided that you specified data points using the `p` facts before. For the whole usecase see [Example of Classification](#example-classification) or [Example of Regression](#example-regression). The other way of using this program is to provide a dataset represented in a list of terms with the `of` topmost operator (see [Constraints](#constraints)). The usage is very straightforward: `knn(Dataset, K, P, Result)`. Euclidean distance is used for computing nearest neighbours.


# Example Classification
In this example the data points in a matrix are represented using the `p` facts and the `of` operator.

```
p([1,1] of a).
p([1,3] of a).
p([1,7] of b).
p([2,2] of a).
p([2,3] of a).
p([2,5] of b).
p([3,2] of a).
p([4,1] of a).
p([4,5] of c).
p([4,6] of b).
p([4,7] of b).
p([5,5] of b).
p([5,6] of c).
p([6,2] of b).
p([6,5] of c).
p([6,6] of c).
p([7,1] of b).
p([7,6] of c).
```

This dataset is depicted in the following figure:

```
  1 2 3 4 5 6 7
  -------------
1|a . a 1 . . b|
2|. a a . b . .|
3|. a . . . . .|
4|a . . . c b b|
5|. . . . b c .|
6|. b . 3 c c .|
7|b 2 . . . c .|
  -------------
```

Running several queries for points of interest (denoted with a number) we obtain class predictions:
```
?- knn(4, [1,4], Class).
Class = a.

?- knn(8, [7,2], Class).
Class = c.

?- knn(4, [4,6], Class).
Class = c.
```


# Example Regression
In this example the data points in a matrix are used to predict vector of real values.

```
p([1,1] of [9, -6]).
p([1,3] of [7, -5]).
p([1,7] of [4, -2]).
p([2,2] of [8, -5.2]).
p([2,3] of [6, -3.1]).
p([2,5] of [5, -2]).
p([3,2] of [6, -3]).
p([4,1] of [5, -2.1]).
p([4,5] of [4, -2]).
p([4,6] of [3, 0]).
p([4,7] of [3, 0.1]).
p([5,5] of [2, 2]).
p([5,6] of [1, 4]).
p([6,2] of [4, 8]).
p([6,5] of [1, 5]).
p([6,6] of [1, 2.7]).
p([7,1] of [4, 5.7]).
p([7,6] of [0, 20]).
```

This dataset is depicted in the following figure (only the first dimension):

```
  1 2 3 4 5 6 7
  -------------
1|9 . 7 B . . 4|
2|. 8 6 . 5 . .|
3|. 6 . . . . .|
4|5 . . . 4 3 3|
5|. . . . 2 1 .|
6|. 4 . C 1 1 .|
7|4 A . . . 0 .|
  -------------
```

Running several queries for points of interest (denoted with a capital letter) we obtain class predictions:
```
?- knn(4, [1,4], R).
R = [6.5, -3.825].

?- knn(8, [7,2], R).
R = [2.875, 4.7875].

?- knn(5, [4,6], R).
R = [2.6, 0.82].
```


### Constraints 

Data points are numeric and can be of any dimensions, but the number of such dimensions must be constant within the dataset. In Prolog this means, that all points are lists (of the same size) of numbers. Target classes must be nonvar. Regression is used if target values are numeric and multidimensional in case they are all lists of numbers.

### Accuracy

Choosing the proper hyperparameter is out of scope of this project, but in practice this would be tackled with weighted KNN and in case of regression KNN locally weighted regression.

# Technical documentation

### Usages

The first usage (implicit dataset) uses `bagof` and the other `knn` function call to succeed. From this point on, they are equivalent.

### Flow

The program generally proceeds in the following order:

1. Check for data validity
2. Data sorted by distance (merge sort)
3. K nearest neighbours (and target data) are extracted
4. Result is interpolated from closest data


### Misc

To fulfill the main functionality, several other helper functions are included:

- `diff_square` computes variance between datapoints and baseline + various other list operations
- `closer` is usesed as a distance comparator between datapoints
- `take` selects first `N` elements from a list
- `count` counts the number of occurences of a term in a list
- `freqs` computes frequency of terms in a list
- `most_frequent` extracts the most frequent term in a list
- `transp` transpose a matrix
- `interpolate` interpolates data based on targets