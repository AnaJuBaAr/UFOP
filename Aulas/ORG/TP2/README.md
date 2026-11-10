# Trabalho Prático 2 - Simulando o sistema de memória cache
Simulador de sistema de memória com hierarquia (CPU, Cache1 < Cache2 < Cache3 < RAM)

## Descrição
O projeto simula a hierarquia de um sistema de memória que além da RAM possui três caches de tamanhos diferentes.

## Funcionalidades
- Mapeamento associativo
- Política de write-back com dirty bit
- Política de Least-Frequently-Used
- Contagem de hits, misses e custo

## Como compilar e executar
1. Limpe o que quer que possa ter sido gerado em uma execução anterior
```bash
make clean
```
2. Execute o Makefile para compilar os arquivos do projeto
```bash
make
```
3. Execute o projeto
```bash
make run
```

## Estrutura do projeto
```
TP2/
├── src/
│   ├──Address.h        # TAD de um endereço
│   ├──Cache.h          # Simula as operações de criação e manipulação de caches, além de lidar com a política de LFU
│   ├──Cpu.h            # Simula as operações de criação e manipulação de uma CPU
│   ├──Generator.h      # Gera as instruções a serem testadas
│   ├──Instructions.h   # Lida com as instruções de forma mais encapsulada
│   ├──Main.c
│   ├──Memory.h         # Memoria que é tida em blocos na RAM e em linhas nas Caches
│   ├──Mmu.h            # Memory Management Unit
│   ├──Ram.h            # Simula as operações de criação e manipulação de uma RAM
│   ├──Support.h        # Funções auxiliares para o funcionamento da main 
│   └──System.h         # Simula um sistema de memória com uma RAM e três Caches
└── 
Makefile                # Arquivo Makefile com comandos convenientes para teste
```
### Cache `findCache`
* Acha a linha do cache com o endereço desejado e retorna o índice da mesma.
* Se não for encontrado retorna -1.
### Cache `insertCache`
* Acha a posição desejada usando **findLFU**.
* Passa as informações atuais da posição para **evicted**
* Armazena **src** na posição
### Cache `findLFU`
* Se alguma linha do cache estiver vaga, retorna o índice da mesma
* Caso contrário, retorna o índice da linha menos frequentemente usada
### MMU `searchInMemory`
* Procura em que nível e posição um dado endereço se encontra nas caches
* Se achar no primeiro cache, retorna a linha
* Se achar em algum dos outros caches ou na RAM, faz uma escalada de nível em nível
### MMU `insertMemory`
* Roda o **insertCache** para achar a posição em que o source será armazenado
* Se o evicted precisar (for valido e sujo), chama o **writeBackMemory**
### MMU `writeBackMemory`
* Acha a primeira posição vazia do nível em que a linha está sendo retirada pra baixo e a armazena ali.
* Se necessário, armazena de volta apenas na RAM
### MMU `writeInMemory`
* Acha a linha a ser atualizada usando **searchInMemory**
* Atualiza seu valor e seu estatus de atualizada
### MMU `flushMemory`
* Passeia do todo das caches até o fim confirmando se existe alguma linha atualizada
* Se achar linhas atualizadas, chama o **writeBackMemory** para todas elas
## Generator
* Programa de autoria Luísa Calegari, Thiago Cecote e Josué Vila Real
* Só foi adaptado para novas métricas fornecidas pelo professor

## Exemplo de saída
```
10000 instrucoes carregadas com sucesso
Programa terminou

========== RESULTADOS TESTE 1 ==========
Cache level 1: hits: 16919; misses: 23081; taxa de acertos: 42.30%
Cache level 2: hits: 10869; misses: 12212; taxa de acertos: 47.09%
Cache level 3: hits: 11859; misses: 353; taxa de acertos: 97.11%
RAM: acessos: 471
Custo total: 21803600
Programa terminou

========== RESULTADOS TESTE 2 ==========
Cache level 1: hits: 39648; misses: 352; taxa de acertos: 99.12%
Cache level 2: hits: 4; misses: 348; taxa de acertos: 1.14%
Cache level 3: hits: 16; misses: 332; taxa de acertos: 4.60%
RAM: acessos: 449
Custo total: 5328900
Programa terminou

========== RESULTADOS TESTE 3 ==========
Cache level 1: hits: 24823; misses: 15177; taxa de acertos: 62.06%
Cache level 2: hits: 14829; misses: 348; taxa de acertos: 97.71%
Cache level 3: hits: 32; misses: 316; taxa de acertos: 9.20%
RAM: acessos: 431
Custo total: 6688800
Programa terminou

========== RESULTADOS TESTE 4 ==========
Cache level 1: hits: 16919; misses: 23081; taxa de acertos: 42.30%
Cache level 2: hits: 22728; misses: 353; taxa de acertos: 98.47%
Cache level 3: hits: 21; misses: 332; taxa de acertos: 5.95%
RAM: acessos: 449
Custo total: 7910200
Programa terminou

========== RESULTADOS TESTE 5 ==========
Cache level 1: hits: 24823; misses: 15177; taxa de acertos: 62.06%
Cache level 2: hits: 14824; misses: 353; taxa de acertos: 97.67%
Cache level 3: hits: 5; misses: 348; taxa de acertos: 1.42%
RAM: acessos: 466
Custo total: 6967400

=========== COMPARACAO DOS SISTEMAS ===========
Teste | L1 / L2 / L3    |   Hits | Misses | Taxa acer |   RAM |  Custo total
------+-----------------+--------+--------+-----------+-------+-------------
1     | 8 / 16 / 32     |  39647 |    353 |    99.12% |   471 |     21803600
2     | 32 / 64 / 128   |  39668 |    332 |    99.17% |   449 |      5328900
3     | 16 / 64 / 256   |  39684 |    316 |    99.21% |   431 |      6688800
4     | 8 / 32 / 128    |  39668 |    332 |    99.17% |   449 |      7910200
5     | 16 / 32 / 64    |  39652 |    348 |    99.13% |   466 |      6967400

```

## Autores
- Ana Júlia Barros Araújo
- Organização de computadores
- 08/11/2026