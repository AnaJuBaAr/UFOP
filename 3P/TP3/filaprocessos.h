#ifndef FILAPROCESSOS_H
#define FILAPROCESSOS_H

#define MAX_LINE 15
#define MAX_VAR 10

typedef struct no{
    char nome[MAX_VAR];
    char valor[MAX_VAR];
    struct no *pEsq;
    struct no *pDir;
} No;

typedef struct{
    No *pRaiz;
} Escopo;

typedef struct elemento{
    Escopo *escopo;
    struct elemento *pAnterior;
} Elemento;

typedef struct{
    Elemento *pTopo;
    int tamanho;
} Pilha;

Escopo *criarEscopo();
void destroiEscopo(No *no);
void adicionaVar(Escopo *escopo, const char *nome, const char *valor);
No *inserirNo(No *no, const char *nome, const char *valor);
No *criarNo(const char *nome, const char *valor);
No *buscarVar(No *no, const char *nome);

Pilha *criarPilha();
void destroiPilha(Pilha *pilha);
void adicionaPilha(Pilha *pilha);
int removerEscopo(Pilha *pilha);
void executar(const char *argv);
void processarLinha(Pilha *pilha, const char *linha);
Escopo *obterEscopoAtual(Pilha *pilha);
No *buscarVarPilha(Pilha *pilha, const char *nome);

#endif