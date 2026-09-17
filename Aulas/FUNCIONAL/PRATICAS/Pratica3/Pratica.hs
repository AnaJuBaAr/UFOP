-- Exercicio 5: Da assinatura monomórfica para a polimórfica
areaCirculo1 :: Double -> Double
areaCirculo1 r = pi * r ^ 2

areaCirculo2 :: Floating a => a -> a
areaCirculo2 r = pi * r ^ 2

-- Exercicio 6: Inferindo restricoes
dobro :: Num a => a -> a
dobro x = 2 * x

maior :: Ord a => a -> a -> a
maior x y = max x y

hipotenusa :: Floating a => a -> a -> a
hipotenusa x y = sqrt(x^2 + y^2)

media :: Fractional a => a -> a -> a
media x y = (x + y) / 2

-- Exercicio 7: Ambiguidade e a funcao read
idade :: Int
idade = read "36"

temperatura :: Double
temperatura = read "21.5"

ativo :: Bool
ativo = read "True"

-- Exercicio 8: Melhorando a clareza com tipos sinônimos
type Nome = String
type Idade = Int
descrevePessoa :: Nome -> Idade -> String
descrevePessoa nome idade = nome ++ " tem " ++ show idade ++ " anos."