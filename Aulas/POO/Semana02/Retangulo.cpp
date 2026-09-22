// CLASSES
#include <iostream>
using namespace std;

class Retangulo{
    double altura, base;

    public:
    void setAltura(double alt){
        altura = alt;
    }
    void setBase(double bas){
        base = bas;
    }

    double getAltura() const{
        return altura;
    }
    double getBase() const{
        return base;
    }
    double calculaArea(){
        return getAltura() * getBase();
    }
    double calculaPerimetro(){
        return getAltura() * 2 + getBase() * 2;
    }
};