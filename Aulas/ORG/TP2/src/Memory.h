#ifndef MEMORY_H
#define MEMORY_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <stdio.h>
#include <stdbool.h>

// DEFINIÇÕES DE VALORES RELEVANTES //
#define WORDS_PER_SLOT 4

// ====== TAG ====== //
typedef struct{
    int words[WORDS_PER_SLOT];
    int add;
    bool valid; //está sendo usado
    bool updated; //se a memoria foi atualizada e agora precisa ser atualizada na ram
    int cost;
    int frequency;
    int cacheHit;
} Memory;

// ============ FUNÇÕES ============ //
void initMemory(Memory*);
void printMemory(Memory*);

// ============ IMPLEMENTAÇÕES ============ //
void initMemory(Memory *memory){
    for(int i = 0; i < WORDS_PER_SLOT; i++){
        memory->words[i] = -1;
    }
    memory->add = -1;
    memory->valid = false;
    memory->updated = false;
    memory->cost = 0;
    memory->frequency = 0;
    memory->cacheHit = 0;
}

void printMemory(Memory *memory){
    for(int i = 0; i < WORDS_PER_SLOT; i++){
        printf("%d, ", memory->words[i]);
    }
    printf("\n");
}

#endif