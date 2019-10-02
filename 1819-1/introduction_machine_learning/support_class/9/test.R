### 3a
NO_TRIALS = 10000000
res3a = mean(rnorm(NO_TRIALS, sd=sqrt(100), mean=180.3) < rnorm(NO_TRIALS, sd=sqrt(50), mean=167.2))
message(res3a)

### 3b
di = rnorm(NO_TRIALS, sd=sqrt(100), mean=180.3) - rnorm(NO_TRIALS, sd=sqrt(50), mean=167.2)
plot(density(di))
