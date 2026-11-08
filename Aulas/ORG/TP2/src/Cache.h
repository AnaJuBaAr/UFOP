#ifndef CACHE_H
#define CACHE_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <stdlib.h>

// INCLUDE DE ARQUIVOS LOCAIS //
#include "Memory.h"

// ====== TAG ====== //
typedef struct{
    Memory *lines;
    int size;
    int hits;
    int misses;
} Cache;

// ============ FUNÇÕES ============ //
Cache *initCache(int);
int findCache(Cache*, int);
int insertCache(Cache*, const Memory*, Memory*);
int findLFU(Cache*);
void destroyCache(Cache*);

// ============ IMPLEMENTAÇÕES ============ //
Cache *initCache(int size){
    Cache *cache = (Cache*)malloc(sizeof(Cache));
    cache->lines = (Memory*)malloc(size * sizeof(Memory));
    for(int i = 0; i < size; i++){
        initMemory(&cache->lines[i]);
    }
    cache->size = size;
    cache->hits = 0;
    cache->misses = 0;

    return cache;
}

// acha a linha do cache com o add desejado e retorna o indice da mesma, caso nao haja retorna -1
int findCache(Cache *cache, int add){
    for(int i = 0; i < cache->size; i++){
        if(cache->lines[i].valid && cache->lines[i].add == add){
            return i;
        }
    }
    return -1;
}

// acha a posição usando o findLFU, coloca a vitima do LFU em evicted e coloca a src na posicao encontrada
int insertCache(Cache *cache, const Memory *src, Memory *evicted){
    int position = findLFU(cache);

    *evicted = cache->lines[position];

    cache->lines[position] = *src;
    cache->lines[position].valid = true;
    cache->lines[position].updated = false;
    cache->lines[position].frequency = 1;

    return position;
}

// se tiver alguma linha vaga retorna o indice da mesma, caso contrario retorna o indice da linha usada com menos frequencia
int findLFU(Cache *cache){
    int victim = 0;


    for(int i = 0; i < cache->size; i++){
        if(!cache->lines[i].valid){
            return i;
        }

        if(cache->lines[i].frequency < cache->lines[victim].frequency){
            victim = i;
        }
    }

    return victim;
}

void destroyCache(Cache *cache){
    free(cache->lines);
    free(cache);
}

#endif