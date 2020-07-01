#include <stdio.h>
#include <math.h>

int main() {
	float num1, num2, operacao1, operacao2;  //Definição das variáveis 
	float operacao2_1, operacao3, operacao3_1; 
	int operacaoescolhida;
	
	printf("Digite os dois números:\n"); //Entrada dos dois números
	scanf("%f", &num1);
	scanf("%f", &num2);

	printf("Escolha a operação a ser feita:\n");
	scanf("%d", &operacaoescolhida);

	operacao1 = pow(num1, num2); //Definindo o que cada operação faz
	operacao2 = sqrt(num1);
	operacao2_1 = sqrt(num2);
	operacao3 = pow(num1, 1.0 / 3.0); //Raiz cúbica
	operacao3_1 = pow(num2, 1.0 / 3.0);

	if(operacaoescolhida == 1) { //Condicionais para cada operação escolhida
		printf("Seu resultado é %.2f\n", operacao1);
	}else if(operacaoescolhida == 2) {
		printf("Os resultados são %.2f e %.2f, respectivamente\n", operacao2, operacao2_1);
	}else if(operacaoescolhida == 3) {
		printf("Os resultados são %.2f e %.2f, respectivamente\n", operacao3, operacao3_1);
	}else {
		printf("ERRO\n");
	}

	return 0;
}