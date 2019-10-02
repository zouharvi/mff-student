entropy = function(x) { t = prop.table(table(x)); return(sum(-t*log2(t))); }
jointe = function(x,y) {
	t = prop.table(table(x,y));
	t = t[t!=0]
	return (sum(-t*log2(t)))
}

mutuale = function(x,y) {
	t = prop.table(table(x,y))
	tx = prop.table(table(x))
	ty = prop.table(table(y))
	s = 0
	for ( i in 1:length(tx) ) {
		for ( j in 1:length(ty) ) {
			if ((as.numeric(t[i,j]) != 0) & (as.numeric(tx[i]) != 0) & (as.numeric(ty[j]) != 0)) {
				s = s - t[i,j]*log2(tx[i]*ty[j]/t[i,j])
			}
		}
	}
	return (as.numeric(s))
}

xy = read.csv('xy.100.csv', sep='\t')

ex = entropy(xy$x)
ey = entropy(xy$y)
ei = entropy2(xy$x, xy$y)
exPy = ei - ex
eyPx = ei - ey

print("Independent?")
print(ei == ex*ey)
