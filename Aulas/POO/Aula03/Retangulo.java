// Implemente a classe Retangulo e as operacoes para calcular a area e o perimetro

package Aula03;

public class Retangulo{
    int altura;
    int largura;
    int perimetro;
    int area;

    public int getAltura(){
        return altura;
    }
    public void setAltura(int altura){
        this.altura = altura;
    }

    public int getLargura(){
        return largura;
    }
    public void setLargura(int largura){
        this.largura = largura;
    }

    public void CalcularPerimetro(){
        this.perimetro = getLargura() * 2 + getAltura() * 2;
    }
    public int getPerimetro(){
        return perimetro;
    }

    public void CalcularArea(){
        this.area = getLargura() * getAltura();
    }
    public int getArea(){
        return area;
    }
}
