# Módulo 06: Funções, Escopo e Passagem de Parâmetros

Este módulo apresenta a modularização de programas em C por meio de funções, explicando a declaração de protótipos, o ciclo de vida das variáveis na pilha de execução (*call stack*), a diferença entre passagem por valor e por referência, e o conceito de recursividade.

---

## 1. Anatomia e Protótipo de uma Função

Dividir um problema complexo em funções pequenas e reutilizáveis facilita a leitura, os testes e a manutenção do código. Em C, uma função segue a estrutura:

```c
tipo_retorno nome_funcao(tipo1 param1, tipo2 param2) {
    // Corpo da função
    return valor;
}
```

### Protótipos de Funções
O compilador lê o arquivo de cima para baixo. Se você escrever uma função auxiliar abaixo da `main()`, precisa declarar seu **protótipo** (assinatura terminada em `;`) antes da `main()`:

```c
int somar(int a, int b); // Protótipo

int main(void) {
    int resultado = somar(10, 5);
    return 0;
}

int somar(int a, int b) { // Implementação
    return a + b;
}
```

---

## 2. Escopo e Tempo de Vida das Variáveis

* **Variáveis Locais:** Declaradas dentro de uma função ou bloco `{ }`. Existem apenas enquanto aquela função está em execução na pilha (*stack*) e são destruídas ao retornar.
* **Variáveis Globais:** Declaradas fora de todas as funções. Permanem na memória durante toda a execução do programa. Devem ser evitadas sempre que possível para não gerar acoplamento oculto entre funções.
* **Variáveis `static` Locais:** Mantêm seu valor preservado entre múltiplas chamadas da mesma função, mas continuam visíveis apenas dentro dela.

---

## 3. Passagem por Valor vs. Passagem por Referência

| Mecanismo | Como funciona | Altera a variável original? |
| :--- | :--- | :--- |
| **Passagem por Valor** | A função recebe uma **cópia** do argumento. | **Não.** Alterações afetam apenas a cópia local. |
| **Passagem por Referência** | A função recebe o **endereço de memória** (`&var`) via ponteiro (`*ptr`). | **Sim.** Permite modificar a variável original ou retornar múltiplos valores. |

> **Nota sobre Vetores:** Quando você passa um vetor para uma função (`void imprimir(int v[], int n)`), a linguagem C passa automaticamente o endereço do primeiro elemento — por isso funções conseguem alterar o conteúdo de vetores diretamente.

---

## 4. Recursividade

Uma função é recursiva quando chama a si mesma para resolver uma instância menor do mesmo problema. Toda função recursiva exige:
1. **Caso Base:** Condição de parada que encerra as chamadas.
2. **Passo Recursivo:** Chamada que aproxima o problema do caso base.

```c
int fatorial(int n) {
    if (n <= 1) return 1;          // Caso base
    return n * fatorial(n - 1);     // Passo recursivo
}
```

---

## 5. Exemplo Prático Completo

Veja o código comentado em [`funcoes.c`](./funcoes.c), que demonstra:
1. Uso de protótipos organizados antes da `main()`.
2. Passagem por valor vs. passagem por referência (troca de valores entre duas variáveis).
3. Passagem de vetor para cálculo de média.
4. Cálculo recursivo de fatorial.

Para compilar e executar:

```bash
gcc -Wall -Wextra -std=c11 funcoes.c -o funcoes
./funcoes
```

---

## 6. Exercícios de Fixação

1. **Verificador de Número Perfeito (`ex01_perfeito.c`):** Crie uma função `int eh_perfeito(int n)` que retorne `1` se a soma dos divisores próprios de `n` for igual a `n` (ex: `6 = 1 + 2 + 3`, `28 = 1 + 2 + 4 + 7 + 14`) ou `0` caso contrário. Liste todos os números perfeitos entre `1` e `1000`.
2. **Estatísticas por Referência (`ex02_min_max.c`):** Escreva uma função `void encontrar_extremos(const int v[], int tamanho, int *min, int *max)` que percorra um vetor de inteiros e grave o menor e o maior valor diretamente nas variáveis apontadas por `min` e `max`.
3. **Potência Recursiva (`ex03_potencia.c`):** Implemente uma função recursiva `long long potencia(int base, int expoente)` para calcular $base^{expoente}$ (com $expoente \ge 0$) sem utilizar a biblioteca `<math.h>`.

---

[⬅️ Módulo Anterior](../05-vetores-strings/README.md) | [🏠 Índice Principal](../README.md) | [Próximo Módulo ➡️](../07-ponteiros-memoria/README.md)
