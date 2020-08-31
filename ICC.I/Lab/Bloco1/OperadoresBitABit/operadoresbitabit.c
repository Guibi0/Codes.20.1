//Operações de portas lógicas(LD) via terminal
#include <stdio.h>

int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", a & b); //Função AND
	printf("%d\n", a | b); //Função OR
	printf("%d\n", a ^ b); //Função XOR
	printf("%d\n", ~ a); //Função NOT
	printf("%d\n", ~ b); //Função NOT
	printf("%d\n", a >> 2); //Deslocamento de bit's
	printf("%d\n", b << 2); //Deslocamento de bit's

	return 0;
}