#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_INST 10000  //quantidade de instruções geradas
#define TAM_FOR 10      //tamanho do laço
#define TAM_MEM 1000    //tamanho da memória (quantidade de endereços possíveis)
#define PROB_FOR 90     //probabilidade de ocorrência do for (%)
#define NUM_OPCODES 2   //numero maximo de opcodes
#define WORDS_PER_BLOCK 4

int repeticions[TAM_FOR][7];  //guarda o laço que será repetido
int instructions[10000][7];

void generator(){
    FILE *arq = fopen("instructions.txt", "w");
    srand(time(NULL));
    int random;
    int localInstructions[8] = {6, 6, 6, 6, 6, 6, 6, 6};

    for(int i = 0; i < TAM_FOR; i++){
        random = rand() % NUM_OPCODES;
        repeticions[i][0] = random;

        for(int j = 1; j <=(localInstructions[random]); j+=2){
            repeticions[i][j] = rand() % TAM_MEM;
            repeticions[i][j+1] = rand() % WORDS_PER_BLOCK;
        }
    }

    for(int i = 0; i < QTD_INST;){
        random = (rand() % 100) + 1;
        if((random <= PROB_FOR) && (i+TAM_FOR < QTD_INST)){
            for(int j = 0; j < TAM_FOR; j++){
                for(int k = 0; k < 7; k++){
                    instructions[i+j][k] = repeticions[j][k];
                }
            }
            i += TAM_FOR;
        } else{
            random = rand() % NUM_OPCODES;
            instructions[i][0] = random;

            for(int j = 1; j <= localInstructions[random]; j+=2){
                instructions[i][j] = rand() % TAM_MEM;
                instructions[i][j+1] = rand() % WORDS_PER_BLOCK;
            }
            i++;
        }
    }

    for(int i = 0; i < QTD_INST; i++){
        for(int j = 0; j < 6; j++){
            fprintf(arq, "%d:", instructions[i][j]);
        }
        fprintf(arq, "%d\n", instructions[i][6]);
    }


    fclose(arq);
}

#endif