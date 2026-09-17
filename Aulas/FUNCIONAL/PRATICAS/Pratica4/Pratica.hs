-- Exercicio 4: Calculo de frete
calculaFrete :: Double -> String -> Double
calculaFrete peso tipoEntrega =
    if tipoEntrega == "Expressa"
        then base * 1.3
        else base
    where
        base
            | peso <= 1 = 15
            | peso <= 10 = 25
            | peso > 10 = 40

-- Exercicio 5: Classificacao de ano
classificacaoAno :: Int -> String
classificacaoAno ano
--    | ano `mod` 4 == 0 = "apenas bissexto"
    | ano `mod` 400 == 0 = "bissexto e secular"
    | ano `mod` 100 == 0 = "apenas secular"
    | ano `mod` 4 == 0 = "apenas bissexto"
    | otherwise = "ano comum"

-- Exercicio 6: Valor final de uma compra
valorFinal :: Int -> Double -> Double
valorFinal regiao valorCompra
    | valorCompra > 5000.0 = valorCompra
    | otherwise = valorCompra * frete
    where
        frete
            | regiao == 1 = 1.08
            | regiao == 2 = 1.06
            | regiao == 3 = 1.03
            | regiao == 4 = 1.12
            | otherwise = 1.15

-- Exercicio 7: Contagem de ocorrencia e valor do premio
valorPremio :: Char -> Char -> Char -> Double -> Double
valorPremio fruta1 fruta2 fruta3 valor
    | qtd == 3 = valor * 10
    | qtd == 2 = valor * 5
    | qtd == 1 = valor
    | otherwise = 0
    where
        qtd =
            contaBanana fruta1 + contaBanana fruta2 + contaBanana fruta3
        contaBanana fruta
            | fruta == 'b' = 1
            | otherwise = 0