#ifndef METODOS_H
#define METODOS_H

#include <stdio.h>

#define M 2
#define MM 4
#define MM2 6

typedef struct{
    int chave;
    char titulo[31];
} Registro;

typedef struct Pagina *Ponteiro;

typedef struct Pagina{
    short quant;
    Registro registros[MM];
    Ponteiro ponteiros[MM+1];
} Pagina;

// ACESSO SEQUENCIAL INDEXADO
int pesquisaASI(int indice[], int tamanho, Registro *item, FILE *arq);
int *Paginacao(FILE *arq);

// ARVORE B
Ponteiro inicializa();
void pesquisaAB(Registro *registro, Ponteiro ponteiro);
void imprime(Ponteiro arvore);
void insereNaPagina(Ponteiro ponteiro, Registro registro, Ponteiro ponteiroDir);
void ins(Registro registro, Ponteiro ponteiro, short *cresceu, Registro *registroRetorno, Ponteiro *ponteiroRetorno);
void insere(Registro registro, Ponteiro *ponteiro);
void insereArq(Ponteiro *ponteiro);
void reconstitui(Ponteiro ponteiroPagina, Ponteiro ponteiroPai, int posicaoPai, short *diminuiu);
void antecessor(Ponteiro ponteiro, int ind, Ponteiro ponteiroPai, short *diminuiu);
void ret(int chave, Ponteiro *ponteiro, short *diminuiu);
void retira(int chave, Ponteiro *ponteiro);
void liberararvore(Ponteiro raiz);

#endif