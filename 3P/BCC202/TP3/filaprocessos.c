#include "filaprocessos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Escopo *criarEscopo(){
    Escopo *escopo = (Escopo*)malloc(sizeof(Escopo));
    escopo->pRaiz = NULL;
    return escopo;
}

void destroiEscopo(No *no){
    if(no == NULL){
        return;
    }
    destroiEscopo(no->pDir);
    destroiEscopo(no->pEsq);
    free(no);
}

void adicionaVar(Escopo *escopo, const char *nome, const char *valor){
    if(!escopo){
        return;
    }

    escopo->pRaiz = inserirNo(escopo->pRaiz, nome, valor);
}

No *inserirNo(No *no, const char *nome, const char *valor){
    if(no == NULL){
        return criarNo(nome, valor);
    }

    int compare = strcmp(nome, no->nome);
    if(compare < 0){
        no->pEsq = inserirNo(no->pEsq, nome, valor);
    } else if(compare > 0){
        no->pDir = inserirNo(no->pDir, nome, valor);
    } else{
        strcpy(no->valor, valor);
    }
    return no;
}

No *criarNo(const char *nome, const char *valor){
    No *no = (No*)malloc(sizeof(No));
    
    strcpy(no->nome, nome);
    strcpy(no->valor, valor);
    no->pDir = NULL;
    no->pEsq = NULL;

    return no;
}

No *buscarVar(No *no, const char *nome){
    if(no == NULL){
        return NULL;
    }

    int compare = strcmp(nome, no->nome);
    if(compare == 0){
        return no;
    } else if (compare < 0){
        return buscarVar(no->pEsq, nome);
    } else{
        return buscarVar(no->pDir, nome);
    }
}

Pilha *criarPilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->pTopo = NULL;
    pilha->tamanho = 0;

    return pilha;
}

void destroiPilha(Pilha *pilha){
    if(pilha == NULL){
        return;
    }

    Elemento *atual = pilha->pTopo;
    while(atual){
        Elemento *proximo = atual->pAnterior;
        if(atual->escopo){
            destroiEscopo(atual->escopo->pRaiz);
            free(atual->escopo);
        }
        free(atual);
        atual = proximo;
    }
    free(pilha);
}

void adicionaPilha(Pilha *pilha){
    Elemento *elemento = (Elemento*)malloc(sizeof(Elemento));
    elemento->escopo = criarEscopo();
    elemento->pAnterior = pilha->pTopo;
    pilha->pTopo = elemento;
    pilha->tamanho++;

}

int removerEscopo(Pilha *pilha){
    if(!pilha || !pilha->pTopo){
        return 0;
    }

    Elemento *remover = pilha->pTopo;
    pilha->pTopo = remover->pAnterior;

    if(remover->escopo){
        destroiEscopo(remover->escopo->pRaiz);
        free(remover->escopo);
    }
    free(remover);
    pilha->tamanho--;
    
    return 1;
}

void executar(const char *argv){
    FILE *arq = fopen(argv, "r");
    
    Pilha *pilha = criarPilha();
    char linha[MAX_LINE];

    while(fgets(linha, sizeof(linha), arq)){
        processarLinha(pilha, linha);
    }

    if(pilha && pilha->tamanho > 0){
        printf("Escopo não fechado\n");
    }

    destroiPilha(pilha);
    fclose(arq);
}

void processarLinha(Pilha *pilha, const char *linha){
    char nomeVar[MAX_VAR];
    char valorVar[MAX_VAR];

    //ignora linhas vazias
    if(strlen(linha) <= 1){
        return;
    }

    //verifica início de escopo
    if(strncmp(linha, "begin", 5) == 0){
        adicionaPilha(pilha);
        return;
    }

    //verifica declaracao de variavel
    if(sscanf(linha, "var %s = %s", nomeVar, valorVar) == 2){
        Escopo *atual = obterEscopoAtual(pilha);
        if(!atual){
            return;
        }
        adicionaVar(atual, nomeVar, valorVar);
        return;
    }

    //verifica comando print
    if(sscanf(linha, "print %s", nomeVar) == 1){
        No *var = buscarVarPilha(pilha, nomeVar);
        if(var){
            printf("%s\n", var->valor);
        } else{
            printf("Variavel %s nao declarada\n", nomeVar);
            exit(1);
        }
        return;
    }

    //verifica fim de escopo
    if(strncmp(linha, "end", 3) == 0){
        if(removerEscopo(pilha) == 0){
            printf("Escopo nao aberto\n");
        }
        return;
    }
}

Escopo *obterEscopoAtual(Pilha *pilha){
    if(!pilha || !pilha->pTopo){
        return NULL;
    }
    return pilha->pTopo->escopo;
}

No *buscarVarPilha(Pilha *pilha, const char *nome){
    if(pilha == NULL){
        return NULL;
    }

    Elemento *atual = pilha->pTopo;
    while(atual){
        if(atual->escopo){
            No *var = buscarVar(atual->escopo->pRaiz, nome);
            if(var){
                return var;
            }
        }
        atual = atual->pAnterior;
    }

    return NULL;
}