#include <stdio.h>
#include <stdlib.h>

#include "metodos.h"

#define TAMPAGINA 10

// PESQUISA POR ACESSO SEQUENCIAL INDEXADO
// int pesquisa(int indice[], int tamanho, Registro *item, FILE *arq){
//     // procura a página onde o item pode se encontrar
//     int i = 0;
//     while(i < tamanho && indice[i] <= item->chave){
//         i++;
//     }

//     //se a chave procurada for menor que a primeira chave, o item não existe no arquivo
//     if(i == 0){
//         return 0;
//     }

//     //a ultima pagina pode ser menor que as anteriores
//     int quantItens;
//     if(i < tamanho){ //a unica pagina que pode ser menor eh a ultima
//         quantItens = TAMPAGINA;
//     } else{
//         fseek(arq, 0, SEEK_END);
//         quantItens = (ftell(arq) / sizeof(Registro)) % TAMPAGINA;

//         if(quantItens == 0){ //se a ultima pagina for do mesmo tamanho das anteriores
//             quantItens = TAMPAGINA;
//         }
//     }

//     //lê a página desejada do arquivo
//     Registro pagina[TAMPAGINA];
//     int desloc = (i-1) * TAMPAGINA * sizeof(Registro);
//     fseek(arq, desloc, SEEK_SET);
//     fread(pagina, sizeof(Registro), quantItens, arq);

//     //pesquisa binária na página lida
//     int esq = 0;
//     int dir = quantItens-1;
//     int meio;

//     while(esq <= dir){
//         meio = (esq + dir) / 2;
//         if(pagina[meio].chave == item->chave){
//             *item = pagina[meio];
//             return 1;
//         } else if(pagina[meio].chave < item->chave){
//             esq = meio + 1;
//         } else{
//             dir = meio - 1;
//         }
//     }

//     return 0;
// }

// int *Paginacao(FILE *arq){
//     //estima a quantidade de páginas possíveis dado um tamanho fixo
//     fseek(arq, 0, SEEK_END);
//     int tamFinal = ftell(arq)/sizeof(Registro);
//     int quantPaginas = (tamFinal + TAMPAGINA - 1) / TAMPAGINA;

//     //cria um vetor para o indice das paginas
//     int *indice = (int*)malloc(quantPaginas * sizeof(int));
//     if(indice == NULL){
//         return NULL;
//     }

//     int i = 0;

//     //preenche o vetor indice com a chave do primeiro registro de cada pagina
//     rewind(arq);
//     Registro pagina[TAMPAGINA];
//     size_t bytesLidos;

//     while((bytesLidos = fread(pagina, sizeof(Registro), TAMPAGINA, arq)) > 0 && i < quantPaginas){
//         indice[i++] = pagina[0].chave;
//     }

//     //retorna o indice criado
//     return indice;
// }

// PESQUISA POR ÁRVORE B
Ponteiro inicializa(){
    return NULL;
}

void pesquisa(Registro *registro, Ponteiro ponteiro){
    if(ponteiro == NULL){
        printf("Registro não está na árvore\n");
        return;
    }

    //encontra entre quais registros da arvore o registro procurado se encontra
    int i;
    for(i = 1; i < ponteiro->quant && registro->chave > ponteiro->registros[i-1].chave; i++);

    //confirma se o registro procurado foi encontrado
    if(registro->chave == ponteiro->registros[i-1].chave){
        *registro = ponteiro->registros[i-1];
        return;
    }

    //confere para qual dos ramos a função deve descer
    if(registro->chave < ponteiro->registros[i-1].chave){
        pesquisa(registro, ponteiro->ponteiros[i-1]);
    } else{
        pesquisa(registro, ponteiro->ponteiros[i]);
    }
}

void imprime(Ponteiro arvore){
    if(arvore == NULL){
        return;
    }

    for(int i = 0; i <= arvore->quant; i++){
        imprime(arvore->ponteiros[i]);

        if(i != arvore->quant){
            printf("Registro %d\n", arvore->registros[i].chave);
        }
    }
}

void insereNaPagina(Ponteiro ponteiro, Registro registro, Ponteiro ponteiroDir){
    int k = ponteiro->quant;
    short NaoAchouPosicao = (k > 0);

    while(NaoAchouPosicao){
        if(registro.chave >= ponteiro->registros[k-1].chave){
            NaoAchouPosicao = 0;
            break;
        }
        ponteiro->registros[k] = ponteiro->registros[k-1];
        ponteiro->ponteiros[k+1] = ponteiro->ponteiros[k];
        k--;

        if(k < 1){
            NaoAchouPosicao = 0;
        }
    }
    ponteiro->registros[k] = registro;
    ponteiro->ponteiros[k+1] = ponteiroDir;
    ponteiro->quant++;
}

