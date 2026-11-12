/**
 * Arquivo: vetores_strings.c
 * Módulo: 05 - Vetores, Matrizes e Manipulação de Strings
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra leitura segura de strings com fgets, uso de <string.h>,
 *            cálculos sobre vetores unidimensionais e leitura de matriz 2x3.
 */

#include <stdio.h>
#include <string.h>

#define QTD_NOTAS 4
#define LINHAS 2
#define COLUNAS 3

int main(void) {
    char aluno[60];
    float notas[QTD_NOTAS];
    float soma = 0.0f;

    /* 1. STRINGS: Leitura segura com fgets (inclui espaços) */
    printf("Digite o nome completo do aluno: ");
    if (fgets(aluno, sizeof(aluno), stdin) != NULL) {
        /* Remove a quebra de linha ('\n') capturada pelo fgets, se existir */
        size_t len = strlen(aluno);
        if (len > 0 && aluno[len - 1] == '\n') {
            aluno[len - 1] = '\0';
        }
    }

    /* 2. VETOR UNIDIMENSIONAL: Leitura e cálculo de estatísticas */
    printf("\nDigite as %d notas de %s:\n", QTD_NOTAS, aluno);
    for (int i = 0; i < QTD_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    float maior = notas[0];
    for (int i = 1; i < QTD_NOTAS; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }

    printf("\n--- Boletim ---\n");
    printf("Aluno: %s (Caracteres no nome: %zu)\n", aluno, strlen(aluno));
    printf("Media: %.2f | Maior nota: %.2f\n", soma / QTD_NOTAS, maior);

    /* 3. MATRIZ BIDIMENSIONAL: Inicialização e exibição tabular */
    int grade[LINHAS][COLUNAS] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    printf("\n--- Matriz %dx%d ---\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%4d ", grade[i][j]);
        }
        printf("\n");
    }

    return 0;
}
