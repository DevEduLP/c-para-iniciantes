/**
 * Arquivo: ponteiros_memoria.c
 * Módulo: 07 - Ponteiros e Alocação Dinâmica de Memória
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra manipulação de endereços, aritmética de ponteiros,
 *            alocação dinâmica na Heap (malloc/realloc) e liberação (free).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* 1. PONTEIROS BÁSICOS E ENDEREÇOS DE MEMÓRIA */
    int sensor = 100;
    int *ptr_sensor = &sensor;

    printf("=== 1. Ponteiros Basicos ===\n");
    printf("Valor de 'sensor':      %d\n", sensor);
    printf("Endereco de 'sensor':   %p\n", (void *)&sensor);
    printf("Valor de 'ptr_sensor':  %p\n", (void *)ptr_sensor);

    /* Alterando o valor original através do ponteiro */
    *ptr_sensor = 250;
    printf("Novo valor via ponteiro: %d\n\n", sensor);

    /* 2. ALOCAÇÃO DINÂMICA NA HEAP (malloc) */
    int qtd = 0;
    printf("=== 2. Alocacao Dinamica (malloc) ===\n");
    printf("Quantos elementos deseja armazenar? ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    /* Reserva espaço contíguo para 'qtd' inteiros na memória Heap */
    int *vetor = (int *)malloc((size_t)qtd * sizeof(int));

    /* Verificação obrigatória de falha de alocação */
    if (vetor == NULL) {
        fprintf(stderr, "Erro critico: falha ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < qtd; i++) {
        /* Aritmética de ponteiros: *(vetor + i) equivale a vetor[i] */
        *(vetor + i) = (i + 1) * 10;
    }

    printf("Elementos alocados: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    /* 3. REDIMENSIONAMENTO (realloc) E LIBERAÇÃO (free) */
    int novo_qtd = qtd + 2;
    int *temp = (int *)realloc(vetor, (size_t)novo_qtd * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Erro ao redimensionar memoria.\n");
        free(vetor);
        return 1;
    }
    vetor = temp;

    /* Preenche apenas as duas novas posições adicionadas */
    for (int i = qtd; i < novo_qtd; i++) {
        vetor[i] = (i + 1) * 10;
    }

    printf("=== 3. Apos realloc (+2 posicoes) ===\n");
    for (int i = 0; i < novo_qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    /* Libera a memória alocada na Heap e anula o ponteiro por segurança */
    free(vetor);
    vetor = NULL;

    return 0;
}
