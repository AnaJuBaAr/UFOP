#ifndef METODOS_H
#define METODOS_H

#include <stdio.h>

typedef struct{
    int chave;
    char titulo[31];
} Registro;

int AcessoSequencialIndexado(int indice[], int tamanho, Registro *item, FILE *arq);
int *Paginacao(FILE *arq);

#endif