/*----------------------------------------------------------------------------------*/
/*Autora: Sabrina Bernardi                                                          */
/*RA: 2040482513018                                                                 */
/*                                                                                  */
/*FATEC-Ipiranga                                                                    */
/*ADS - Estrutura de Dados                                                          */
/*Prof - Veríssimo                                                                  */
/*                                                                                  */
/*Id da Atividade: N2-3                                                             */
/*Exercício 02 — Parte A: Mini-sistema de estatísticas com ponteiros                */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

/*
 * Passar um array para uma função em C significa passar um PONTEIRO
 * para o primeiro elemento. Qualquer mudança feita dentro da função
 * afeta o array original — não uma cópia!
 *
 * Toda iteração usa ptr++ (incremento de ponteiro) — sem índices [ ].
 */

// Calcula e RETORNA a média aritmética
float calcularMedia(float *vet, int n) {
    float soma = 0;
    float *ptr = vet; // ptr começa apontando para o 1º elemento
    for (int i = 0; i < n; i++) {
        soma += *ptr; // *ptr: lê o valor atual
        ptr++;        // avança para o próximo elemento
    }
    return soma / n;
}

// Encontra o maior e o menor valor
// maior e menor são ponteiros: a função ESCREVE diretamente neles
void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    *maior = *vet; // *maior: escreve no endereço apontado por maior
    *menor = *vet; // *menor: escreve no endereço apontado por menor

    float *ptr = vet + 1; // começa do 2º elemento
    for (int i = 1; i < n; i++) {
        if (*ptr > *maior) *maior = *ptr; // *maior: atualiza o valor no endereço
        if (*ptr < *menor) *menor = *ptr; // *menor: atualiza o valor no endereço
        ptr++;
    }
}

// Normaliza o vetor: divide cada elemento pelo valor máximo
// Altera o vetor ORIGINAL porque recebemos o ponteiro para ele
void normalizar(float *vet, int n) {
    // Acha o maior valor
    float maior = *vet;
    float *ptr = vet + 1;
    for (int i = 1; i < n; i++) {
        if (*ptr > maior) maior = *ptr;
        ptr++;
    }
    // Divide cada elemento pelo maior
    ptr = vet; // volta ao início
    for (int i = 0; i < n; i++) {
        *ptr = *ptr / maior; // *ptr: lê E escreve no endereço apontado
        ptr++;
    }
}

// Imprime o vetor formatado com um título
void imprimirVetor(float *vet, int n, const char *titulo) {
    printf("%s: [ ", titulo);
    float *ptr = vet;
    for (int i = 0; i < n; i++) {
        printf("%.4f ", *ptr); // *ptr: lê o valor atual
        ptr++;
    }
    printf("]\n");
}

int main() {
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int n = 6;

    imprimirVetor(notas, n, "Notas originais  ");

    float media = calcularMedia(notas, n);
    printf("Media : %.2f\n", media);

    float maior, menor;
    // &maior e &menor: passamos os endereços para a função escrever neles
    encontrarExtremos(notas, n, &maior, &menor);
    printf("Maior : %.2f\n", maior);
    printf("Menor : %.2f\n", menor);

    normalizar(notas, n);
    imprimirVetor(notas, n, "Notas normalizadas");

    /*
     * POR QUE normalizar alterou o vetor original?
     *
     * Ao passar 'notas', passamos o ENDEREÇO do primeiro elemento.
     * Dentro de normalizar, a linha  *ptr = *ptr / maior  escreve
     * diretamente naquele endereço de memória — não existe cópia.
     * Essa é a diferença entre passagem por valor e por ponteiro:
     * por ponteiro, a função acessa e modifica a variável original.
     */

    return 0;
}
