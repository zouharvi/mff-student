import Data.List

tetris :: [[Int]] -> [[Int]]
tetris m = transpose mC
    where
        mT = transpose m
        mC = filter (\column -> (length (filter (==0) column)) /= 0) mT