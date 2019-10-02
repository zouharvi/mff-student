# 2.e
mean(sapply(1:10000, function(i) {
	# 1 - hearts, 0 otherwise
	cards = sample(c(rep(0, 24), rep(1, 8)), 32)[1:24]
	resC = sapply(1:20, function(i) sum(sample(cards, 2)))
	p_a = 12 * mean(resC)
	r_a = sum(cards)
	return(r_a-p_a)
}))

# 3.a
f = function(x) { if(x >= 1) { return(2/x^3);}  else { return(0); } }
F = function(x) { return(1-1/x^2); }

x = seq(1, 20, 0.001)
y = sapply(x, f)
Y = sapply(x, F)

plot(x, y, type='l')
polygon(c(1, x[x<5], 5),  c(0, y[x<5], 0), col="red")

# 3.e
U = function() sample(seq(10^-6, 1, 10^-6), 1)
X = function(u) 1/sqrt(1-u)

trial = function(n) {
	resX = sapply(1:n, function(i) X(U()))
	# drop results > 20, this is not correct, but makes the graph more readable
	resX = resX[resX < 20]
	plot(ecdf(resX), do.points=FALSE,
		main=paste('empirical cdf vs. theoretical cdf (n = ', n, ')'))
	lines(x, Y, type='l', col='red')
	message(n, ' : ',  mean(resX))
}
trial(20)
trial(100)
trial(1000)
