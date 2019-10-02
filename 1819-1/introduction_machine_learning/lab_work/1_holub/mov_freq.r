examples = read.csv('mov.development.csv', sep='\t')

a = apply(examples[,c(11:28)], 2, sum) # apply sum on each column on feature columns

b = table(sort(a)) # create frequency table from a

b # show

