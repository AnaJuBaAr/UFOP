#ifndef EXERCITO_H
#define EXERCITO_H

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
 * É composto por Unidade
 * Compoe uma Batalha
 */

 #include "Unidade.h"
 
 #include <vector>

class Exercito{
    private:
        std::string nome;
        std::vector<Unidade*> unidades;
        int vitorias;
        int derrotas;
        int empates;
        
    public:
        Exercito(std::string);
        ~Exercito(){}

        std::string getNome() const;
        void setNome(std::string);

        std::vector<Unidade*> getUnidades() const;
        void setUnidades(std::vector<Unidade*>);

        int getVitorias() const;
        void setVitorias(int);

        int getDerrotas() const;
        void setDerrotas(int);

        int getEmpates() const;
        void setEmpates(int);

        void adicionarUnidade(Unidade*);

        std::string getResultado();
        
        void imprimeUnidade();
};

#endif