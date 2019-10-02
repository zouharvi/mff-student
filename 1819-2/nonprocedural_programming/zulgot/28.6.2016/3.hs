--použít fold na funkci, která drží dvojici [pocet, pismeno] a pismeno
-- pokud jsou pismena stejný, výsledek je [pocet +1, pismeno]
-- pokud jsou jiný, výsledek je [0, nove_pismeno]
-- Spíš by měla držet seznam dvojic a operovat jen s poslední dvojicí

comp:: Tuple -> Char -> [Tuple]
comp (c, n) c2 
    | c==c2 = [(c,n+1)]
    | c/=c2 = [(c2, 1),(c,n)]

eval:: String -> [Either Char Tuple]
eval x = map vypis (foldl counter [] x)

counter:: [Tuple] -> Char -> [Tuple]
counter x c2
	| x==[] = comp (c2,0) c2 
	| otherwise = reverse ((comp (head (reverse x)) c2) ++ (tail (reverse x)))


type Tuple = (Char, Int)

vypis:: Tuple -> Either Char Tuple
vypis (c,n) 
	| n==1 = Left c
	| n>1 = Right (c,n)


otherway:: [Either Char Tuple] -> String
otherway x = concat (map cti x)

cti:: Either Char Tuple -> [Char]
cti (Right (c,0)) = []
cti(Right (c,n)) = c: cti( Right (c,n-1))
cti (Left a) = [a]


