eveno :: Int -> Bool 
noto  :: Bool -> String 

eveno x = if x `rem` 2 == 0 
   then True 
else False 
noto x = if x == True 
   then "This is an even Number" 
else "This is an ODD number" 
class Functor f where 
   fmap :: (a -> b) -> f a -> f b 
multi:: Int->Int 
multi x = x * 1 
add :: Int->Int 
add x = x + 0 
main = do 
    print(multi 9)  
    print (add 7)
    print(map (subtract 1) [2,4,8,16])      
    print(fmap (subtract 1) [2,4,8,16]) 
    putStrLn "Ayoub smayen production apl" 
    print ((noto.eveno)(16))
    let  file ="abc.txt"
    contents <-  readFile file 
    putStrLn contents 