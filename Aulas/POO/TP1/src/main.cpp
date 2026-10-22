#include <iostream>
#include "Campanha.h"
#include "Date.h"

int main() {
    Date date(12, 7, 2005);

    Campanha campanha;

    campanha.adicionarBatalha(date, "1", "2");
    campanha.adicionarBatalha(date, "3", "4");

    campanha.simularBatalhas();

    campanha.gerarTabelaDePosicoes(7);

    campanha.mostrarUnidadeMaisDestrutiva();

    return 0;
}   