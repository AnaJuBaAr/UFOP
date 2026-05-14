#ifndef FORMULA_H
#define FORMULA_H

typedef struct{
    int literais[3];
}Clausula;

typedef struct{
    Clausula *clausulas;
    int qtdVariaveis;
    int qtdClausulas;
}Formula;

Formula *criaFormula(int, int);
//destroiFormula();
void adicionaClausula(Formula *);
void imprimeFormula(Formula *);
//solucaoFormula();

#endif