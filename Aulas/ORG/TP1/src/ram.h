#ifndef RAM_H
#define RAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int *slots;
    int size;
} Ram;

Ram *createRam(int size){
    Ram *ram = (Ram*)malloc(sizeof(Ram));
    ram->size = size;
    ram->slots = (int*)malloc(size * sizeof(int));
    return ram;
}

Ram *createEmptyRam(int size){
    Ram *ram = createRam(size);
    for(int i = 0; i < size; i++){
        ram->slots[i] = 0;
    }
    return ram;
}

Ram *createRandomRam(int size){
    srand(time(NULL));
    Ram *ram = createRam(size);
    for(int i = 0; i < size; i++){
        ram->slots[i] = rand()%100;
    }
    return ram;
}

void setData(Ram *ram, int address, int content){
    ram->slots[address] = content;
}

int getData(Ram *ram, int address){
    return ram->slots[address];
}

void printRam(Ram *ram){
    printf("RAM CONTENT:\n");
    for(int i = 0; i < ram->size; i++){
        printf("Ram[%d]: %d\n", i, ram->slots[i]);
    }
}

void destroyRam(Ram *ram){
    free((ram)->slots);
    free(ram);
    ram = NULL;
}

#endif