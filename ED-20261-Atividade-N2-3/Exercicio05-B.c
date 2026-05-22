/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 05 — Parte B: Consultas estruturais da ABB                              */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Mesma ABB do Exercício 05-A:
 *
 *               50
 *              /   \
 *            30     70
 *           /  \   /  \
 *          20  40 60   80
 *         / \   \  \
 *        10  25  45  65
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

// Altura: -1 para nulo, 0 para folha, 1+max(esq,dir) para outros
int alturaNo(No *no) {
    if (no == NULL) return -1;
    int e = alturaNo(no->esq);
    int d = alturaNo(no->dir);
    return 1 + (e > d ? e : d);
}

// Profundidade: distância em arestas do nó até a raiz
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado) return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Grau: número de filhos diretos (0, 1 ou 2)
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

// Percurso em-ordem (esq → nó → dir) para mostrar grau de todos os nós
void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esq);
    printf("  No %2d: grau %d\n", raiz->dado, grauNo(raiz));
    emOrdem(raiz->dir);
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

    // a) Altura dos nós: 50, 30, 70, 20, 10
    printf("--- a) Altura dos nos ---\n");
    int nos_h[] = {50, 30, 70, 20, 10};
    for (int i = 0; i < 5; i++) {
        No *no = buscarNo(raiz, nos_h[i]);
        printf("  altura(%2d) = %d\n", nos_h[i], alturaNo(no));
    }

    // b) Profundidade dos nós: 50, 30, 70, 45, 10
    printf("\n--- b) Profundidade dos nos ---\n");
    int nos_p[] = {50, 30, 70, 45, 10};
    for (int i = 0; i < 5; i++) {
        printf("  profundidade(%2d) = %d\n", nos_p[i],
               profundidadeNo(raiz, nos_p[i], 0));
    }

    // c) Grau de cada nó (percurso em-ordem)
    printf("\n--- c) Grau de cada no (em-ordem) ---\n");
    emOrdem(raiz);

    // d) Altura total da árvore
    printf("\n--- d) Altura total da arvore ---\n");
    printf("  Altura total = %d\n", alturaNo(raiz));

    liberarArvore(raiz);
    return 0;
}
