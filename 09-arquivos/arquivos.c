/**
 * Arquivo: arquivos.c
 * Módulo: 09 - Manipulação de Arquivos em C (fopen, fread, fwrite, fclose)
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra escrita e leitura em arquivo de texto (fprintf/fgets)
 *            e persistência de structs em arquivo binário (fwrite/fread).
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char descricao[40];
    double valor;
} Registro;

void demonstrar_arquivo_texto(void);
void demonstrar_arquivo_binario(void);

int main(void) {
    demonstrar_arquivo_texto();
    printf("\n");
    demonstrar_arquivo_binario();
    return 0;
}

void demonstrar_arquivo_texto(void) {
    const char *nome_arquivo = "historico.txt";

    /* 1. ESCRITA EM MODO TEXTO ("w" cria ou sobrescreve o arquivo) */
    FILE *fp = fopen(nome_arquivo, "w");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de texto para escrita");
        return;
    }

    fprintf(fp, "Log de Execucao - Modulo 09\n");
    fprintf(fp, "Status: Operacao concluida com sucesso.\n");
    fclose(fp); /* Fecha e garante a gravação dos dados no disco */

    /* 2. LEITURA EM MODO TEXTO ("r" abre apenas para leitura) */
    fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de texto para leitura");
        return;
    }

    printf("=== Conteudo de '%s' ===\n", nome_arquivo);
    char linha[128];
    /* Forma segura: verifica o retorno de fgets em vez de usar !feof(fp) */
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        printf("%s", linha);
    }

    fclose(fp);
}

void demonstrar_arquivo_binario(void) {
    const char *nome_binario = "dados.bin";

    Registro lista_saida[2] = {
        {1, "Sensor Temperatura", 24.8},
        {2, "Sensor Pressao", 1013.2}
    };

    /* 1. GRAVAÇÃO BINÁRIA ("wb") */
    FILE *fp = fopen(nome_binario, "wb");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo binario para escrita");
        return;
    }

    size_t gravados = fwrite(lista_saida, sizeof(Registro), 2, fp);
    fclose(fp);

    /* 2. LEITURA BINÁRIA ("rb") */
    fp = fopen(nome_binario, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo binario para leitura");
        return;
    }

    Registro lista_entrada[2];
    size_t lidos = fread(lista_entrada, sizeof(Registro), 2, fp);
    fclose(fp);

    printf("=== Conteudo de '%s' (%zu/%zu registros lidos) ===\n",
           nome_binario, lidos, gravados);

    for (size_t i = 0; i < lidos; i++) {
        printf("ID: %d | Descricao: %-20s | Valor: %.1f\n",
               lista_entrada[i].id,
               lista_entrada[i].descricao,
               lista_entrada[i].valor);
    }
}
