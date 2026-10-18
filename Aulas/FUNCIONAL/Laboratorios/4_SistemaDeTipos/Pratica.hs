-- Exercicio 5: da assinatura monomorfica para a polimorfica
--areaCirculo :: Double -> Double
areaCirculo :: Floating a => a -> a
areaCirculo r = pi * r ^ 2

-- Exercicio 6: inferindo restrições
-- Num a => a -> a
dobro x = 2 * x
-- maior :: Ord a => a -> a -> a
maior x y = max x y
-- hipotenusa :: Floating a => a -> a -> a
hipotenusa x y = sqrt(x^2 + y^2)
-- media :: Fractional a => a -> a -> a
media x y = (x + y) / 2

-- Exercicio 7: ambiguidade e a função read
idade :: Int
idade = read "36"

temperatura :: Double
temperatura = read "21.5"

ativo :: Bool
ativo = read "True"

-- Exercicio 8: melhorando a clareza com tipos sinonimos
type Nome = String
type Idade = Int

descrevePessoa :: Nome -> Idade -> String
descrevePessoa nome idade = nome ++ " tem " ++ show idade ++ " anos."

-- Exercicio 9: organizando com where - area de um cilindro
areaCilindro :: Double -> Double -> Double
areaCilindro raio altura = areaLateral + 2 * areaBase
    where
        areaLateral = 2 * pi * raio * altura
        areaBase    = areaCirculo raio

-- Exercicio 10: organizando com where - juros compostos
montanteJurosCompostos :: Double -> Double -> Int -> Double
montanteJurosCompostos principal taxaAnual anos = principal * fatorAcumulacao
    where
        fatorAcumulacao = (1 + taxaAnual) ^ anos

-- Exercicio 11: organizando com where - area da superficie de um cone
areaCone :: Double -> Double -> Double
areaCone raio altura = areaBase + areaLateral
    where
        areaBase    = areaCirculo raio
        areaLateral = pi * raio * geratriz
        geratriz    = sqrt(raio ^ 2 + altura ^ 2)

-- Exercicio 12: altura maxima de um projetil
grausParaRadianos :: Double -> Double
grausParaRadianos graus = graus * (pi / 180)

alturaMaxima :: Double -> Double -> Double
alturaMaxima v0 anguloGraus =
    let
        g     = 9.81
        theta = grausParaRadianos anguloGraus
        vy    = v0 * sin theta
    in
        vy ^ 2 / (2 * g)
