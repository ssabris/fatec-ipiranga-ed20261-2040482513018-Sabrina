/******************************************************************************

ed01

1. Escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.

2. Escrever uma função recursiva para calcular uma sequencia de fibonacci

A sequência de Fibonacci consiste em uma série de números, tais que, 
definindo seus dois primeiros números como sendo 0 e 1, 
os números seguintes são obtidos através da soma dos seus dois antecessores.

*******************************************************************************/
#include <stdio.h>

//01 - Recursividade base x elevada a y
int recursiva(int x, int y) {
	if(y==0) {
		return 1;
	} else {
		return x * recursiva(x, y-1);
	}
}

int main() {
	int x = 2;
	int y = 2;

	int resultado = recursiva(x,y);

	printf("base %d elevada a %d resulta em %d", x, y, resultado);

	return 0;
}
