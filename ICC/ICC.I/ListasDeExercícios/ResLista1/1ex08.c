//Cálculo de aumento salarial
#include <stdio.h>

int main() {
	float salario0;

	printf("Insira o valor do salário atual: R$");
	scanf("%f", &salario0); //Entrada do salário

	if(salario0 <= 300 && salario0 > 0) { //Condicional para receber cada tipo de aumento
		printf("O novo salário será de: R$%.2f\n", salario0 * 1.35);
	}else if(salario0 > 300) {
		printf("O novo salário será de: R$%.2f\n", salario0 * 1.15);
	}
	
	return 0;
}