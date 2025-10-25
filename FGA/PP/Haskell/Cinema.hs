getPrice :: Int -> Int
getPrice a
    | a <= 17 = 15
    | a >= 18 && a <= 59 = 30
    | otherwise = 20

calc :: Int -> Int -> Int
calc a b = getPrice a + getPrice b

main :: IO ()
main = do
    a <- readLn :: IO Int
    b <- readLn :: IO Int
    print (calc a b)
