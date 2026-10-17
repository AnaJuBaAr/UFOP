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
        virtual ~Unidade(){}

        int getPoderAtaque() const{
            return poderAtaque;
        }
        void setPoderAtaque(int pa){
            poderAtaque = pa;
        }

        int getDestruicoes() const{
            return destruicoes;
        }
        void setDestruicoes(int des){
            destruicoes = des;
        }

        //funcao polimorfica pura
        int virtual getPoderAtaque() = 0;
        //
        void somaDestruicoes();
};

#endif