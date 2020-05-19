//Cálculo de rendimento de investimentos
#include <stdio.h>

int main() {
	float tipodeinvestimento, valorinvestido;

	tipodeinvestimento = -1;

	while(tipodeinvestimento == -1) { //Para recomeçar quando digitado um tipo de investimento não válido

	printf("Escolha tipo de investimento:");
	scanf("%f", &tipodeinvestimento);
	
	if(tipodeinvestimento == 1 || tipodeinvestimento == 2) { //Escolha do entre poupança e fundos de renda fixa
		printf("Digite o valor investido: R$");
		scanf("%f", &valorinvestido);

		if(tipodeinvestimento == 1){ //Cálculo do rendimento
			printf("O valor após um mês de rendimento será de R$%.2f\n", valorinvestido * 1.03);
		}else {
			printf("O valor após um mês de rendimento será de R$%.2f\n", valorinvestido * 1.04);
		}
	
	}else { 
		printf("Esse não é um tipo de investimento válido\n");	
		tipodeinvestimento = -1;
	}	
	
	} 

	return 0;
}