#include <stdlib.h>   // Standard library (operações sobre vars, args)
#include <stdio.h>    // Standard Input-Output (printf...)

int main(int argc, char *argv[]) {
	// Stack (cada uma com 4 bytes)
	int entrada1, entrada2, resultado;
	/*
	 	Stack
	 	----------
	0	|        |
	1	|        |
		----------
	2	|        | resultado
	3	|        |
	4	|        |
	5	|        |
		----------
	6	|        | entrada2
	7	|        |
	8	|        |
	9	|        |
		----------
	10	|        | entrada1
	11	|        |
	12	|        |
	13	|        |
	 	----------
	 */

	printf("Digite a entrada 1: ");
	scanf("%d", &entrada1);

	printf("Digite a entrada 2: ");
	scanf("%d", &entrada2);

	resultado = entrada1 + entrada2;
	printf("Resultado = %d\n", resultado);

	return 0;
}
