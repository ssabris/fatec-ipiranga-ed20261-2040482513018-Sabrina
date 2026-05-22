/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 03 — Parte C: Profundidade da recursão com indentação                   */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * Adicionamos o parâmetro 'nivel' para rastrear a profundidade.
 * A saída é indentada com  nivel * 2  espaços, mostrando
 * visualmente como a pilha de chamadas se aprofunda.
 */
void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    if (n == 0) return;

    // Passo 1: desce mais um nível à esquerda
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    // Indenta de acordo com a profundidade atual
    for (int i = 0; i < nivel * 2; i++) printf(" ");
    printf("[nivel %d] Mover disco %d: %c --> %c\n", nivel, n, origem, destino);

    // Passo 3: desce mais um nível à direita
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {
    printf("--- n = 1 ---\n");
    hanoi(1, 'A', 'C', 'B', 0);

    printf("\n--- n = 3 ---\n");
    hanoi(3, 'A', 'C', 'B', 0);

    printf("\n--- n = 4 ---\n");
    hanoi(4, 'A', 'C', 'B', 0);

    return 0;
}
