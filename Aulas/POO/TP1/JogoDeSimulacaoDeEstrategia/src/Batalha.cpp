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

void Batalha :: ataqueExercitoA(){
    
}
//void Batalha :: AtaqueExercitoB()

//std::string Batalha :: getResultado()