//Cálculo de aumento salarial
#include <stdio.h>

int main() {
	float salarioatual;

	printf("Insira o valor do salário atual: R$");
	scanf("%f", &salarioatual); //Entrada do salário

	if(salarioatual <= 300 && salarioatual > 0) { //Condicional para receber cada aumento
		printf("Valor de aumento: R$%.2f\nO novo salário é: R$%.2f\n" , salarioatual * 0.15, salarioatual * 1.15);	
	}else if(salarioatual < 600 && salarioatual > 300) {
		printf("Valor de aumento: R$%.2f\nO novo salário é: R$%.2f\n", salarioatual * 0.1, salarioatual * 1.10);
	}else if(salarioatual <= 900 && salarioatual >= 600) {
		printf("Valor de aumento: R$%.2f\nO novo salário é: R$%.2f\n", salarioatual * 0.05, salarioatual * 1.05);	
	}else if(salarioatual > 900) {
		printf("Valor de aumento: R$0.00\nSalário não alterado\n");

	}
	
	return 0;
}