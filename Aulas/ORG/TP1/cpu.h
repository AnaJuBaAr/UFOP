#ifndef CPU_H
#define CPU_H

#include "instruction.h"
#include "ram.h"

typedef struct{
    int reg1;
    int reg2;
    int pc;
    Instruction *program;
    int opcode;
} Cpu;

Cpu *createCpu(){
    Cpu *cpu = (Cpu*)malloc(sizeof(Cpu));
    return cpu;
}

void setReg1(Cpu *cpu, int value){
    cpu->reg1 = value;
}

int getReg1(Cpu *cpu){
    return cpu->reg1;
}

void setReg2(Cpu *cpu, int value){
    cpu->reg2 = value;
}

int getReg2(Cpu *cpu){
    return cpu->reg2;
}

void setProgram(Cpu *cpu, Instruction *program){
    cpu->program = program;
}

void initeCPU(Cpu *cpu, Ram *ram){
    cpu->opcode = -100;
    for(cpu->pc = 0; cpu->opcode != -1; cpu->pc++){
        Instruction instruction = cpu->program[cpu->pc];
        cpu->opcode = instruction.opcode;

        switch(cpu->opcode){
            //halt
            case -1:
                printRam(ram);
                return;
                break;
            
            //sum
            case 0:
                cpu->reg1 = getData(ram, instruction.add1);
                cpu->reg2 = getData(ram, instruction.add2);
                
                cpu->reg1 += cpu->reg2;

                setData(ram, instruction.add3, cpu->reg1);
                break;

            //sub
            case 1:
                cpu->reg1 = getData(ram, instruction.add1);
                cpu->reg2 = getData(ram, instruction.add2);
                
                cpu->reg1 -= cpu->reg2;

                setData(ram, instruction.add3, cpu->reg1);
                break;

            //copy from reg to ram
            case 2:
                if(instruction.add1 == 1){
                    setData(ram, instruction.add2, cpu->reg1);
                } else{
                    setData(ram, instruction.add2, cpu->reg2);
                }
                break;

            //copy from ram to reg
            case 3:
                if(instruction.add1 == 1){
                    cpu->reg1 = getData(ram, instruction.add2);
                } else{
                    cpu->reg2 = getData(ram, instruction.add2);
                }
                break;
        }
    }
}

void destroyCpu(Cpu *cpu){
    free(cpu);
    cpu = NULL;
}

#endif