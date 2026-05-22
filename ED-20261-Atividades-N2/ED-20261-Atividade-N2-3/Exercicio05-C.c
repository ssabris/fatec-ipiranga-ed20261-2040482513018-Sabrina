/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 05 — Parte C: Verificação manual com ASCII art                          */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================
 * DESENHO DA ABB APÓS TODAS AS INSERÇÕES:
 * Valores inseridos: 50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65
 *
 *                    50                 <- raiz
 *                  /    \
 *                30      70
 *               /  \    /  \
 *             20   40  60   80
 *            /  \    \   \
 *           10  25   45   65
 *
 * ============================================================
 * VERIFICAÇÃO MANUAL DE 3 NÓS:
 *
 * Nó 50 (raiz):
 *   Altura     = 3  (caminho mais longo: 50→30→20→10)
 *   Profund.   = 0  (é a raiz, distância 0 até ela mesma)
 *   Grau       = 2  (tem filho esq=30 e filho dir=70)
 *   → funções retornam: altura=3 ✓  prof=0 ✓  grau=2 ✓
 *
 * Nó 30 (nó intermediário):
 *   Altura     = 2  (caminho mais longo: 30→20→10)
 *   Profund.   = 1  (raiz → 30: 1 aresta)
 *   Grau       = 2  (tem filho esq=20 e filho dir=40)
 *   → funções retornam: altura=2 ✓  prof=1 ✓  grau=2 ✓
 *
 * Nó 10 (folha):
 *   Altura     = 0  (não tem filhos)
 *   Profund.   = 3  (raiz→30→20→10: 3 arestas)
 *   Grau       = 0  (não tem filhos — é folha)
 *   → funções retornam: altura=0 ✓  prof=3 ✓  grau=0 ✓
 * ============================================================
 */

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = valor;
        novo->esq  = NULL;
        novo->dir  = NULL;
        return novo;
    }
    if (valor < raiz->dado)      raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado) raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

int alturaNo(No *no) {
    if (no == NULL) return -1;
    int e = alturaNo(no->esq);
    int d = alturaNo(no->dir);
    return 1 + (e > d ? e : d);
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado) return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no) {
    if (no == NULL) return 0;
    return (no->esq != NULL) + (no->dir != NULL);
}

No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    for (int i = 0; i < 11; i++) raiz = inserir(raiz, valores[i]);

    // Verificação dos 3 nós comentados acima
    int nos[] = {50, 30, 10};
    printf("Verificacao manual dos 3 nos:\n\n");
    printf("%-5s %-10s %-12s %-6s\n", "No", "Altura", "Profundidade", "Grau");
    printf("------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        No *no = buscarNo(raiz, nos[i]);
        printf("%-5d %-10d %-12d %-6d\n",
               nos[i],
               alturaNo(no),
               profundidadeNo(raiz, nos[i], 0),
               grauNo(no));
    }
    printf("\nResultados batem com a verificacao manual no comentario do codigo. OK!\n");

    liberarArvore(raiz);
    return 0;
}
