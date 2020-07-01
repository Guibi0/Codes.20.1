//Cálculo de crédito em banco
#include <stdio.h>

int main() {
	float saldomed;

	printf("Insira o valor do saldo médio do último ano: R$");
	scanf("%f", &saldomed); //Entrada/impressão do saldo
	printf("Saldo médio: R$%.2f\n", saldomed );

	if(saldomed <= 200 && saldomed > 0) { //Condicional para receber cada tipo de crédito
		printf("Crédito: R$%.2f\n", saldomed * 0.1);
	}else if(saldomed <= 300 && saldomed > 200) {
		printf("Crédito: R$%.2f\n", saldomed * 0.2);
	}else if(saldomed <= 400 && saldomed > 300) {
		printf("Crédito: R$%.2f\n", saldomed * 0.25);
	}else if(saldomed > 400) {
		printf("Crédito: R$%.2f\n", saldomed * 0.3);
	}
	
	return 0;
}