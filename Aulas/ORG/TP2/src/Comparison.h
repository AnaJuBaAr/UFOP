#ifndef COMPARISON_H
#define COMPARISON_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <stdio.h>

// INCLUDE DE ARQUIVOS LOCAIS //
#include "System.h"

// ====== TAG ====== //
typedef struct{
    int size[NUM_CACHES];
    int hits;           // acessos resolvidos em alguma cache (L1 + L2 + L3)
    int misses;         // acessos que nao acharam em nenhuma cache (foram a RAM)
    int ramAccesses;
    long totalCost;
} Result;

// ============ FUNÇÕES ============ //
void collectResult(System*, Result*);
void printComparison(Result*, int);

// ============ IMPLEMENTAÇÕES ============ //
// guarda os numeros de um System ja executado (chamar depois do flushMemory)
void collectResult(System *system, Result *res){
    res->hits = 0;
    for(int level = 1; level <= NUM_CACHES; level++){
        Cache *c = getCache(system, level);
        res->size[level - 1] = c->size;
        res->hits += c->hits;
    }
    // so o ultimo nivel decide se o acesso foi miss "de verdade"
    res->misses      = getCache(system, NUM_CACHES)->misses;
    res->ramAccesses = system->ram->hits;
    res->totalCost   = system->totalCost;
}

// imprime a tabela comparando todos os sistemas
void printComparison(Result *results, int n){
    printf("\n=========== COMPARACAO DOS SISTEMAS ===========\n");
    printf("%-5s | %-15s | %6s | %6s | %9s | %5s | %12s\n",
           "Teste", "L1 / L2 / L3", "Hits", "Misses", "Taxa acer", "RAM", "Custo total");
    printf("------+-----------------+--------+--------+-----------+-------+-------------\n");

    for(int i = 0; i < n; i++){
        Result *r = &results[i];

        char sizes[32];
        snprintf(sizes, sizeof(sizes), "%d / %d / %d", r->size[0], r->size[1], r->size[2]);

        int total = r->hits + r->misses;
        double rate = total > 0 ? 100.0 * r->hits / total : 0.0;

        printf("%-5d | %-15s | %6d | %6d | %8.2f%% | %5d | %12ld\n",
               i + 1, sizes, r->hits, r->misses, rate, r->ramAccesses, r->totalCost);
    }
}

#endif