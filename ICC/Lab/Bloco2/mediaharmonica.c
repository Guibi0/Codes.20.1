 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que calcula uma média harmônica amortizada
 *******************************************************************************/
#include <stdio.h>

int main() {

	//Entrada da quantidade de trabalhos
	int n;
	scanf("%d", &n);

	//Entrada das notas dos trabalhos e calculo do divisor na média
	double notas[n], divisor = 0;
	for (int i = 0; i < n; i ++) {
		scanf("%lf", &notas[i]);

		//Somatória dos inversos de 'notas+1', para todas as notas
		divisor += 1 / (notas[i] + 1);
	}

	//Imprime o resultado
	printf("%.2lf\n", (n/divisor) - 1);

	return 0;
}