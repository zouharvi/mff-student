# protein ligandability recognition
library('randomForest')

data = read.csv('plr.dataset.D.development.csv', sep='\t')
hist(data$ligand_distance)


set.seed(1); test.index = sample(30, 3, rep=F)
proteins = unique(data$protein_id)
proteins.test = proteins[test.index] 
proteins.train = proteins[-test.index] 

data.train = as.data.frame(data[data$protein_id %in% proteins.train,]) 
data.test = as.data.frame(data[data$protein_id %in% proteins.test,]) 


# plot distribution for test/train data
par(mfrow=c(2,1))
plot(cut(data.test$ligand_distance, breaks=seq(0,5.2,0.2)))
plot(cut(data.train$ligand_distance, breaks=seq(0,5.2,0.2)))

# do the distributions differ drastically?



fr = randomForest(ligand_distance ~ ., data.train, ntree=200, mtry=12)
# Mean of squared residuals (by out-of-bag data)

# compute with different (ntree, mtry) values -> table
data.predicted = predict(fr, data.test, type='response')
MSE = sum((data.predicted - data.test$ligand_distance)^2)/length(data.predicted)

# Q: Why is test MSE much higher than MSE of the out-of-bag data?
# A: Because we used different proteins.

# variable importance
varImpPlot(fr)


# HW: compare to simple decision tree (rpart)

# conclusion: it is necessary to analyze the data beforehand (the're hugely problematic)




message('doing 10 experiments, this will take a while (~3 minutes)')
experiments = integer(10)
for (i in 1:10) {
	test.index = sample(30, 3, rep=F)
	proteins = unique(data$protein_id)
	proteins.test = proteins[test.index]
	proteins.train = proteins[-test.index]

	data.train = as.data.frame(data[data$protein_id %in% proteins.train,])
	data.test = as.data.frame(data[data$protein_id %in% proteins.test,])
	
	fr = randomForest(ligand_distance ~ ., data.train, ntree=200, mtry=12)
	data.predicted = predict(fr, data.test, type='response')

	MSE = sum((data.predicted - data.test$ligand_distance)^2)/length(data.predicted)
	experiments[i] = MSE
	message(paste("iteration: ", i))
}
var(experiments)
