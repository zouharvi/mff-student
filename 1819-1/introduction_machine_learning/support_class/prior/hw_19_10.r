# input 
men.mean = 180.3
men.sd = sqrt(100)
women.mean = 167.2
women.sd = sqrt(50)

###############
# EXCERCISE 3 #
###############

# for symetric plot, create range roughly around the center of mass
# create plotting range with fine increments
plot.com = round((men.mean+women.mean)/2)
plot.var = 50
plot.increment = 0.00005
plot.range = seq(plot.com-plot.var, plot.com+plot.var, plot.increment)

# create density distribution function
men.d = dnorm(plot.range, mean=men.mean, sd=men.sd)
women.d = dnorm(plot.range, mean=women.mean, sd=women.sd)

# plot first women because of lower variance, then add men
plot(plot.range, women.d, type='l', main="PDF (density) of average height (cm)", ylab='probability density', xlab='height (cm)')
lines(plot.range, men.d)

# pick indexes satisfying given condition + generate and plot polygon
women.condition = plot.range >= 166 & plot.range <= 168
women.polygon_x = c(166, plot.range[women.condition], 168)
women.polygon_y = c(0, women.d[women.condition], 0)
polygon(x=women.polygon_x, y=women.polygon_y, col='red')

# condition is noncontinuous
men.condition_1 = plot.range < 165 
men.condition_2 = plot.range > 200
men.polygon_1_x = c(plot.com-plot.var, plot.range[men.condition_1], 165)
men.polygon_1_y = c(0, men.d[men.condition_1], 0)
men.polygon_2_x = c(200, plot.range[men.condition_2], plot.com+plot.var)
men.polygon_2_y = c(0, men.d[men.condition_2], 0)
polygon(x=men.polygon_1_x, y=men.polygon_1_y, col='blue')
polygon(x=men.polygon_2_x, y=men.polygon_2_y, col='blue')

# area estimation (the lower the delta, the closer to actual integral it is)
pseudo_integrate = function(ys, delta) {
	s = 0
	for (i in 3:(length(ys)-1)) {
		s = s + delta*(ys[i-1]+ys[i])/2
	} 
	return(s)
}

# compute areas under curve
women.prob = pseudo_integrate(women.polygon_y, plot.increment)
men.prob = pseudo_integrate(men.polygon_1_y, plot.increment) + pseudo_integrate(men.polygon_2_y, plot.increment)

# format legend
legend("topright",
	legend=c(
		paste("Men ℝ \\ (166, 199) prob:\t", round(men.prob*100,2), "%"),
		paste("Women (166, 168) prob:\t", round(women.prob*100, 2), "%")),
	col=c("blue", "red"),
	pch=c(19,19)
)

###############
# EXCERCISE 4 #
###############
ex4.var = 0.005
ex4.a = pseudo_integrate(men.d[plot.range > 178-ex4.var & plot.range < 178+ex4.var], plot.increment)
ex4.b = pseudo_integrate(men.d[plot.range > 169-ex4.var & plot.range < 169+ex4.var], plot.increment)
print(ex4.a/ex4.b)
