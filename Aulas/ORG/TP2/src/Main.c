// INCLUDE DE ARQUIVOS LOCAIS //
#include "Generator.h"
#include "Instructions.h"
#include "System.h"
#include "Mmu.h"
#include "Cpu.h"
#include "Comparison.h"

#define TESTE1_C1 8
#define TESTE1_C2 16
#define TESTE1_C3 32
#define TESTE2_C1 32
#define TESTE2_C2 64
#define TESTE2_C3 728
#define TESTE3_C1 16
#define TESTE3_C2 64
#define TESTE3_C3 256
#define TESTE4_C1 8
#define TESTE4_C2 32
#define TESTE4_C3 128
#define TESTE5_C1 16
#define TESTE5_C2 32
#define TESTE5_C3 64

Instruction *loadProgram(const char*, int*);

int testes[15] = {8, 16, 32, 32, 64, 128, 16, 64, 256, 8, 32, 128, 16, 32, 64};

int main(){
    //gera o arquivo com as instrucoes
    generator();

    //carrega o programa
    int count = 0;
    Instruction *program = loadProgram("instructions.txt", &count);
    if(program == NULL){
        printf("Erro de carregamento\n");
        return 1;
    }
    printf("%d instrucoes carregadas com sucesso\n", count);

    Cpu *cpu = initCpu();
    setProgram(cpu, program);

    Result result[5];
    for(int i = 0; i < 5; i++){
        System *system = initSystem(TAM_MEM, testes[3*i], testes[3*i+1], testes[3*i+2]);
        
        runCpu(cpu, system);

        flushMemory(system);
        printResultsSystem(system, i+1);

        collectResult(system, &result[i]);

        destroySystem(system);

    }

    printComparison(result, 5);
    
    destroyCpu(cpu);
    destroyInstruction(program);

    return 0;
}

Instruction *loadProgram(const char *path, int *count){
    FILE *arq = fopen(path, "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    Instruction *program = initInstruction(QTD_INST+1);
    int n = 0;
    int op, t1, o1, t2, o2, t3, o3;

    while(n < QTD_INST && (fscanf(arq, "%d:%d:%d:%d:%d:%d:%d", &op, &t1, &o1, &t2, &o2, &t3, &o3) == 7)){
        Address add1 = {t1, o1};
        Address add2 = {t2, o2};
        Address add3 = {t3, o3};

        setInstruction(program, n, add1, add2, add3, op);
        n++;
    }

    fclose(arq);

    Address halt = {0, 0};
    setInstruction(program, n, halt, halt, halt, -1);

    *count = n;
    return program;
}