#ifndef CAMPANHA_H
#define CAMPANHA_H

#include "Batalha.h"
#include "Aeronave.h"
#include "Infantaria.h"
#include "Veiculo.h"

#include <algorithm>
#include <fstream>

/*              Campanha
 * ---------------------------------------
 * - batalhas: vector<Batalha*>
 * ---------------------------------------
 * + simularBatalhas(): void
 * + gerarTabelaDePosicoes(): void
 * + mostrarUnidadeMaisDestrutiva(): void
 * 
 * É composto por Batalha
 */

class Campanha{
    private:
        std::vector<Batalha*> batalhas;

    public:
        Campanha();
        ~Campanha();

        std::vector<Batalha*> getBatalhas() const;
        void setBatalhas(std::vector<Batalha*>);

        void adicionarBatalha(Date, std::string, std::string);

        void simularBatalhas();
        void gerarTabelaDePosicoes(int);
        void mostrarUnidadeMaisDestrutiva();
};

#endif