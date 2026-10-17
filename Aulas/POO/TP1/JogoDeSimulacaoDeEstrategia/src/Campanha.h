#ifndef CAMPANHA_H
#define CAMPANHA_H

#include "Batalha.h"

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
        ~Campanha(){}

        std::vector<Batalha*> getBatalhas() const;
        void setBatalhas(std::vector<Batalha*>);

        void simularBatalha();
        void gerarTabelaDePosicoes();
        void mostrarUnidadeMaisDestrutiva();
};

#endif