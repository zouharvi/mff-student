data NT a = N a [NT a] 

ocisluj::NT a->NT (a,Int) 
ocisluj x = y 
        where (y,_)=ocislujSeZacatkem 1 x 

ocislujSeZacatkem :: Int -> NT a -> (NT (a,Int),Int) 
ocislujSeZacatkem x (N a p) = ((N (a,x) p1),n) 
                        where (p1,n) = ocislujpole (x+1) p 

ocislujpole :: Int -> [NT a] -> ([NT (a,Int)],Int) 
ocislujpole x [] = ([],x) 
ocislujpole x (a:as) =((b:bs),z) 
                 where (b,x1) = ocislujSeZacatkem x a 
                       (bs,z) = ocislujpole x1 as 
