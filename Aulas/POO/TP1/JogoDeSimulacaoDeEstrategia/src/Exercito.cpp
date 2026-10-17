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

Exercito :: Exercito(std::string e_nome){
    nome = e_nome;
    unidades = std::vector<Unidade*>();
    vitorias = 0;
    derrotas = 0;
    empates = 0;
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

std::string Exercito :: getResultado(){
    std::string resultado = "Vitórias: %d, Empates: %d, Derrotas: %d", getVitorias(), getEmpates(), getDerrotas();
    return resultado;
}

void Exercito :: imprimeUnidade(){

}