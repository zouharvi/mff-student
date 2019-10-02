#######
# HW1 #
#######

M = 400

# declare a new Mx6 array filled with zeroes
p = matrix(0, M, 6)

# p[m, k] = probability of getting k distinct numbers on m dice
# fill in trivial case
p[1,1] = 1

for(m in 2:M) {
    for(k in 1:6) {
        # avoid underindexing
	if(k > 1) {
            # we already chose k-1 different numbers, the last one has to be different as well
            p[m,k] = p[m-1, k-1] * (6 -(k-1)) / 6
	}
	# we already chose k different numbers, so just make sure the last one is one of the k
        p[m,k] = p[m,k] + p[m-1,k] * k / 6
    }
}

"P[m,k] table with row margin sums:"
addmargins(p, 2)


# Do we need to get all six numbers in the same throw?

# A) yes
prob = p[6,6]
nprob = 1-prob
vec = 1:100000
e = sum(vec * prob * nprob^(vec -1))
e 
# easier way is to just 1/prob (about 64)

# B) no, we just want to see every number at least once
# run 10^4 tests
s = 0
for(i in 1:10^4) {
    features = matrix(0, 6)
    pos = 0
    while(sum(features) != 6) {
        features[sample(1:6, 1)] = 1
        pos = pos + 1
    }
    s = s + pos
    features
}
s/10^4
# about 14.65


#######
# HW2 #
#######

# we already have the required table for m <= M

# phantom plot
plot(
    matrix(1:M, 6, M),
    p,
    xlab="Number of throws (m)",
    ylab="Probability of k distinct (by color)",
    type='n',
)
# add colored lines
for(i in 1:6) {
    lines(1:M, p[,i], col=rainbow(6)[i])
}
# add legend
legend("right", legend=1:6, col=rainbow(6), pch=1)
