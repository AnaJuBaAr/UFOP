/*            Exercito
 * -----------------------------------
 * - nome: std::string
 * - unidades: vector<Unidade*>
 * - vitorias: int
 * - derrotas: int
 * - empates: int
 * -----------------------------------
 * + adicionarUnidade(Unidade+): void
 * + getResultados(): std::string
 * + imprimeUnidades(): void
 * 
 * É composto por Unidade. Cada exercito possui 5 unidades das quais duas sao infantaria, duas sao veiculo e 1 eh aeronave
 * Compoe uma Batalha
 */

#include "Unidade.h"
#include "Exercito.h"
#include "Infantaria.h"

Exercito :: Exercito(std::string e_nome){
    nome = e_nome;
    unidades = std::vector<Unidade*>();
    vitorias = 0;
    derrotas = 0;
    empates = 0;
}

Exercito :: ~Exercito(){
    for(size_t i = 0; i < unidades.size(); i++){
        delete unidades[i];
    }
    unidades.clear();
}

std::string Exercito :: getNome() const{
    return nome;
}
void Exercito :: setNome(std::string e_nome){
    nome = e_nome;
}

std::vector<Unidade*> Exercito :: getUnidades() const{
    return unidades;
}
void Exercito :: setUnidades(std::vector<Unidade*> e_unidades){
    unidades = e_unidades;
}

int Exercito :: getVitorias() const{
    return vitorias;
}
void Exercito :: setVitorias(int e_vitorias){
    vitorias = e_vitorias;
}

int Exercito :: getDerrotas() const{
    return derrotas;
}
void Exercito :: setDerrotas(int e_derrotas){
    derrotas = e_derrotas;
}

int Exercito :: getEmpates() const{
    return empates;
}
void Exercito :: setEmpates(int e_empates){
    empates = e_empates;
}

void Exercito :: adicionarUnidade(Unidade* e_unidade){
    unidades.push_back(e_unidade);
}

//soma total do poder de ataque de todas as unidades dentro do exercito para ser usado no calculo de quem ganhou o ataque
int Exercito :: getPoderAtaqueTotal(){
    int resultado = 0;
    for(size_t i = 0; i < unidades.size(); i++){
        resultado += unidades[i]->getPoderAtaque();
    }
    
    return resultado;
}

void Exercito :: somaVitorias(){
    setVitorias(getVitorias()+1);
}

void Exercito :: somaDerrotas(){
    setDerrotas(getDerrotas()+1);
}

void Exercito :: somaEmpates(){
    setEmpates(getEmpates()+1);
}

void Exercito :: somaDestruicaoUnidades(){
    for(size_t i = 0; i < unidades.size(); i++){
        unidades[i]->somaDestruicoes();
    }
}

std::string Exercito :: getResultado(){
    std::string resultado = 
                            "Vitórias: " + std::to_string(getVitorias()) +
                            ", Empates: " + std::to_string(getEmpates()) +
                            ", Derrotas: " + std::to_string(getDerrotas()) + "\n";
    return resultado;
}

void Exercito :: imprimeUnidade(){
    for(size_t i = 0; i < unidades.size(); i++){
        std::cout << "Unidade " << i+1 << std::endl;
        std::cout << "Poder de ataque: " << unidades[i]->getPoderAtaque() << std::endl;
        std::cout << "Destruições: " << unidades[i]->getDestruicoes() << std::endl;
    }
}