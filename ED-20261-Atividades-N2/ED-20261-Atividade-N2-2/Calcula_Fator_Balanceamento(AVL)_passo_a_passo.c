*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-2-                                                            */
/*Objetivo: Calculando Fator de Balanceamento(AVL) Passo a passo                    */
/*                                                                                  */
/*Autora: Sabrina Bernardi                                                          */
/*Data: 12/05/2026                                                                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó da Árvore
struct No {
    int valor;
    int altura;
    struct No* esq;
    struct No* dir;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->altura = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// Função para calcular a altura recursivamente (com prints)
int calcularAltura(struct No* n, int profundidade) {
    // Indentação visual para mostrar a profundidade da recursão
    for (int i = 0; i < profundidade; i++) printf("  ");

    // Caso base: nó NULL retorna -1
    if (n == NULL) {
        printf("nó NULL: -1\n");
        return -1;
    }

    printf("nó %d: chama filhos\n", n->valor);

    // Calcula altura dos filhos (recursão)
    int h_esq = calcularAltura(n->esq, profundidade + 1);
    int h_dir = calcularAltura(n->dir, profundidade + 1);

    int resultado = 1 + (h_esq > h_dir ? h_esq : h_dir);

    // Mostra o cálculo feito neste nó
    for (int i = 0; i < profundidade; i++) printf("  ");
    printf("nó %d: 1 + max(%d, %d) = %d\n",
           n->valor, h_esq, h_dir, resultado);

    return resultado;
}

// Função para obter o Fator de Balanceamento (com prints)
int obterFB(struct No* n) {
    if (n == NULL) {
        return 0;
    }

    printf("\n=== Altura subarvore ESQUERDA (para FB do no %d) ===\n", n->valor);
    int h_esq = calcularAltura(n->esq, 1);

    printf("\n=== Altura subarvore DIREITA (para FB do no %d) ===\n", n->valor);
    int h_dir = calcularAltura(n->dir, 1);

    int fb = h_esq - h_dir;

    printf("\n=== Fator de Balanceamento do nó %d ===\n", n->valor);
    printf("  FB = h_esq - h_dir = %d - %d = %d\n", h_esq, h_dir, fb);

    return fb;
}

int main() {
    // Criação dos nós
    struct No* no20 = criarNo(20);
    struct No* no10 = criarNo(10);
    struct No* no5  = criarNo(5);
    struct No* no2  = criarNo(2);

    // Árvore linear à esquerda: 20 -> 10 -> 5 -> 2 -> NULL
    no20->esq = no10;
    no10->esq = no5;
    no5->esq  = no2;

    printf("Arvore desbalanceada: 20 -> 10 -> 5 -> 2\n");
    printf("Estrutura: cada no aponta para o filho esquerdo\n");
    printf("==========================================\n");

    int fb_raiz = obterFB(no20);

    printf("\n==========================================\n");
    printf("Arvore: 20 -> 10 -> 5 -> 2\n");
    printf("Fator de Balanceamento do No 20 (Raiz): %d\n", fb_raiz);

    // Liberação de memória
    free(no2);
    free(no5);
    free(no10);
    free(no20);

    return 0;
}
