# Guia Introdutório de Programação C para Iniciantes

Material didático voltado para estudantes de Computação e Análise e Desenvolvimento de Sistemas (ADS), com explicações passo a passo, exemplos comentados e exercícios práticos.

## Objetivo
Construir uma base sólida em programação estruturada e gerenciamento de memória, partindo dos fundamentos da linguagem C até tópicos essenciais de baixo nível.

## Conteúdo Programático

- [x] **Módulo 01:** [Introdução à Linguagem C e Configuração do Ambiente](./01-introducao/README.md)
- [x] **Módulo 02:** [Variáveis, Tipos de Dados, Operadores e Entrada/Saída (`printf` e `scanf`)](./02-variaveis-entrada-saida/README.md)
- [x] **Módulo 03:** [Estruturas Condicionais (`if`, `else`, `switch`)](./03-condicionais/README.md)
- [x] **Módulo 04:** [Estruturas de Repetição (`while`, `do-while`, `for`)](./04-lacos-repeticao/README.md)
- [x] **Módulo 05:** [Vetores, Matrizes e Manipulação de Strings](./05-vetores-strings/README.md)
- [x] **Módulo 06:** [Funções, Escopo e Passagem de Parâmetros](./06-funcoes/README.md)
- [x] **Módulo 07:** [Ponteiros e Alocação Dinâmica de Memória (`malloc`, `calloc`, `free`)](./07-ponteiros-memoria/README.md)
- [x] **Módulo 08:** [Estruturas (`struct`) e Tipos Definidos (`typedef`)](./08-structs/README.md)
- [x] **Módulo 09:** [Manipulação de Arquivos em C (`fopen`, `fread`, `fwrite`, `fclose`)](./09-arquivos/README.md)

## Estrutura do Repositório

```text
c-para-iniciantes/
├── README.md
├── 01-introducao/
│   ├── README.md
│   └── ola_mundo.c
├── 02-variaveis-entrada-saida/
│   ├── README.md
│   └── entrada_saida.c
├── 03-condicionais/
│   ├── README.md
│   └── condicionais.c
├── 04-lacos-repeticao/
│   ├── README.md
│   └── lacos_repeticao.c
├── 05-vetores-strings/
│   ├── README.md
│   └── vetores_strings.c
├── 06-funcoes/
│   ├── README.md
│   └── funcoes.c
├── 07-ponteiros-memoria/
│   ├── README.md
│   └── ponteiros_memoria.c
├── 08-structs/
│   ├── README.md
│   └── structs.c
└── 09-arquivos/
    ├── README.md
    └── arquivos.c
```

## Como Compilar os Exemplos

Todos os códigos seguem o padrão **C11** e podem ser compilados via terminal com o **GCC**:

```bash
gcc -Wall -Wextra -std=c11 arquivo.c -o programa
./programa
```

## Autor
**Eduardo Livi Pedruzzi** — Estudante de Análise e Desenvolvimento de Sistemas (Unochapecó) | Pesquisador em Computação Aplicada e Sistemas de Baixo Nível.  
Portfólio Acadêmico: [eduardolivi.vercel.app](https://eduardolivi.vercel.app)
