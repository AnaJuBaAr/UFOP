#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.h"

#include <random>

class Veiculo : public Unidade{
    private:
        int blindagem;
        int potenciaDeFogo;
    public:
        Veiculo();
        ~Veiculo(){}

        int getBlindagem() const;
        void setBlindagem(int);

        int getPotenciaDeFogo() const;
        void setPotenciaDeFogo(int);

        int getPoderAtaque() override;
};

#endif