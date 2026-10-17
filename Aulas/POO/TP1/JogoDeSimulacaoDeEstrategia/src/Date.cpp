/*            Date
 * -----------------------------
 * - dia: int
 * - mes: int
 * - ano: int
 * -----------------------------
 * + formatarData(): std::string
 * 
 * Compoe uma Batalha
 */

#include "Date.h"

Date :: Date(int e_dia, int e_mes, int e_ano){
    dia = e_dia;
    mes = e_mes;
    ano = e_ano;
}

int Date :: getDia() const{
    return dia;
}
void Date :: setDia(int e_dia){
    dia = e_dia;
}

int Date :: getMes() const{
    return mes;
}
void Date :: setMes(int e_mes){
    mes = e_mes;
}

int Date :: getAno() const{
    return ano;
}
void Date :: setAno(int e_ano){
    ano = e_ano;
}

std::string Date :: formatarData(){
    std::string data = "%d/%d/%d", getDia(), getMes(), getAno();
    return data;
}