 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que calcula potências
 *******************************************************************************/
#include <stdio.h>

int main() {

	//Recebe a base 'a' e o expoente 'b'
	double a;
	int b;
	scanf("%lf %d", &a, &b);

	//Declara resultado inicializando-o em 1, caso b seja = a 0
	double potencia = 1;

	//Calcula potência a^b 
	if (b > 0) { //multiplicando 'a' por 'a' 'b' vezes, para b positivo
		for (; b > 0; b--) {
			potencia *= a;
		}
	} else if (b < 0) { //multiplicando o 1/a por 1/a 'b' vezes, para b negativo
		for (; b < 0; b++) {
			potencia *= 1 / a;
		}
	}

	//Imprime o resultado
	printf("%lf\n", potencia);

	return 0;
}