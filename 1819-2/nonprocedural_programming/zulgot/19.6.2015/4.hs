data NT a = N a [NT a]

vypis:: [NT a] -> [a]
vypis []=[]
vypis ((N a b):xs)= [a] ++ (vypis b) ++ (vypis xs)

komplet:: NT a -> [a]
komplet x = vypis [x]
