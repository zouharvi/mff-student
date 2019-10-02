library(HSAUR)
library(rpart)

forbes = Forbes2000
forbes$profits[is.na(forbes$profits)] = 0				# replace NAs by 0
forbes$profits = factor(forbes$profits > 0.2)			# make binary category

set.seed(123); s = sample(1:2000)						# random index sample
train = s[1:1000]
test  = s[1001:2000]

write.table(forbes[train, 2:8], "forbes.train.csv", sep="\t", row.names=F)
write.table(forbes[test,  2:8], "forbes.test.csv",  sep="\t", row.names=F)

