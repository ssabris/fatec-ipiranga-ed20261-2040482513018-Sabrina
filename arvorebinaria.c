/*
 * Atividade N2-1: Explorando Árvore Binária
 * Fatec Ipiranga - Estrutura de Dados
 * Prof. Veríssimo
 */

#include <stdio.h>
#include <stdlib.h>

/* ===================== ESTRUTURA ===================== */

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

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

/* ===================== RAIZ ===================== */

void imprimir_raiz(No *raiz) {
    printf("========================================\n");
    printf("RAIZ:\n");
    if (raiz != NULL)
        printf("  %d\n", raiz->valor);
    else
        printf("  (arvore vazia)\n");
    printf("\n");
}

/* ===================== NÓS INTERNOS E FOLHAS ===================== */

void imprimir_nos_internos(No *no) {
    if (no == NULL) return;
    /* Nó interno: tem ao menos um filho */
    if (no->esq != NULL || no->dir != NULL)
        printf("  %d\n", no->valor);
    imprimir_nos_internos(no->esq);
    imprimir_nos_internos(no->dir);
}

void imprimir_folhas(No *no) {
    if (no == NULL) return;
    /* Folha: não tem filhos */
    if (no->esq == NULL && no->dir == NULL)
        printf("  %d\n", no->valor);
    imprimir_folhas(no->esq);
    imprimir_folhas(no->dir);
}

/* ===================== NÍVEIS ===================== */

/* Imprime todos os nós que estão no nível alvo */
void imprimir_nivel(No *no, int nivel_atual, int nivel_alvo) {
    if (no == NULL) return;
    if (nivel_atual == nivel_alvo) {
        printf("  %d\n", no->valor);
        return;
    }
    imprimir_nivel(no->esq, nivel_atual + 1, nivel_alvo);
    imprimir_nivel(no->dir, nivel_atual + 1, nivel_alvo);
}

