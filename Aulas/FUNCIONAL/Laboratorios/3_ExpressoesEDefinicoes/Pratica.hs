module Pratica where

    -- Exercicio 2: primeiras definicoes em um arquivo
    dobro x = x * 2
    quadrado x = x ^ 2
    quadradoDoDobro x = quadrado(dobro x)
    dobroDoQuadrado x = dobro (quadrado x)

    -- Exercicio 3: organizando uma formula com where
    areaCoroa raioExterno raioInterno = areaExterna - areaInterna
        where
            areaExterna = pi * (raioExterno ^ 2)
            areaInterna = pi * (raioInterno ^ 2)

    -- Exercicio 4: organizando uma expressao com let...in
    distanciaPontos x1 y1 x2 y2 = 
        let
            dx = (x2 - x1) ^ 2
            dy = (y2 - y1) ^ 2
        in
            sqrt(dx + dy)
    
    -- Exercicio 5: diagnosticando a regra de layout
    mediaPonderada n1 n2 = soma / peso
        where
            soma = 2 * n1 + 3 * n2
            peso = 5
    mediaPonderada2 n1 n2 = soma / peso
        where{
            soma = 2 * n1 + 3 * n2
        ;   peso = 5    
        }
    
    -- Exercicio 6: consolidacao extra classe - formula de Heron
    areaTrianguloHeron a b c = sqrt (s * (s - a) * (s - b) * (s * c))
        where
            s = (a + b + c) / 2
    areaTrianguloHeronLet a b c =
        let s = (a + b + c) / 2
        in sqrt (s * (s - a) * (s - b) * (s * c))