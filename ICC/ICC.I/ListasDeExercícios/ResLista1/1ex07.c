//Cálculo de aumento salarial
#include <stdio.h>

int main() {
	float salario0;

	printf("Insira o valor do salário atual: R$");
	scanf("%f", &salario0); //Entrada do salário

	if(salario0 < 500 && salario0 > 0) { //Condicional para receber o aumento
		printf("O novo salário será de: R$%.2f\n", salario0 * 1.3);
	}else if(salario0 >= 500) {
		printf("O salário não pode receber aumento pois excede a faixa de salários beneficiados.\n");
	}
	
	return 0;
}