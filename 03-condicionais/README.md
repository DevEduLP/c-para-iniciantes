# Módulo 03: Estruturas Condicionais (`if`, `else`, `switch`)

Este módulo apresenta o controle de fluxo condicional em C, permitindo que o programa tome decisões lógicas com base em expressões relacionais, operadores booleanos e seleções múltiplas.

---

## 1. Operadores Relacionais e Lógicos

Em C, não existe um tipo booleano nativo no padrão clássico sem incluir `<stdbool.h>`: qualquer expressão avaliada como **`0`** é considerada **falsa**, e qualquer valor **diferente de zero** (geralmente `1`) é considerado **verdadeiro**.

### Operadores Relacionais

| Operador | Significado | Exemplo | Resultado (se `x = 5`) |
| :--- | :--- | :--- | :--- |
| `==` | Igual a | `x == 5` | `1` (Verdadeiro) |
| `!=` | Diferente de | `x != 3` | `1` (Verdadeiro) |
| `>` | Maior que | `x > 10` | `0` (Falso) |
| `<` | Menor que | `x < 10` | `1` (Verdadeiro) |
| `>=` | Maior ou igual a | `x >= 5` | `1` (Verdadeiro) |
| `<=` | Menor ou igual a | `x <= 4` | `0` (Falso) |

> **Armadilha clássica:** Nunca confunda atribuição (`=`) com comparação (`==`). Escrever `if (x = 0)` atribui `0` a `x` e avalia a condição como falsa sem gerar erro de sintaxe.

### Operadores Lógicos

| Operador | Nome | Descrição |
| :--- | :--- | :--- |
| `&&` | **E** lógico (*AND*) | Verdadeiro apenas se **ambas** as condições forem verdadeiras |
| `\|\|` | **OU** lógico (*OR*) | Verdadeiro se **pelo menos uma** das condições for verdadeira |
| `!` | **NÃO** lógico (*NOT*) | Inverte o valor lógico (`!0` vira `1`; `!1` vira `0`) |

---

## 2. Estrutura `if`, `else if` e `else`

Permite executar blocos distintos de código de acordo com testes sequenciais:

```c
if (nota >= 7.0) {
    printf("Aprovado!\n");
} else if (nota >= 5.0) {
    printf("Em recuperacao.\n");
} else {
    printf("Reprovado.\n");
}
```

---

## 3. Operador Ternário (`? :`)

Forma compacta de escrever um `if / else` simples que retorna um valor:

```c
int maior = (a > b) ? a : b;
```

---

## 4. Estrutura `switch / case`

Ideal quando uma única variável inteira (`int` ou `char`) precisa ser comparada contra vários valores constantes específicos:

```c
switch (opcao) {
    case 1:
        printf("Iniciar sistema\n");
        break;
    case 2:
        printf("Configuracoes\n");
        break;
    default:
        printf("Opcao invalida\n");
        break;
}
```

> **Importante:** O comando `break` encerra o bloco `switch`. Sem ele, a execução continua invadindo os `case` seguintes (*fall-through*).

---

## 5. Exemplo Prático Completo

Veja o código comentado em [`condicionais.c`](./condicionais.c), que combina um menu interativo via `switch` com validações de faixa numérica utilizando `if / else if / else` e operadores lógicos.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 condicionais.c -o condicionais
./condicionais
```

---

## 6. Exercícios de Fixação

1. **Classificador de Triângulos (`ex01_triangulo.c`):** Leia três lados inteiros (`a`, `b`, `c`). Primeiro verifique se formam um triângulo válido (cada lado deve ser menor que a soma dos outros dois). Se válido, classifique-o como **Equilátero**, **Isósceles** ou **Escaleno**.
2. **Ano Bissexto (`ex02_bissexto.c`):** Leia um ano (`int`) e informe se ele é bissexto utilizando uma única expressão lógica com `&&` e `||` (divisível por 4 e não por 100, ou divisível por 400).
3. **Calculadora Simples (`ex03_calculadora.c`):** Leia dois números reais e um caractere de operação (`+`, `-`, `*`, `/`). Use `switch` para calcular o resultado e trate a divisão por zero com `if`.

---

[⬅️ Módulo Anterior](../02-variaveis-entrada-saida/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../04-lacos-repeticao/README.md)
