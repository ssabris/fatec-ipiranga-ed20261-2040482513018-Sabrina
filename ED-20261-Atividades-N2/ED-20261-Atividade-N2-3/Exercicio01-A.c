/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 01 — Parte A: Troca de valores usando ponteiros (&, *)                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * Ponteiro é uma variável que guarda o ENDEREÇO de outra variável.
 *
 *   int x = 5;
 *   int *p = &x;   --> &x retorna o endereço de x; p guarda esse endereço
 *   *p = 10;       --> *p acessa o valor NO endereço apontado, ou seja, muda x
 *
 * Troca sem variável temporária, usando soma e subtração:
 *   *a = *a + *b   --> *a passa a ter a soma dos dois
 *   *b = *a - *b   --> *b recupera o valor original de *a
 *   *a = *a - *b   --> *a recupera o valor original de *b
 */
void trocar(int *a, int *b) {
    *a = *a + *b; // *a: lê e escreve no endereço apontado por a
    *b = *a - *b; // *b: recupera o valor original de a
    *a = *a - *b; // *a: recupera o valor original de b
}

int main() {
    int x = 15;
    int y = 42;

    // &x --> operador de referência: retorna o endereço de x na memória
    printf("Antes da troca:\n");
    printf("  x = %d  |  endereco de x = %p\n", x, (void *)&x);
    printf("  y = %d  |  endereco de y = %p\n", y, (void *)&y);

    trocar(&x, &y); // passamos os ENDEREÇOS para que a função modifique os originais

    printf("\nDepois da troca:\n");
    printf("  x = %d\n", x);
    printf("  y = %d\n", y);

    return 0;
}
