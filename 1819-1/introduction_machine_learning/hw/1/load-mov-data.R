#################################################################################
#################################################################################

### R code for loading the MOV data

### Barbora Hladka, Martin Holub

### ESSLLI 2015

### http://ufal.mff.cuni.cz/esslli2015

#################################################################################
#################################################################################
#################################################################################

examples <- read.csv("mov.development.csv", sep="\t")

## convert timestamp to date object
examples$timestamp <- as.POSIXct(examples$timestamp, origin="1970-01-01")
names(examples)

## get votes
votes <- examples[,c(2,1,3,4)]
names(votes)

## get users
u <- unique(examples[,c(2,5:8)])
attach(u)
users <- u[order(user),]
detach(u)
names(users)

## get movies
movies <- unique(examples[,c(1,9:33)])
names(movies)


