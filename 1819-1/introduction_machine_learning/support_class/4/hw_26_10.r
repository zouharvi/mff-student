#######
# HW1 #
#######

# analytically:
# idea: choose without order two women and two men, then add order (to positive as well as all outcomes)
pA = choose(7,2)*choose(10,2)*factorial(2)*factorial(2)/(choose(12,4)*factorial(4))
# (7 * 6  * 10 * 9)  / (12 * 11 * 10 * 9)

# simulation:
SIM_SIZE = 10^5
mS = matrix(0, SIM_SIZE)
mS = sapply(mS, function(row) return(sample(1:12, 4, rep=F)))
pS = sum(mS[1,] <= 7 & mS[3,] <= 7)/SIM_SIZE

# result:
message('HW1:')
message(paste('pA: ', round(pA*100,2), '%'))
message(paste('pS: ', round(pS*100,2), '%'))
message('\n')


#######
# HW2 #
#######

# brute force simulation:
SIM_SIZE = 10^5
mS = matrix(0, SIM_SIZE)
mS = sapply(mS, function(row) {
	se = sample(1:6, 6, rep=T)
	return (
		se[1] <= se[2] &
		se[2] <= se[3] &
		se[3] <= se[4] &
		se[4] <= se[5] &
		se[5] <= se[6]
	)}
);
pS = sum(mS)/SIM_SIZE

# can be computed using dynamic programming (already appeared in one of the first classes)
# seD[i,j] = number of nondecreasing sequences ending with rolling j on i-th throw
MAX_THROWS = 6
seD = matrix(nrow = MAX_THROWS, ncol = 6)
seD[1,] = rep(1, 6)
for(i in 2:MAX_THROWS) {
	for(j in 1:6) {
		seD[i,j] = sum(seD[i-1, 1:j])
	}
}
pD = sum(seD[MAX_THROWS,])/6^MAX_THROWS


message('HW2:')
message(paste('pS: ', round(pS*100,2), '%'))
message(paste('pD: ', round(pD*100,2), '%'))
message('\n')
