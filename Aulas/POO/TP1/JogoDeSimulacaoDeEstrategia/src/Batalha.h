#ifndef BATALHA_H
#define BATALHA_H

#include "Exercito.h"
#include "Date.h"

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

class Batalha{
    private:
        Date data;
        Exercito *exercitoA;
        Exercito *exercitoB;
        int resultadoA;
        int resultadoB;

    public:
        Batalha(Date, Exercito*, Exercito*);
        ~Batalha(){}

        Date getData() const;
        void setData(Date);

        Exercito* getExercitoA() const;
        void setExercitoA(Exercito *);

        Exercito* getExercitoB() const;
        void setExercitoB(Exercito *);

        int getResultadoA() const;
        void setResultadoA(int);

        int getResultadoB() const;
        void setResultadoB(int);

        void ataqueExercitoA();
        void AtaqueExercitoB();
        std::string getResultado();
};

#endif