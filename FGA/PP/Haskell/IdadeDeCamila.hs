import Data.List (sort)

main::IO ()
main = do
    a <- readLn :: IO Int
    b <- readLn :: IO Int
    c <- readLn :: IO Int
    let ages = [a, b, c]    
    print ((sort ages) !! 1)