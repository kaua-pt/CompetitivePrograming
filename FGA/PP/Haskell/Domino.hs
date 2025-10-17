main :: IO ()
main = do
    buf <- getLine
    let n = read buf :: Int
    let points = div ((n + 1) * (n + 2)) 2
    print points
