data Btree a = Nill | Node (Btree a) a (Btree a )

fold:: b-> (b->a->b->b) -> Btree a -> b
fold b func Nill = b
fold b func (Node l a r) = func (fold b func l) a (fold b func r)

listy:: b->a->b->b
listy l a r 
	| l==0, r==0 = 1
	| (l/=0 || r/=0) = r+l

hloubka:: b->a->b->b
hloubka l a r = (l/=0 || r/=0) = (max r l)+1
