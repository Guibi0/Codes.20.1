//Cálculo de aumento salarial
#include <stdio.h>

int main() {
	float salarioatual;

	printf("Insira o valor do salário atual: R$");
	scanf("%f", &salarioatual); //Entrada do salário

	if(salarioatual <= 300 && salarioatual > 0) { //Condicional para receber cada aumento
		printf("O novo salário é: R$%.2f\n" , salarioatual * 1.5);	
	}else if(salarioatual <= 500 && salarioatual > 300) {
		printf("O novo salário é: R$%.2f\n", salarioatual * 1.4);
	}else if(salarioatual <= 700 && salarioatual > 500) {
		printf("O novo salário é: R$%.2f\n", salarioatual * 1.3);	
	}else if(salarioatual <= 800 && salarioatual > 700) {
		printf("O novo salário é: R$%.2f\n", salarioatual * 1.2);	
	}else if(salarioatual <= 1000 && salarioatual > 800) {
		printf("O novo salário é: R$%.2f\n", salarioatual * 1.1);	
	}else if(salarioatual > 1000) {
		printf("O novo salário é: R$%.2f\n", salarioatual * 1.05);	
	}
	
	return 0;
}