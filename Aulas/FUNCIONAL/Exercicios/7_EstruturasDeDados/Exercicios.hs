import Data.Maybe
import GHC.LanguageExtensions.Type (Extension(MagicHash))

-- Exercicio 7.2: Acesso a componentes  
obterCoordenadaY :: (Double, Double) -> Double
obterCoordenadaY ponto = snd ponto

-- Exercicio 7.3: criando pares
duplicarPrimeiro :: Num a => (a, b) -> (a, b)
duplicarPrimeiro par = (fst par * 2, snd par)

-- Exercicio 7.4: dividindo ao meio
metade :: [a] -> ([a], [a])
metade lista = splitAt tam lista
    where
        tam = div tamLista 2
        tamLista = length lista

-- Exercicio 7.5: último elemento
ultimo :: [a] -> a
ultimo lista = head (reverse lista)

ultimo' :: [a] -> a
ultimo' lista = lista !! length lista

-- Exercicio 7.6: todos menos o último
primeiros :: [a] -> [a]
primeiros lista = reverse (tail (reverse lista))

-- Exercicio 7.7: concatenação e comprimento
infoLista :: [a] -> [a] -> ([a], Int)
infoLista l1 l2 = (lista, length lista)
    where lista = l1 ++ l2

-- Exercicio 7.8: segundo elemento
segundo :: [a] -> a 
segundo xs = head (tail xs)

-- Exercicio 7.9: palíndromo
palindromo :: Eq a => [a] -> Bool
palindromo xs = xs == reverse xs 

-- Exercicio 7.10: produto recursivo
produtoLista :: Num a => [a] -> a
produtoLista xs 
    | null xs   = 1
    | otherwise = head xs * produtoLista (tail xs)

-- Exercicio 7.11: eficiência ao construir listas
adicionarFinal :: [a] -> a -> [a]
adicionarFinal xs x = xs ++ x'
    where x' = [x]

-- Exercicio 7.12: idade opcional
obterIdade :: Maybe Int -> Int
obterIdade maybeIdade = fromMaybe 0 maybeIdade

-- Exercicio 7.13: consulta em lista de associação
notas :: [(String, Double)]
notas = [("Ana", 8.5), ("Bruno", 7.0), ("Carla", 9.2)]

consultarNota :: String -> Double
consultarNota nome = fromMaybe 0.0 (lookup nome notas)

-- Exercicio 7.14: sistema de reserva de viaagens
type Nome = String
type Destino = String
type Classe = String

type Reserva = (Nome, Destino, Maybe Classe)

reserva1 :: Reserva
reserva1 = ("Ana", "Ouro Preto", Just "Economia")

-- Exercicio 7.15: gerenciamento de projetos
type NomeProjeto = String
type ListaIntegrantes = [String]
type DataEntrega = String

type Projeto = (NomeProjeto, ListaIntegrantes, Maybe DataEntrega)

projeto1 :: Projeto
projeto1 = ("Avião", ["Ana", "Carlos"], Nothing)