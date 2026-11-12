/**
 * Arquivo: condicionais.c
 * Módulo: 03 - Estruturas Condicionais (if, else, switch)
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra tomada de decisão com if / else if / else,
 *            operadores lógicos (&&, ||), operador ternário e menu switch.
 */

#include <stdio.h>

int main(void) {
    int opcao = 0;

    printf("=== Sistema de Analise Academica ===\n");
    printf("1 - Verificar situacao por nota e frequencia\n");
    printf("2 - Verificar paridade e sinal de um numero\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            float nota = 0.0f;
            int frequencia = 0;

            printf("\nDigite a nota final (0.0 a 10.0): ");
            scanf("%f", &nota);

            printf("Digite a frequencia em porcentagem (0 a 100): ");
            scanf("%d", &frequencia);

            /* Validação de intervalo utilizando OU lógico (||) */
            if (nota < 0.0f || nota > 10.0f || frequencia < 0 || frequencia > 100) {
                printf("Erro: valores fora do intervalo permitido.\n");
            } else if (frequencia < 75) {
                printf("Situacao: Reprovado por falta (%d%% de frequencia).\n", frequencia);
            } else if (nota >= 7.0f && frequencia >= 75) {
                printf("Situacao: Aprovado! Nota: %.1f\n", nota);
            } else if (nota >= 5.0f) {
                printf("Situacao: Exame final. Nota: %.1f\n", nota);
            } else {
                printf("Situacao: Reprovado por nota (%.1f).\n", nota);
            }
            break;
        }

        case 2: {
            int numero = 0;

            printf("\nDigite um numero inteiro: ");
            scanf("%d", &numero);

            /* Operador ternário para verificar se o resto da divisão por 2 é zero */
            const char *paridade = (numero % 2 == 0) ? "Par" : "Impar";

            if (numero > 0) {
                printf("O numero %d e Positivo e %s.\n", numero, paridade);
            } else if (numero < 0) {
                printf("O numero %d e Negativo e %s.\n", numero, paridade);
            } else {
                printf("O numero e Zero (neutro e Par).\n");
            }
            break;
        }

        default:
            printf("\nOpcao invalida! Execute novamente e escolha 1 ou 2.\n");
            break;
    }

    return 0;
}
