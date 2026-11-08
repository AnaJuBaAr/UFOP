#ifndef CPU_H
#define CPU_H

// INCLUDE DE ARQUIVOS LOCAIS //
#include "Memory.h"
#include "Instructions.h"
#include "System.h"
#include "Mmu.h"

// ====== TAG ====== //
typedef struct{
    Memory reg1;
    Memory reg2;
    Memory reg3;
    int pc;
    Instruction *program;
    int opcode;
} Cpu;

// ============ FUNÇÕES ============ //
Cpu *initCpu();
void setReg1(Cpu*, Memory);
Memory getReg1 (Cpu*);
void setReg2(Cpu*, Memory);
Memory getReg2 (Cpu*);
void setReg3(Cpu*, Memory);
Memory getReg3 (Cpu*);
void setProgram(Cpu*, Instruction*);
void runCpu(Cpu*, System*);
void destroyCpu(Cpu*);

// ============ IMPLEMENTAÇÕES ============ //
Cpu *initCpu(){
    Cpu *cpu = (Cpu*)malloc(sizeof(Cpu));
    return cpu;
}

void setReg1(Cpu *cpu, Memory value){
    cpu->reg1 = value;
}

Memory getReg1 (Cpu *cpu){
    return cpu->reg1;
}

void setReg2(Cpu *cpu, Memory value){
    cpu->reg2 = value;
}

Memory getReg2 (Cpu *cpu){
    return cpu->reg2;
}

void setReg3(Cpu *cpu, Memory value){
    cpu->reg3 = value;
}

Memory getReg3 (Cpu *cpu){
    return cpu->reg3;
}

void setProgram(Cpu *cpu, Instruction *program){
    cpu->program = program;
}

void runCpu(Cpu *cpu, System *system){
    cpu->opcode = -100;
    for(cpu->pc = 0; cpu->opcode != -1; cpu->pc++){
        Instruction instruction = cpu->program[cpu->pc];
        cpu->opcode = instruction.opcode;

        if(cpu->opcode != -1){
            setReg1(cpu, *searchInMemory(instruction.add1, system));
            setReg2(cpu, *searchInMemory(instruction.add2, system));
            setReg3(cpu, *searchInMemory(instruction.add3, system));
        }

        switch(cpu->opcode){
            case -1:
                printf("Programa terminou\n");
                break;
            case 0:{
                int a = cpu->reg1.words[instruction.add1.offset];
                int b = cpu->reg2.words[instruction.add2.offset];
                int result = a + b;
                cpu->reg3 = *writeInMemory(system, instruction.add3, result);
                break;
            }
            case 1:{
                int a = cpu->reg1.words[instruction.add1.offset];
                int b = cpu->reg2.words[instruction.add2.offset];
                int result = a - b;
                cpu->reg3 = *writeInMemory(system, instruction.add3, result);
                break;
            }
        }
    }
}

void destroyCpu(Cpu *cpu){
    free(cpu);
}

#endif