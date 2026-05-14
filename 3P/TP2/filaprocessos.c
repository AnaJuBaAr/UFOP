#include "filaprocessos.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>

#define MC 100

//le e retorna a quantidade de entradas a serem lidas
int primeiraEntrada(){
    int qtd_entradas;
    scanf("%d", &qtd_entradas);
    return qtd_entradas;
}

//cria uma FilaProcesso com uma quantidade x de Processos dentro
FilaProcesso *criarFila(int tamanho){
    FilaProcesso *fila = (FilaProcesso*)malloc(sizeof(FilaProcesso));
    fila->tamanho = tamanho;
    fila->filaProcessos = criarProcesso(tamanho);
    
    return fila;
}

Processo *criarProcesso(int tamanho){
    Processo *processos = (Processo*)malloc(tamanho * sizeof(Processo));

    return processos;
}

//le e armazena o ID, T, P e C de cada um dos Processos
void segundaEntrada(FilaProcesso *fila){
    for(int i = 0; i < fila->tamanho; i++){
        __fpurge(stdin);
        scanf("%d", &fila->filaProcessos[i].ID);
        scanf("%f", &fila->filaProcessos[i].T);
        scanf("%d", &fila->filaProcessos[i].P);
        scanf("%d", &fila->filaProcessos[i].C);
    }
    mergeSort(fila->filaProcessos, 0, fila->tamanho-1);
}

//particiona a fila ao meio até que a particao so tenha 1 processso
void mergeSort(Processo *fila, int esquerda, int direita){
    if(esquerda < direita){
        int meio = (esquerda + direita) / 2;
        mergeSort(fila, esquerda, meio);
        mergeSort(fila, meio+1, direita);
        merge(fila,esquerda, meio, direita);
    }
}

//ordena os processos por ordem de execucao
void merge(Processo *fila, int esquerda, int meio, int direita){
    int size_esq = (meio - esquerda + 1);
    int size_dir = (direita - meio);

    Processo *fila_esq = criarProcesso(size_esq);
    Processo *fila_dir = criarProcesso(size_dir);

    //preenche as filas da esquerda e direita
    int i;
    for(i = 0; i < size_esq; i++){
        fila_esq[i] = fila[i+esquerda];
    }
    int j;
    for(j = 0; j < size_dir; j++){
        fila_dir[j] = fila[meio+j+1];
    }

    i = j = 0;

    for(int k = esquerda; k <= direita; k++){
        if(i < size_esq && j < size_dir){ //confere se as filas dos dois lados ainda possuem processos
            if(comparar(fila_esq[i], fila_dir[j])){ //compara se o processo da esquerda vem antes do processo da direita
                fila[k] = fila_esq[i];
                i++;
            } else{
                fila[k] = fila_dir[j];
                j++;
            }
        } else if(i < size_esq){
            fila[k] = fila_esq[i];
            i++;
        } else if(j < size_dir){
            fila[k] = fila_dir[j];
            j++;
        }
    }
    destroiProcesso(fila_dir);
    destroiProcesso(fila_esq);
}

//compara dois processos para saber se eles devem ordenados pelo nível de prioridade (P) ou pelo tempo de chegada (T)
int comparar(Processo processo1, Processo processo2){
    if(processo1.P < processo2.P){ //se a prioridade 1 for menor que a prioridade 2: retorna TRUE
        return 1;
    } else if(processo1.P > processo2.P){ //se a prioridade 1 for maior que a prioridade 2: retorna FALSE
        return 0;
    } else{ //se as prioridades forem iguais
        return (processo1.T <= processo2.T) ? 1 : 0; //retorna TRUE se o tempo 1 for menor ou igual ao tempo 2 e retorna FALSE caso tempo 1 seja maior que tempo 2
    }
}

//calcula a quantidade de vezes o escalonador será repetido para que todos os proccesso sejam completamente realizados
int repeticoes(FilaProcesso *fila){
    int repeticoes = 0;
    for(int i = 0; i < fila->tamanho; i++){
        repeticoes = repeticoes + fila->filaProcessos[i].C;
    }

    return repeticoes;
}

void escalonador(FilaProcesso *fila, FilaProcesso *log_CPU, int loop){
    if(loop > 0){
        int ciclos;
        if(fila->filaProcessos[0].C > MC){
            ciclos = MC;
        } else{
            ciclos = fila->filaProcessos[0].C;
        }

        adicionarLoopCPU(log_CPU, fila->filaProcessos[0], ciclos);
        fila->filaProcessos[0].P++;
        fila->filaProcessos[0].C = fila->filaProcessos[0].C - ciclos;
        adicionaFila(fila);

        loop = loop - ciclos;
        escalonador(fila, log_CPU, loop);
    }
}

void adicionarLoopCPU(FilaProcesso *fila, Processo processo, int ciclos){
    int index = fila->tamanho;

    aumentarCapacidadeFila(fila, fila->tamanho+1);

    fila->filaProcessos[index] = processo;
    fila->filaProcessos[index].C = ciclos;
}

void aumentarCapacidadeFila(FilaProcesso *fila, int novoTamanho){
    Processo *novaFila = (Processo*)realloc(fila->filaProcessos, novoTamanho * sizeof(Processo));
    fila->filaProcessos = novaFila;
    fila->tamanho = novoTamanho;
}

/*verifica se o processo já foi finalizado
    se sim, faz o insertSort dele em sua nova posição
    se não, adiciona o processo já finalizado na última posição da fila e move todos os outros processos para a posição anterior
*/
void adicionaFila(FilaProcesso *fila){
    moverPrimeiroProcesso(fila);
    if(fila->filaProcessos[fila->tamanho-1].C == 0){
        removerUltimoProcesso(fila);
    } else{
        insertionSort(fila);
    }
}

void moverPrimeiroProcesso(FilaProcesso *fila){
    Processo aux = fila->filaProcessos[0];
    for(int i = 0; i < fila->tamanho-1; i++){
            fila->filaProcessos[i] = fila->filaProcessos[i+1];
    }
    fila->filaProcessos[fila->tamanho-1] = aux;
}

void removerUltimoProcesso(FilaProcesso *fila){
    fila->tamanho--;
}

void insertionSort(FilaProcesso *fila){
    for(int i = 1; i < fila->tamanho; i++){
        Processo aux = fila->filaProcessos[i];
        int j = i - 1;

        while((j >= 0) && (aux.P < fila->filaProcessos[j].P)){
            fila->filaProcessos[j+1] = fila->filaProcessos[j];
            j--;
        }
        fila->filaProcessos[j+1] = aux;
    }
}

void imprimeLog(FilaProcesso *log_CPU){
    system("clear");
    printf("Log CPU:\n");
    for(int i = 0; i < log_CPU->tamanho; i++){
        printf("%d %d %d\n", log_CPU->filaProcessos[i].ID, log_CPU->filaProcessos[i].P, log_CPU->filaProcessos[i].C);
    }
}

//desaloca a quantidade de processo necessária para esvaziar a fila e depois desaloca uma FilaProcesso
void destroiFila(FilaProcesso *fila){
    destroiProcesso(fila->filaProcessos);
    free(fila);
}

//desaloca um Processo
void destroiProcesso(Processo *processo){
    free(processo);
}