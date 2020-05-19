//Programa que identifica trio pitagórico
#include <stdio.h>
#include <math.h>

int main() {
	double lados[3];

	for (int i = 0; i < 3; i++) {  //Entrada dos três lados de uma vez usando laço de repetição
		scanf("%lf", &lados[i]);
	}

	double maior = lados[2];

	for (int i = 0; i < 2; i++) { //Laço para descobrir qual o maior lado dado de entrada
		if (lados[i] > maior) {
			maior = lados [i];
		}
	}

	if (lados[0] == 0 || lados[1] == 0 || lados[2] == 0) { //Confere se o Teorema de Pitágoras é aplicável no trio de lados
		printf("NAO\n");                  			       //(sendo todos diferentes de zero)		 
	}else if ((pow(lados[0], 2) + pow(lados[1], 2) + pow(lados[2], 2) - pow(maior, 2)) == pow(maior, 2)) {
		printf("SIM\n");
	}else {
		printf("NAO\n");
	}	

	return 0;	
}