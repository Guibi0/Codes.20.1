 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que retorna o n primeiros múltiplos de 2 números
 *******************************************************************************/
#include <stdio.h>

int main() {

	//Recebe a quantidade 'n'múltiplos que será impressa no final
	int n;
	scanf("%d", &n);

	//Recebe os 2 números
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	//Declara multiplicadores úteis para o laço posterior
	int mult1 = 0, mult2 = 0; 
	for (int i = 0; i < n; i++) {
		//Calcula os múltiplos a serem tratados a cada volta do laço
		int multiplode1 = num1 * mult1;
		int multiplode2 = num2 * mult2;

		//Condicionais que garantem a ordem crescente da impressão
		if (multiplode1 == multiplode2) {			
			//Imprime o um múltiplo comum
			printf("%d\n", multiplode1);
			/*Incrementa os multiplicadores(para não tratar de múltiplos já 
			impressos na próxima volta do laço)*/
			mult1++;
			mult2++;

		}else if (multiplode1 < multiplode2) {
			//Imprime um múltiplo do primeiro número
			printf("%d\n", multiplode1);
			mult1++;

		}else {
			//Imprime um múltiplo do segundo número
			printf("%d\n", multiplode2);
			mult2++;
		}						

	}

	return 0;
}