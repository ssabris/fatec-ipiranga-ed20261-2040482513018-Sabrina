/*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-1                                                             */
/*Objetivo: Explorando Árvore Binária (BST)                                         */
/*                                                                                  */
/*Autora: Sabrina Bernardi                                                          */
/*Data: 05/05/2026                                                                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "minhabib.h"

/* ======================= FUNÇÕES =======================*/

/* ===================== CRIAÇÃO NÓ ===================== */

No* criar_no(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

/* ===================== BUSCA DE NÓ ==================== */

No* buscar(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->valor == valor) return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

/* ===================== FUNÇÕES OBRIGATÓRIAS ==================== */

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;
    /* Nó interno: tem ao menos um filho */
    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("  %d\n", raiz->valor);
    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;
    /* Folha: não tem filhos */
    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("  %d\n", raiz->valor);
    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    if (raiz == NULL) return;
    printf("  %d (Nivel %d)\n", raiz->valor, nivel_atual);
    imprimir_niveis(raiz->esq, nivel_atual + 1);
    imprimir_niveis(raiz->dir, nivel_atual + 1);
}

int calcular_altura(No* no) {
    if (no == NULL) return -1;
    int h_esq = calcular_altura(no->esq);
    int h_dir = calcular_altura(no->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL) return -1;
    if (raiz->valor == valor) return profundidade_atual;
    
    int esq = calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    if (esq != -1) return esq;
    
    return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}

void imprimir_ancestrais(No* raiz, int valor) {
    /* Se chegou no fim ou encontrou o valor, a recursão para */
    if (raiz == NULL || raiz->valor == valor) return;
    
    /* Aproveita a propriedade da BST para guiar a impressão de baixo pra cima */
    if (valor < raiz->valor && buscar(raiz->esq, valor) != NULL) {
        imprimir_ancestrais(raiz->esq, valor);
        printf("  %d\n", raiz->valor);
    } else if (valor > raiz->valor && buscar(raiz->dir, valor) != NULL) {
        imprimir_ancestrais(raiz->dir, valor);
        printf("  %d\n", raiz->valor);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;
    
    /* Imprime o filho (se existir) e passa a recursão, 
       garantindo que não vai imprimir o nó raiz inicial */
    if (no->esq != NULL) {
        printf("  %d\n", no->esq->valor);
        imprimir_descendentes(no->esq);
    }
    if (no->dir != NULL) {
        printf("  %d\n", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

/* ===================== FUNÇÃO PRINCIPAL DE DIAGNÓSTICO ===================== */

void analisar_arvore(No* raiz, int valorBusca) {
    printf("\n================ DIAGNOSTICO DA ARVORE ================\n");
    
    printf("--- Nos Internos ---\n");
    imprimir_nos_internos(raiz);
    
    printf("\n--- Folhas ---\n");
    imprimir_folhas(raiz);
    
    printf("\n--- Todos os Niveis ---\n");
    imprimir_niveis(raiz, 0);
    
    printf("\n--- Metricas Gerais ---\n");
    printf("  Altura da Arvore: %d\n", calcular_altura(raiz));
    
    printf("\n--- Analise do Valor: %d ---\n", valorBusca);
    int prof = calcular_profundidade(raiz, valorBusca, 0);
    if (prof != -1) {
        printf("  Profundidade: %d\n", prof);
    } else {
        printf("  Profundidade: Valor nao encontrado.\n");
    }
    
    printf("  Ancestrais:\n");
    if (buscar(raiz, valorBusca) != NULL && raiz != NULL && raiz->valor != valorBusca) {
        imprimir_ancestrais(raiz, valorBusca);
    } else {
        printf("  (Nenhum ancestral ou valor nao encontrado)\n");
    }
    
    No* noBusca = buscar(raiz, valorBusca);
    printf("  Descendentes:\n");
    if (noBusca) {
        if (noBusca->esq == NULL && noBusca->dir == NULL) {
            printf("  (Nao possui descendentes)\n");
        } else {
            imprimir_descendentes(noBusca);
        }
    } else {
        printf("  (Valor nao encontrado para verificar descendentes)\n");
    }
    
    printf("=======================================================\n");
}
