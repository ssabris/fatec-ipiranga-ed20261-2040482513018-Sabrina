/*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-2                                                             */
/*Objetivo: Calculando Fator de Balanceamento(AVL)                                  */
/*                                                                                  */
/*Autora: Sabrina Bernardi                                                          */
/*Data: 05/05/2026                                                                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó da Árvore
struct No {
    int valor;
    int altura; // Pode ser utilizado para armazenar a altura calculada
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

// Requisito: Função para calcular a altura recursivamente
int calcularAltura(struct No* n) {
    // Caso base: se o nó for NULL, retorna -1
    if (n == NULL) {
        return -1;
    }

    // Calcula a altura dos filhos
    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);

    // Retorna 1 + o maior valor entre a altura da esquerda e da direita
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

// Requisito: Função para obter o Fator de Balanceamento (FB)
int obterFB(struct No* n) {
    // Se o nó for NULL, o fator de balanceamento é 0
    if (n == NULL) {
        return 0;
    }

    // Calcula a altura da subárvore esquerda e da subárvore direita
    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);

    // FB = Altura da Esquerda - Altura da Direita
    return h_esq - h_dir;
}

int main() {
    // 4. Criação dos nós da árvore com os valores solicitados
    struct No* no20 = criarNo(20);
    struct No* no10 = criarNo(10);
    struct No* no5 = criarNo(5);
    struct No* no2 = criarNo(2);

    // Conectando os nós para formar a estrutura linear à esquerda (20 -> 10 -> 5 -> 2 -> NULL)
    no20->esq = no10;
    no10->esq = no5;
    no5->esq = no2;

    // Calculando o Fator de Balanceamento da Raiz (Nó 20)
    int fb_raiz = obterFB(no20);

    // Exibição dos resultados
    printf("Árvore de busca desbalanceada: 20 -> 10 -> 5 -> 2\n");
    printf("Fator de Balanceamento do Nó 20 (Raiz): %d\n", fb_raiz);

    // Liberação de memória (boa prática em C)
    free(no2);
    free(no5);
    free(no10);
    free(no20);

    return 0;
}
