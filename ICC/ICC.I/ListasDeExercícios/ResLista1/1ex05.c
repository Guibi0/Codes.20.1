//Mini calculadora de 4 operações para dois números
#include <stdio.h>
#include <math.h>

int main () {
	float num1, num2, operacao1, operacao2, operacao3, operacao4; //Denifindo as variáveis
	int operacaoescolhida;
	
	printf("Digite os dois números:\n"); //Entrada dos dois números
	scanf("%f", &num1);
	scanf("%f", &num2);

	operacao1 = (num1 + num2) / 2; //Definindo como procedem as operações
	operacao2 = sqrt(pow(num1 - num2, 2)); //Raiz da diferença
	operacao3 = num1 * num2; 
	operacao4 = num1 / num2;

	printf("Escolha a operação a ser feita:\n"); //Usuário escolhe a operação
	scanf("%d", &operacaoescolhida);
	
	if(operacaoescolhida == 1) { //Condições com relação a operação escolhida
		printf("%.2f\n", operacao1);
	}else if(operacaoescolhida == 2) {
		printf("Seu resultado é %.2f\n", operacao2);
	}else if(operacaoescolhida == 3) {
		printf("Seu resultado é %.2f\n", operacao3);
	}else if(operacaoescolhida == 4 && num2 != 0) { //'num !=(≠) 0' para evitar divisão por 0
		printf("Seu resultado é %.2f\n", operacao4);
	}else {
		printf("ERRO\n");
	}	
	return 0;
} 
	

