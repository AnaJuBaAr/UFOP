-- Exercicio 10.1: disjunção lógica
ou :: Bool -> Bool -> Bool
ou True True   = True
ou True False  = True
ou False True  = True
ou False False = False

ou' :: Bool -> Bool -> Bool
ou' True _  = True
ou' False x = x

ou'' :: Bool -> Bool -> Bool
ou'' False False = False
ou'' _     _ = True
