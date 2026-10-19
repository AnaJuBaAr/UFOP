import Data.Maybe
import Control.Monad.Trans.Maybe (MaybeT(MaybeT))

type Cliente = String
type NomeProduto = String
type Quantidade = Int
type ValorTotal = Double

type ItemPedido = (NomeProduto, Quantidade)
type PedidoCliente = (Cliente, [ItemPedido], Maybe ValorTotal)
type TabelaDescontos = [(Cliente, Double)]

pedidoAlice :: PedidoCliente
pedidoAlice = ("Alice", [("Notebook", 1), ("Mouse", 2)], Just 5050.0)

pedidoBob :: PedidoCliente
pedidoBob = ("Bob", [("Cadeira", 4)], Nothing)

descontos :: TabelaDescontos
descontos = 
    [ ("Alice", 0.10)
    , ("Carlos", 0.05)
    ]

-- Exercicio 5: conferencia das unidades de um pedido
quantidadeTotalUnidades :: [ItemPedido] -> Int
quantidadeTotalUnidades itens
    | null itens = 0
    | otherwise  = snd (head itens) + quantidadeTotalUnidades (tail itens)

-- Exercicio 6: lista de produtos para a separação
nomesProdutos :: [ItemPedido] -> [NomeProduto]
nomesProdutos itens
    | null itens = []
    | otherwise  = fst (head itens) : nomesProdutos (tail itens)

-- Exercicio 7: programa de descontos da loja
consultarDesconto :: Cliente -> TabelaDescontos -> Double
consultarDesconto cliente tabela =
    fromMaybe 0.0 (lookup cliente tabela)

clienteTemDesconto :: Cliente -> TabelaDescontos -> Bool
clienteTemDesconto cliente tabela =
    isJust (lookup cliente tabela)

-- Exercicio 8: total opicional de um pedido
totalOuPadrao :: ValorTotal -> Maybe ValorTotal -> ValorTotal
totalOuPadrao padrao total =
    fromMaybe padrao total

descricaoTotal :: Maybe ValorTotal -> String
descricaoTotal total
    | isJust total = "Total: R$ " ++ show (fromJust total)
    | otherwise    = "Total ainda não calculado"

-- Exercicio 9: classificação de triangulos com resultado opcional
classificaTriangulo :: (Num a, Ord a) => a -> a -> a -> Maybe String
classificaTriangulo a b c 
    | positivo     = Nothing
    | desigualdade = Nothing
    | equilatero   = Just "Equilatero"
    | isosceles    = Just "Isósceles"
    | escaleno     = Just "Escaleno"
    where
        positivo = 
            a < 0 || b < 0 || c < 0
        desigualdade =
            a >= b+c || b >= c+a || c >= a+b
        equilatero =
            a == b && b == c
        isosceles =
            a == b || b == c || c == a 
        escaleno =
            a /= b && b /= c 

-- Exercicio 10: caixa eletronico com tuplas
saqueCaixa :: Integral a => a -> (a, a, a, a)
saqueCaixa valor = (q50, q20, q10, q1)
    where
        qr50 = divMod valor 50
        q50 = fst qr50
        r50 = snd qr50

        qr20 = divMod r50 20
        q20 = fst qr20
        r20 = snd qr20

        qr10 = divMod r20 10
        q10 = fst qr10
        r10 = snd qr10

        q1 = r10

-- Exercicio 11: modelagem de um catálogo de livros
type Titulo = String
type Autor = String
type Ano = Int

type Livro = (Titulo, [Autor], Maybe Ano)

livro1 :: Livro
livro1 = ("Quem é você Alaska", ["John Green"], Just 2005)

livro2 :: Livro
livro2 = ("Will e Will", ["John Green", "David Levithan"], Nothing)

livro3 :: Livro
livro3 = ("A rebelde do deserto", ["Alwyn Hamilton"], Just 2015)

catalogo :: [Livro]
catalogo = [livro1, livro2, livro3]