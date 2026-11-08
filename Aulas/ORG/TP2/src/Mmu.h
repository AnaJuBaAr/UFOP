#ifndef MMU_H
#define MMU_H

// INCLUDE DE BIBLIOTECAS PADRÃO //
#include <string.h>

// INCLUDE DE ARQUIVOS LOCAIS //
#include "Memory.h"
#include "System.h"
#include "Address.h"

// ============ FUNÇÕES ============ //
Memory *searchInMemory(Address, System*);
int insertMemory(System*, int, const Memory*);
void writeBackMemory(System*, int, const Memory*);
Memory *writeInMemory(System*, Address, int);
void flushMemory(System*);

// ============ IMPLEMENTAÇÕES ============ //
Memory *searchInMemory(Address add, System *system){
    int foundLevel = 0;
    int foundPosition = -1;

    for(int level = 1; level <= NUM_CACHES; level++){
        Cache *cache = getCache(system, level);
        system->totalCost += getCostCache(level);

        int position = findCache(cache, add.tag);
        if(position >= 0){
            cache->hits++;
            cache->lines[position].frequency++;
            foundLevel = level;
            foundPosition = position;
            break;
        } else{
            cache->misses++;
        }
    }

    if(foundLevel == 1){
        return(&system->cache1->lines[foundPosition]);
    }

    Memory copy;
    int fisrtLevelToFill;

    if(foundLevel > 1){
        copy = getCache(system, foundLevel)->lines[foundPosition];
        fisrtLevelToFill = foundLevel-1;
    } else{
        system->totalCost += RAM_COST;
        system->ram->hits++;
        copy = getData(system->ram, add.tag);
        copy.add = add.tag;
        fisrtLevelToFill = NUM_CACHES;
    }

    int positionCache1 = -1;
    for(int level = fisrtLevelToFill; level >= 1; level--){
        int position = insertMemory(system, level, &copy);
        if(level == 1){
            positionCache1 = position;
        }
    }

    return &system->cache1->lines[positionCache1];
}

int insertMemory(System *system, int level, const Memory *src){
    Memory evicted;
    int position = insertCache(getCache(system, level), src, &evicted);

    if(evicted.valid && evicted.updated){
        writeBackMemory(system, level, &evicted);
    }

    return position;
}

void writeBackMemory(System *system, int level, const Memory *block){
    for(int n = level+1; n <= NUM_CACHES; n++){
        Cache *cache = getCache(system, n);
        int position = findCache(cache, block->add);

        if(position >= 0){
            memcpy(cache->lines[position].words, block->words, sizeof(block->words));
            cache->lines[position].updated = true;
            system->totalCost += getCostCache(n);
            return;
        }
    }

    memcpy(system->ram->blocks[block->add].words, block->words, sizeof(block->words));
    system->totalCost += RAM_COST;
    system->ram->hits++;
}

Memory *writeInMemory(System *system, Address add, int value){
    Memory *line = searchInMemory(add, system);
    line->words[add.offset] = value;
    line->updated = true;

    return line;
}

void flushMemory(System *system){
    for(int i = 1; i <= NUM_CACHES; i++){
        Cache *cache = getCache(system, i);

        for(int j = 0; j < cache->size; j++){
            Memory *line = &cache->lines[j];

            if(line->valid && line->updated){
                writeBackMemory(system, i, line);
                line->updated = false;
            }
        }
    }
}

#endif