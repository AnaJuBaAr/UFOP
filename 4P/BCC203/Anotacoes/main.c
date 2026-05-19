#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "metodos.h"

int main(){
    /*FILE *arq = fopen("arquivo.bin", "rb");

    Registro x;
    x.chave = 80;

    int *indice = Paginacao(arq);

    if(AcessoSequencialIndexado(indice, 4, &x, arq)){
        printf("Livro(%d): %s\n", x.chave, x.titulo);
    } else{
        printf("Livro não encontrado\n");
    }*/

    Registro registro;
    registro.chave = 80;
        
    Ponteiro arvore = inicializa();

    insereArq(&arvore);

    imprime(arvore);

    //pesquisaAB(&registro, arvore->ponteiros[0]);
    
    liberararvore(arvore);

    return 0;
}