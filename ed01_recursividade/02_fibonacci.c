/******************************************************************************

ed01

1. Escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.

2. Escrever uma função recursiva para calcular uma sequencia de fibonacci

A sequência de Fibonacci consiste em uma série de números, tais que, 
definindo seus dois primeiros números como sendo 0 e 1, 
os números seguintes são obtidos através da soma dos seus dois antecessores.

*******************************************************************************/

// 02 - Recursividade Fibonacci

#include <stdio.h>

int fibonacci(int n){
    //caso base: se n for <=1 retorna n
    if(n<=1){
        return n;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;

    printf("Termos da Sequencia de Fibonacci:\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Fibonacci(%d) = %d\n", n, fibonacci(i));
    }
    
    return 0;
}