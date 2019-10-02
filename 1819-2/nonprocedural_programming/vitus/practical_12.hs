greet :: IO()
greet = do
    putStr "Filename: "
    file <- getLine
    putStr "Operation (r/w): "
    operation <- getLine
    if operation == "r" then do
        fileContents <- readFile file
        putStrLn fileContents
    else
        if operation == "w" then do
            putStr "Contents: "
            fileContents <- getLine
            writeFile file fileContents
        else
            putStrLn "Invalid operation"