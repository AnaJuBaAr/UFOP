#ifndef AERONAVE_H
#define AERONAVE_H

#include "Unidade.h"

#include <random>

class Aeronave : public Unidade{
    private:
        int manobralidade;
        int alcance;
        
    public:
        Aeronave();
        ~Aeronave(){}

        int getManobralidade() const;
        void setManobralidade(int);

        int getAlcance() const;
        void setAlcance(int);

        int getPoderAtaque() override;

        void printUnidade() override;
        std::string getTipo() override;
};

#endif