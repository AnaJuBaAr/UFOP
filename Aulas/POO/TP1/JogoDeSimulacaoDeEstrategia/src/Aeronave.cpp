/*     Aeronave
 * --------------------
 * - manobralidade: int
 * - alcance: int
 * --------------------
 * + getPoderAtaque()
 * 
 * getPoderAtaque():
 *  ((poderAtaque * 5) + (manobralidade * 3) + (alcance * 2)) / 10
 *  poderAtaque: entre 50 e 90
 *  manobralidade: entre 30 e 70
 *  alcance: entre 20 e 50
 *  polimorfismo
 * 
 * Herda de Unidade
 */

#include "Aeronave.h"

Aeronave :: Aeronave() : Unidade(){
    //gerador de numeros aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribuicaoPoderAtaque(50, 90);
    setPoderAtaque(distribuicaoPoderAtaque(gen));

    std::uniform_int_distribution<int> distribuicaoManobralidade(30, 70);
    manobralidade = distribuicaoManobralidade(gen);

    std::uniform_int_distribution<int> distribuicaoAlcance(20, 50);
    alcance = distribuicaoAlcance(gen);
}

int Aeronave :: getManobralidade() const{
    return manobralidade;
}
void Aeronave :: setManobralidade(int e_manobralidade){
    manobralidade = e_manobralidade;
}

int Aeronave :: getAlcance() const{
    return alcance;
}
void Aeronave :: setAlcance(int e_alcance){
    alcance = e_alcance;
}

int Aeronave :: getPoderAtaque(){
    int poderAtaque = ((getPoderAtaque() * 5) + (getManobralidade() * 3) + (getAlcance() * 2) / 10);
    return poderAtaque;
}