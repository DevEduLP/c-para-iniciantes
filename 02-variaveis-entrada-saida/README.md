# Módulo 02: Variáveis, Tipos de Dados e Entrada/Saída

Este módulo aborda como a linguagem C reserva espaço na memória RAM para armazenar dados, os tipos primitivos fundamentais, os operadores aritméticos e a leitura de dados via teclado com `scanf`.

---

## 1. Tipos de Dados Primitivos

Em C, toda variável precisa ter seu tipo declarado explicitamente antes de ser usada, pois o compilador precisa saber quantos bytes alocar na memória e como interpretar os bits armazenados.

| Tipo | Descrição | Tamanho Típico (x86_64) | Especificador (`printf`/`scanf`) |
| :--- | :--- | :--- | :--- |
| `char` | Caractere único (tabela ASCII) ou inteiro pequeno | 1 byte | `%c` |
| `int` | Número inteiro (positivo ou negativo) | 4 bytes | `%d` ou `%i` |
| `float` | Número real de precisão simples (~6 casas decimais) | 4 bytes | `%f` |
| `double` | Número real de precisão dupla (~15 casas decimais) | 8 bytes | `%lf` |

> **Dica:** Você pode verificar o tamanho exato de qualquer tipo ou variável no seu computador utilizando o operador `sizeof(tipo)`.

---

## 2. Declaração de Variáveis e Constantes

* **Variáveis:** Seguem o formato `tipo nome = valor_inicial;`. Inicializar variáveis evita ler "lixo de memória" (valores residuais que estavam naquele endereço).
* **Constantes:** Utilizam o qualificador `const` para impedir que o valor seja alterado durante a execução do programa.

```c
int idade = 25;
float altura = 1.75f;
char inicial = 'E';
const float PI = 3.14159f;
```

---

## 3. Operadores Aritméticos e Divisão Inteira

| Operador | Operação | Exemplo (`a = 10, b = 3`) | Resultado |
| :--- | :--- | :--- | :--- |
| `+` | Adição | `a + b` | `13` |
| `-` | Subtração | `a - b` | `7` |
| `*` | Multiplicação | `a * b` | `30` |
| `/` | Divisão | `a / b` | `3` (trunca a parte decimal) |
| `%` | Módulo (resto da divisão) | `a % b` | `1` (apenas para inteiros) |

> **Atenção à divisão inteira:** Em C, dividir dois valores `int` (`10 / 3`) descarta a fração e resulta em `3`. Para obter `3.333...`, pelo menos um dos operandos precisa ser ponto flutuante (ex: `10.0 / 3` ou `(float)a / b`).

---

## 4. Leitura de Dados com `scanf` e o Operador `&`

A função `scanf` lê dados digitados no terminal e os grava diretamente no endereço de memória da variável. Por isso, é obrigatório utilizar o operador **`&`** (*address-of*) antes do nome da variável:

```c
int numero;
scanf("%d", &numero); // Lê um inteiro e salva no endereço de 'numero'
```

* **Limpeza de buffer com `char`:** Ao ler um `char` após um número, a tecla `Enter` (`\n`) anterior pode ficar pendente no buffer do teclado. Colocar um espaço antes do especificador (`scanf(" %c", &letra);`) instrui o `scanf` a ignorar espaços em branco e quebras de linha anteriores.

---

## 5. Exemplo Prático Completo

Veja o código comentado em [`entrada_saida.c`](./entrada_saida.c), que calcula o Índice de Massa Corporal (IMC) e demonstra o uso de tipos, constantes, operadores e formatação de casas decimais (`%.2f`).

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 entrada_saida.c -o entrada_saida
./entrada_saida
```

---

## 6. Exercícios de Fixação

1. **Conversor de Temperatura (`ex01_temperatura.c`):** Leia uma temperatura em graus Celsius (`float`), converta para Fahrenheit usando a fórmula $F = (C \times 1.8) + 32$ e exiba o resultado com 1 casa decimal (`%.1f`).
2. **Decomposição de Segundos (`ex02_tempo.c`):** Leia uma quantidade total de segundos (`int`) e utilize divisão inteira (`/`) e módulo (`%`) para exibir o equivalente em **horas, minutos e segundos**.
3. **Média Ponderada (`ex03_media.c`):** Leia três notas (`double`) de um estudante e calcule a média ponderada considerando pesos **2**, **3** e **5**, exibindo o resultado final formatado com duas casas decimais.

---

[⬅️ Módulo Anterior](../01-introducao/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../03-condicionais/README.md)
