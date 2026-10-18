-- Exercicio 5: calculo de frete
calculaFrete :: Double -> String -> Double
calculaFrete peso tipoEntrega
    | peso <= 1.0                = 15 * modalidade
    | peso > 1.0 && peso <= 10.0 = 25 * modalidade
    | peso > 10                  = 40 * modalidade
    where
        modalidade =
            if tipoEntrega == "Expressa"
                then 1.3
            else 1

-- Exercicio 5: classificação de ano
classificaAno :: Int -> String
classificaAno ano
    | (ano `mod` 400) == 0 = "Ano bissexto e secular"
    | (ano `mod` 100) == 0 = "Ano secular"
    | (ano `mod` 4) == 0   = "Ano bissexto"
    | otherwise            = "Ano comum"

-- Exercicio 6: valor final de uma compra
valorFinal :: Int -> Double -> Double
valorFinal regiao valorCompra
    | valorCompra > 5000 = valorCompra
    | regiao == 1        = valorCompra * 1.08
    | regiao == 2        = valorCompra * 1.06
    | regiao == 3        = valorCompra * 1.03
    | regiao == 4        = valorCompra * 1.12
    | regiao == 5        = valorCompra * 1.15

-- Exercicio 7: contagem de ocorrências e valor do prêmio
valorPremio :: Char -> Char -> Char -> Double -> Double
valorPremio fruta1 fruta2 fruta3 valor
    | frutas == 3 = valor * 10
    | frutas == 2 = valor * 5
    | frutas == 1 = valor
    | frutas == 0 = 0.0
    where
        frutas = teste fruta1 + teste fruta2 + teste fruta3
        teste fruta
            | fruta == 'b' = 1
            | otherwise    = 0

-- Exercicio 8: cobrança por transmissão de dados
quantidadeValida :: Double -> Bool
quantidadeValida qtd
    | qtd >= 0  = True
    | otherwise = False

precoTransmissao :: Double -> Double
precoTransmissao qtd
    | qtd <= 5              = qtd * valorBase
    | qtd > 5 && qtd <= 10  = 5 * valorBase + (qtd - 5) * (valorBase/100 * 0.96)
    | qtd > 10 && qtd <= 20 = 10 * valorBase + (qtd - 10) * (valorBase/100 * 0.94)
    | qtd > 20 && qtd <= 40 = 20 * valorBase + (qtd - 20) * (valorBase/100 * 0.92)
    | otherwise             = qtd * (valorBase/100 * 0.9)
    where
        valorBase = 10

-- Exercicio 9: classificação por faixa
classeVulnerabilidade :: Double -> String
classeVulnerabilidade valor
    | valor >= 0 && valor < 0.2   = "Muito baixa"
    | valor >= 0.2 && valor < 0.4 = "Baixa"
    | valor >= 0.4 && valor < 0.6 = "Media"
    | valor >= 0.6 && valor < 0.8 = "Alta"
    | otherwise                   = "Muito alta"

acaoRemocao :: Double -> String
acaoRemocao valor
    | valor >= 0 && valor < 0.4   = "Nenhuma ação de remoção"
    | valor >= 0.4 && valor < 0.6 = "Remoção em uma semana"
    | valor >= 0.6 && valor < 0.8 = "Remoção em dois dias"
    | valor >= 0.8 && valor >= 1  = "Remoção imediata"

ajudaCusto :: Double -> Double
ajudaCusto valor
    | valor >= 0 && valor < 0.4   = 0.0
    | valor >= 0.4 && valor < 0.6 = 1000.0
    | valor >= 0.6 && valor < 0.8 = 3000.0
    | valor >= 0.8 && valor >= 1  = 5000.0