/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 05 — Parte A: Estrutura e inserção da Árvore Binária de Busca (ABB)     */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*
 * REGRA DA ABB:
 *   Valor MENOR que o nó pai → vai para a ESQUERDA
 *   Valor MAIOR que o nó pai → vai para a DIREITA
 *
 * Após inserir: 50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65
 *
 *               50
 *              /   \
 *            30     70
 *           /  \   /  \
 *          20  40 60   80
 *         / \   \  \
 *        10  25  45  65
 */

// Definição do nó
typedef struct No {
    int dado;
    struct No *esq; // filho esquerdo (valores menores)
    struct No *dir; // filho direito  (valores maiores)
} No;

// Insere um valor na ABB de forma recursiva
No *inserir(No *raiz, int valor) {
    // Nó vazio → cria o novo nó aqui
    if (raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = valor;
        novo->esq  = NULL;
        novo->dir  = NULL;
        return novo;
    }
    if (valor < raiz->dado)      raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado) raiz->dir = inserir(raiz->dir, valor);
    // valor == raiz->dado: ignoramos duplicatas
    return raiz;
}

// Retorna a altura do nó (nulo = -1, folha = 0)
int alturaNo(No *no) {
    if (no == NULL) return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    return 1 + ((altEsq > altDir) ? altEsq : altDir);
}

// Retorna a profundidade de um valor a partir da raiz
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;        // não encontrou
    if (raiz->dado == valor) return prof; // encontrou!
    if (valor < raiz->dado) return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Retorna o grau do nó (número de filhos diretos: 0, 1 ou 2)
int grauNo(No *no) {
    if (no == NULL) return 0;
    return (no->esq != NULL) + (no->dir != NULL);
}

// Auxiliar: busca e retorna o ponteiro para o nó com 'valor'
No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

// Libera toda a memória alocada na árvore
void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = 11;
    for (int i = 0; i < n; i++) raiz = inserir(raiz, valores[i]);

    printf("Arvore construida com sucesso!\n");
    printf("Raiz: %d\n", raiz->dado);
    printf("Filho esquerdo da raiz: %d\n", raiz->esq->dado);
    printf("Filho direito da raiz : %d\n", raiz->dir->dado);

    liberarArvore(raiz);
    return 0;
}
