/**
 * Arquivo: entrada_saida.c
 * Módulo: 02 - Variáveis, Tipos de Dados e Entrada/Saída
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra declaração de variáveis, constantes, operadores
 *            aritméticos, tamanho em memória (sizeof) e leitura via scanf.
 */

#include <stdio.h>

int main(void) {
    /* Declaração e inicialização das variáveis */
    char inicial = '\0';
    int idade = 0;
    float peso = 0.0f;
    float altura = 0.0f;
    float imc = 0.0f;

    /* Constante simbólica para fator de conversão de altura (cm para m) */
    const float CM_PARA_METROS = 100.0f;

    printf("=== Cadastro e Calculo de IMC ===\n\n");

    /* Leitura de caractere (espaço antes de %c ignora quebras de linha residuais) */
    printf("Digite a inicial do seu primeiro nome: ");
    scanf(" %c", &inicial);

    /* Leitura de inteiro */
    printf("Digite sua idade (anos): ");
    scanf("%d", &idade);

    /* Leitura de ponto flutuante */
    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura em centimetros (ex: 175): ");
    scanf("%f", &altura);

    /* Conversão de centímetros para metros e cálculo do IMC */
    float altura_metros = altura / CM_PARA_METROS;
    imc = peso / (altura_metros * altura_metros);

    /* Exibição formatada dos resultados */
    printf("\n--- Resumo ---\n");
    printf("Inicial: %c | Idade: %d anos\n", inicial, idade);
    printf("Altura: %.2f m | Peso: %.1f kg\n", altura_metros, peso);
    printf("IMC calculado: %.2f\n", imc);

    /* Demonstração de ocupação em memória RAM */
    printf("\n--- Tamanho dos Tipos nesta Maquina ---\n");
    printf("char:   %zu byte(s)\n", sizeof(char));
    printf("int:    %zu byte(s)\n", sizeof(int));
    printf("float:  %zu byte(s)\n", sizeof(float));
    printf("double: %zu byte(s)\n", sizeof(double));

    return 0;
}
