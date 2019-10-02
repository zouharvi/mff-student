# load the dataset
data = read.csv('test1.eval.anonymous.csv', sep='\t', header=TRUE)
data = data[data$Eval != '',]

# compute associated p values
chi_indp = function(title, A, B) {
	A = as.numeric(A)
	B = as.numeric(B)
	A.p = prop.table(table(A))
	B.p = prop.table(table(B))
	
	expected = A.p %*% t(B.p) * length(A)
	chi.2s = sum((table(A, B) - expected)^2/ expected)

	pv = (1-pchisq(chi.2s, df = 2))*100
	message(title)
	message('p-value: ', round(pv,2), '%')
	message()
}

chi_indp('Eval-Version', data$Eval, data$Version)
chi_indp('Eval-Review', data$Eval, data$Review)
chi_indp('Eval-Course', data$Eval, data$Course)
chi_indp('Eval-Gender', data$Eval, data$Gender)
chi_indp('Eval-X3b', data$Eval, data$X3b)
chi_indp('Eval-X3a', data$Eval, data$X3a)
chi_indp('Eval-X1b', data$Eval, data$X1b)

# prediction 
library(rpart)
CV_SIZE = 8
test.index = sample(1:nrow(data), nrow(data)/CV_SIZE)
data.train = data[-test.index, ]
data.test = data[test.index, ]

# default cp
model = rpart(Eval ~ ., data.train)
pr = predict(model, data.test, type='class')
er = mean(pr != data.test$Eval)
message('Default cp error rate: ', round(er,2), '%')


# optimal cp
default = rpart(Eval ~ ., data.train, cp=NA)
cpt = default$cptable[, c(1,4)]
cp = cpt[cpt[,2] <= min(cpt[,2])+sd(cpt[,2])][[1]]
pr = predict(default, data.test, type='class')
er = mean(pr != data.test$Eval)
message('Overfit cp error rate: ', round(er,2), '%')

model = rpart(Eval ~ ., data.train, cp = cp)
pr = predict(model, data.test, type='class')
er = mean(pr != data.test$Eval)
message('Optimal cp error rate: ', round(er,2), '%')

#model = randomForest(Eval ~., data.train, na.action=na.exclude)
#pr = predict(model, data.test, type='class')
#er = mean(pr != data.test$Eval)
#message('Random forest error rate: ', round(er,2), '%')

# attribute pruning
library(FSelector)
message('\n\nPruned attributes:')
print(cutoff.k(gain.ratio(Eval ~., data[10:24]), k=3))
print(cutoff.k(gain.ratio(Eval ~., data[10:24]), k=1))


# new prediction
message('\n\nPrediction with pruned attributes:')
data = data[c('X3b', 'X3a', 'X1b', 'Eval')]
data.train = data[-test.index, ]
data.test = data[test.index, ]

model = rpart(Eval ~ ., data.train)
pr = predict(model, data.test, type='class')
er = mean(pr != data.test$Eval)
message('Default cp error rate: ', round(er,2), '%')

default = rpart(Eval ~ ., data.train, cp=NA)
cpt = default$cptable[, c(1,4)]
cp = cpt[cpt[,2] <= min(cpt[,2])+sd(cpt[,2])][[1]]
pr = predict(default, data.test, type='class')
er = mean(pr != data.test$Eval)
message('Overfit cp error rate: ', round(er,2), '%')

model = rpart(Eval ~ ., data.train, cp = cp)
pr = predict(model, data.test, type='class')
er = mean(pr != data.test$Eval)
model = rpart(Eval ~ ., data, cp = cp)
pr = predict(model, data, type='class')
er = mean(abs(pr - data$Eval))
message('Optimal cp error rate: ', round(er,2), '%')


# chi-squared

# die
a = c(5, 8, 1, 15, 10, 1)^2/100
ch2 = sum(a)
pv = (1-pchisq(ch2, df=5))*100

# classifier
b = c(3, 3)^2
b = b/c(78, 22)
ch2 = sum(b)
pv = (1-pchisq(ch2, df=1))*100
