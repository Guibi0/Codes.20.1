//Calculo do n-ésimo termo de uma PG e de sua soma finita
#include <stdio.h>
#include <math.h>

int main() {
	double a1, q, n; //Representação padrão de PG

	scanf("%lf %lf %lf", &a1, &q, &n); //Entrada das condicionais da PG

	printf("%.2lf\n", a1 * (pow(q, (n - 1))));  //Cálculo/Impressão do an
	printf("%.2lf\n", a1 * (1 - pow(q, n)) / (1 - q)); //Impressção da soma da PG via fórmula já reduzida

	return 0;
}