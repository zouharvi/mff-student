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
# create PDF integral (-inf, a)
men.p = pnorm(plot.range, mean=men.mean, sd=men.sd)
women.p = pnorm(plot.range, mean=women.mean, sd=women.sd)

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

# compute areas under curve
women.prob = women.p[plot.range == 168]-women.p[plot.range == 166]
men.prob = men.p[plot.range==165] + 1 - men.p[plot.range==200] 

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
ex4.a = men.p[plot.range == round(178 + men.sd)] - men.p[plot.range == round(178 - men.sd)]
ex4.b = women.p[plot.range == round(169 + women.sd)] - women.p[plot.range == round(169 - women.sd)]
message(paste("178 cm man: \t", round(ex4.a*100,2), "%"))
message(paste("169 cm woman: \t", round(ex4.b*100,2), "%"))
