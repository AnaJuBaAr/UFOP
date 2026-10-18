-- Exercicio 4.1: salário líquido
salario :: Double -> Double
salario x = x * 1.03

-- Exercicio 4.2: força gravitacional
cteGravitacaoUniversal :: Double
cteGravitacaoUniversal = 6.67e-11

forcaGravitacional :: Double -> Double -> Double -> Double
forcaGravitacional m1 m2 d = cteGravitacaoUniversal * m1 * m2 / d ^ 2

forcaTerraLua :: Double
forcaTerraLua = forcaGravitacional 6e24 1e23 (4e5 * 1000)

-- Exercicio 4.3: temperatura
type Temperatura = Double

converteTemperatura :: Temperatura -> Temperatura
converteTemperatura c = 9 / 5 * c + 32

-- Exercicio 4.4: velocidade
type Velocidade = Int
aumentaVelocidade :: Velocidade -> Velocidade
aumentaVelocidade x = x * 2

-- Exercicio 4.6
identidade x = x
-- identidade :: p -> p
primeiro x y = x
-- primeiro :: p1 -> p2 -> p1
segundo x y = y
-- segundo :: p1 -> p2 -> p2
const x y = x
-- const :: p1 -> p2 -> p1

-- Exercicio 4.8: inferência de tipos qualificados
dobro x = x * 2
-- Num
aprovado nota = nota >= 6
-- Ord, Num
myLog x b = log x / log b
-- Floating

-- Exercicio 4.9: equacao de segundo grau
equacao :: Integer -> Integer -> Integer -> Bool
equacao a b c
    | b ^ 2 - 4 * a * c >= 0 = True
    | otherwise = False