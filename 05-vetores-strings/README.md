# Módulo 05: Vetores, Matrizes e Manipulação de Strings

Este módulo aborda o armazenamento contíguo de dados na memória RAM por meio de vetores unidimensionais, matrizes multidimensionais e cadeias de caracteres (*strings*) terminadas em caractere nulo (`'\0'`).

---

## 1. Vetores Unidimensionais (*Arrays*)

Um vetor é uma coleção de elementos do **mesmo tipo** armazenados em endereços consecutivos de memória. Em C, a indexação sempre começa em **`0`** e vai até **`N - 1`**.

```c
int notas[5] = {8, 7, 9, 6, 10}; // Índices válidos: 0, 1, 2, 3 e 4
```

> **Cuidado com limites (*Buffer Overflow*):** A linguagem C não verifica automaticamente se você acessou `notas[5]`. Acessar índices fora do intervalo invade regiões vizinhas da memória e gera comportamento indefinido.

---

## 2. Matrizes (Vetores Bidimensionais)

Matrizes organizam dados em linhas e colunas (`tipo nome[linhas][colunas]`), sendo muito utilizadas para tabelas numéricas, tabuleiros e grades de coordenadas:

```c
int matriz[2][3] = {
    {1, 2, 3}, // Linha 0
    {4, 5, 6}  // Linha 1
};
```

Para percorrer todos os elementos de uma matriz, utilizam-se dois laços `for` aninhados (o externo percorre as linhas e o interno percorre as colunas).

---

## 3. Strings em C e o Caractere Nulo (`'\0'`)

Diferente de linguagens de alto nível, C não possui um tipo `string` nativo. Uma *string* é simplesmente um **vetor de `char`** encerrado obrigatoriamente pelo caractere terminador nulo **`'\0'`** (código ASCII `0`).

```c
char curso[4] = "ADS"; // Ocupa 4 bytes: 'A', 'D', 'S', '\0'
```

### Leitura Segura com `fgets`
Evite `scanf("%s", texto)` para frases, pois ele para no primeiro espaço e não limita a quantidade de caracteres lidos. Prefira **`fgets`**:

```c
char nome[50];
fgets(nome, sizeof(nome), stdin); // Lê até 49 caracteres + '\0'
```

### Funções Essenciais de `<string.h>`

| Função | Finalidade |
| :--- | :--- |
| `strlen(s)` | Retorna a quantidade de caracteres antes do `'\0'` |
| `strcpy(dest, orig)` | Copia o conteúdo de `orig` para `dest` |
| `strcmp(s1, s2)` | Compara duas strings (retorna `0` se forem idênticas) |
| `strcat(dest, orig)` | Concatena `orig` ao final de `dest` |

---

## 4. Exemplo Prático Completo

Veja o código comentado em [`vetores_strings.c`](./vetores_strings.c), que demonstra:
1. Leitura segura de strings com `fgets` e remoção do `\n` final.
2. Processamento estatístico (maior, menor e média) sobre um vetor de números reais.
3. Percorrimento de uma matriz bidimensional com laços aninhados.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 vetores_strings.c -o vetores_strings
./vetores_strings
```

---

## 5. Exercícios de Fixação

1. **Inversor de Vetor (`ex01_inverter.c`):** Leia 6 números inteiros para um vetor e exiba seus elementos na ordem inversa da leitura sem criar um segundo vetor auxiliar.
2. **Verificador de Palíndromo (`ex02_palindromo.c`):** Leia uma palavra usando `fgets` (ou `scanf("%49s", palavra)`) e verifique se ela é um palíndromo (ex: `"arara"`, `"radar"`), comparando os caracteres das extremidades em direção ao centro.
3. **Soma da Diagonal Principal (`ex03_diagonal.c`):** Preencha uma matriz quadrada `3x3` de inteiros com valores digitados pelo usuário, exiba a matriz formatada e calcule a soma dos elementos da diagonal principal (`linha == coluna`).

---

[⬅️ Módulo Anterior](../04-lacos-repeticao/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../06-funcoes/README.md)
