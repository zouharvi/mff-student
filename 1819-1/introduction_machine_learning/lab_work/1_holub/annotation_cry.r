# load data

cry.A = read.csv("cry-A.csv", header = F, sep = ";", col.names = c("id", "class", "void"))
cry.A$void = NULL
# str(cry.A$class)
table(cry.A$class)

# plot summary

Atc = table(cry.A$class)
barplot(Atc, main = "Annotated cry disambiguation", col = rainbow(ncol(Atc)), ylim = c(0, max(Atc)+10))
# (barplot(Atc) works just fine)


# compute inter annotator agreement
cry.B = read.csv("cry-B.csv", header = F, sep = ";", col.names = c("id", "class", "void"))
cry.B$void = NULL

cry.B = data.table(cry.B)
cry.A = data.table(cry.A)
setkey(cry.A)
setkey(cry.B)

setnames(cry.AB, c("id", "A", "B"))
ABt = table(cry.AB[, c(2,3), with = F])

total = sum(ABt)
agree = 0
for (i in 1:ncol(ABt) ) { 
	for (j in 1:nrow(ABt) ) {
		if ( i == j ) { agree = agree + ABt[i, j] } 
	}
}
IAA = agree/total
cat("IAA: ", IAA, "\n")
