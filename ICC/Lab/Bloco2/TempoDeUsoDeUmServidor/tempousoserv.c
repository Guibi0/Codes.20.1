 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que encontra o mês com maior acesso a um server
 *******************************************************************************/
#include <stdio.h>

int main() {

	//Recebe as quantidades de horas de acesso nos meses, de janeiro a dezembro
	double horasdeacesso[12];
	for (int i = 0; i < 12; i++) scanf("%lf", &horasdeacesso[i]);

	//Encontra o mês com maior acesso, armazendo os dados em duas variável
	double maioracesso = horasdeacesso[0];
	int mes = 0;	
	for (int i = 0; i < 12; ++i) {
		if (horasdeacesso[i] > maioracesso) {
			mes = i + 1;
			maioracesso = horasdeacesso[i];
		}
	}

	//Imprime o mês com maior acesso e a quantidade de horas jogadas neste mês
	printf("%d %.2lf\n", mes, maioracesso);
	
	return 0;
}