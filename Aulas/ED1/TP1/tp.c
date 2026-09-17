#include "formula.h"

#include <stdio.h>

int main(){
    int qtdVariaveis, qtdClausulas;
    scanf("%d%d", &qtdVariaveis, &qtdClausulas);
    Formula *formula = criaFormula(qtdVariaveis, qtdClausulas);

    adicionaClausula(formula);
}