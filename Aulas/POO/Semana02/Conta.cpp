// CLASSES
#include <iostream>
using namespace std;

class Conta{
    private:
    int numeroConta, saldo;
    Cliente contarrentista;
    Data data;

    public:
    bool depositar(double valor){
        if(valor > 0){
            saldo += valor;
            return true;
        }

        return false;
    }
    bool saque(double valor){
        if(valor > saldo){
            return false;
        }

        saldo -= valor;
        return true;
    }
    bool transferencia(Conta destinatario, double valor){
        if(valor > saldo){
            return false;
        }

        if(!destinatario.depositar(valor)){
            return false;
        }

        saldo -= valor;
        return true;
    }
};

class Cliente{
    private:
    string nome;
    string endereco;
    string cpf;
    
    public:
    void setNome(string name){
        nome = name;
    }
    void setCPG(string CPF){
        cpf = CPF;
    }
    void setEndereco(string end){
        endereco = end;
    }
    string getNome(){
        return nome;
    }
    string getCPF(){
        return cpf;
    }
    string getEndereco(){
        return endereco;
    }
};

class Data{
    private:
    int dia, mes, ano;

    public:
    void setDia(int day){
        dia = day;
    }
    void setMes(int month){
        mes = month;
    }
    void setANo(int year){
        ano = year;
    }
    int getDia(){
        return dia;
    }
    int getMes(){
        return mes;
    }
    int getAno(){
        return ano;
    }
};