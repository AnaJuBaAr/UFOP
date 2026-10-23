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

Campanha :: ~Campanha(){
    for(size_t i = 0; i < batalhas.size(); i++){
        delete batalhas[i];
    }
    batalhas.clear();
}

std::vector<Batalha*> Campanha :: getBatalhas() const{
    return batalhas;
}

void Campanha :: setBatalhas(std::vector<Batalha*> e_batalhas){
    batalhas = e_batalhas;
}

void Campanha :: adicionarBatalha(Date date,std::string nomeA, std::string nomeB){

    Exercito* exercitoA = new Exercito(nomeA);
    Infantaria* infantaria1 = new Infantaria;
    Infantaria* infantaria2 = new Infantaria;
    Veiculo* veiculo1 = new Veiculo;
    Veiculo* veiculo2 = new Veiculo;
    Aeronave* aeronave1 = new Aeronave;
    exercitoA->adicionarUnidade(infantaria1);
    exercitoA->adicionarUnidade(infantaria2);
    exercitoA->adicionarUnidade(veiculo1);
    exercitoA->adicionarUnidade(veiculo2);
    exercitoA->adicionarUnidade(aeronave1);

    Exercito* exercitoB = new Exercito(nomeB);
    Infantaria* infantaria3 = new Infantaria;
    Infantaria* infantaria4 = new Infantaria;
    Veiculo* veiculo3 = new Veiculo;
    Veiculo* veiculo4 = new Veiculo;
    Aeronave* aeronave2 = new Aeronave;
    exercitoB->adicionarUnidade(infantaria3);
    exercitoB->adicionarUnidade(infantaria4);
    exercitoB->adicionarUnidade(veiculo3);
    exercitoB->adicionarUnidade(veiculo4);
    exercitoB->adicionarUnidade(aeronave2);

    Batalha* batalha = new Batalha(date, exercitoA, exercitoB);

    batalhas.push_back(batalha);
}

void Campanha :: simularBatalhas(){
    for(size_t i = 0; i < batalhas.size(); i++){
        batalhas[i]->ataqueExercitoA();
        batalhas[i]->ataqueExercitoB();

        std::cout << batalhas[i]->getResultado();
    }
}

/* Passeia por todo o vetor de batalhas. Em cada batalha, olha se o nome dos exercitos já
existe em um vetor local, se sim faz nada, senão coloca o exercito no vetor*/
void Campanha :: gerarTabelaDePosicoes(int possibilidade){
    std::vector<Exercito*> exercitos;

    for(size_t i = 0; i < batalhas.size(); i++){
        bool existe = false;

        for(size_t j = 0; j < exercitos.size(); j++){
            if(exercitos[j]->getNome() == batalhas[i]->getExercitoA()->getNome()){
                exercitos[j]->setVitorias(exercitos[j]->getVitorias() + batalhas[i]->getExercitoA()->getVitorias());
                existe = true;
                break;
            }
        }
        if(!existe){
            Exercito* a = batalhas[i]->getExercitoA();
            a->setVitorias(batalhas[i]->getExercitoA()->getVitorias());   // zera e já soma o resultado desta batalha
            exercitos.push_back(a);
        }

        existe = false;
        for(size_t j = 0; j < exercitos.size(); j++){
            if(exercitos[j]->getNome() == batalhas[i]->getExercitoB()->getNome()){
                exercitos[j]->setVitorias(exercitos[j]->getVitorias() + batalhas[i]->getExercitoB()->getVitorias());
                existe = true;
                break;
            }
        }
        if(!existe){
            Exercito* b = batalhas[i]->getExercitoB();
            b->setVitorias(batalhas[i]->getExercitoB()->getVitorias());
            exercitos.push_back(b);
        }
    }

    //ordena os exercitos em ordem decrescente pelo numero de vitorias
    std::sort(exercitos.begin(), exercitos.end(), [](Exercito* a, Exercito* b){
        return a->getVitorias() > b->getVitorias();
    });

    //imprimir na tela
    if(possibilidade == 1){
        for(size_t i = 0; i < exercitos.size(); i++){
            std::cout << "Exercito " << exercitos[i]->getNome() << ". " << exercitos[i]->getVitorias() << std::endl;
        }
    }
    //salva em arquivo .txt
    else{
        std::ofstream arquivo("tabela.txt");
        for(size_t i = 0; i < exercitos.size(); i++){
            arquivo << "Exercito " << exercitos[i]->getNome() << ". " << exercitos[i]->getVitorias() << std::endl;
        }
        arquivo.close();
    }
}

void Campanha :: mostrarUnidadeMaisDestrutiva(){
    Unidade* unidadeMaisDestrutiva = nullptr;
    Exercito* exercitoPertencente = nullptr;

    for(size_t i = 0; i < batalhas.size(); i++){
        for(size_t j = 0; j < batalhas[i]->getExercitoA()->getUnidades().size(); j++){
            if((unidadeMaisDestrutiva == nullptr) || (batalhas[i]->getExercitoA()->getUnidades()[j]->getDestruicoes() > unidadeMaisDestrutiva->getDestruicoes())){
                unidadeMaisDestrutiva = batalhas[i]->getExercitoA()->getUnidades()[j];
                exercitoPertencente = batalhas[i]->getExercitoA();
            }
            if(batalhas[i]->getExercitoB()->getUnidades()[j]->getDestruicoes() > unidadeMaisDestrutiva->getDestruicoes()){
                unidadeMaisDestrutiva = batalhas[i]->getExercitoB()->getUnidades()[j];
                exercitoPertencente = batalhas[i]->getExercitoB();
            }
        }
    }

    std::cout << "Unidade mais destrutiva. " 
              << "Exercito: " << exercitoPertencente->getNome() << ", "
              << "Unidade de " << unidadeMaisDestrutiva->getTipo() << ". "
              << "Poder de ataque: " << unidadeMaisDestrutiva->getPoderAtaque() 
              << ", Destruições: " << unidadeMaisDestrutiva->getDestruicoes() << std::endl;
    unidadeMaisDestrutiva->printUnidade();
}