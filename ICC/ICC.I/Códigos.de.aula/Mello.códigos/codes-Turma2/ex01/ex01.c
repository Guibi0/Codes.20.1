#include <stdio.h> // Standard Input-Output

// define o início do meu programa
int main(int argc, char *argv[]) {
	// 1 byte --> 0 0 1 0 1 1 0 0 (8 bits)
	char meu_caracter; // Stack -> 1 byte
	int meu_inteiro;   // Stack -> 4 bytes

	int *ponteiro;     // Stack -> 8 bytes (guarda um endereço)


	printf("Executando...\n"); // escrever na tela
	while (1); // travar a execução

	return 0; // define o retorno do meu programa
}
