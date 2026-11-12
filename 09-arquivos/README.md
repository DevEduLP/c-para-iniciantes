# Módulo 09: Manipulação de Arquivos em C (`fopen`, `fread`, `fwrite`, `fclose`)

Este módulo apresenta a persistência de dados em disco por meio da biblioteca padrão `<stdio.h>`, abordando fluxos (`FILE *`), modos de abertura, leitura e escrita em modo texto e gravação direta de estruturas em arquivos binários.

---

## 1. Ponteiro de Arquivo (`FILE *`) e Modos de Abertura

Em C, qualquer arquivo em disco é manipulado por meio de um ponteiro do tipo `FILE *`, retornado pela função `fopen(caminho, modo)`:

| Modo | Significado | Cria se não existir? | Apaga conteúdo anterior? |
| :--- | :--- | :--- | :--- |
| `"r"` | Leitura (*Read*) | **Não** (retorna `NULL`) | Não |
| `"w"` | Escrita (*Write*) | **Sim** | **Sim** (sobrescreve tudo) |
| `"a"` | Anexar (*Append*) | **Sim** | Não (escreve ao final) |
| `"rb"` / `"wb"` | Leitura / Escrita **Binária** | `"wb"` cria; `"rb"` não | `"wb"` apaga; `"rb"` não |

> **Regra obrigatória:** Sempre verifique se `fopen` retornou `NULL` (ex: arquivo inexistente ou falta de permissão) antes de tentar ler ou escrever, e sempre encerre o fluxo com `fclose(fp)` para descarregar o buffer (*flush*) no disco.

---

## 2. Arquivos de Texto vs. Arquivos Binários

* **Arquivos de Texto (`.txt`, `.csv`, `.log`):** Armazenam caracteres legíveis por humanos usando funções como `fprintf`, `fscanf`, `fgets` e `fputs`.
* **Arquivos Binários (`.bin`, `.dat`):** Gravam o conteúdo exato dos bytes da memória RAM diretamente no disco por meio de `fwrite` e `fread` — ideal para salvar `struct`s inteiras sem precisar converter números para texto.

### Assinatura de `fwrite` e `fread`

```c
size_t fwrite(const void *ptr, size_t tamanho_elemento, size_t qtd, FILE *stream);
size_t fread(void *ptr, size_t tamanho_elemento, size_t qtd, FILE *stream);
```

---

## 3. Verificação de Fim de Arquivo (`feof`)

Um erro clássico de iniciantes é usar `while (!feof(fp))` para controlar laços de leitura, o que faz o loop rodar uma vez a mais após a última linha falhar. A forma correta é testar o retorno da própria função de leitura (`fgets`, `fscanf` ou `fread`):

```c
char linha[128];
while (fgets(linha, sizeof(linha), fp) != NULL) {
    printf("%s", linha);
}
```

---

## 4. Exemplo Prático Completo

Veja o código comentado em [`arquivos.c`](./arquivos.c), que demonstra:
1. Gravação e leitura linha a linha em arquivo de texto (`historico.txt`).
2. Serialização e recuperação de um vetor de `struct` em arquivo binário (`dados.bin`) usando `fwrite` e `fread`.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 arquivos.c -o arquivos
./arquivos
```

---

## 5. Exercícios de Fixação

1. **Contador de Linhas e Palavras (`ex01_contador_texto.c`):** Abra um arquivo de texto existente em modo `"r"`, percorra seu conteúdo caractere por caractere com `fgetc(fp)` até `EOF` e exiba o total de caracteres e de quebras de linha (`'\n'`).
2. **Exportador CSV (`ex02_exportar_csv.c`):** Crie um programa que leia nome e nota de 3 alunos e salve os dados no formato `nome;nota` dentro de um arquivo `notas.csv` utilizando `fprintf`.
3. **Agenda Binária Persistente (`ex03_agenda_binaria.c`):** Defina uma `struct Contato` (`nome` e `telefone`) e implemente duas opções no menu: (1) adicionar um novo contato ao final do arquivo `agenda.bin` usando modo `"ab"` e `fwrite`, e (2) listar todos os contatos gravados usando `"rb"` e `fread`.

---

[⬅️ Módulo Anterior](../08-structs/README.md) | [🏠 Índice Principal](../README.md)
