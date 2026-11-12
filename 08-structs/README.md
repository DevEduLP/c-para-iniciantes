# Módulo 08: Estruturas (`struct`) e Tipos Definidos (`typedef`)

Este módulo apresenta a criação de tipos de dados compostos em C por meio de `struct` e `typedef`, permitindo agrupar variáveis heterogêneas sob uma mesma entidade lógica — base fundamental para listas encadeadas, árvores, grafos e registros bancários ou acadêmicos.

---

## 1. Definindo uma `struct` e Usando `typedef`

Enquanto um vetor armazena múltiplos elementos do **mesmo tipo**, uma `struct` agrupa campos (membros) de **tipos diferentes** em um bloco contíguo de memória.

Combinar `struct` com `typedef` elimina a necessidade de repetir a palavra-chave `struct` toda vez que uma variável for declarada:

```c
typedef struct {
    int matricula;
    char nome[60];
    float media;
} Estudante;

Estudante aluno1 = {202601, "Ana Silva", 8.75f};
```

---

## 2. Acesso aos Membros: Operador Ponto (`.`) vs. Seta (`->`)

A forma de acessar os campos internos depende de você ter a estrutura diretamente em mãos ou um **ponteiro** para ela:

| Contexto | Operador | Exemplo | Equivalência |
| :--- | :--- | :--- | :--- |
| Variável direta (`Estudante e`) | `.` (ponto) | `e.media = 9.0f;` | Acesso direto ao membro |
| Ponteiro (`Estudante *ptr`) | `->` (seta) | `ptr->media = 9.0f;` | `(*ptr).media = 9.0f;` |

> **Por que passar ponteiros de `struct` para funções?** Estruturas podem ocupar dezenas ou centenas de bytes. Passar um ponteiro (`const Estudante *e`) evita copiar todos os dados na pilha (*Stack*) a cada chamada de função, aumentando a eficiência do programa.

---

## 3. Estruturas Aninhadas e Vetores de `struct`

Uma `struct` pode conter outras `struct` como campos e também pode ser organizada em vetores para representar coleções de registros (como um cadastro de produtos, contas ou aeronaves):

```c
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    Data data_cadastro;
} Registro;
```

---

## 4. Alinhamento de Memória (*Struct Padding*)

O compilador frequentemente insere bytes vazios (*padding*) entre os membros de uma `struct` para alinhá-los aos limites de palavra da arquitetura do processador (4 ou 8 bytes), garantindo leituras rápidas na CPU. Por isso, `sizeof(MinhaStruct)` pode ser ligeiramente maior que a soma simples dos tamanhos de seus campos individuais.

---

## 5. Exemplo Prático Completo

Veja o código comentado em [`structs.c`](./structs.c), que demonstra:
1. Composição de estruturas aninhadas (`Data` dentro de `ContaBancaria`).
2. Criação e manipulação de um vetor de `struct`.
3. Passagem de ponteiro de `struct` para funções de atualização (depósito) e leitura (`const` na exibição).

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 structs.c -o structs
./structs
```

---

## 6. Exercícios de Fixação

1. **Cadastro de Livros (`ex01_biblioteca.c`):** Defina uma `struct Livro` com `titulo` (`char[80]`), `autor` (`char[60]`) e `ano` (`int`). Leia os dados de 3 livros para um vetor e exiba apenas os livros publicados após o ano `2015`.
2. **Distância entre Pontos 2D (`ex02_ponto2d.c`):** Crie uma `struct Ponto` com coordenadas `double x` e `double y`. Escreva uma função `double calcular_distancia(const Ponto *a, const Ponto *b)` que calcule a distância euclidiana entre dois pontos utilizando `sqrt()` da biblioteca `<math.h>`.
3. **Alocação Dinâmica de `struct` (`ex03_produto_dinamico.c`):** Defina uma `struct Produto` (`codigo`, `nome`, `preco`), aloque dinamicamente um vetor para `N` produtos usando `malloc`, preencha os dados via ponteiro (`->`), exiba o produto mais caro e libere a memória com `free`.

---

[⬅️ Módulo Anterior](../07-ponteiros-memoria/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../09-arquivos/README.md)
