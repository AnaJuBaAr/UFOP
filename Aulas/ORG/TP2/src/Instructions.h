#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <stdlib.h>

// INCLUDE DE ARQUIVOS LOCAIS //
#include "Address.h"

// ====== TAG ====== //
typedef struct{
    Address add1;
    Address add2;
    Address add3;
    int opcode;
} Instruction;

// ============ FUNÇÕES ============ //
Instruction *initInstruction(int);
void setInstruction(Instruction*, int, Address, Address, Address, int);
void destroyInstruction(Instruction*);

// ============ IMPLEMENTAÇÕES ============ //
Instruction *initInstruction(int qtd){
    Instruction *instruction = (Instruction*)malloc(qtd * sizeof(Instruction));
    return instruction;
}

void setInstruction(Instruction *instruction, int indice, Address add1, Address add2, Address add3, int opcode){
    instruction[indice].add1 = add1;
    instruction[indice].add2 = add2;
    instruction[indice].add3 = add3;
    instruction[indice].opcode = opcode;
}

void destroyInstruction(Instruction *instruction){
    free(instruction);
}

#endif