
```{r, echo=TRUE, warning=FALSE}
mod.rf = function(train, test, iteration, ntree, mtry, nodesize, maxnodes) {
  # switch to factor to mak randomForests do classification
  train$class = as.factor(train$class)
  test$class = as.factor(test$class)
  
  model = randomForest(class ~ ., train,
                       ntree=ntree, mtry=mtry, nodesize=nodesize, maxnodes=maxnodes)
  trp = predict(model, train, type='response')
  tep = predict(model, test, type='response')
  
  train$class = as.numeric.factor(train$class)
  test$class = as.numeric.factor(test$class)
  trer = mean(abs(train$class-as.numeric.factor(trp)))
  teer = mean(abs(test$class-as.numeric.factor(tep)))
  return(c(teer, trer))
}
# each takes about 1 minute to compute with CV=10
# ntree, mtry, nodesize, maxnodes
CV('Random forests (200, 20, 5, 100)', 'er',
   function(a, b, i) { return(mod.rf(a, b, i, 200, 20, 5, 100)); })
CV('Random forests (200, 20, 5, 100)', 'er',
   function(a, b, i) { return(mod.rf(a, b, i, 200, 20, 5, 100)); })
CV('Random forests (400, 50, 5, 200)', 'er',
   function(a, b, i) { return(mod.rf(a, b, i, 400, 30, 5, 200)); })
```


## KNN
### Unweighted
```{r, echo=TRUE}
mod.knn = function(train, test, iteration, k) {
  test_class = test$class
  test$class = NULL
  train_class = train$class
  train$class = NULL
  teer = mean(abs(as.numeric.factor(knn(train, test, train_class, k=k))-test_class))
 # trer = mean(abs(as.numeric.factor(knn(train, train, train_class))-train_class))
  return(c(teer, 0))
}
CV('KNN (k=5)', 'er', function(a, b, c) { mod.knn(a, b, c, 5) })
CV('KNN (k=15)', 'er', function(a, b, c) { mod.knn(a, b, c, 15) })
CV('KNN (k=35)', 'er', function(a, b, c) { mod.knn(a, b, c, 35) })
```

### Weighted
We should probably normalize the data (scale function)
```{r, echo=TRUE}
mod.knnw = function(train, test, iteration, k) {
  teer = mean(abs((kknn(class ~ ., train=train, test=test, k=k)$CL - test$class)))
  return(c(teer, 0))
}
CV('Weighted KNN (k=5)', 'er', function(a, b, c) { mod.knnw(a, b, c, 5) })
CV('Weighted KNN (k=15)', 'er', function(a, b, c) { mod.knnw(a, b, c, 15) })
CV('Weighted KNN (k=35)', 'er', function(a, b, c) { mod.knnw(a, b, c, 35) })
```

