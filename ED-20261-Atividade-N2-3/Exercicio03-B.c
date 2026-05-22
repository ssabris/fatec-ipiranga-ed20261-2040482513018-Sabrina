/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 03 — Parte B: Análise de complexidade — contador de movimentos          */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

// Contador global de movimentos
int contador = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 0) return;
    hanoi(n - 1, origem, auxiliar, destino);
    contador++; // conta o movimento do disco maior
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    printf("%-5s %-22s %-15s\n", "n", "Movimentos (contado)", "2^n - 1 (esperado)");
    printf("------------------------------------------------\n");

    for (int n = 1; n <= 6; n++) {
        contador = 0;
        hanoi(n, 'A', 'C', 'B');

        // Calcula 2^n - 1 manualmente (sem pow)
        int esperado = 1;
        for (int i = 0; i < n; i++) esperado *= 2;
        esperado -= 1;

        printf("%-5d %-22d %-15d\n", n, contador, esperado);
    }

    /*
     * ANÁLISE:
     * A cada nível N, o número de movimentos é exatamente 2^N - 1.
     * Isso demonstra que o algoritmo tem complexidade O(2^n) —
     * ou seja, dobra o trabalho a cada disco adicionado.
     * Para 20 discos já seriam mais de 1 milhão de movimentos!
     */

    return 0;
}
