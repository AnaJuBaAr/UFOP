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
│   ├──Address.h        #
│   ├──Cache.h          #
│   ├──Cpu.h            #
│   ├──Instructions.h   #
│   ├──Generator.h      #
│   ├──Main.c           #
│   ├──Memory.h         #
│   ├──Mmu.h            #
│   ├──Ram.h            #
│   └──System.h         #
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

## Autores
- Ana Júlia Barros Araújo
- Organização de computadores
- 08/11/2026