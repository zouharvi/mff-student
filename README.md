# prolog-knn
Simple k-nearest neighbors algorithm (KNN) implementation in Prolog for points on the plane.

# User Documentation
To run a K-NN algorithm with parameter K on some point P simply use `knn(K, P, Class)`, provided that you specified data points using the `p` facts before. For the whole usecase see [Example](#example). The other way of using this program is to provide a dataset represented in a list of terms with the `of` topmost operator (see [Constraints](#constraints)). The usage is very straightforward: `knn(Dataset, K, P, Class)`. Euclidean distance is used for computing nearest neighbours.


# Example
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


### Constraints 

Data points are numeric and can be of any dimensions, but the number of such dimensions must be constant within the dataset. In Prolog this means, that all points are lists (of the same size) of numbers. Target classes must be nonvar.

### Accuracy

Choosing the proper hyperparameter is out of scope of this project, but in practice this would be tackled with weighted KNN and in case of regression KNN locally weighted regression.

# Technical documentation

### Usages

The first usage (implicit dataset) uses `bagof` and the other `knn` function call to succeed. From this point on, they are equivalent.

### Flow

The program generally proceeds in the following order:

1. Check for data validity
2. Data sorted by distance (merge sort)
3. K nearest neighbours (and classes) are extracted
4. Most frequent class is found


### Misc

To fulfill the main functionality, several other helper functions are included:

- `diff_square` computes variance between datapoints and baseline
- `take` selects first `N` elements from a list
- `count` counts the number of occurences of a term in a list
- `freqs` computes frequency of terms in a list
- `most_frequent` extracts the most frequent term in a list