void ins(Registro registro, Ponteiro ponteiro, short *cresceu, Registro *registroRetorno, Ponteiro *ponteiroRetorno){
    if(ponteiro == NULL){
        *cresceu = 1;
        (*registroRetorno) = registro;
        (*ponteiroRetorno) = NULL;
        return;
    }

    long i;
    for(i = 1; i < ponteiro->quant && registro.chave > ponteiro->registros[i-1].chave; i++);

    if(registro.chave == ponteiro->registros[i-1].chave){
        printf("Registro já existente\n");
        *cresceu = 0;
        return;
    }

    if(registro.chave < ponteiro->registros[i-1].chave){
        i--;
    }

    ins(registro, ponteiro->ponteiros[i], cresceu, registroRetorno, ponteiroRetorno);

    if(!*cresceu){
        return;
    }

    if(ponteiro->quant < MM){
        insereNaPagina(ponteiro, *registroRetorno, *ponteiroRetorno);
        *cresceu = 0;
        return;
    }

    Ponteiro ponteiroTemporario;
    ponteiroTemporario = (Ponteiro)malloc(sizeof(Pagina));
    ponteiroTemporario->quant = 0;
    ponteiroTemporario->ponteiros[0] = NULL;
    
    if(i < M+1){
        insereNaPagina(ponteiro, *registroRetorno, *ponteiroRetorno);
    } else{
        insereNaPagina(ponteiroTemporario, *registroRetorno, *ponteiroRetorno);
    }

    for(long j = M + 2; j <= MM; j++){
        insereNaPagina(ponteiroTemporario, ponteiro->registros[j-1], ponteiro->ponteiros[j]);
    }

    ponteiro->quant = M;
    ponteiroTemporario->ponteiros[0] = ponteiro->ponteiros[M+1];
    *registroRetorno = ponteiro->registros[M];
    *ponteiroRetorno = ponteiroTemporario;
}

void insere(Registro registro, Ponteiro *ponteiro){
    short cresceu;
    Registro registroRetorno;
    Pagina *ponteiroRetorno, *ponteiroTemporario;

    ins(registro, *ponteiro, &cresceu, &registroRetorno, &ponteiroRetorno);

    if(cresceu){
        ponteiroTemporario = (Pagina*)malloc(sizeof(Pagina));
        ponteiroTemporario->quant = 1;
        ponteiroTemporario->registros[0] = registroRetorno;
        ponteiroTemporario->ponteiros[1] = ponteiroRetorno;
        ponteiroTemporario->ponteiros[0] = *ponteiro;
        *ponteiro = ponteiroTemporario;
    }
}

void insereArq(Ponteiro *ponteiro){
    FILE *arq = fopen("arquivo.bin", "rb");
    Registro *pagina = (Registro*)malloc(10 * sizeof(Registro));

    rewind(arq);
    fread(pagina, sizeof(Registro), 10, arq);
    for(int i = 0; i < 10; i++){
        insere(pagina[i], ponteiro);
    }
    free(pagina);
    fclose(arq);
}

