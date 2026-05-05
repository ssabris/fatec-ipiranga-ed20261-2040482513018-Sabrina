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
#include "minhalib.h"

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

/* ===================== BUSCA DE NÓ (Auxiliar) ================= */

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

/* --- Auxiliar para Ancestrais --- */
int _imprimir_ancestrais_aux(No* no, int valor) {
    if (no == NULL) return 0;
    if (no->valor == valor) return 1;
    if (_imprimir_ancestrais_aux(no->esq, valor) ||
        _imprimir_ancestrais_aux(no->dir, valor)) {
        printf("  %d\n", no->valor);
        return 1;
    }
    return 0;
}

void imprimir_ancestrais(No* raiz, int valor) {
    int encontrou = _imprimir_ancestrais_aux(raiz, valor);
    if (!encontrou) {
        printf("  (Nenhum ancestral ou valor nao encontrado)\n");
    }
}

/* --- Auxiliar para Descendentes --- */
void _imprimir_tudo(No* no) {
    if (no == NULL) return;
    printf("  %d\n", no->valor);
    _imprimir_tudo(no->esq);
    _imprimir_tudo(no->dir);
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;
    /* Imprime apenas as subárvores, ignorando o próprio nó alvo */
    _imprimir_tudo(no->esq);
    _imprimir_tudo(no->dir);
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
    imprimir_ancestrais(raiz, valorBusca);
    
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
