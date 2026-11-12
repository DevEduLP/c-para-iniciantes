# Módulo 07: Ponteiros e Alocação Dinâmica de Memória

Este módulo explica o funcionamento de ponteiros, aritmética de endereços e gerenciamento manual de memória na *Heap* (`malloc`, `calloc`, `realloc` e `free`) — um dos pilares da programação de baixo nível em C.

---

## 1. O que é um Ponteiro?

Um **ponteiro** é uma variável que não armazena um dado comum (como `10` ou `'A'`), mas sim o **endereço de memória RAM** onde outra variável está localizada.

### Operadores Fundamentais

| Operador | Nome | Função |
| :--- | :--- | :--- |
| `&` | Endereço (*Address-of*) | Obtém o endereço de memória onde a variável está armazenada |
| `*` | Desreferência (*Dereference*) | Acessa ou modifica o valor guardado no endereço apontado |

```c
int valor = 42;
int *ptr = &valor; // 'ptr' guarda o endereço de 'valor'

printf("Endereco: %p\n", (void *)ptr); // Exibe o endereço hexadecimal
printf("Conteudo: %d\n", *ptr);        // Exibe 42
*ptr = 99;                             // Altera 'valor' para 99 indiretamente
```

> **Boa prática:** Sempre inicialize ponteiros que ainda não apontam para um endereço válido com `NULL` (`int *ptr = NULL;`). Desreferenciar um ponteiro não inicializado causa falha de segmentação (*Segmentation Fault*).

---

## 2. Ponteiros e Vetores (Aritmética de Ponteiros)

Em C, o nome de um vetor funciona como um ponteiro constante para o seu primeiro elemento (`&vetor[0]`). Quando você soma `1` a um ponteiro (`ptr + 1`), o compilador avança automaticamente `sizeof(tipo)` bytes na memória:

```c
int v[3] = {10, 20, 30};
int *p = v;

printf("%d\n", *(p + 1)); // Equivale a v[1], imprime 20
```

---

## 3. Memória *Stack* vs. *Heap* e Alocação Dinâmica

* **Stack (Pilha):** Memória automática e rápida, mas com tamanho fixo definido em tempo de compilação (ex: `int v[100];`).
* **Heap (Monte):** Região de memória flexível gerenciada manualmente pelo programador em tempo de execução por meio da biblioteca `<stdlib.h>`.

### Funções de Gerenciamento (`<stdlib.h>`)

| Função | Assinatura | Comportamento |
| :--- | :--- | :--- |
| `malloc` | `void *malloc(size_t bytes)` | Aloca `bytes` contíguos sem inicializar (contém lixo de memória) |
| `calloc` | `void *calloc(size_t qtd, size_t tam)` | Aloca espaço para `qtd` elementos e inicializa todos os bits com **zero** |
| `realloc` | `void *realloc(void *ptr, size_t novo_tam)` | Redimensiona um bloco já alocado preservando os dados existentes |
| `free` | `void free(void *ptr)` | Libera a memória alocada de volta ao sistema operacional |

### Regras de Ouro da Alocação Dinâmica
1. **Sempre verifique `NULL`:** Se faltar memória RAM, `malloc`/`calloc` retornam `NULL`.
2. **Evite *Memory Leaks*:** Para cada `malloc` ou `calloc`, deve existir exatamente um `free` correspondente.
3. **Evite *Dangling Pointers*:** Após chamar `free(ptr)`, atribua `ptr = NULL;` para evitar acessos acidentais a memória já liberada.

---

## 4. Exemplo Prático Completo

Veja o código comentado em [`ponteiros_memoria.c`](./ponteiros_memoria.c), que demonstra:
1. Inspeção de endereços e manipulação indireta com `&` e `*`.
2. Alocação dinâmica de um vetor de tamanho definido pelo usuário em tempo de execução (`malloc`).
3. Expansão dinâmica do vetor com `realloc` e liberação segura com `free`.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 ponteiros_memoria.c -o ponteiros_memoria
./ponteiros_memoria
```

---

## 5. Exercícios de Fixação

1. **Vetor Dinâmico de Notas (`ex01_vetor_dinamico.c`):** Pergunte ao usuário quantos alunos existem na turma (`N`), aloque dinamicamente um vetor de `float` com `malloc`, leia as `N` notas, exiba a média geral e libere a memória com `free`.
2. **Cópia de String Dinâmica (`ex02_duplicar_string.c`):** Implemente uma função `char *duplicar_string(const char *origem)` que calcule o tamanho da string original (`strlen`), aloque exatamente `strlen(origem) + 1` bytes na *Heap* com `malloc`, copie o conteúdo e retorne o novo ponteiro.
3. **Matriz Dinâmica 2D (`ex03_matriz_dinamica.c`):** Aloque dinamicamente uma matriz `L x C` utilizando um ponteiro duplo (`int **matriz`), preencha com valores sequenciais, exiba a grade e libere cada linha antes de liberar o vetor principal de ponteiros.

---

[⬅️ Módulo Anterior](../06-funcoes/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../08-structs/README.md)
