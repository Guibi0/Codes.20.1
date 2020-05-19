#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 2, b = 5, c = 3;

	printf("Resultado = %f\n", (a + b) / 3.0);
	// int + int ---> int
	// int / float ---> float
	printf("Resultado = %f\n", (a + b) / (c * 1.0));

	// Tipos de dado primitivos
	// - tipo oferecido pela linguagem de programação
	printf("Inteiros\n");
	printf("Tamanho do tipo int em bytes é %d\n", sizeof(int));
	printf("Tamanho do tipo short em bytes é %d\n", sizeof(short));
	printf("Tamanho do tipo long em bytes é %d\n", sizeof(long));
	printf("Caracter\n");
	printf("Tamanho do tipo char em bytes é %d\n", sizeof(char));
	printf("Números reais\n");
	printf("Tamanho do tipo double em bytes é %d\n",sizeof(double));
	printf("Tamanho do tipo float em bytes é %d\n",sizeof(float));

	return 0;
}
