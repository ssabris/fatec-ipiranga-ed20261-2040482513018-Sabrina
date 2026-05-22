/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 04 — Parte A: Busca Binária Recursiva                                   */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

// Contador de chamadas recursivas
int chamadas = 0;

/*
 * BUSCA BINÁRIA RECURSIVA
 *
 * O vetor deve estar ordenado em ordem crescente.
 * A cada chamada, olhamos o elemento do MEIO:
 *   - É o alvo? Retorna o índice. ← CASO BASE (encontrou)
 *   - Alvo menor? Busca na metade esquerda.
 *   - Alvo maior? Busca na metade direita.
 *   - inicio > fim? Não existe. ← CASO BASE (não encontrou)
 *
 * Complexidade: O(log n) — muito mais rápido que busca linear O(n).
 */
int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    chamadas++; // conta cada chamada recursiva

    // CASO BASE: intervalo vazio → não encontrou
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2; // índice do elemento central

    if (vet[meio] == alvo) {
        return meio;                                    // ENCONTROU!
    } else if (alvo < vet[meio]) {
        return buscaBinaria(vet, inicio, meio - 1, alvo); // vai para a esquerda
    } else {
        return buscaBinaria(vet, meio + 1, fim, alvo);    // vai para a direita
    }
}

int main() {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int tam = 10;

    printf("Vetor: ");
    for (int i = 0; i < tam; i++) printf("%d ", dados[i]);
    printf("\n\n");

    // Busca por valor PRESENTE (23)
    chamadas = 0;
    int idx = buscaBinaria(dados, 0, tam - 1, 23);
    printf("Buscando 23: indice %d | Chamadas recursivas: %d\n", idx, chamadas);

    // Busca por valor AUSENTE (99)
    chamadas = 0;
    idx = buscaBinaria(dados, 0, tam - 1, 99);
    printf("Buscando 99: indice %d (nao encontrado) | Chamadas: %d\n", idx, chamadas);

    // Busca pelo PRIMEIRO elemento (2)
    chamadas = 0;
    idx = buscaBinaria(dados, 0, tam - 1, 2);
    printf("Buscando  2: indice %d | Chamadas recursivas: %d\n", idx, chamadas);

    return 0;
}
