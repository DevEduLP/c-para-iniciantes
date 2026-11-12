# Módulo 04: Estruturas de Repetição (`while`, `do-while`, `for`)

Este módulo apresenta os laços de repetição (*loops*) em C, permitindo automatizar tarefas repetitivas, percorrer sequências numéricas e validar entradas do usuário sem duplicação de código.

---

## 1. Comparativo entre os Laços

| Estrutura | Quando testar a condição | Melhor caso de uso |
| :--- | :--- | :--- |
| `while` | **Antes** de executar o bloco | Quando não se sabe antecipadamente quantas repetições ocorrerão (ex: leitura até um valor sentinela). |
| `do-while` | **Depois** de executar o bloco | Quando o código precisa rodar **pelo menos uma vez** (ex: menus interativos e validação de entrada). |
| `for` | **Antes** de executar o bloco | Quando o número de iterações é conhecido ou há um contador claro (ex: percorrer de `0` a `N - 1`). |

---

## 2. Sintaxe das Estruturas

### Laço `while`
Executa enquanto a condição for verdadeira. Se a condição já iniciar falsa, o bloco nunca roda:

```c
int contador = 1;
while (contador <= 5) {
    printf("%d ", contador);
    contador++; // Incremento obrigatório para evitar loop infinito
}
```

### Laço `do-while`
Garante a primeira execução antes de testar a condição no final (note o ponto e vírgula `;` obrigatório após o `while`):

```c
int numero;
do {
    printf("Digite um numero positivo: ");
    scanf("%d", &numero);
} while (numero <= 0);
```

### Laço `for`
Agrupa inicialização, condição de parada e incremento em uma única linha:

```c
for (int i = 0; i < 10; i++) {
    printf("Iteracao %d\n", i);
}
```

---

## 3. Controle de Fluxo: `break` e `continue`

* **`break`**: Interrompe imediatamente o laço mais interno e continua a execução após o fechamento do bloco.
* **`continue`**: Pula o restante das instruções da iteração atual e avança diretamente para o próximo ciclo do laço.

---

## 4. Exemplo Prático Completo

Veja o código comentado em [`lacos_repeticao.c`](./lacos_repeticao.c), que demonstra:
1. Validação de entrada com `do-while`.
2. Cálculo de tabuada e somatório acumulado com `for`.
3. Contagem regressiva e busca com `while` e `break`.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 lacos_repeticao.c -o lacos_repeticao
./lacos_repeticao
```

---

## 5. Exercícios de Fixação

1. **Validador de Notas e Média (`ex01_media_turma.c`):** Leia notas de alunos até que o usuário digite `-1` (valor sentinela). Ignore notas inválidas (menores que `0` ou maiores que `10`) usando `continue` e, ao final, exiba a média aritmética das notas válidas.
2. **Sequência de Fibonacci (`ex02_fibonacci.c`):** Leia um número inteiro $N$ ($N \ge 1$) e imprima os $N$ primeiros termos da sequência de Fibonacci utilizando um laço `for`.
3. **Verificador de Número Primo (`ex03_primo.c`):** Leia um inteiro positivo e utilize um laço para verificar se ele é primo. Otimize o loop interrompendo-o com `break` assim que encontrar o primeiro divisor exato.

---

[⬅️ Módulo Anterior](../03-condicionais/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../05-vetores-strings/README.md)
