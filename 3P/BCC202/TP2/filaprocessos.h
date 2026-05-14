#ifndef FILAPROCESSOS_H
#define FILAPROCESSOS_H

//TAD Processo
typedef struct{
    int ID;     //identificador
    float T;    //tempo de chegada
    int P;      //nível de prioridade
    int C;      //quantidade de ciclos na CPU
} Processo;

//TAD FilaProcesso
typedef struct{
    Processo *filaProcessos;
    int tamanho;
} FilaProcesso;

//==================== FUNÇÕES ====================//
int primeiraEntrada();

FilaProcesso *criarFila(int);

Processo *criarProcesso(int);

void segundaEntrada(FilaProcesso *);

void mergeSort(Processo *, int, int);

void merge(Processo *, int, int, int);

int comparar(Processo, Processo);

int repeticoes(FilaProcesso *);

//atende os processos seguindo a fila criada
void escalonador(FilaProcesso *, FilaProcesso *, int);

void adicionarLoopCPU(FilaProcesso *, Processo, int);

void aumentarCapacidadeFila(FilaProcesso *, int);

//adiciona um processo na fila
void adicionaFila(FilaProcesso *);

void moverPrimeiroProcesso(FilaProcesso *);

void removerUltimoProcesso(FilaProcesso *fila);

void insertionSort(FilaProcesso *);

//imprime na tela a ordem de atendimento dos processos, com seus ids e prioridades
void imprimeLog(FilaProcesso *);

//desaloca um TAD FilaProcessos
void destroiFila(FilaProcesso *);
void destroiProcesso(Processo *);

#endif