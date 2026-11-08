#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdlib.h>

typedef struct{
    int add1;
    int add2;
    int add3;
    int opcode;
} Instruction;

Instruction *createInstruction(int qtd){
    Instruction *instruction = (Instruction*)malloc(qtd * sizeof(Instruction));
    return instruction;
}

void setInstruction(Instruction *instruction, int indice, int add1, int add2, int add3, int opcode){
    instruction[indice].add1 = add1;
    instruction[indice].add2 = add2;
    instruction[indice].add3 = add3;
    instruction[indice].opcode = opcode;
}

void destroyInstruction(Instruction *instruction){
    free(instruction);
}

#endif