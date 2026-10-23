#include <iostream>
#include "Campanha.h"
#include "Date.h"

int main() {
    Date date(12, 7, 2005);

    Campanha campanha;

    campanha.adicionarBatalha(date, "Espartanos", "Persas");
    campanha.adicionarBatalha(date, "Romanos", "Germânicos");
    campanha.adicionarBatalha(date, "Persas", "Assírios");
    campanha.adicionarBatalha(date, "Espartanos", "Germânicos");

    campanha.simularBatalhas();

    campanha.gerarTabelaDePosicoes(7);

    campanha.mostrarUnidadeMaisDestrutiva();

    return 0;
}   