-- Fatorial
fatorial :: Integer -> Integer
fatorial n
    | n == 0 = 1
    | n > 0  = n * fatorial (n - 1)

-- Potencia de dois
potDois :: Integer -> Integer
potDois n
    | n == 0 = 1
    | n > 0  = 2 * potDois (n - 1)

-- Multiplicação
mul :: Integer -> Integer -> Integer
mul m n
    | n == 0    = 0
    | n > 0     = m + mul m (n - 1)
    | otherwise = negate (mul m (negate n))

-- Fibonacci
fib :: Integer -> Integer
fib n
    | n == 0 = 0
    | n == 1 = 1
    | n > 1  = fib (n - 2) + fib (n - 1)

-- Par Ímpar
par :: Integer -> Bool
par n
    | n == 0    = True
    | n > 0     = impar (n - 1)
    | otherwise = par (-n)

impar :: Integer -> Bool
impar n
    | n == 0    = False
    | n > 0     = par (n - 1)
    | otherwise = impar (-n)

-- Potencia de dois com funcao auxiliar
potdois :: Integer -> Integer
potdois n = potdois' n 1

potdois' :: Integer -> Integer -> Integer
potdois' x y
    | x == 0 = y
    | x > 0  = potdois' (x-1)(2*y)