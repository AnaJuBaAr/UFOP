#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da estrutura do registro
typedef struct {
    int chave;
    long dado1;
    char dado2[1001];
    char dado3[5001];
} Registro;

// Função para gerar string aleatória
void gerar_string_aleatoria(char *str, int tamanho) {
    static const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                     "abcdefghijklmnopqrstuvwxyz"
                                     "0123456789";
    int num_caracteres = sizeof(caracteres) - 1;
    
    for (int i = 0; i < tamanho - 1; i++) {
        str[i] = caracteres[rand() % num_caracteres];
    }
    str[tamanho - 1] = '\0';
}

// Função para gerar registros aleatórios
void gerar_registro(Registro *reg, int chave) {
    reg->chave = chave;
    reg->dado1 = (long)rand() * rand();  // Valor long aleatório
    
    // Gerar strings aleatórias
    gerar_string_aleatoria(reg->dado2, sizeof(reg->dado2));
    gerar_string_aleatoria(reg->dado3, sizeof(reg->dado3));
}

// Função para escrever registros no arquivo binário
void escrever_arquivo(const char *nome_arquivo, int num_registros) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nome_arquivo);
        exit(1);
    }
    
    Registro registro;
    
    printf("Gerando %d registros...\n", num_registros);
    
    for (int i = 0; i < num_registros; i++) {
        gerar_registro(&registro, i + 1);  // Chaves de 1 a 100
        
        size_t escritos = fwrite(&registro, sizeof(Registro), 1, arquivo);
        
        if (escritos != 1) {
            printf("Erro ao escrever o registro %d!\n", i + 1);
            fclose(arquivo);
            exit(1);
        }
        
        if ((i + 1) % 10 == 0) {
            printf("Registros escritos: %d\n", i + 1);
        }
    }
    
    fclose(arquivo);
    printf("Arquivo '%s' criado com sucesso!\n", nome_arquivo);
}

// Função para ler e exibir os registros do arquivo (verificação)
void ler_arquivo(const char *nome_arquivo, int num_registros) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
        return;
    }
    
    Registro registro;
    int contador = 0;
    
    printf("\n--- Lendo registros do arquivo ---\n");
    
    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1 && contador < num_registros) {
        printf("\nRegistro %d:\n", contador + 1);
        printf("  Chave: %d\n", registro.chave);
        printf("  Dado1 (long): %ld\n", registro.dado1);
        printf("  Dado2 (primeiros 50 caracteres): %.50s...\n", registro.dado2);
        printf("  Dado3 (primeiros 50 caracteres): %.50s...\n", registro.dado3);
        printf("  Tamanho real Dado2: %zu\n", strlen(registro.dado2));
        printf("  Tamanho real Dado3: %zu\n", strlen(registro.dado3));
        
        contador++;
        
        if (contador >= 5) {  // Mostra apenas os 5 primeiros
            printf("\n... (mais %d registros no arquivo)\n", num_registros - contador);
            break;
        }
    }
    
    fclose(arquivo);
}

// Função para mostrar informações do arquivo
void info_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
        return;
    }
    
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fclose(arquivo);
    
    printf("\n--- Informações do Arquivo ---\n");
    printf("Nome: %s\n", nome_arquivo);
    printf("Tamanho total: %.2f KB (%.2f MB)\n", 
           tamanho / 1024.0, tamanho / (1024.0 * 1024.0));
    
    // Calcula tamanho esperado
    int num_registros = 100;
    long tamanho_esperado = num_registros * sizeof(Registro);
    printf("Tamanho esperado (100 registros): %.2f KB\n", 
           tamanho_esperado / 1024.0);
    
    if (tamanho == tamanho_esperado) {
        printf("Tamanho do arquivo está correto!\n");
    } else {
        printf("Atenção: Tamanho do arquivo difere do esperado!\n");
    }
    
    printf("Tamanho de cada registro: %zu bytes\n", sizeof(Registro));
    printf("  - chave (int): %zu bytes\n", sizeof(int));
    printf("  - dado1 (long): %zu bytes\n", sizeof(long));
    printf("  - dado2 (char[1001]): %zu bytes\n", sizeof(char[1001]));
    printf("  - dado3 (char[5001]): %zu bytes\n", sizeof(char[5001]));
}

int main() {
    const char *nome_arquivo = "registros100.bin";
    const int num_registros = 100;
    
    // Inicializa gerador de números aleatórios
    srand(time(NULL));
    
    printf("=== Gerador de Arquivo Binário de Registros ===\n\n");
    
    // Gera o arquivo com 100 registros
    escrever_arquivo(nome_arquivo, num_registros);
    
    // Mostra informações do arquivo
    info_arquivo(nome_arquivo);
    
    // Lê e exibe alguns registros para verificação
    ler_arquivo(nome_arquivo, num_registros);
    
    printf("\nPrograma concluído!\n");
    
    return 0;
}