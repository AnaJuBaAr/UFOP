#include "formula.h"

#include <stdlib.h>
#include <stdio.h>

Formula *criaFormula(int qtdVariaveis, int qtdClausulas){
    Formula *formula = (Formula*)malloc(sizeof(Formula));
    formula->qtdVariaveis = qtdVariaveis;
    formula->qtdClausulas = qtdClausulas;
    formula->clausulas = (Clausula*)malloc(qtdClausulas * sizeof(Clausula));

    return formula;
}

void adicionaClausula(Formula *formula){
    for(int i = 0; i < formula->qtdClausulas; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &formula->clausulas[i].literais[j]);
        }
    }
}

void imprimeFormula(Formula *formula){
    printf("Formula:\n");
}