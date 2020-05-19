//Cálculo de gratificação salarial
#include <stdio.h>

int main() {
	float preco0, precoaumentado;

	printf("Insira o preço atual do produto: R$");
	scanf("%f", &preco0); //Entrada do preço

	if(preco0 <= 50 && preco0 > 0) { //Percentuais de aumento e impressão do novo preço
		printf("O novo preço é: R$%.2f\n", precoaumentado = preco0 * 1.05);	
	}else if(preco0 <= 100 && preco0 > 50) {
		printf("O novo preço é: R$%.2f\n", precoaumentado = preco0 * 1.1);	
	}else if(preco0 > 100) {
		printf("O novo preço é: R$%.2f\n", precoaumentado = preco0 * 1.15);
	}	

	if(precoaumentado <= 80 && precoaumentado > 0) { //Classificação, por categoria, do novo preço
		printf("Esse produto é classificado como barato\n");	
	}else if(precoaumentado <= 120 && precoaumentado > 80) {
		printf("Esse produto é classificado como normal\n");	
	}else if(precoaumentado <= 200 && precoaumentado > 120) {
		printf("Esse produto é classificado como caro\n");	
	}else if(precoaumentado > 200) {
		printf("Esse produto é classificado como muito caro\n");
	}	
	
	return 0;
}