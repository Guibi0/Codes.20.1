/*Dada a equação: x^2 - y^2 = p, onde p é um número primo e x, y pertencentes a N. 
Imprima todas os pares (x, y) que a satisfaça.*/
#include <stdio.h>

int main() {

	double x, y, p;

	scanf("%lf", &p);

	y = (p - 1)/2;
	x = y + 1;

	if ((int)y == y) {
		printf("1\n%d %d\n", (int)x, (int)y);
	}else {
		printf("0\n");
	}
	
	return 0;
}