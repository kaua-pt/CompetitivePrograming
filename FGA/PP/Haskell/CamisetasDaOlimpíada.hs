main :: IO ()
main = do
    n <- readLn :: IO Int
    sizes <- sequence $ replicate n (readLn :: IO Int)
    p <- readLn :: IO Int
    m <- readLn :: IO Int

    let (one, two) = foldl
            (\(ones, others) x ->
                if x == 1
                then (ones + 1, others)
                else (ones, others + 1))
            (0, 0)
            sizes

    print (if one <= p && two <= m then 'S' else 'N')
