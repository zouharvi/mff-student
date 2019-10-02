library(rpart)
library(rpart.plot)

best_tree = function(formula, train, test, test_true) {
	cps = 0.5^(-1:15)
	m = 0
	mi = 0
	for ( i in cps ) {
		model = rpart(formula, train, cp=i)
		predicted = predict(model, test, type='class')
		t = table(predicted, test_true)
		acc = (sum(diag(t))/length(test))
		if ( acc > m ) { m = acc; mi = i; }
	}
	print(mi)
	return(m); 
}

# best_tree(profits ~ country + category + sales + assets + marketvalue, F[data.train, 1:8], F[data.test, 1:8], F[data.test,1:8]$profits)
