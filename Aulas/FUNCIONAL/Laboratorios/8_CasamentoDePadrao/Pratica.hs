import Data.Maybe

-- Exercicio 1: reescrevendo o processamento pela estrutura de dados
type NomeProduto = String
type Quantidade = Int
type ItemPedido = (NomeProduto, Quantidade)

quantidadeTotalUnidades :: [ItemPedido] -> Int
quantidadeTotalUnidades itens
    | null itens = 0
    | otherwise = snd (head itens) + quantidadeTotalUnidades (tail itens)

nomesProdutos :: [ItemPedido] -> [NomeProduto]
nomesProdutos itens
    | null itens = []
    | otherwise = fst (head itens) : nomesProdutos (tail itens)

quantidadeTotalUnidades' :: [ItemPedido] -> Int
quantidadeTotalUnidades' []          = 0
quantidadeTotalUnidades' ((_, y):xs) = y + quantidadeTotalUnidades' xs

nomesProdutos' :: [ItemPedido] -> [NomeProduto]
nomesProdutos' [] = []
nomesProdutos' ((x, _):xs) = x : nomesProdutos' xs

-- Exercicio 2: tratando maybe diretamente por padrões
type ValorTotal = Double

descricaoTotal :: Maybe ValorTotal -> String
descricaoTotal total
    | isJust total = "Total: R$ " ++ show (fromJust total)
    | otherwise = "Total ainda nao calculado"

descricaoTotal' :: Maybe ValorTotal -> String
descricaoTotal' Nothing = "Total ainda nao calculado"
descricaoTotal' (Just x)  = "Total: R$ " ++ show x

-- Exercicio 3: produzindo uma mensagem a partir do resultado de uma consulta
type Aluno = String
type Nota = Double
type TabelaNotas = [(Aluno, Nota)]

notas :: TabelaNotas
notas =
    [ ("Ana", 8.5)
    , ("Bruno", 6.0)
    , ("Carla", 9.2)
    ]

mensagemNota :: Aluno -> TabelaNotas -> String
mensagemNota aluno tabela =
    case lookup aluno tabela of
        { Nothing -> "Aluno nao encontrado";
          Just x  -> "Nota: " ++ show x 
        }

-- Exercicio 4: implementando RLE com casamento de padrão
comprime :: String -> [(Char, Int)]
comprime []     = []
comprime (x:xs) = comprimeBloco x 1 xs

comprimeBloco :: Char -> Int -> String ->  [(Char, Int)]
comprimeBloco c n []           = [(c, n)]
comprimeBloco c n texto@(x:xs)
    | c == x    = comprimeBloco x (n+1) xs
    | otherwise = (c, n) : comprime texto

descomprime :: [(Char, Int)] -> Maybe String
descomprime [] = Just ""
descomprime ((c, n): xs)
    | n <= 0    = Nothing
    | otherwise = 
        case descomprime xs of
            Nothing    -> Nothing
            Just resto -> Just (replicate n c ++ resto)

-- Exercicio 5: implementação do algoritmo de Luhn
toDigits :: Integer -> [Integer]
toDigits x 
    | x <= 0    = []
    | otherwise = reverse (toDigitsRev x)

toDigitsRev :: Integer -> [Integer]
toDigitsRev x 
    | x < 10    = [x]
    | otherwise = x `mod` 10 : toDigitsRev (x `div` 10)

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther = reverse . dobra . reverse
    where
        dobra []       = []
        dobra [x]      = [x]
        dobra (x:y:xs) = x : y*2 : dobra xs

sumDigits :: [Integer] -> Integer
sumDigits []     = 0
sumDigits (x:xs) = sum (toDigits x) + sumDigits xs