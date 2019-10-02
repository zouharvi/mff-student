source('load-mov-data.R')
cat(rep('\n', 100)) # clear screen

##########
# PART 1 #
##########

# ... vectors of features
normalize = function(...) {
	return( prop.table(table(list(...))) )
}

# x: normalized vector of probabilities (eg. by normalize)
entropy_simple = function(x) {
	return( -sum(x*log2(x), na.rm =T) )
}

exOcc = examples$occupation
exRat = examples$rating
hRatPOcc = entropy_simple(normalize(exOcc, exRat)) - entropy_simple(normalize(exRat))
message('PART1:\n\nH(OCCUPATION|RATING): ', hRatPOcc, '\n\n\n')


##########
# PART 2 #
##########

mov67tab = table(examples$movie)
mov67nam = names(mov67tab[mov67tab == 67])
mov67 = examples[examples$movie %in% mov67nam, c(3,9)]
# remove (year) suffix
mov67$title = sapply(as.character(mov67$title),
	FUN=function(row) {
		mov_title = paste(head(strsplit(row, ' ')[[1]], -1), collapse=' ')
		return(mov_title)
	})
# word wrap, remove ', The' suffix
mov67$title = sapply(mov67$title,
	FUN=function(row) {
		interm = row 
		if(endsWith(row, ", The")) {
			interm = substr(row, start=1, stop =nchar(row)-5)
		}
		return(paste(strwrap(interm, width=18), collapse='\n'))
	})

# bring back order
mov67$title = with(mov67,factor(title,levels=unique(title)))

# add more space
op = par(mar = c(10, 4, 4, 2) + 0.1)

# actuall plotting
boxplot(rating ~ title, mov67, las=2, cex.axis=0.8, main='Movies rated 67 times')
points(x=1:length(unique(mov67$title)),
       y=aggregate(rating ~ title, mov67, mean)$rating,
       col='red',
       pch=20)

# restore graphing parameters
par(op)

message('PART2:\n\n(graph)\n\n\n')


##########
# PART 3 #
##########

users[,c('ONE', 'TWO', 'THREE', 'FOUR', 'FIVE')]=0

# go through all examples
apply(examples[,c(2,3)], 1, function(x) {
	u = as.numeric(x[1])
	r = 5 + as.numeric(x[2])
	users[u, r] <<- users[u, r] + 1
});

# same column indexes are coincidential
users[,6:10] = round(
	cbind(
		users[6:10],
		prop.table(as.matrix(users[6:10]), margin = 1)
	)[6:10],2)

ddg = hclust(dist(users[,c(2, 6:10)]), method='average')
uCluss = cutree(ddg, 20)

# assign do original data frame
users$cluss = cutree(ddg, 20)

# create new data frame
cluss = data.frame(no_users=as.vector(table(users$cluss)))
cluss$age = round(aggregate(age ~ cluss, users, mean)$age,2)

# doesn't omit the first one from either side
duplicities = users[duplicated(users[,c(2,6:11)]) | duplicated(users[,c(2,6:11)], fromLast=T),]

message('PART3:\n\nClusters:')
print(cluss)

cat('\nDuplicates: ')
print(table(factor(duplicities$cluss, levels=1:20)))
