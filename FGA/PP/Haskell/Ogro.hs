main :: IO ()
main = do
    e <- readLn :: IO Int
    d <- readLn :: IO Int
    let a = if e > d then d + e else 2 * (d - e)
    print a

