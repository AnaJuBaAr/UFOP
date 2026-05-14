#ifndef METODOS_H
#define METODOS_H

#include <stdio.h>

typedef struct{
    int chave;
    long dado1;
    char dado2[1000];
    char dado3[5000];
} Registro;

int AcessoSequencialIndexado(int indice[], int tamanho, Registro *item, FILE *arq);
int *Paginacao(FILE *arq);

#endif