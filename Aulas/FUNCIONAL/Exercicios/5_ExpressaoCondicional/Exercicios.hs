import Control.Concurrent (Chan)
-- Exercicio 5.2: maior de tres valores (com if)
max3 a b c =
    if a > b && a > c
        then a
        else if b > c
            then b
            else c

-- Exercicio 5.3: rastreando guardas
min3 :: Integer -> Integer -> Integer -> Integer
min3 a b c
    | a < b && a < c = a
    | b < c          = b
    | otherwise      = c

{--- Exercicio 5.5: refatorando para guardas
descreveLetra :: char -> String
descreveLetra c
    | c >= 'a' && c <= 'z' = "Letra minúscula"
    | c >= 'A' && c <= 'Z' = "Letra maiúscula"
    | otherwise            = "Não é uma letra"-}

-- Exercicio 5.6: número de raízes reais (guardas e where)
numRaizes :: Rational -> Rational -> Rational -> String
numRaizes a b c
    | delta > 0  = "Duas raízes"
    | delta == 0 = "Uma raíz"
    | delta < 0  = "Não possui raízes"
    where
        delta = b ^ 2 - 4 * a * c

-- Exercicio 5.7: custo do retrato (guardas complexas e where)
precoRetrato :: Integer -> String -> Double
precoRetrato ind dia
    | dia == "sábado" || dia == "domingo"  = preco * 1.2
    | otherwise                            = preco
    where
        preco
            | ind == 1  = 100.0
            | ind == 2  = 130.0
            | ind == 3  = 150.0
            | ind == 4  = 165.0
            | ind == 5  = 175.0
            | ind == 6  = 180.0
            | otherwise = 185.0

-- Exercicio 5.8: notas de um aluno (guardas e where)
conceito :: Double -> Double -> Double -> Char
conceito trabLab aval exame
    | media >= 8 && media <= 10 = 'A'
    | media >= 7 && media < 8   = 'B'
    | media >= 6 && media < 7   = 'C'
    | media >= 5 && media < 6   = 'D'
    | otherwise                 = 'E'
    where
        media = (trabLab * 2 + aval * 3 + exame * 5) / 10

-- Exercicio 5.10: lógica booleana nas guardas
podeDirigir :: Int -> Bool -> Bool
podeDirigir idade carteira
    | idade >= 18 && carteira = True
    | otherwise               = False

-- Exercicio 5.11: análise de elegibilidade por modalidade
analiseEligibilidade :: String -> Int -> Char -> String
analiseEligibilidade nome idade modalidade
    | modalidade == 'a' =
        if idade >= 18
            then nome ++ " pode participar da modalidade"
        else "Faltam " ++ show (18 - idade) ++ " para " ++ nome ++ " poder participar."
    | modalidade == 'b' =
        if idade >= 21
            then nome ++ " pode participar da modalidade"
        else "Faltam " ++ show (21 - idade) ++ " para " ++ nome ++ " poder participar."

-- Exercicio 5.12: classificação do consumo de um reservstório
classificaConsumo :: Double -> Double -> Double -> Double -> String
classificaConsumo altura largura comprimento consumo
    | autonomia <= 1                  = "Consumo extremo"
    | autonomia > 1 && autonomia <= 3 = "Consumo elevado"
    | autonomia > 3 && autonomia <= 7 = "Consumo moderado"
    | otherwise                       = "Consumo reduzido"
    where
        autonomia = capacidade / consumo
        capacidade = altura * largura * comprimento / 1000