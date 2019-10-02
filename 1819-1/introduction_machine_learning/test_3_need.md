### Lecture 1
- gold standard
- supervised/unsupervised learning


### Lecture 2
- covariance, correlation
- chi squared
- entropy, conditional entropy
- clustering algorithms:
- - hiearchical
- - partitional
- - - k means
- similarity
- - cosine, eucledian, manhattan, hamming
- k means algorithm
- - within cluster variation, total within cluster variation
- - centroid update, data update
- - elbow method
- hiearchical clustering
- - dendrogram
- - single, average, complete linkage (dissimilarity)


### Lecture 3
- entropy, conditional entropy
- mutual information (information gain)
- decision tree (leaves: most common value/mean)
- tree growing, treee pruning (grow large, then prune)
- more data should be better
- k fold cross validation (LOOCV)
- baseline classifier
- confusion matrix
- (sample|test|training) (error rate|accuracy)
- precision, recall, specificity (real negative), f measure
- mean square error, classification error, generalization error (true error)


### Lecture 4
- (simple|) linear regression (general formula)
- categorical values to linear regression
- gradient descent algorithm
- polynomial regression
- R^2 (coefficient of determination)
- hyperplane
- logistic regression (sigmoid function 1/(1+e^-y) )
- decision boundary


### Lecture 5
- best k for k fold CV
- bootstraping
- hypothesis testing (null hypothesis)
- alpha is a property of data, p value is property of the test
- we reject H_0 iff p value is small enough
- significance level, confidence level
- examples from p23
- confidence interval P[m - sd/sqrt(n) quantile(alpha/2) < target mean < m + sd/sqrt(n) quatnile(alpha/2) ] = 1-alpha
- t-test if we don't know the variance - same condfidence interval, just t.test quantile function for alpha and n-1 degrees of freedom 
- paired t-test


### Lecture 6
- instance based learning
- different metrics can be used
- knn classification and regression (usually mean)
- shepard's method, weighted
- locally weighted linear regression
- naive bayes classifier (naive conditional independence assumption)
- argmax_k pr(y_k) \prod pr(x_i|y_k)
- generative vs. discriminative classifier
- - gen. makes assumption about the data from samples
- - eg. Naive Bayes
- - discriminative relies on the data quality
- bayesian belief network -> K2 algorithm
- maximum likelihood estimation ?????


### Lecture 7
- impurity measure, goodness of split (decrease of purity)
- misclassification error, information gain, gini index
- stopping criteria, 
- optimal cp value
- resampling for ensemble classifiers pnorm(10, 21, 0.3) (distribution function)
- resampling, bootstraping
- bagging
- - draw K random samples and train K learners
- - combine by majority vote or mean
- boosting
- - learners have different weights
- Adaboost TODO
- unstable learning (small change in training data produces vastly different result)
- random forest
- - each tree is maximal


### Lecture 8
- support vector machines
- - find optimal hyperplane
- - data is lineary separable if there exists such hyperplane
- - support vectors are the instances touching the supporting hyperplane 
- - large margin classifier
- - add fake eg. polynomial variables 
- - large vs. soft margin classifier
- ROC (TPR on FPR)


### Lecture 9
- curse of dimensionality
- feature ranking
- information gain, gini index, chi-squared, correlaction coefficient
- can be produced by adaboost, random forest
- bayes classifier provides the limit to optimal
- - same feature vectors, different target values
- pearsons chisq test
- - test of independence
- - goodness of fit test
- - test of homogenity
- sum of k independent standard normal variables
- chisq distribution
- - degrees of freedom
- - \sum (observed_i - expected_i)^2/expected_i


### Lecture 10
- generalization vs training error
- bias variance tradeoff
- - for knn: higher k, lower variance, larger bias
- regularization
- - minimize classical loss function + penalty
- ridge
- - penalty = omega_1^2 + omega_2^2 + ..
- - can't shrink to zero
- lasso
- - penalty = |omega_1| + |omega_2| + ..
- - can eliminate completely
- elastic net
- - combination of both
- soft margin svm is equivalent to regularization ???