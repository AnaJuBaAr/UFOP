// INCLUDE DE ARQUIVOS LOCAIS //
#include "Generator.h"
#include "Instructions.h"
#include "System.h"
#include "Mmu.h"
#include "Cpu.h"
#include "Support.h"

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