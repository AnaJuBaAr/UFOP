-- Exercicio 6.7: fatorial duplo
fatorialDuplo :: Integer -> Integer
fatorialDuplo n
    | n <= 0 = 1
    | n > 0  = n * fatorialDuplo (n - 2)

-- Exercicio 6.8: multiplicação em um intervalo
produtoIntervalo :: Integer -> Integer -> Integer
produtoIntervalo m n
    | m > n  = 1
    | m == n = m
    | m < n  = m * produtoIntervalo (m+1) n

-- Exercicio 6.9: fatorial
fatorial :: Integer -> Integer
fatorial n
    | n == 0 = 1
    | n > 0  = produtoIntervalo 1 n

-- Exercicio 6.10: adição
soma :: Integer -> Integer -> Integer
soma x y
    | y == 0 = x
    | y > 0  = soma (succ x)(pred y)

-- Exercicio 6.11: potenciação
potencia :: Integer -> Integer -> Integer
potencia x n
    | n == 0 = 1
    | n > 0  = x * potencia x (n-1)

-- Exercicio 6.12: raiz quadrada inteira
raizInteira :: Integer -> Integer
raizInteira n = raizInteira' n n
    where
        raizInteira' n i 
            | i^2 > n   = raizInteira' n (i-1)
            | otherwise = i

-- Exercicio 6.13: quociente e resto da divisão inteira
quociente :: Integer -> Integer -> Integer
quociente p q
    | p < q     = 0
    | otherwise = 1 + quociente (p-q) q

resto :: Integer -> Integer -> Integer
resto p q
    | p < q     = p
    | otherwise = p - quociente p q * q

-- Exercicio 6.14: máximo divisor comum
mdc :: Integer -> Integer -> Integer
mdc a b
    | b == 0    = 0
    | b < 0     = mdc a (-b)
    | otherwise = mdc b (a `mod` b)

-- Exercicio 6.16: sequência de Fibonacci com acumulador
fibonacci :: Integer -> Integer
fibonacci x = fibonacci' x 0 1
    where
        fibonacci' x a b
            | x == 0    = a
            | x == 1    = b
            | otherwise = fibonacci' (x-1) b (a+b)