/*Dado um tabuleiro de Xadrez com N de largura e M de comprimento, 
imprima o número de casas pretas no tabuleiro. Considere que a casa 
no canto superior esquerdo sempre é preta.*/
#include <stdio.h>
#include <math.h>

int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	if ( a * b % 2 == 0) {
		printf("%d", a * b / 2);
	}else {
		printf("%d", ((a * b) + 1 ) / 2);
	}

	return 0;
}

