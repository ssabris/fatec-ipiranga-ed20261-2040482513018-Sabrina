/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 06 — Parte B: Relatório completo de nó                                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

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

// Ancestrais do pai até a raiz (recursiva)
int imprimirAncestralRec(No *raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    int achou = 0;
    if (valor < raiz->dado) achou = imprimirAncestralRec(raiz->esq, valor);
    else                    achou = imprimirAncestralRec(raiz->dir, valor);
    if (achou) printf("%d ", raiz->dado);
    return achou;
}

// Descendentes em percurso em-ordem
void percorrerEmOrdem(No *raiz) {
    if (raiz == NULL) return;
    percorrerEmOrdem(raiz->esq);
    printf("%d ", raiz->dado);
    percorrerEmOrdem(raiz->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    No *no = buscarNo(raiz, valor);
    if (no == NULL) return;
    percorrerEmOrdem(no->esq);
    percorrerEmOrdem(no->dir);
}

int contarNos(No *no) {
    if (no == NULL) return 0;
    return 1 + contarNos(no->esq) + contarNos(no->dir);
}

// Relatório completo de um nó
void relatorioNo(No *raiz, int valor) {
    No *no = buscarNo(raiz, valor);

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-3d             |\n", valor);
    printf("+----------------------------------+\n");

    if (no == NULL) {
        printf("| ERRO: valor nao encontrado!      |\n");
        printf("+----------------------------------+\n\n");
        return;
    }

    printf("| Profundidade : %-3d               |\n",
           profundidadeNo(raiz, valor, 0));
    printf("| Altura       : %-3d               |\n",
           alturaNo(no));
    printf("| Grau         : %-3d               |\n",
           grauNo(no));

    printf("| Ancestrais   : ");
    if (!imprimirAncestralRec(raiz, valor))
        printf("(nenhum - e a raiz)");
    printf("\n");

    printf("| Descendentes : ");
    imprimirDescendentes(raiz, valor);
    printf("\n");

    printf("| Qtd Descend. : %-3d               |\n",
           contarNos(no) - 1);
    printf("+----------------------------------+\n\n");
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

    relatorioNo(raiz, 50); // raiz
    relatorioNo(raiz, 30); // nó intermediário
    relatorioNo(raiz, 70); // nó intermediário

    liberarArvore(raiz);
    return 0;
}
