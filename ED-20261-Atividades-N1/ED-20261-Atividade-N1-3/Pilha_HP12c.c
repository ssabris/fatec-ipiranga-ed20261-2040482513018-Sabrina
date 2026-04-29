/*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */        
/*ADS - Estrutura de Dados                                                          */
/*Id da Atividade: N1-3                                                             */
/*Objetivo: Simulador de Calculadora HP12c (Pilha RPN)                              */
/*                                                                                  */
/*Autor: Sabrina Bernardi                                                           */
/*Data:29/03/2026                                                                   */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1. A Estrutura da Pilha (Memórias X, Y, Z e T)
typedef struct {
    float t;
    float z;
    float y;
    float x; // O visor da calculadora [cite: 14]
} HP12c;

// Função para iniciar a calculadora com zeros
void inicializar(HP12c *calc) {
    calc->t = 0.0;
    calc->z = 0.0;
    calc->y = 0.0;
    calc->x = 0.0;
}

// 2. Exibição Detalhada 
void mostrar_pilha(HP12c *calc) {
    printf("--- Memoria Atual ---\n");
    printf("T: %.2f\n", calc->t);
    printf("Z: %.2f\n", calc->z);
    printf("Y: %.2f\n", calc->y);
    printf("X: %.2f (Visor)\n", calc->x);
    printf("---------------------\n\n");
}

// 3. Função de Empilhar (Push) - Quando um número entra
void empilhar(HP12c *calc, float valor) {
    // Tudo "sobe" uma posição
    calc->t = calc->z;
    calc->z = calc->y;
    calc->y = calc->x;
    calc->x = valor; // Novo número no visor
}

// 4. Função de Processamento das Operações [cite: 22]
void calcular(HP12c *calc, char operador) {
    float resultado = 0.0;

    // Executa a operação usando Y e X
    switch(operador) {
        case '+': resultado = calc->y + calc->x; break;
        case '-': resultado = calc->y - calc->x; break;
        case '*': resultado = calc->y * calc->x; break;
        case '/': 
            if (calc->x != 0) {
                resultado = calc->y / calc->x; 
            } else {
                printf("Erro: Divisao por zero!\n");
                return;
            }
            break;
        default:
            printf("Operador invalido!\n");
            return;
    }

    // O resultado vai para o X, e a pilha "desce"
    calc->x = resultado;
    calc->y = calc->z;
    calc->z = calc->t;
    // Na HP12c real, o valor de T se repete quando a pilha desce
}

// 5. Bloco Principal (Main)
int main() {
    HP12c calculadora;
    inicializar(&calculadora);

    // Expressão de teste fornecida na atividade [cite: 26]
    char expressao[] = "5 1 2 + 4 * + 3 -";
    printf("Expressao RPN: %s\n\n", expressao);

    // A função strtok divide a string de entrada usando os espaços
    char *token = strtok(expressao, " ");

    while (token != NULL) {
        printf("Lendo entrada: '%s'\n", token);

        // Validação simples: se o token começar com um dígito, é um número [cite: 21]
        if (isdigit(token[0])) {
            float numero = atof(token); // Converte a string para float
            empilhar(&calculadora, numero);
        } else {
            // Se não é número, passa para a função calcular como operador
            calcular(&calculadora, token[0]);
        }

        // Exibe o estado da pilha após cada entrada ou operação 
        mostrar_pilha(&calculadora);

        // Pega o próximo pedaço da expressão
        token = strtok(NULL, " ");
    }

    // Mensagem final formatada conforme exigência [cite: 29, 30]
    printf("O resultado da expressão algébrica é: %.0f\n", calculadora.x);

    return 0;
}
