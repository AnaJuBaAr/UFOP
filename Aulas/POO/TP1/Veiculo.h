#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.h"

class Veiculo : public Unidade{
private:
    int blindagem;
    int potenciaDeFogo;
public:
    Veiculo();
    ~Veiculo();
};

#endif