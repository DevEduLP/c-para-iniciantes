/**
 * Arquivo: lacos_repeticao.c
 * Módulo: 04 - Estruturas de Repetição (while, do-while, for)
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra o uso prático de do-while para validação de entrada,
 *            for para geração de tabuada e somatório, e while com break.
 */

#include <stdio.h>

int main(void) {
    int numero = 0;

    /* 1. DO-WHILE: Garante que o usuário digite um número válido (1 a 10) */
    do {
        printf("Digite um numero inteiro entre 1 e 10: ");
        scanf("%d", &numero);

        if (numero < 1 || numero > 10) {
            printf("Valor invalido! Tente novamente.\n");
        }
    } while (numero < 1 || numero > 10);

    /* 2. FOR: Gera a tabuada e calcula o somatório dos resultados */
    int soma_resultados = 0;
    printf("\n--- Tabuada do %d ---\n", numero);

    for (int i = 1; i <= 10; i++) {
        int produto = numero * i;
        soma_resultados += produto;
        printf("%2d x %2d = %3d\n", numero, i, produto);
    }
    printf("Soma total dos resultados: %d\n", soma_resultados);

    /* 3. WHILE + BREAK: Busca o primeiro múltiplo de 7 maior que o número base */
    int candidato = numero + 1;
    printf("\n--- Busca com while e break ---\n");

    while (1) {
        if (candidato % 7 == 0) {
            printf("Primeiro multiplo de 7 maior que %d: %d\n", numero, candidato);
            break; /* Encerra o laço infinito assim que encontra o alvo */
        }
        candidato++;
    }

    return 0;
}
