/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que encontra o máximo e o mínino dentre um conjunto de números
 *******************************************************************************/
#include <stdio.h>

int main() {

	//Entrada da quantidad 'n' de números do conjunto
	int n;
	scanf("%d", &n);

	/*Entrada do conjunto a ser analisado, juntamente com a definição do máximo 
	e mínino*/
	int conjunto[n], maior, menor;
	for (int i = 0; i < n; i++) {
		scanf("%d", &conjunto[i]);

		//Incializa variáveis 'maior' e 'menor' na primeira volta do laço
		if (i == 0) {
			maior = conjunto[i];
			menor = maior;
		}else { //Encontra máximo e mínimo via comparações
			if (conjunto[i] > maior) maior = conjunto[i];

			if (conjunto[i] < menor) menor = conjunto[i]; 
		}
	}

	//Imprime máximo e mínimo
	printf("max: %d\nmin: %d\n", maior, menor);

	return 0;
}