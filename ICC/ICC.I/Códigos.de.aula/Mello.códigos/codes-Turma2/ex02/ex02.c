// .h = header = cabeçalho
#include <stdio.h> // Biblioteca chamada Standard Input-Output

// A função principal. É o ponto de entrada da execução da minha app
int main(int argc, char *argv[]) {
	int posicao; // Stack -> 4 bytes (int)

	// argc ???
	// - argument counter = contador de argumentos
	// 	contar o número de parâmetros passados na linha comando
	printf("Número de argumentos do programa = %d\n", argc);

	// argv ???
	// - argument vector = vetor de argumentos
	//      oferece acesso aos argumentos
	printf("Primeiro argumento = %s\n", argv[0]);
	printf("Segundo argumento = %s\n", argv[1]);

	// laço de repetição
	//  (inicializacao; teste condicional; incremento)
	for (posicao = 0; posicao < argc; posicao++) {
		// posicao++ é igual a posicao = posicao + 1
		printf("Argumento %d = %s\n",posicao,argv[posicao]);
	}

	// retorno oferecido ao sistema operacional
	// código 0 -> sucesso
	return 0;
}
