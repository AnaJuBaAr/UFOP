/*       Veiculo
 * ---------------------
 * - blindagem: int
 * - potenciaDeFogo: int
 * ---------------------
 * + getPoderAtaque()
 * 
 * getPoderAtaque():
 *  ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10
 *  poderAtaque: entre 40 e 80
 *  blindagem: entre 30 e 70
 *  potenciaDeFogo: entre 20 e 50
 *  polimorfismo
 * 
 * Herda de Unidade
 */

#include "Veiculo.h"

Veiculo :: Veiculo() : Unidade(){
    //gerador de numeros aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribuicaoPoderAtaque(40, 80);
    setPoderAtaque(distribuicaoPoderAtaque(gen));

    std::uniform_int_distribution<int> distribuicaoBlindagem(30, 70);
    blindagem = distribuicaoBlindagem(gen);

    std::uniform_int_distribution<int> distribuicaoPotenciaDeFogo(20, 50);
    potenciaDeFogo = distribuicaoPotenciaDeFogo(gen);
}

int Veiculo :: getBlindagem() const{
    return blindagem;
}
void Veiculo :: setBlindagem(int e_blindagem){
    blindagem = e_blindagem;
}

int Veiculo :: getPotenciaDeFogo() const{
    return potenciaDeFogo;
}
void Veiculo :: setPotenciaDeFogo(int e_potenciaDeFogo){
    potenciaDeFogo = e_potenciaDeFogo;
}

int Veiculo :: getPoderAtaque(){
    int poderAtaque = ((getPoderAtaqueUnidade() * 5) + (getBlindagem() * 4) + (getPotenciaDeFogo() * 1)) / 10;
    return poderAtaque;
}

void Veiculo :: printUnidade(){
    std::cout << "Blindagem: " << getBlindagem() << ", " 
              << "Potencia de fogo: " << getPotenciaDeFogo() << std::endl;
}

std::string Veiculo :: getTipo(){
    return "Veiculo";
}