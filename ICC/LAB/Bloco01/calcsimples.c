//Calculadora simples de quatro(cinco) operações entre dois números reais
#include <stdio.h>

int main() {

	double a, b; //Aloca as váriaveis reias e a operação
	char op;

	scanf("%lf %c %lf", &a, &op, &b); //Leitura e endereçamento das entradas

	switch (op) { //Indentifica qual a operação a ser feita, a faz, imprimindo o resultado
		
		case '+': 
			printf("%lf\n", a + b);
			break;

		case '-': 
			printf("%lf\n", a - b);
			break;

		case '*': 
			printf("%lf\n", a * b);
			break;

		case '/': 
			printf("%lf\n", a / b);
			break;

		case '%': 
			printf("%lf\n", (a / b) * 100);
			break;	
	}

	return 0;
}
