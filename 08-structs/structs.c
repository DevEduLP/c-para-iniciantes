/**
 * Arquivo: structs.c
 * Módulo: 08 - Estruturas (struct) e Tipos Definidos (typedef)
 * Autor: Eduardo Livi Pedruzzi
 * Descrição: Demonstra definição de tipos compostos com typedef struct,
 *            estruturas aninhadas, vetor de structs e acesso via seta (->).
 */

#include <stdio.h>
#include <string.h>

/* Estrutura auxiliar para representar datas */
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

/* Estrutura principal contendo uma struct aninhada */
typedef struct {
    int numero;
    char titular[50];
    double saldo;
    Data abertura;
} ContaBancaria;

/* Protótipos usando ponteiros para evitar cópia desnecessária na Stack */
void depositar(ContaBancaria *conta, double valor);
void exibir_conta(const ContaBancaria *conta);

int main(void) {
    /* Inicialização de um vetor de estruturas */
    ContaBancaria contas[2] = {
        {1001, "Carlos Mendes", 1500.00, {12, 3, 2024}},
        {1002, "Mariana Costa", 3250.50, {28, 8, 2025}}
    };

    printf("=== Estado Inicial das Contas ===\n");
    for (int i = 0; i < 2; i++) {
        /* Passa o endereço (&) de cada elemento do vetor */
        exibir_conta(&contas[i]);
    }

    /* Realiza uma operação modificando a struct via ponteiro */
    printf("\nRealizando deposito de R$ 450.00 na conta 1001...\n");
    depositar(&contas[0], 450.00);

    printf("\n=== Estado Atualizado ===\n");
    exibir_conta(&contas[0]);

    /* Demonstração do tamanho total ocupado pela struct na memória */
    printf("\nTamanho de ContaBancaria na memoria: %zu bytes\n", sizeof(ContaBancaria));

    return 0;
}

/* Recebe um ponteiro mutável e usa o operador seta (->) para alterar o saldo */
void depositar(ContaBancaria *conta, double valor) {
    if (conta != NULL && valor > 0.0) {
        conta->saldo += valor;
    }
}

/* 'const' garante que esta função apenas lê os campos sem modificá-los */
void exibir_conta(const ContaBancaria *conta) {
    if (conta == NULL) {
        return;
    }

    printf("Conta #%d | Titular: %-15s | Saldo: R$ %8.2f | Aberta em: %02d/%02d/%04d\n",
           conta->numero,
           conta->titular,
           conta->saldo,
           conta->abertura.dia,
           conta->abertura.mes,
           conta->abertura.ano);
}