void reconstitui(Ponteiro ponteiroPagina, Ponteiro ponteiroPai, int posicaoPai, short *diminuiu){
    Pagina *auxiliar;
    long disAuxiliar, j;

    if(posicaoPai < ponteiroPai->quant){
        auxiliar = ponteiroPai->ponteiros[posicaoPai+1];
        disAuxiliar = (auxiliar->quant-M+1)/2;
        ponteiroPagina->registros[ponteiroPagina->quant] = ponteiroPai->registros[posicaoPai];
        ponteiroPagina->ponteiros[ponteiroPagina->quant+1] = auxiliar->ponteiros[0];
        ponteiroPagina->quant++;

        if(disAuxiliar > 0){
            for(j = 1; j < disAuxiliar; j++){
                insereNaPagina(ponteiroPagina, auxiliar->registros[j-1], auxiliar->ponteiros[j]);
            }

            ponteiroPai->registros[posicaoPai] = auxiliar->registros[disAuxiliar-1];
            auxiliar->quant -= disAuxiliar;

            for(j = 0; j < auxiliar->quant; j++){
                auxiliar->registros[j] = auxiliar->registros[j+disAuxiliar];
            }
            for(j = 0; j <= auxiliar->quant; j++){
                auxiliar->ponteiros[j] = auxiliar->ponteiros[j+disAuxiliar];
            }
            *diminuiu = 0;
        } else{
            for(j = 1; j <= M; j++){
                insereNaPagina(ponteiroPagina, auxiliar->registros[j-1], auxiliar->ponteiros[j]);
            }
            free(auxiliar);
            for(j = posicaoPai+1; j < ponteiroPai->quant; j++){
                ponteiroPai->registros[j-1] = ponteiroPai->registros[j];
                ponteiroPai->ponteiros[j] = ponteiroPai->ponteiros[j+1];
            }
            ponteiroPai->quant--;

            if(ponteiroPai->quant >= M){
                *diminuiu = 0;
            }
        }
    } else{
        auxiliar = ponteiroPai->ponteiros[posicaoPai-1];
        disAuxiliar = (auxiliar->quant-M+1)/2;

        for(j = ponteiroPagina->quant; j >= 1; j--){
            ponteiroPagina->registros[j] = ponteiroPagina->registros[j-1];
            ponteiroPagina->registros[0] = ponteiroPai->registros[posicaoPai-1];
        }
        for(j = ponteiroPagina->quant; j >= 0; j--){
            ponteiroPagina->ponteiros[j+1] = ponteiroPagina->ponteiros[j];
            ponteiroPagina->quant++;
        }

        if(disAuxiliar > 0){
            for(j = 1; j < disAuxiliar; j++){
                insereNaPagina(ponteiroPagina, auxiliar->registros[auxiliar->quant-j], auxiliar->ponteiros[auxiliar->quant-j+1]);
            }
            ponteiroPagina->ponteiros[0] = auxiliar->ponteiros[auxiliar->quant - disAuxiliar+1];
            ponteiroPai->registros[posicaoPai-1] = auxiliar->registros[auxiliar->quant - disAuxiliar];
            auxiliar->quant -= disAuxiliar;
            *diminuiu = 0;
        } else{
            for(j = 1; j <= M; j++){
                insereNaPagina(auxiliar, ponteiroPagina->registros[j-1], ponteiroPagina->ponteiros[j]);
            }

            free(ponteiroPagina);
            ponteiroPai->quant--;

            if(ponteiroPai->quant >= M){
                *diminuiu = 0;
            }
        }
    }
}

void antecessor(Ponteiro ponteiro, int ind, Ponteiro ponteiroPai, short *diminuiu){
    if(ponteiroPai->ponteiros[ponteiroPai->quant] != NULL){
        antecessor(ponteiro, ind, ponteiroPai->ponteiros[ponteiroPai->quant], diminuiu);

        if(*diminuiu){
            reconstitui(ponteiroPai->ponteiros[ponteiroPai->quant], ponteiroPai, (long)ponteiroPai->quant, diminuiu);
        }
        return;
    }

    ponteiro->registros[ind-1] = ponteiroPai->registros[ponteiroPai->quant-1];
    ponteiroPai->quant--;
    *diminuiu = (ponteiroPai->quant < M);
}

void ret(int chave, Ponteiro *ponteiro, short *diminuiu){
    long j, ind = 1;
    Ponteiro pagina;

    if(*ponteiro == NULL){
        printf("ERRO: registro nao esta na arvore\n");
        return;
    }

    pagina = *ponteiro;
    while(ind < pagina->quant && chave > pagina->registros[ind-1].chave){
        ind++;
    }

    if(chave == pagina->registros[ind-1].chave){
        if(pagina->ponteiros[ind-1] == NULL){
            pagina->quant--;
            *diminuiu = (pagina->quant < M);

            for(j = ind; j <= pagina->quant; j++){
                pagina->registros[j-1] = pagina->registros[j];
                pagina->ponteiros[j] = pagina->ponteiros[j+1];
            }
            return;
        }

        antecessor(*ponteiro, ind, pagina->ponteiros[ind-1], diminuiu);
        
        if(*diminuiu){
            reconstitui(pagina->ponteiros[ind-1], *ponteiro, ind-1, diminuiu);
        }

        return;
    }

    if(chave > pagina->registros[ind-1].chave){
        ind++;
    }

    ret(chave, &pagina->ponteiros[ind-1], diminuiu);

    if(*diminuiu){
        reconstitui(pagina->ponteiros[ind-1], *ponteiro, ind-1, diminuiu);
    }
}

void retira(int chave, Ponteiro *ponteiro){
    short diminuiu;
    Ponteiro auxiliar;

    ret(chave, ponteiro, &diminuiu);

    if(diminuiu && (*ponteiro)->quant == 0){
        auxiliar = *ponteiro;
        *ponteiro = auxiliar->ponteiros[0];
        free(auxiliar);
    }
}

void liberararvore(Ponteiro raiz){
    if (raiz == NULL) return;
    
    for (int i = 0; i <= raiz->quant; i++) {
        liberararvore(raiz->ponteiros[i]);
    }
    free(raiz);
}