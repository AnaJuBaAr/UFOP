/*
    Escreva uma ou mais classes para calcular o saldo de uma conta corrente que percente a um correntista. Considere:
    1. O sistema deve permitir fazer saques, depositos e transferencias;
    2. O saldo nunca pode ser negativo;
    3. A conta corrente deve incluir a data de abertura da conta.
*/

package Aula03;

public class ContaCorrente{
    private int numeroConta;
    private int saldo;
    private Cliente contarrentista;
    private Data data;

    public boolean depositar(double valor){
        if(valor > 0){
            this.saldo += valor;

            return true;
        }

        return false;
    }

    public boolean saque(double valor){
        if(valor > this.saldo){
            return false;
        }

        this.saldo -= valor;

        return true;
    }

    public boolean transferencia(ContaCorrente destinatario, double valor){
        if(valor > this.saldo || destinatario == null){
            return false;
        }
        
        if(!destinatario.depositar(valor)){
            return false;
        }

        this.saldo -= valor;

        return true;
    }
}

class Cliente{
    private String nome;
    private String endereco;
    private String cpf;

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public String getCpf() {
        return cpf;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public String getEndereco() {
        return endereco;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
}

class Data{
    private int dia;
    private int mes;
    private int ano;

    public void setDia(int dia) {
        this.dia = dia;
    }
    public int getDia() {
        return dia;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }
    public int getMes() {
        return mes;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
    public int getAno() {
        return ano;
    }
}