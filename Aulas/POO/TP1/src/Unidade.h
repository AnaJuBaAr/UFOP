#ifndef UNIDADE_H
#define UNIDADE_H

#include <iostream>
using namespace std;

/*        Unidade
 * -----------------------
 * - poderAtaque: int
 * - destruicoes: int
 * -----------------------
 * + getPoderAtaque(): int
 * + somaDestruicao()
 * 
 * poderAtaque():
 *  calculado com getPoderAtaque() das subclasses.
 *  polimorfiasmo
 * 
 * Compoe um Exercito
 * Heranca de Aeronave, Infantaria e Veiculo
 */

class Unidade{
    private:
        int poderAtaque;
        int destruicoes;

    public:
        //construtor e destrutor
        Unidade();
        virtual ~Unidade() = default;

        int getPoderAtaqueUnidade() const;
        void setPoderAtaque(int e_poderAtaque);

        int getDestruicoes() const;
        void setDestruicoes(int e_destruicoes);

        //funcao polimorfica pura
        int virtual getPoderAtaque() = 0;
        //
        void somaDestruicoes();
};

#endif