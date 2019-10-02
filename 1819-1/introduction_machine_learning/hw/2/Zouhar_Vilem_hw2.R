library(ISLR)
library(e1071)
library(class)
library(rpart)
library(rpart.plot)
library(crossval)

#################
# preprocessing #
#################
d = Auto
# Auto$is_american default (otherwise linearly dependent and thus results in NA in logR)
d$is_european = ifelse(d$origin == 2, 1, 0)
d$is_japanese = ifelse(d$origin == 3, 1, 0)
d$origin = d$name = NULL

#######
# 1.1 #
#######
lmres1 = lm(formula = mpg ~ ., data = d)
print(lmres1)

#######
# 1.2 # 
#######

# lm needs sorted input
sorted = d[order(Auto$acceleration), ]

# plot the base graph
plot(sorted$acceleration, sorted$mpg,
	xlab = 'acceleration',
	ylab = 'mpg',
	main = 'mpg from acceleration polynomial regression')

MAX_DEGREE = 5 
COLORS = rainbow(MAX_DEGREE, end = 0.8, v = 0.9)

# perhaps the `outer` would work just fine, but this is much simpler
for(i in 1:MAX_DEGREE) {
	lmres2 = lm(
		formula = mpg ~ poly(acceleration, i),
		data = sorted)
	predMPG = predict(lmres2)
	points(sorted$acceleration, predMPG, type='l', lwd=1.5, col=COLORS[i])
	# this could also be computed via `rsq = function (x, y) cor(x, y) ^ 2`
	message(paste("Degree", i, "R^2:", summary(lmres2)$r.squared))	
}

legend("topleft",
	legend = c(1:MAX_DEGREE),
	col = COLORS,
	lty = 1,
	lwd = 2,
)


#######
# 2.1 #
#######
sum(d$mpg==median(d$mpg))
d$mpg01 = ifelse(d$mpg > median(d$mpg), 1, 0)
d$mpg = NULL
mpg01.prop = prop.table(table(d$mpg01))
message('Entropy: ', -sum(mpg01.prop * log2(mpg01.prop)))


#######
# 2.2 #
#######
set.seed(054)
random = sample(1:nrow(d), nrow(d))
d.train = d[random[1:(nrow(d)*0.8)],]
d.test = d[-random[1:(nrow(d)*0.8)],]


#######
# 2.3 #
#######
MFC.val = as.numeric(names(sort(table(d.train$mpg01),decreasing=T)[1]))
MFC.acc = sum(d.test$mpg01 == MFC.val)/nrow(d.test)
message('MFC accuracy: ', MFC.acc)


#######
# 2.4 #
#######
lmres3 = glm(
	formula = mpg01 ~ .,
	data = d.train,
	family = 'binomial')
d.train.pmpg = ifelse(
	predict(
		lmres3,
		type = 'response', 
		newdata = d.train
	) > 0.5,
	1, 0)
d.train.pmpg.err = mean(abs(d.train.pmpg - d.train$mpg01))

d.test.pmpg = ifelse(
	predict(
		lmres3,
		type = 'response', 
		newdata = d.test
	) > 0.5,
	1, 0)

d.test.pmpg.cv = table(d.test.pmpg, d.test$mpg01)
d.test.pmpg.err = (d.test.pmpg.cv[1,2] + d.test.pmpg.cv[2,1])/nrow(d.test)

lmres3 = glm(
	formula = mpg01 ~ .,
	data = d.train,
	family = 'binomial')

lm.train.pred = predict(
	lmres3,
	type = 'response', 
	newdata = d.train)
lm.train.pred = ifelse(lm.train.pred > 0.5, 1, 0)

lm.test.pred = predict(
	lmres3,
	type = 'response', 
	newdata = d.test)
lm.test.pred = ifelse(lm.test.pred > 0.5, 1, 0)

message('Logistic regression test error rate:  ', mean(abs(lm.test.pred - d.test$mpg01)))
message('Logistic regression train error rate: ', mean(abs(lm.train.pred - d.train$mpg01)))
print(table(lm.test.pred, d.test$mpg01))
print(lmres3)

#######
# 2.5 #
#######
as.numeric.factor <- function(x) {as.numeric(levels(x))[x]}

# name already omitted
trm.default = rpart(mpg01 ~ ., d.train, method='class', cp=NA)
rpart.plot(trm.default)
message('Decision tree (min cp) train error rate: ',
	mean(abs(as.numeric.factor(predict(trm.default, d.train, type='class')) - d.train$mpg01)))
message('Decision tree (min cp) test error rate:  ',
	mean(abs(as.numeric.factor(predict(trm.default, d.test, type='class')) - d.test$mpg01)))

# tune cp
trm.cpt = trm.default$cptable[, c(1,4)]
trm.optimal_cp = trm.cpt[trm.cpt[,2] <= min(trm.cpt[,2]) + sd(trm.cpt[-1,2])][[1]]

trm.optimal = rpart(mpg01 ~ ., d.train, cp=trm.optimal_cp, method='class') 
rpart.plot(trm.optimal)

message('Decision tree (optimal cp) train error rate: ',
	mean(abs(as.numeric.factor(predict(trm.optimal, d.train, type='class')) - d.train$mpg01)))
message('Decision tree (optimal cp) test error rate:  ',
	mean(abs(as.numeric.factor(predict(trm.optimal, d.test, type='class')) - d.test$mpg01)))

#######
# 2.6 #
#######
# for some reason, naiveBayes requires output variable to be a factor
d.train$mpg01 = as.factor(d.train$mpg01)
d.test$mpg01 = as.factor(d.test$mpg01)
nbm = naiveBayes(mpg01 ~ ., data=d.train)
nbm.test.pred  = as.numeric(predict(nbm, d.test))
nbm.train.pred = as.numeric(predict(nbm, d.train))
# return to numeric
d.train$mpg01 = as.numeric(d.train$mpg01)
d.test$mpg01 = as.numeric(d.test$mpg01)
message('Naive Bayes test error rate:  ', mean(abs(nbm.test.pred - d.test$mpg01)))
message('Naive Bayes train error rate: ', mean(abs(nbm.train.pred- d.train$mpg01)))
nbm.test.cm = table(nbm.test.pred, d.test$mpg01)
print(nbm.test.cm)
nbm.test.tp = nbm.test.cm[1,1]
nbm.test.tn = nbm.test.cm[2,2]
nbm.test.fp = nbm.test.cm[2,1]
nbm.test.fn = nbm.test.cm[1,2]
message('Naive Bayes precision: ', nbm.test.tp/(nbm.test.tp+nbm.test.fp))
message('Naive Bayes recall:    ', nbm.test.tp/(nbm.test.tp+nbm.test.fn))


#######
# 2.7 #
#######
KNN_CV_FOLDS = 8
MAX_NEIGHBOURS = 300

knnCV = function(k) {
	knnFun = function(train.x, train.y, test.x, test.y, k) {
		pred.knn = knn(train.x, test.x, train.y, k=k)
		return(confusionMatrix(test.y, pred.knn, 0))
	}
	return(crossval(knnFun,
		subset(d, select = -c(mpg01)), # drop mpg01
		d$mpg01,
		K=KNN_CV_FOLDS,
		k=k,
		verbose=FALSE))
}

perK = function(k){
	stat = knnCV(k)
	stat.all = sum(stat$stat)
	stat.diag = stat$stat["TP"] + stat$stat["TN"]
	return(1-(stat.diag/stat.all))
}

erPerK = sapply(1:MAX_NEIGHBOURS, perK)
plot(erPerK, type='l', xlab='k', ylab='error rate')
