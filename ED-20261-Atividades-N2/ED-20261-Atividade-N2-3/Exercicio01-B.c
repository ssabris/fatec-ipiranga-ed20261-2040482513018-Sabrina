/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 01 — Parte B: Aritmética de ponteiros em vetor                          */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * Em C, o nome de um array é um ponteiro para seu primeiro elemento.
 * Em vez de v[i], usamos *(v + i) — são equivalentes.
 *
 * Aritmética de ponteiros:
 *   ptr++     --> avança sizeof(int) bytes (vai para o próximo int)
 *   *ptr      --> lê o valor no endereço atual
 */

// Função auxiliar de troca (usada na inversão)
void trocar(int *a, int *b) {
    *a = *a + *b; // *a: escreve no endereço apontado por a
    *b = *a - *b; // *b: recupera o valor original de a
    *a = *a - *b; // *a: recupera o valor original de b
}

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int tamanho = 5;
    int *ptr;

    // a) Imprime cada elemento e seu endereço
    printf("a) Elementos e enderecos:\n");
    ptr = v; // ptr aponta para o primeiro elemento do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("  Endereco: %p  |  Valor: %d\n", (void *)ptr, *ptr);
        // ptr: o próprio endereço atual
        // *ptr: o valor armazenado nesse endereço
        ptr++; // avança para o próximo inteiro na memória
    }

    // b) Soma de todos os elementos
    int soma = 0;
    ptr = v; // volta para o início do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += *ptr; // *ptr: lê o valor atual
        ptr++;        // avança para o próximo
    }
    printf("\nb) Soma de todos os elementos: %d\n", soma);

    // c) Inverte o vetor in-place com dois ponteiros
    // Um começa no início, outro no final; trocamos e caminhamos para o meio
    int *inicio = v;               // aponta para v[0]
    int *fim    = v + tamanho - 1; // aponta para v[4] (último elemento)

    while (inicio < fim) {
        trocar(inicio, fim); // &inicio e &fim já são ponteiros
        inicio++; // *inicio: avança em direção ao centro
        fim--;    // *fim: recua em direção ao centro
    }

    printf("\nc) Vetor invertido:\n  ");
    ptr = v;
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *ptr); // *ptr: lê o valor no endereço atual
        ptr++;               // avança para o próximo
    }
    printf("\n");

    return 0;
}
