/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 03 — Parte A: Torres de Hanói recursivo                                 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * PROBLEMA DAS TORRES DE HANÓI:
 * Mover N discos da haste ORIGEM para a haste DESTINO,
 * usando AUXILIAR como apoio. Nunca colocar disco maior sobre menor.
 *
 * SOLUÇÃO RECURSIVA:
 *   1. Mover N-1 discos de ORIGEM para AUXILIAR (usando DESTINO)
 *   2. Mover o disco maior de ORIGEM para DESTINO
 *   3. Mover N-1 discos de AUXILIAR para DESTINO (usando ORIGEM)
 *
 * CASO BASE: n == 0 → não há disco para mover, retorna.
 */
void hanoi(int n, char origem, char destino, char auxiliar) {
    // Caso base: sem discos, nada a fazer
    if (n == 0) return;

    // Passo 1: move N-1 discos de origem para auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Passo 2: move o disco maior (disco N) para destino
    printf("Mover disco %d: %c --> %c\n", n, origem, destino);

    // Passo 3: move N-1 discos de auxiliar para destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    printf("--- n = 1 ---\n");
    hanoi(1, 'A', 'C', 'B');

    printf("\n--- n = 3 ---\n");
    hanoi(3, 'A', 'C', 'B');

    printf("\n--- n = 4 ---\n");
    hanoi(4, 'A', 'C', 'B');

    return 0;
}
