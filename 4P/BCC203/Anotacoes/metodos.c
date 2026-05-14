#include <stdio.h>
#include <stdlib.h>

#include "metodos.h"

#define TAMPAGINA 10

int AcessoSequencialIndexado(int indice[], int tamanho, Registro *item, FILE *arq){
    //busca em que página a chave do item buscado provavelmente se encontra, comparando-o com a tabela do índice das páginas
    int i = 0;
    while(i < tamanho && indice[i] <= item->chave){
        i++;
    }
    //confirma que existe a possibilidade de a chave estar no arquivo
    if(i == 0){
        return 0;
    }

    //confirma a quantidade de Registros na página a ser aberta
    fseek(arq, 0, SEEK_END);
    int quantItens = (ftell(arq)/sizeof(Registro)) % TAMPAGINA;
    if(quantItens == 0){
        quantItens = TAMPAGINA;
    }

    //calcula o deslocamento necessário para chegar ao início da página desejada
    int desloc = (i-1) * TAMPAGINA * sizeof(Registro);
    fseek(arq, desloc, SEEK_SET);
    //abre a página desejada na memória principal
    Registro pagina[quantItens];
    fread(&pagina, sizeof(Registro), quantItens, arq);

    //busca pela chave desejada dentro da página por meio de pesquisa binária
}

int *Paginacao(FILE *arq){
    //estima a quantidade de páginas possíveis dado um tamanho fixo
    fseek(arq, 0, SEEK_END);
    int tamFinal = ftell(arq)/sizeof(Registro);
    int quantPaginas = (tamFinal / TAMPAGINA) + (tamFinal % TAMPAGINA);

    //cria um vetor para o indice das paginas
    int *indice = (int*)malloc(quantPaginas * sizeof(int));
    int i = 0;

    //preenche o vetor indice com a chave do primeiro registro de cada pagina
    rewind(arq);
    Registro pagina[TAMPAGINA];
    while(fread(pagina, sizeof(Registro), TAMPAGINA, arq) <= TAMPAGINA){
        indice[i++] = pagina[0].chave;
    }

    //retorna o indice criado
    return indice;
}