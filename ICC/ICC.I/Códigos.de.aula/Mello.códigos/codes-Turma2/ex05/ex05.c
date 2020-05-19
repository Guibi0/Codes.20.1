#include <stdio.h>
#include <math.h>

/*
	STACK
	=====
   	
	vector (10 bytes)		
	r (4 bytes)
	q (4 bytes)
	i (4 bytes)
	temp (4 bytes)
	number (4 bytes)

	Stack
	---------
	|   49  | vector
	|   49  |
	|   49  |
	|   48  |
	|   49  |
	|   49  |
	|   0   | '\0' = 0
	|   ?   |
	|   ?   |
	|   ?   |
	---------
	|       | r
	|       |
	|       |
	|       |
	---------
	|       | q
	|       |
	|       |
	|       |
	---------
	|       | i
	|       |
	|       |
	|       |
	---------
	|       | temp
	|       |
	|       |
	|       |
	---------
	|       | number
	|       |
	|       |
	|       |
	---------
  */
int main(int argc, char *argv[]) {
	int number, temp; // Stack -> int (4 bytes)
	int i, q, r; // Stack -> int (4 bytes)
	char vector[10]; // Stack -> 1 * 10 bytes

	printf("Digite um decimal: ");
	// %d -> verificar se um int foi digitado
	// manipular até 4 bytes
	scanf("%d", &number);  

	// Conversão da base decimal para a binária
	// Laço de repetição
	temp = number;
	//for (i = 0; i < 20; i++) {
	/*for (;;) { // for ever
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
		if (q == 0) break;
	}*/
	// Teste de mesa
	// =============
	// i = 0, 2^i = 1 < number	---> 1
	// i = 1, 2^i = 2 < number	---> 1
	// i = 2, 2^i = 4 < number	---> 1
	// i = 3, 2^i = 8 < number	---> 0
	// i = 4, 2^i = 16 < number	---> 1
	// i = 5, 2^i = 32 < number	---> 1
	// i = 6, 2^i = 64 < number
	/*for (i = 0; pow(2,i) < number; i++) {
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
	}*/
	
	for (i = 0, q = -1; q != 0; i++) {
		q = temp / 2;
		r = temp % 2;
		//vector[i] = r == 0 ? '0' : '1'; // tabela ASCII
		vector[i] = r == 0 ? 48 : 49; // tabela ASCII
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
	}
	vector[i] = '\0'; //vector[i] = 0;

	printf("Resultado binário: %s\n", vector);

	/*
	q = -1;
	while (q != 0) {
		q = temp / 2;
		r = temp % 2;
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
	}*/

	/*
	do {
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
	} while (q != 0);*/

	/*
	for (q = -1; q = temp / 2; ) {
		r = temp % 2;
		printf("q: %d\tr: %d\n", q, r);
		temp = q;
	}*/

	printf("O número é %d\n", number);

	return 0;
}
