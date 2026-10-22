#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
private:
    int dia;
    int mes;
    int ano;
public:
    Date(){}
    Date(int, int, int);
    ~Date(){}

    int getDia() const;
    void setDia(int);

    int getMes() const;
    void setMes(int);

    int getAno() const;
    void setAno(int);

    std::string formatarData();
};

#endif