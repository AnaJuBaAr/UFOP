#include "filaprocessos.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd_entradas;
    FilaProcesso *fila;
    FilaProcesso *log_CPU;

    qtd_entradas = primeiraEntrada();
    fila = criarFila(qtd_entradas);
    segundaEntrada(fila);
    int loop = repeticoes(fila);
    log_CPU = criarFila(0);
    escalonador(fila, log_CPU, loop);
    imprimeLog(log_CPU);
    destroiFila(fila);
    destroiFila(log_CPU);
    return 0;
}