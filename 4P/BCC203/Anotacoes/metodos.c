#include <stdio.h>
#include <stdlib.h>

#include "metodos.h"

#define TAMPAGINA 10

int AcessoSequencialIndexado(int indice[], int tamanho, Registro *item, FILE *arq){
    // procura a página onde o item pode se encontrar
    int i = 0;
    while(i < tamanho && indice[i] <= item->chave){
        i++;
    }

    //se a chave procurada for menor que a primeira chave, o item não existe no arquivo
    if(i == 0){
        return 0;
    }

    //a ultima pagina pode ser menor que as anteriores
    int quantItens;
    if(i < tamanho){ //a unica pagina que pode ser menor eh a ultima
        quantItens = TAMPAGINA;
    } else{
        fseek(arq, 0, SEEK_END);
        quantItens = (ftell(arq) / sizeof(Registro)) % TAMPAGINA;

        if(quantItens == 0){ //se a ultima pagina for do mesmo tamanho das anteriores
            quantItens = TAMPAGINA;
        }
    }

    //lê a página desejada do arquivo
    Registro pagina[TAMPAGINA];
    int desloc = (i-1) * TAMPAGINA * sizeof(Registro);
    fseek(arq, desloc, SEEK_SET);
    fread(pagina, sizeof(Registro), quantItens, arq);

    //pesquisa binária na página lida
    int esq = 0;
    int dir = quantItens-1;
    int meio;

    while(esq <= dir){
        meio = (esq + dir) / 2;
        if(pagina[meio].chave == item->chave){
            *item = pagina[meio];
            return 1;
        } else if(pagina[meio].chave < item->chave){
            esq = meio + 1;
        } else{
            dir = meio - 1;
        }
    }

    return 0;
}

int *Paginacao(FILE *arq){
    //estima a quantidade de páginas possíveis dado um tamanho fixo
    fseek(arq, 0, SEEK_END);
    int tamFinal = ftell(arq)/sizeof(Registro);
    int quantPaginas = (tamFinal + TAMPAGINA - 1) / TAMPAGINA;

    //cria um vetor para o indice das paginas
    int *indice = (int*)malloc(quantPaginas * sizeof(int));
    if(indice == NULL){
        return NULL;
    }

    int i = 0;

    //preenche o vetor indice com a chave do primeiro registro de cada pagina
    rewind(arq);
    Registro pagina[TAMPAGINA];
    size_t bytesLidos;

    while((bytesLidos = fread(pagina, sizeof(Registro), TAMPAGINA, arq)) > 0 && i < quantPaginas){
        indice[i++] = pagina[0].chave;
    }

    //retorna o indice criado
    return indice;
}