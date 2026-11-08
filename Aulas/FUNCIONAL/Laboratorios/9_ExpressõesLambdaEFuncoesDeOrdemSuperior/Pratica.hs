-- Exercicio 7: aplicação parcial e seções na prática
somaQuadradosPares :: [Int] -> Int
somaQuadradosPares xs = sum (map quadrado (filter ehPar xs))
    where
        quadrado x = x * x
        ehPar x = even x

stringsMaioresQue5 :: [String] -> [String]
stringsMaioresQue5 xs = filter grande xs
    where
        grande s = length s > 5

adicionaExclamacaoPar :: [String] -> [String]
adicionaExclamacaoPar xs = map adiciona (filter comprimentoPar xs)
    where
        adiciona s = s ++ "!"
        comprimentoPar s = even (length s)

-- Exercicio 6: substituindo funções locais por lambda
somaQuadradosParesLambda :: [Int] -> Int
somaQuadradosParesLambda xs = sum(map (\x -> x * x) (filter (\x -> even x) xs))

stringsMaioresQue5Lambda :: [String] -> [String]
stringsMaioresQue5Lambda xs = filter (\x -> length x > 5) xs

adicionaExclamacaoParLambda :: [String] -> [String]
adicionaExclamacaoParLambda xs = map (\x -> x ++ "!")(filter (\x -> even (length x)) xs)

ehVogal :: Char -> Bool
ehVogal = (`elem` "aeiou")

adicionaCom :: String -> String
adicionaCom = (++ ".com")

subtraiDe10 :: Int -> Int
subtraiDe10 = (10 -)

tresPrimeiros :: [a] -> [a]
tresPrimeiros = take 3

-- Exercicio 8: processando dados com lambdas e padrões
type Nome = String
type Preco = Double
type Venda = (Nome, Preco)

aplicaTaxa :: [Venda] -> [Venda]
aplicaTaxa =
    map (\(nome, preco) ->
        if preco > 50.0
            then (nome, preco * 1.10)
            else (nome, preco))

type Nota = Double
type Aluno = (Nome, Nota, Nota)

alunosAprovados :: [Aluno] -> [String]
alunosAprovados =
    map (\(nome, _, _) -> nome)
    . filter (\(_, n1, n2) -> (n1 + n2) / 2 >= 7.0)

aplicaDesconto :: [Venda] -> [Venda]
aplicaDesconto =
    map (\(nome, preco) -> (nome, preco * 0.95))

-- Exercicio 9: identificando padrões de percurso
quadrados :: Num a => [a] -> [a]
quadrados [] = []
quadrados (x:xs) = x * x : quadrados xs

positivos :: (Num a, Ord a) => [a] -> [a]
positivos [] = []
positivos (x:xs)
    | x > 0 = x : positivos xs
    | otherwise = positivos xs

soma :: Num a => [a] -> a
soma [] = 0
soma (x:xs) = x + soma xs

quadradosMap :: Num a => [a] -> [a]
quadradosMap [] = []
quadradosMap xs = map (\x -> x * x) xs 

positivosFilter :: (Num a, Ord a) => [a] -> [a]
positivosFilter [] = []
positivosFilter xs = filter (> 0) xs

somaFoldr :: Num a => [a] -> a
somaFoldr [] = 0
somaFoldr xs = foldr (+) 0 xs

somaQuadradosPositivos :: (Num a, Ord a) => [a] -> a 
somaQuadradosPositivos = foldr (+) 0. map(\x -> x * x) . filter (> 0)

-- Exercicio 10: reescrevendo nas duas direcoes
somar1ALista :: [Int]
somar1ALista = [x + 1 | x <- [10, 20, 30]]

filtrarMaiorQue5 :: [Int]
filtrarMaiorQue5 = [x | x <- [1, 8, 2, 9], x > 5]

dobrarNumerosImpares :: [Int] 
dobrarNumerosImpares = [x * 2| x <- [1 .. 10], odd x]

concatenaListas :: [(Int, Char)]
concatenaListas = [(x, y) | x <- [1, 2], y <- ['a', 'b']]

somar1AListaMap :: [Int]
somar1AListaMap = map (+1) [1..5]

filtrarNumerosPares :: [Int]
filtrarNumerosPares = filter (even) [1..20]

quadradoNumerosImpares :: [Int]
quadradoNumerosImpares = map (^2) (filter odd [1..10])

concatenarListasConcatMap :: [(Int, Int)]
concatenarListasConcatMap = concatMap (\x -> map (\y -> (x, y)) [4, 5]) [1, 2, 3]

-- Exercicioo 11: combinando funcoes de ordem superior
quantidades :: [Int]
quantidades = [2, 1, 5, 3]

precos :: [Int]
precos = [150, 1299, 80, 250]

subtotais :: [Int] -> [Int] -> [Int]
subtotais = zipWith (*)

totalCompra :: [Int] -> [Int] -> Int
totalCompra qs = foldr (+) 0 . subtotais qs

subtotaisAcimaDeLC :: Int -> [Int] -> [Int] -> [Int]
subtotaisAcimaDeLC limite qs ps =
    [x | x <- subtotais qs ps, x > limite]