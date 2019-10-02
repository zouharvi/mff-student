type Edges = [(Char, Char)]
type Verticies a = [(Char, a)]
data Graf a= EV (Edges, Verticies a) deriving (Show)

-- Edges, Queue, Seen
bfs :: Graf a -> [Verticies a] -> [Verticies a] -> Int -> Graf (a, Int)
bfs _ [] seen _ = []
bfs (EV (edges, verticies)) queue seen num = (EV (edges, new_verticies++bfs_verticies)) 
    where
        (EV (_, new_verticies)) = bfs (EV (edges, verticies)) next_queue (seen ++ queue) (num+1)
        next_queue = foldl (++) [] [neighbours edges x| x <- queue]
        