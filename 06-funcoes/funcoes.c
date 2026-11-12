/**
 * Arquivo: funcoes.c
 * Módulo: 06 - Funções, Escopo e Passagem de Parâmetros
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra protótipos, passagem por valor, passagem por referência
 *            usando endereços, manipulação de vetores em funções e recursão.
 */

#include <stdio.h>

/* Protótipos das funções */
void tentar_trocar_valor(int a, int b);
void trocar_referencia(int *a, int *b);
float calcular_media(const float valores[], int tamanho);
unsigned long long fatorial_recursivo(int n);

int main(void) {
    int x = 10;
    int y = 25;

    /* 1. PASSAGEM POR VALOR vs. REFERÊNCIA */
    printf("=== 1. Passagem de Parametros ===\n");
    printf("Valores iniciais: x = %d, y = %d\n", x, y);

    tentar_trocar_valor(x, y);
    printf("Apos passagem por valor:      x = %d, y = %d (inalterados)\n", x, y);

    trocar_referencia(&x, &y);
    printf("Apos passagem por referencia: x = %d, y = %d (trocados!)\n\n", x, y);

    /* 2. PASSAGEM DE VETOR PARA FUNÇÃO */
    printf("=== 2. Vetor como Parametro ===\n");
    float medicoes[] = {7.5f, 8.0f, 9.5f, 6.0f};
    int qtd = (int)(sizeof(medicoes) / sizeof(medicoes[0]));

    float media = calcular_media(medicoes, qtd);
    printf("Media das %d medicoes: %.2f\n\n", qtd, media);

    /* 3. RECURSIVIDADE */
    printf("=== 3. Recursividade ===\n");
    int numero = 6;
    printf("Fatorial de %d = %llu\n", numero, fatorial_recursivo(numero));

    return 0;
}

/* Recebe apenas cópias de 'a' e 'b'; as variáveis originais não mudam */
void tentar_trocar_valor(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

/* Recebe os endereços de memória e altera os valores originais via desreferência (*) */
void trocar_referencia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 'const' garante que a função apenas lê o vetor sem modificá-lo */
float calcular_media(const float valores[], int tamanho) {
    if (tamanho <= 0) {
        return 0.0f;
    }

    float soma = 0.0f;
    for (int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }
    return soma / (float)tamanho;
}

/* Calcula n! chamando a própria função até atingir o caso base (n <= 1) */
unsigned long long fatorial_recursivo(int n) {
    if (n <= 1) {
        return 1ULL;
    }
    return (unsigned long long)n * fatorial_recursivo(n - 1);
}
