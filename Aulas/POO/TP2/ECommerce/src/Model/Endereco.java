package Model;

public class Endereco {
    private String pais;
    private String cep;
    private String estado;
    private String cidade;
    private String bairro;
    private String logradouro;
    private String numero;
    private String complemento;

    public Endereco(){}

    public void setPais(String pais){
        this.pais = pais;
    }
    public String getPais(){
        return pais;
    }

    public void setCep(String cep){
        this.cep = cep;
    }
    public String getCep(){
        return cep;
    }

    public void setEstado(String estado){
        this.estado = estado;
    }
    public String getEstado(){
        return estado;
    }

    public void setCidade(String cidade){
        this.cidade = cidade;
    }
    public String getCidade(){
        return cidade;
    }

    public void setBairro(String bairro){
        this.bairro = bairro;
    }
    public String getBairro(){
        return bairro;
    }

    public void setLogradouro(String logradouro){
        this.logradouro = logradouro;
    }
    public String getLogradouro(){
        return logradouro;
    }

    public void setNumero(String numero){
        this.numero = numero;
    }
    public String getNumero(){
        return numero;
    }

    public void setComplemento(String complemento){
        this.complemento = complemento;
    }
    public String getComplemento(){
        return complemento;
    }
}
