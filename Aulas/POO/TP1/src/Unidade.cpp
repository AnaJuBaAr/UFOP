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

#include "Unidade.h"

Unidade :: Unidade(){
    poderAtaque = 0;
    destruicoes = 0;
}

int Unidade :: getPoderAtaqueUnidade() const{
    return poderAtaque;
}
void Unidade :: setPoderAtaque(int e_poderAtaque){
    poderAtaque = e_poderAtaque;
}

int Unidade :: getDestruicoes() const{
    return destruicoes;
}
void Unidade :: setDestruicoes(int e_destruicoes){
    destruicoes = e_destruicoes;
}

void Unidade :: somaDestruicoes(){
    setDestruicoes(getDestruicoes() + 1);
}