//Calculadora de potência

#include <stdio.h>
#include <math.h>

int main() {
	float a, b; //Entrada da base e do expoente
	
	scanf("%f %f", &a, &b);
	printf("%.4f\n", pow(a, b)); //Impressão usando 'pow'(função de potência)
	
	return 0;
}