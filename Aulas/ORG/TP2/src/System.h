#ifndef SYSTEM_H
#define SYSTEM_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
// INCLUDE DE ARQUIVOS LOCAIS //
#include "Ram.h"
#include "Cache.h"

// DEFINIÇÕES DE VALORES RELEVANTES //
#define NUM_CACHES 3
#define CACHE1_COST 10
#define CACHE2_COST 100
#define CACHE3_COST 1000
#define RAM_COST 10000

// ====== TAG ====== //
typedef struct{
    Ram *ram;
    Cache *cache1;
    Cache *cache2;
    Cache *cache3;
    long totalCost;
} System;

// ============ FUNÇÕES ============ //
System *initSystem(int, int, int, int);
Cache *getCache(System*, int);
int getCostCache(int);
void destroySystem(System*);
void printResultsSystem(System*, int);

// ============ IMPLEMENTAÇÕES ============ //
System *initSystem(int sizeRam, int sizeCache1, int sizeCache2, int sizeCache3){
    System *system = (System*)malloc(sizeof(System));
    system->ram = initEmptyRam(sizeRam);
    system->cache1 = initCache(sizeCache1);
    system->cache2 = initCache(sizeCache2);
    system->cache3 = initCache(sizeCache3);
    system->totalCost = 0;

    return system;
}

Cache *getCache(System *system, int level){
    switch(level){
        case 1:
            return system->cache1;
        case 2:
            return system->cache2;
        default:
            return system->cache3;
    }
}

int getCostCache(int level){
    switch(level){
        case 1:
            return CACHE1_COST;
        case 2:
            return CACHE2_COST;
        default:
            return CACHE3_COST;
    }
}

void printResultsSystem(System *system, int add){
    printf("\n========== RESULTADOS TESTE %d ==========\n", add);

    for(int level = 1; level <= NUM_CACHES; level++){
        Cache *cache = getCache(system, level);
        int total = cache->hits + cache->misses;
        double rate = total > 0 ? (100.0 * cache->hits / total) : 0.0;
        
        printf("Cache level %d: hits: %d; misses: %d; taxa de acertos: %.2f%%\n", level, cache->hits, cache->misses, rate);
    }
    printf("RAM: acessos: %d\n", system->ram->hits);
    printf("Custo total: %ld\n", system->totalCost);
}

void destroySystem(System *system){
    destroyRam(system->ram);
    destroyCache(system->cache1);
    destroyCache(system->cache2);
    destroyCache(system->cache3);
    free(system);
}

#endif