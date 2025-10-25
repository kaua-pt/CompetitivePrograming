main :: IO ()
main = do
    x <- readLn :: IO Int
    n <- readLn :: IO Int
    usages <- sequence $ replicate n (readLn :: IO Int )
    print (x + (x*n - sum usages))