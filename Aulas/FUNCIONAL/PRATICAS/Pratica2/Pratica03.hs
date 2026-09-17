module Aula03 where
    -- Exercicio 02: Primeiras definicoes em um arquivo
    dobro x = 2 * x
    quadrado x = x ^ 2
    quadradoDoDobro x = quadrado (dobro x)
    dobroDoQuadrado x = dobro (quadrado x)

    -- Exercicio 03: Organizando uma formula com where
    areaCoroa raioExterno raioInterno = 
        areaExterna - areaInterna
        where
            areaExterna = pi * raioExterno ^ 2
            areaInterna = pi * raioInterno ^ 2
    areaCoroa2 raioExterno raioInterno =
        (pi * raioExterno ^ 2) - (pi * raioInterno ^ 2)
    
    -- Exercicio 04: Organizando uma expressao com let...in
    distanciaPontos x1 y1 x2 y2 =
        let dx = (x2 - x1) ^ 2
            dy = (y2 - y1) ^ 2
        in sqrt (dx + dy)
    distanciaPontosWhere x1 y1 x2 y2 =
        sqrt (dx + dy)
        where
            dx = (x2 + x1) ^ 2
            dy = (y2 - y1) ^ 2
    
    -- Exercicio 05: Diagnosticando a regra de layout
    mediaPonderada n1 n2 =
        soma / pesos
        where
            soma = 2 * n1 + 3 * n2
            pesos = 5
    mediaPonderada2 n1 n2 = soma / pesos
        where {soma = 2 * n1 + 3 * n2; pesos = 5}

    -- Exercicio 06: Consolidacao extra classe - formula de Heron
    areaTrianguloHeron a b c =
        sqrt(s * (s - a) * (s - b) * (s - c))
        where
            s = (a + b + c) / 2
    areaTrianguloHeronLetIn a b c =
        let s = (a + b + c) / 2
        in sqrt(s * (s - a) * (s - b) * (s - c))