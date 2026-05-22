/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 06 — Parte A: Funções de parentesco (ancestrais e descendentes)         */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Mesma ABB do Exercício 05:
 *
 *               50
 *              /   \
 *            30     70
 *           /  \   /  \
 *          20  40 60   80
 *         / \   \  \
 *        10  25  45  65
 *
 * ANCESTRAIS de X: todos os nós no caminho de X até a raiz.
 *   Ex: ancestrais de 10 → {20, 30, 50}
 *
 * DESCENDENTES de X: todos os nós abaixo de X (exceto ele mesmo).
 *   Ex: descendentes de 30 → {10, 20, 25, 40, 45}
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

/*
 * imprimirAncestral — implementada de forma recursiva
 *
 * Desce na direção do valor. Se o valor for encontrado abaixo,
 * imprime o nó atual no retorno (do pai direto até a raiz).
 * Retorna 1 se encontrou, 0 caso contrário.
 */
void imprimirAncestral(No *raiz, int valor) {
    // Função auxiliar recursiva interna (retorna int para sinalizar achou)
    // Como C não permite funções aninhadas, usamos uma função separada
    // — veja imprimirAncestralRec abaixo
    (void)raiz; (void)valor; // placeholder, ver abaixo
}

int imprimirAncestralRec(No *raiz, int valor) {
    if (raiz == NULL) return 0;           // não encontrou
    if (raiz->dado == valor) return 1;    // encontrou! não imprime o próprio nó

    int achou = 0;
    if (valor < raiz->dado) achou = imprimirAncestralRec(raiz->esq, valor);
    else                    achou = imprimirAncestralRec(raiz->dir, valor);

    // Se o valor estava abaixo, este nó é ancestral → imprime
    if (achou) printf("%d ", raiz->dado);
    return achou;
}

/*
 * imprimirDescendentes — percurso em-ordem pela subárvore do nó
 * (exclui o próprio nó, percorre apenas seus filhos)
 */
void percorrerEmOrdem(No *raiz) {
    if (raiz == NULL) return;
    percorrerEmOrdem(raiz->esq);
    printf("%d ", raiz->dado);
    percorrerEmOrdem(raiz->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    No *no = buscarNo(raiz, valor);
    if (no == NULL) { printf("(valor nao encontrado na arvore)\n"); return; }
    // Percorre apenas os filhos (excluindo o próprio nó)
    percorrerEmOrdem(no->esq);
    percorrerEmOrdem(no->dir);
}

/*
 * contarDescendentes — conta todos os nós da subárvore exceto o próprio nó
 */
int contarNos(No *no) {
    if (no == NULL) return 0;
    return 1 + contarNos(no->esq) + contarNos(no->dir);
}

int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    return contarNos(no) - 1; // total da subárvore menos o próprio nó
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    for (int i = 0; i < 11; i++) raiz = inserir(raiz, valores[i]);

    // Teste das funções de parentesco
    int testes[] = {10, 30, 45, 70};
    for (int i = 0; i < 4; i++) {
        int v = testes[i];
        printf("No %d:\n", v);

        printf("  Ancestrais   : ");
        if (!imprimirAncestralRec(raiz, v)) printf("(nenhum — e a raiz)");
        printf("\n");

        printf("  Descendentes : ");
        imprimirDescendentes(raiz, v);
        printf("\n");

        No *no = buscarNo(raiz, v);
        printf("  Qtd descend. : %d\n\n", contarDescendentes(no));
    }

    liberarArvore(raiz);
    return 0;
}
