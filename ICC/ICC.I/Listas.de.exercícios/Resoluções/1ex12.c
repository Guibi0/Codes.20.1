//Cálculo de gratificação salarial
#include <stdio.h>

int main() {
	float salariobruto;

	printf("Insira o valor do salário atual: R$");
	scanf("%f", &salariobruto); //Entrada do salário

	if(salariobruto <= 350 && salariobruto > 0) { //Condicional para receber cada gratificação(**imposto de 7% sobre o salário)
		printf("Valor a receber é: R$%.2f\n", salariobruto * 0.93 + 100);	
	}else if(salariobruto < 600 && salariobruto > 350) {
		printf("Valor a receber é: R$%.2f\n", salariobruto * 0.93 +  75);
	}else if(salariobruto <= 900 && salariobruto >= 600) {
		printf("Valor a receber é: R$%.2f\n", salariobruto * 0.93 + 50);	
	}else if(salariobruto > 900) {
		printf("Valor a receber é: R$%.2f\n", salariobruto * 0.93 + 35);

	}
	
	return 0;
}