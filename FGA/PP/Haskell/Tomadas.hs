import Data.List (sort)

runSum :: [Int] -> [Int]
runSum [] = []
runSum [x] = [x]
runSum (x:xs) = (x - 1) : runSum xs

main :: IO ()
main = do
    buf <- getLine
    let numeros = map read (words buf) :: [Int]
    let resultado = runSum $ sort numeros
    print $ sum resultado 