import Control.Monad.RWS (MonadWriter(pass))
-- Exercicio 4: cálculo aproximado de pi
valorPi :: Integer -> Double
valorPi k = 4 * valorPi' 0 (k-1)

valorPi' :: Integer -> Integer -> Double
valorPi' i k 
    | i > k     = 0.0
    | k > 0     = termo + valorPi' k (i+1)
        where
            termo = fromIntegral((-1) ^ i) / (2 * fromIntegral i + 1)

-- Exercicio 5: simulador de crescimento populacional
simulaPopulacao :: Integer -> Double -> Integer -> Integer -> Integer
simulaPopulacao popInicial taxa colheita anos 
    | anos == 0       = popInicial
    | popInicial <= 0 = 0
    | anos > 0        = simulaPopulacao popAtual taxa colheita (anos-1)
    where
        popAtual = floor(fromIntegral popInicial * (1.0 + taxa)) - colheita

-- Exercicio 6: Conjectura de Collatz
analisaTrajetoria :: Integer -> (Int, Integer)
analisaTrajetoria n = aux n 0 n
    where
        aux :: Integer -> Int -> Integer -> (Int, Integer)
        aux atual passos maior 
            | atual == 1 = (passos, maior)
            | otherwise  = aux proximo (passos+1) novoMaior
            where
                proximo
                    | even atual = div atual 2
                    | otherwise  = 3 * atual + 1
                novoMaior = max maior proximo