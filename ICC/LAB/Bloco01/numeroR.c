//3 operações com mesmo nº a
#include <stdio.h>

int main() {
	double a; 
	
	scanf("%lf", &a);
	
	printf("%d\n", (int)a); //'a' inteiro
	printf("%.4f\n", a - (int)a); //Primeiras 4 casas decimais de 'a'
	printf("%.0f\n", a); //a arredondado 

	return 0;
}