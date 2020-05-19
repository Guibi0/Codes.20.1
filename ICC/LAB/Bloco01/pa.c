//Cálculo do n-ésimo termo de uma PA e de sua soma
#include <stdio.h>

int main() {
	long int a1, r, n; //Representação padrão de PA

	scanf("%ld %ld %ld", &a1, &r, &n); //Entrada das condicionais da PA

	printf("%ld\n", a1 + r * (n - 1)); //Impressão do an
	printf("%ld\n", (2 * a1 * n + r * n * (n - 1)) / 2); //Impressção da soma da PA via fórmula já reduzida

	return 0;
}