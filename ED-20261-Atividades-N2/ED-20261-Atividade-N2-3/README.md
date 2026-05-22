# Estrutura de Dados — Atividade Avaliativa N2-3

**Instituição:** FATEC Ipiranga  
**Curso:** Análise e Desenvolvimento de Sistemas  
**Disciplina:** Estrutura de Dados  
**Professor:** Veríssimo  
**Período:** 2026.1  
**Entrega:** 26/05/2026  

---

## Sobre a atividade

Esta atividade consolida os três pilares da disciplina estudados no semestre:

- **Ponteiros** — operadores de referência e desreferenciação, aritmética de ponteiros, passagem por referência em funções
- **Recursividade** — caso base, caso recursivo, pilha de chamadas
- **Árvore Binária de Busca (ABB)** — altura, profundidade, grau, ancestrais e descendentes

---

## Estrutura de arquivos

```
ED-20261-Atividade-N2-3/
│
├── Exercicio01-A.c      # Troca de valores com ponteiros (& e *)
├── Exercicio01-B.c      # Aritmética de ponteiros em vetor (sem índices)
│
├── Exercicio02-A.c      # Mini-sistema de estatísticas com ponteiros
│
├── Exercicio03-A.c      # Torres de Hanói — implementação recursiva
├── Exercicio03-B.c      # Torres de Hanói — tabela de complexidade
├── Exercicio03-C.c      # Torres de Hanói — rastreamento de profundidade
│
├── Exercicio04-A.c      # Busca binária recursiva
├── Exercicio04-B.c      # Potenciação rápida (fast exponentiation)
│
├── Exercicio05-A.c      # ABB — estrutura e funções de inserção
├── Exercicio05-B.c      # ABB — consultas estruturais (altura, prof., grau)
├── Exercicio05-C.c      # ABB — verificação manual com ASCII art
│
├── Exercicio06-A.c      # ABB — funções de ancestrais e descendentes
├── Exercicio06-B.c      # ABB — relatório completo de nó
├── Exercicio06-C.c      # ABB — teste sistemático (4 nós + valor inexistente)
│
└── README.md
```

---

## Como compilar e executar

Todos os arquivos compilam com o comando padrão exigido pelo enunciado:

```bash
gcc -Wall -Wextra -o prog ExercicioNN-X.c
./prog
```

**Exemplo:**

```bash
gcc -Wall -Wextra -o prog Exercicio03-C.c
./prog
```

---

## Resumo de cada exercício

### Exercício 01 — Ponteiros: referência, desreferenciação e aritmética

**Parte A** — Função `trocar(int *a, int *b)` que troca dois inteiros usando apenas soma e subtração, sem variável temporária. Demonstra os operadores `&` (referência) e `*` (desreferenciação).

**Parte B** — Percorre o vetor `{10, 20, 30, 40, 50}` usando exclusivamente aritmética de ponteiros (`ptr++`, `*ptr`), sem o operador `[]`. Imprime endereços, calcula a soma e inverte o vetor in-place com dois ponteiros.

---

### Exercício 02 — Sistema de estatísticas com ponteiros

Implementa quatro funções que operam sobre um vetor de floats recebido por ponteiro:

| Função | O que faz |
|---|---|
| `calcularMedia` | Retorna a média aritmética |
| `encontrarExtremos` | Escreve o maior e o menor em ponteiros recebidos |
| `normalizar` | Divide cada elemento pelo valor máximo (altera o original) |
| `imprimirVetor` | Imprime o vetor formatado com título |

Toda iteração usa `ptr++` — sem índices `[]`.

---

### Exercício 03 — Torres de Hanói recursivo

**Parte A** — Implementação recursiva da função `hanoi(n, origem, destino, auxiliar)`.

**Parte B** — Contador global de movimentos. Demonstra que o total é sempre `2^n - 1`, confirmando complexidade `O(2^n)`.

| n | Movimentos | 2ⁿ − 1 |
|---|---|---|
| 1 | 1 | 1 |
| 2 | 3 | 3 |
| 3 | 7 | 7 |
| 4 | 15 | 15 |
| 5 | 31 | 31 |
| 6 | 63 | 63 |

**Parte C** — Adiciona o parâmetro `nivel` e indenta a saída com `nivel * 2` espaços, tornando visível a profundidade da pilha de chamadas.

---

### Exercício 04 — Busca binária e potenciação rápida

**Parte A** — Busca binária recursiva `buscaBinaria(vet, inicio, fim, alvo)`. Complexidade `O(log n)`. Testada com um valor presente, um ausente e o primeiro elemento, contando as chamadas recursivas de cada busca.

**Parte B** — Potenciação rápida `potenciaRapida(base, exp)` usando exponenciação por quadrados. Complexidade `O(log exp)` contra `O(n)` da abordagem ingênua.

```
Caso base:   exp == 0  →  retorna 1
Caso par:    base^exp  =  (base^(exp/2))²
Caso ímpar:  base^exp  =  base × base^(exp-1)
```

---

### Exercício 05 — Árvore Binária de Busca: propriedades dos nós

Valores inseridos em sequência: `50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65`

```
               50
              /   \
            30     70
           /  \   /  \
          20  40 60   80
         / \   \  \
        10  25  45  65
```

**Parte A** — Definição da estrutura `No` e implementação de `inserir`, `alturaNo`, `profundidadeNo` e `grauNo`.

**Parte B** — Consultas calculadas pelas funções:

| Nó | Altura | Profundidade | Grau |
|---|---|---|---|
| 50 | 3 | 0 | 2 |
| 30 | 2 | 1 | 2 |
| 70 | 2 | 1 | 2 |
| 20 | 1 | 2 | 2 |
| 10 | 0 | 3 | 0 |
| 45 | 0 | 3 | 0 |

**Parte C** — Verificação manual de 3 nós com ASCII art da árvore nos comentários do código.

---

### Exercício 06 — Ancestrais, descendentes e relatório

Usa a mesma ABB do Exercício 05.

**Parte A** — Funções `imprimirAncestral` (recursiva, do pai até a raiz), `imprimirDescendentes` (percurso em-ordem) e `contarDescendentes`.

**Parte B** — Função `relatorioNo` que imprime:

```
+----------------------------------+
| RELATORIO DO NO: 30              |
+----------------------------------+
| Profundidade : 1                 |
| Altura       : 2                 |
| Grau         : 2                 |
| Ancestrais   : 50                |
| Descendentes : 10 20 25 40 45    |
| Qtd Descend. : 5                 |
+----------------------------------+
```

**Parte C** — Teste sistemático chamando `relatorioNo` para os nós `50` (raiz), `30` (intermediário), `10` (folha), `70` (intermediário) e `99` (inexistente — exibe mensagem de erro).

---

## Conceitos-chave

**Ponteiro** — variável que armazena o endereço de memória de outra variável.  
`&x` retorna o endereço de `x`; `*p` acessa o valor no endereço apontado por `p`.

**Recursividade** — função que chama a si mesma com um argumento menor, até atingir o caso base que encerra a recursão.

**ABB** — árvore onde todo nó à esquerda tem valor menor e todo nó à direita tem valor maior que o nó pai. Isso permite busca em `O(log n)` em árvores balanceadas.
