/*    Infantaria
 * ------------------
 * - forca: int
 * - velocidade: int
 * ------------------
 * + getPoderAtaque()
 * 
 * getPoderAtaque():
 *  ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10
 *  poderAtaque: entre 30 e 60
 *  forca: entre 20 e 50
 *  velocidade: entre 10 e 40
 *  polimorfismo
 * 
 * Herda de Unidade
 */

#include "Infantaria.h"

Infantaria :: Infantaria() : Unidade(){
    //gerador de numeros aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribuicaoPoderAtaque(30, 60);
    setPoderAtaque(distribuicaoPoderAtaque(gen));

    std::uniform_int_distribution<int> distribuicaoForca(20, 50);
    forca = distribuicaoForca(gen);

    std::uniform_int_distribution<int> distribuicaoVelocidade(10, 40);
    velocidade = distribuicaoVelocidade(gen);
}

int Infantaria :: getForca() const{
    return forca;
}
void Infantaria :: setForca(int e_forca){
    forca = e_forca;
}

int Infantaria :: getVelocidade() const{
    return velocidade;
}
void Infantaria :: setVelocidade(int e_velocidade){
    velocidade = e_velocidade;
}

int Infantaria :: getPoderAtaque(){
    int poderAtaque = ((getPoderAtaqueUnidade() * 5) + (getForca() * 3) + (getVelocidade() * 2)) / 10;
    return poderAtaque;
}