/* Retorna a altura da árvore (número de níveis) */
int altura_arvore(No *no) {
    if (no == NULL) return 0;
    int h_esq = altura_arvore(no->esq);
    int h_dir = altura_arvore(no->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

void imprimir_todos_niveis(No *raiz) {
    printf("========================================\n");
    printf("NIVEIS:\n");
    int total = altura_arvore(raiz);
    for (int i = 1; i <= 7; i++) {
        printf("  Nivel %d:", i);
        if (i > total) {
            printf(" (vazio)\n");
        } else {
            printf("\n");
            imprimir_nivel(raiz, 1, i);
        }
    }
    printf("\n");
}

/* ===================== GRAU ===================== */

int grau_no(No *no) {
    if (no == NULL) return -1;
    int g = 0;
    if (no->esq != NULL) g++;
    if (no->dir != NULL) g++;
    return g;
}

void imprimir_grau_todos(No *no) {
    if (no == NULL) return;
    printf("  %d -> grau %d\n", no->valor, grau_no(no));
    imprimir_grau_todos(no->esq);
    imprimir_grau_todos(no->dir);
}

/* ===================== BUSCA DE NÓ ===================== */

No* buscar(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->valor == valor) return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

/* ===================== ANCESTRAIS ===================== */

/* Retorna 1 se encontrou o valor na subárvore e imprime o caminho (ancestrais) */
int imprimir_ancestrais(No *no, int valor) {
    if (no == NULL) return 0;
    if (no->valor == valor) return 1;
    if (imprimir_ancestrais(no->esq, valor) ||
        imprimir_ancestrais(no->dir, valor)) {
        printf("  %d\n", no->valor);
        return 1;
    }
    return 0;
}

/* ===================== DESCENDENTES ===================== */

void imprimir_descendentes(No *no, int primeiro) {
    if (no == NULL) return;
    if (!primeiro)  //não imprime o próprio nó, só seus filhos em diante 
        printf("  %d\n", no->valor);
    imprimir_descendentes(no->esq, 0);
    imprimir_descendentes(no->dir, 0);
}

/* ===================== ALTURA DO NÓ ===================== */

int altura_no(No *no) {
    if (no == NULL) return -1;
    int h_esq = altura_no(no->esq);
    int h_dir = altura_no(no->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

/* ===================== PROFUNDIDADE DO NÓ ===================== */

int profundidade_no(No *raiz, int valor, int prof_atual) {
    if (raiz == NULL) return -1;
    if (raiz->valor == valor) return prof_atual;
    int esq = profundidade_no(raiz->esq, valor, prof_atual + 1);
    if (esq != -1) return esq;
    return profundidade_no(raiz->dir, valor, prof_atual + 1);
}

/* ===================== SUB-ÁRVORE ===================== */

void imprimir_subarvore(No *no, int prefixo[], int nivel, int eh_direito) {
    if (no == NULL) return;

    //Imprime a linha de prefixo
    for (int i = 0; i < nivel - 1; i++) {
        if (prefixo[i])
            printf("│   ");
        else
            printf("    ");
    }

    if (nivel > 0) {
        if (eh_direito)
            printf("└── ");
        else
            printf("├── ");
    }

    printf("%d\n", no->valor);

    // Se tem dois filhos, o esquerdo tem irmão (├──), o direito não (└──) 
    //Se tem um filho só, ele é o último (└──)
    int tem_dois = (no->esq != NULL && no->dir != NULL);

    if (no->esq != NULL) {
        //prefixo[nivel]=1 quando haverá irmão direito depois (para manter │)
        prefixo[nivel] = tem_dois ? 1 : 0;
        imprimir_subarvore(no->esq, prefixo, nivel + 1, tem_dois ? 0 : 1);
    }
    if (no->dir != NULL) {
        prefixo[nivel] = 0;
        imprimir_subarvore(no->dir, prefixo, nivel + 1, 1);
    }
}

/* ===================== MAIN ===================== */

int main() {
    No *raiz = NULL;

    //Inserção dos valores conforme o exemplo da atividade
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 65, 5, 2};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    /* --- RAIZ --- */
    imprimir_raiz(raiz);

    /* --- NÓS INTERNOS --- */
    printf("========================================\n");
    printf("NOS INTERNOS:\n");
    imprimir_nos_internos(raiz);
    printf("\n");

    /* --- FOLHAS --- */
    printf("========================================\n");
    printf("NOS EXTERNOS (FOLHAS):\n");
    imprimir_folhas(raiz);
    printf("\n");

    /* --- NÍVEIS --- */
    imprimir_todos_niveis(raiz);

    /* --- GRAU --- */
    printf("========================================\n");
    printf("GRAU DOS NOS:\n");
    imprimir_grau_todos(raiz);
    printf("\n");

    /* --- ANCESTRAIS E DESCENDENTES (nó 60) --- */
    int no_alvo = 60;
    printf("========================================\n");
    printf("ANCESTRAIS DO NO %d:\n", no_alvo);
    imprimir_ancestrais(raiz, no_alvo);
    printf("\n");

    printf("========================================\n");
    printf("DESCENDENTES DO NO %d:\n", no_alvo);
    No *alvo = buscar(raiz, no_alvo);
    if (alvo != NULL)
        imprimir_descendentes(alvo, 1);
    else
        printf("  No nao encontrado.\n");
    printf("\n");

    /* --- ALTURA DO NÓ --- */
    printf("========================================\n");
    printf("ALTURA DO NO %d:\n", no_alvo);
    if (alvo != NULL)
        printf("  %d\n", altura_no(alvo));
    printf("\n");

    /* --- PROFUNDIDADE DO NÓ --- */
    printf("========================================\n");
    printf("PROFUNDIDADE DO NO %d:\n", no_alvo);
    printf("  %d\n", profundidade_no(raiz, no_alvo, 0));
    printf("\n");

    /* --- SUB-ÁRVORE (raiz 30) --- */
    int no_sub = 30;
    printf("========================================\n");
    printf("SUBARVORE COM RAIZ %d:\n", no_sub);
    No *sub = buscar(raiz, no_sub);
    if (sub != NULL) {
        int prefixo[20] = {0};
        imprimir_subarvore(sub, prefixo, 0, 1);
    } else {
        printf("  No nao encontrado.\n");
    }
    printf("\n");

    return 0;
}