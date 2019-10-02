data Bag a = Item a | Items [Bag a]

fold:: (a->b) -> ([b] -> b) -> Bag a -> b
fold mainfunc listfunc (Item a) = mainfunc a
fold mainfunc listfunc (Items bag) = listfunc [fold mainfunc listfunc x | x<-bag ]


listy:: Bag a -> [a]
listy x = fold change concat x 

change:: a -> [a]
change a = [a]


