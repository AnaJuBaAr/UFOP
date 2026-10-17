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

#include "Campanha.h"

Campanha :: Campanha(){
    batalhas = std::vector<Batalha*>();
}

std::vector<Batalha*> Campanha :: getBatalhas() const{
    return batalhas;
}

void Campanha :: setBatalhas(std::vector<Batalha*> e_batalhas){
    batalhas = e_batalhas;
}

//metodo para adicionar uma nova batalha

//metodo nao esta pronto
void Campanha :: simularBatalha(){
    //talvez criar metodo para criar batalha
    Date data(1, 1, 1);
    Exercito *tubaroes = new Exercito("tubaroes");
    Exercito *golfinhos = new Exercito("golfinhos");
    Batalha* batalha1 = new Batalha(data, tubaroes, golfinhos);
    batalhas.push_back(batalha1);
}

//void Campanha :: gerarTabelaDePosicoes()

//metodo nao esta pronto
void Campanha :: mostrarUnidadeMaisDestrutiva(){
    Unidade* unidadeMaisDestrutiva;

    for(Batalha *b : batalhas){
        Exercito* exercitos[2] = {
            b->getExercitoA(),
            b->getExercitoB()
        };

        for(Exercito* e : exercitos){
            for(Unidade* u : e->getUnidades()){

            }
        }
    }
}