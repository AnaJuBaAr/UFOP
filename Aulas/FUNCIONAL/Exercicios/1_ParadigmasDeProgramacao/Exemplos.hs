import GHC.Utils.Encoding (zDecodeString)
-- Soma dos elementos de uma lista
soma []     = 0
soma(x:xs)  = x + soma xs

-- Ordenacao por QuickSort
qsort []     = []
qsort (x:xs) = qsort ys ++ [x] ++ qsort zs
    where
        ys = [a | a <- xs, a <= x]
        zs = [b | b <- xs, b > x]

-- Exercicio 1.6: Desafio: produto de uma lista
produto []     = 0
produto (x:xs) = x * produto xs

-- Exercicio 1.7: Desafio: ordenacao decrescente
qsortD []     = []
qsortD (x:xs) = qsort ys ++ [x] ++ qsort zs
    where
        ys = [a | a <- xs, a >= x]
        zs = [b | b <- xs, b < x]