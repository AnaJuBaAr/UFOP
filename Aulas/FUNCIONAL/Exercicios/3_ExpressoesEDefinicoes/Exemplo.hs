-- Exercicio 3.4: o ciclo de desenvolvimento
dobro x = x + x
quadruplo x = dobro (dobro x)
areaCirculo r = pi * (r ^ 2)

-- Exercicio 3.5: combinando funcoes
quadradoDoDobro x = quadrado (dobro x)
    where quadrado x = x ^ 2
dobroDoQuadrado x = dobro(quadrado x)
    where quadrado x = x ^ 2

-- Exercicio 3.6: conversao de temperatura
celsiusParaFahrenheit c = 9 / 5 * c + 32

-- Exercicio 3.7: lados de um triangulo
ladosTriangulo a b c
    | a + b > c && a + c > b && b + c > a = True
    | otherwise = False

-- Exercicio 3.8: receptor de radio
freqResonancia l c = 1 / (2 * pi * sqrt(l * c))

-- Exercicio 3.9: custo da energia eletrica
custoEnergia salMin qwh = valor - desconto
    where
        valor = qwh * (salMin / 5)
        desconto = 15 * (valor / 100)

-- Exercicio 3.10: energia armazenada em uma mola
energiaMola k f = 1 / k * x ^ 2
    where
        x = f / k

-- Exercicio 3.11: area de um triangulo (formula de Heron)
areaTrianguloHeron a b c = sqrt (p * (p - a) * (p - b) * (p - c))
    where
        p = (a + b + c) / 2