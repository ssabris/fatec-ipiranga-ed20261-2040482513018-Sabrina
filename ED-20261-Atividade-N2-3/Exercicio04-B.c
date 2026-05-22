/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 04 — Parte B: Potenciação Rápida (Fast Exponentiation)                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * POTENCIAÇÃO RÁPIDA (Exponenciação por quadrados)
 *
 * CASO BASE: exp == 0 → qualquer número elevado a 0 é 1.
 *
 * CASO RECURSIVO:
 *   Se exp for PAR:   base^exp = (base^(exp/2))²
 *   Se exp for ÍMPAR: base^exp = base * base^(exp-1)
 *
 * A cada chamada, o expoente cai pela METADE (se par).
 * Complexidade: O(log exp)  ←  muito melhor que O(n) da abordagem ingênua.
 *
 * Exemplo visual — 2^10:
 *   2^10 = (2^5)²
 *   2^5  = 2 × (2^4)
 *   2^4  = (2^2)²
 *   2^2  = (2^1)²
 *   2^1  = 2 × (2^0)
 *   2^0  = 1              → apenas 6 chamadas!
 */

int chamadasRapida  = 0;
int chamadasIngenua = 0;

long long potenciaRapida(long long base, int exp) {
    chamadasRapida++;

    // CASO BASE
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        // exp PAR: calcula a metade e eleva ao quadrado
        long long metade = potenciaRapida(base, exp / 2);
        return metade * metade;
    } else {
        // exp ÍMPAR: multiplica base pelo resultado de exp-1
        return base * potenciaRapida(base, exp - 1);
    }
}

// Versão ingênua para comparação
long long potenciaIngenua(long long base, int exp) {
    chamadasIngenua++;
    if (exp == 0) return 1; // CASO BASE
    return base * potenciaIngenua(base, exp - 1); // CASO RECURSIVO: b^n = b * b^(n-1)
}

void testar(long long base, int exp) {
    chamadasRapida  = 0;
    chamadasIngenua = 0;
    long long res = potenciaRapida(base, exp);
    potenciaIngenua(base, exp); // só para contar chamadas
    printf("%lld^%2d = %15lld | Rapida: %2d chamadas | Ingenua: %2d chamadas\n",
           base, exp, res, chamadasRapida, chamadasIngenua);
}

int main() {
    printf("%-30s %-20s %-20s\n",
           "Expressao", "Chamadas rapida", "Chamadas ingenua");
    printf("--------------------------------------------------------------\n");

    testar(2, 10);
    testar(3,  7);
    testar(5,  0);
    testar(7, 12);

    /*
     * COMPARAÇÃO:
     * A potenciação ingênua usa tantas chamadas quanto o expoente + 1.
     * A rápida usa apenas O(log exp) — a diferença cresce muito
     * para expoentes grandes (ex: exp=100: ingênua=101, rápida≈10).
     */

    return 0;
}
