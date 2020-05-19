//Cálculo de valor de um carro novo de acordo com o custo de fábrica
#include <stdio.h>

int main() {
	float custofabrica;

	printf("Insira o cuso de fábrica: R$");
	scanf("%f", &custofabrica); //Entrada/impressão do custo de fábrica

	if(custofabrica <= 12000 && custofabrica > 0) { //Condicional para cada valor de impostos 
		printf("Preço ao consumidor: R$%.2f\n", custofabrica * 1.05); //1+5%(distribuidor)+0%(impostos)
	}else if(custofabrica <= 25000 && custofabrica > 12000) {
		printf("Preço ao consumidor: R$%.2f\n", custofabrica * 1.25); //1+10%(distribuidor)+15%(impostos)
	}else if(custofabrica > 25000) {
		printf("Preço ao consumidor: R$%.2f\n", custofabrica * 1.35); //1+15%(distribuidor)+20%(impostos)
	}
	
	return 0;
}