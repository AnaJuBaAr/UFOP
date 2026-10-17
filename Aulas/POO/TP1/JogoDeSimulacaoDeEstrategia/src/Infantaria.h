#ifndef INFANTARIA_H
#define INFANTARIA_H

#include "Unidade.h"

#include <random>

class Infantaria : public Unidade{
    private:
        int forca;
        int velocidade;
    public:
        Infantaria();
        ~Infantaria(){}

        int getForca() const;
        void setForca(int);

        int getVelocidade() const;
        void setVelocidade(int);

        int getPoderAtaque() override;
};

#endif