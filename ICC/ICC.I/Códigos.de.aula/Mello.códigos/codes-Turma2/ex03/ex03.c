#include <stdio.h>

/*	Stack (Intel)
 	------------
0	|          |
	------------
1	|          | res
2	|          |
3	|          |
4	|          |
	------------
5	|          | num2
6	|          |
7	|          |
8	|          |
	------------
9	|          | num1
10	|          |
11	|          |
12	|          |
	------------
 */

int main(int argc, char *argv[]) {
	int num1, num2, res; // Stack (4 bytes)

	printf("Digite o primeiro número: ");
	scanf("%d", &num1);

	printf("Digite o segundo número: ");
	scanf("%d", &num2);

	res = num1 + num2;
	printf("Resultado = %d\n", res);

	return 0;
}
