-- Cadastro de usuário
type Nome = String
type Idade = Int
type Interesse = String

type Usuario = (Nome, Maybe Idade, [Interesse])

usuario1 :: Usuario
usuario1 = ("Alice", Just 25, ["Haskell", "Música", "Cinema"])

usuario2 :: Usuario
usuario2 = ("Bob", Nothing, ["Esportes", "Viagens"])

usuario3 :: Usuario
usuario3 = ("Carlos", Just 30, [])

-- Catálogo de livros
type Titulo = String
type Autor = String
type Ano = Int

type Livro = (Titulo, [Autor], Maybe Ano)

livro1 :: Livro
livro1 = ("Aprendendo Haskell", ["João SIlva"], Just 2020)

livro2 :: Livro
livro2 = ("Paradigmas de Programação", ["M. Oliveira", "P. Santos"], Nothing)

livro3 :: Livro
livro3 = ("Introdução à Computação", ["Carlos Mendes"], Just 2018)

-- Inventário de produtos
type NomeProduto = String
type Quantidade = Int
type Preco = Double

type Produto = (NomeProduto, Quantidade, Maybe Preco)

produto1 :: Produto
produto1 = ("Notebook", 10, Just 4500.0)

produto2 :: Produto
produto2 = ("Cadeira", 5, Nothing)

produto3 :: Produto
produto3 = ("Mesa", 2, Just 850.0)

-- Sistema de pedidos
type Cliente = String
type NomeProduto' = String
type Quantidade' = Int
type ValorTotal = Double

type ItemPedido = (NomeProduto', Quantidade')
type PedidoCliente = (Cliente, [ItemPedido], Maybe ValorTotal)

pedidos :: [PedidoCliente]
pedidos =
    [ ("Alice", [("Notebook", 1), ("Mouse", 2)], Just 5050.0)
    , ("Bob", [("Cadeira", 4)], Nothing)
    , ("Carlos", [("Mesa", 1), ("Luminaria", 3)], Just 1850.0)
    ]