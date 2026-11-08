#ifndef RAM_H
#define RAM_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// INCLUDE DE ARQUIVOS LOCAIS //
#include "Memory.h"

// ====== TAG ====== //
typedef struct{
    Memory *blocks;
    int size;
    int hits;
} Ram;

// ============ FUNÇÕES ============ //
Ram *initRam(int);
Ram *initEmptyRam(int);
Ram *initRandomRam(int);
void setData(Ram*, int, Memory);
Memory getData(Ram*, int);
void printRam(Ram*);
void destroyRam(Ram*);

// ============ IMPLEMENTAÇÕES ============ //
Ram *initRam(int size){
    Ram *ram = (Ram*)malloc(sizeof(Ram));
    ram->blocks = (Memory*)malloc(size * sizeof(Memory));
    for(int i = 0; i < size; i++){
        initMemory(&ram->blocks[i]);
    }
    ram->size = size;
    ram->hits = 0;

    return ram;
}

Ram *initEmptyRam(int size){
    Ram *ram = initRam(size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < WORDS_PER_SLOT; j++){
            ram->blocks[i].words[j] = 0;
        }
    }

    return ram;
}

Ram *initRandomRam(int size){
    srand(time(NULL));

    Ram *ram = initRam(size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < WORDS_PER_SLOT; j++){
            ram->blocks[i].words[j] = rand()%100;
        }
    }

    return ram;
}

void setData(Ram *ram, int add, Memory data){
    ram->blocks[add] = data;
}

Memory getData(Ram *ram, int add){
    return ram->blocks[add];
}

void printRam(Ram *ram){
    printf("CONTEUDO DA RAM\n");
    for(int i = 0; i < ram->size; i++){
        printMemory(&ram->blocks[i]);
    }
}

void destroyRam(Ram *ram){
    free(ram->blocks);
    free(ram);
}



#endif