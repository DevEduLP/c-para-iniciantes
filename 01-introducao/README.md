# Módulo 01: Introdução à Linguagem C

Este módulo apresenta os fundamentos da linguagem C, o fluxo de compilação até o código de máquina e a anatomia do primeiro programa executável.

---

## 1. Por que estudar C?

Criada por Dennis Ritchie em 1972 nos laboratórios Bell, a linguagem C é compilada, estruturada e oferece acesso direto à memória e ao hardware. Ela serve de alicerce para:

* **Sistemas Operacionais:** Kernels como Linux, Windows e macOS.
* **Sistemas Embarcados e Aviônica:** Microcontroladores e softwares de tempo real onde previsibilidade e baixo consumo de memória são críticos.
* **Estruturas de Dados e Algoritmos:** Implementação eficiente de árvores, grafos e compressores de dados sem camadas ocultas de abstração.

---

## 2. O Ciclo de Compilação

O computador não executa diretamente o texto escrito no arquivo `.c`. O compilador (como o **GCC**) transforma o código-fonte em um programa binário por meio de quatro etapas sequenciais:

1. **Pré-processamento:** Expande diretivas que começam com `#`, como `#include` e `#define`.
2. **Compilação:** Traduz o código C pré-processado em código **Assembly** específico para a arquitetura do processador.
3. **Montagem (Assembly):** Traduz as instruções Assembly em código de máquina binário (arquivo objeto `.o` ou `.obj`).
4. **Ligação (Linking):** Une o código objeto às bibliotecas padrão (como a `stdio.h`) para gerar o arquivo executável final.

---

## 3. Anatomia do Primeiro Programa

Veja o código completo no arquivo [`ola_mundo.c`](./ola_mundo.c):

```c
#include <stdio.h>

int main(void) {
    printf("Ola, Mundo! Bem-vindo a programacao em C.\n");
    return 0;
}
```

### Explicação linha a linha:

* **`#include <stdio.h>`**: Diretiva de pré-processamento que importa a biblioteca padrão de entrada e saída (*Standard Input/Output*). Sem ela, o compilador não reconhece a função `printf`.
* **`int main(void)`**: Ponto de entrada obrigatório de todo programa em C. O `int` indica que a função devolve um número inteiro ao sistema operacional, e `void` especifica que ela não recebe argumentos.
* **`{ ... }`**: Chaves delimitam o bloco de instruções pertencente à função `main`.
* **`printf(...)`**: Função que imprime texto formatado no terminal. O caractere de escape `\n` insere uma quebra de linha ao final da frase, e o ponto e vírgula (`;`) encerra a instrução.
* **`return 0;`**: Encerra a execução de `main` e informa ao sistema operacional que o programa finalizou sem erros.

---

## 4. Compilação e Execução no Terminal (GCC)

No terminal do VS Code ou prompt de comando, navegue até a pasta `01-introducao` e execute:

```bash
gcc -Wall -Wextra -std=c11 ola_mundo.c -o ola_mundo
```

* **`-Wall -Wextra`**: Ativa avisos importantes do compilador para detectar erros comuns logo na compilação.
* **`-std=c11`**: Define o padrão moderno C11 da linguagem.
* **`-o ola_mundo`**: Define o nome do arquivo executável gerado.

Para rodar o programa compilado:

* **Linux / macOS:** `./ola_mundo`
* **Windows (CMD / PowerShell):** `ola_mundo.exe`

---

## 5. Exercícios de Fixação

1. **Cartão de Apresentação (`ex01_apresentacao.c`):** Crie um programa que exiba seu nome completo, seu curso e a cidade onde você mora, cada informação em uma linha separada usando `\n`.
2. **Saída Formatada (`ex02_tabela.c`):** Utilize apenas chamadas `printf` e tabulações (`\t`) para desenhar no terminal uma pequena tabela alinhada com 3 linguagens de programação e seus respectivos anos de criação.
3. **Teste de Erro (`ex03_diagnostico.c`):** Remova propositalmente o ponto e vírgula (`;`) após o `printf` no arquivo `ola_mundo.c`, tente compilar com `gcc` e leia a mensagem de erro apontada pelo compilador para entender como identificar falhas de sintaxe.

---

[⬅️ Voltar ao Índice Principal](../README.md) | [Próximo Módulo ➡️](../02-variaveis-entrada-saida/README.md)
