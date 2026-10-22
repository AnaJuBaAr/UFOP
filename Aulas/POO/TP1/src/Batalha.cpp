/*           Batalha
 * ------------------------------
 * - date: Date
 * - ExercitoA: Exercito*
 * - exercitoB: Exercito*
 * - resultadoA: int
 * - resultadoB: int
 * ------------------------------
 * + ataqueExercitoA(): void
 * + ataqueExercitoB(): void
 * + getResultado(): std::string
 * 
 * É composto por Exercito e por Date
 * Compoe uma Campanha
 */

#include "Batalha.h"

Batalha :: Batalha(Date e_data, Exercito* e_exercitoA, Exercito* e_exercitoB){
    data = e_data;
    exercitoA = e_exercitoA;
    exercitoB = e_exercitoB;
    resultadoA = 0;
    resultadoB = 0;
}

Batalha :: ~Batalha(){
    delete exercitoA;
    delete exercitoB;
}

Date Batalha :: getData() const{
    return data;
}
void Batalha :: setData(Date e_data){
    data = e_data;
}

Exercito* Batalha :: getExercitoA() const{
    return exercitoA;
}
void Batalha :: setExercitoA(Exercito* e_exercito){
    exercitoA = e_exercito;
}

Exercito* Batalha :: getExercitoB() const{
    return exercitoB;
}
void Batalha :: setExercitoB(Exercito* e_exercito){
    exercitoB = e_exercito;
}

int Batalha :: getResultadoA() const{
    return resultadoA;
}
void Batalha :: setResultadoA(int e_resultadoA){
    resultadoA = e_resultadoA;
}

int Batalha :: getResultadoB() const{
    return resultadoB;
}
void Batalha :: setResultadoB(int e_resultadoB){
    resultadoB = e_resultadoB;
}

/* Em um ataque, apenas o exercito que iniciou o conflito soma destruições às suas undades se o ataque for bem sucedido*/
void Batalha :: ataqueExercitoA(){
    int poderExercitoA = exercitoA->getPoderAtaqueTotal();
    int poderExercitoB = exercitoB->getPoderAtaqueTotal();

    if(poderExercitoA > poderExercitoB){
        exercitoA->somaVitorias();
        exercitoA->somaDestruicaoUnidades();

        exercitoB->somaDerrotas();
    }
    else if(poderExercitoA < poderExercitoB){
        exercitoA->somaDerrotas();

        exercitoB->somaVitorias();
    }
    else{
        exercitoA->somaEmpates();
        exercitoB->somaEmpates();
    }
}
void Batalha :: ataqueExercitoB(){
    int poderExercitoB = exercitoB->getPoderAtaqueTotal();
    int poderExercitoA = exercitoA->getPoderAtaqueTotal();

    if(poderExercitoB > poderExercitoA){
        exercitoB->somaVitorias();
        exercitoB->somaDestruicaoUnidades();

        exercitoA->somaDerrotas();
    }
    else if(poderExercitoB < poderExercitoA){
        exercitoB->somaDerrotas();

        exercitoA->somaVitorias();
    }
    else{
        exercitoB->somaEmpates();
        exercitoA->somaEmpates();
    }
}

std::string Batalha :: getResultado(){
    std::string resultado = 
                            exercitoA->getNome() + " " + std::to_string(exercitoA->getVitorias()) + " X " + 
                            std::to_string(exercitoB->getVitorias()) + " " + exercitoB->getNome() + "\n";
    return resultado;
}