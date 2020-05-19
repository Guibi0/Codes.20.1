 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que obtém a quantidade mínima de moedas para um determinado troco
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

//>Função que calcula a quantidade de cada tipo(1 real, 50, 25, 10, 5, e 1 
//centavos) de moeda para um certo troco     
//>Parâmetros: um inteiro com o troco, e dois vetores de inteiros, um com os 
//valores de cada moeda, e outro para contar quantas vão para o troco
//>Retorno: um vetor com as quantidades de cada moeda
int calcula_troco(int quantia_atual, int valores[], int qtdas[]) {
	//Contagem para os 6 tipos de moeda
	for (int i = 0; i < 6; i++) {
		qtdas[i] = quantia_atual / valores[i];
		quantia_atual %= valores[i];
 	}

	return 0;
}

//Função principal
int main() {
	//Recebe o troco ser calculado em centavos
	int troco;
	scanf("%d", &troco);

	//Declara vetor com os valores de cada moeda
	int valores_moeda[] = {100, 50, 25, 10, 5, 1};

	//Declara vetor zerado para contar a quantidade para cada tipo
	int qtdas_moeda[6] = {};

	//Chama a função 
	calcula_troco(troco, valores_moeda, qtdas_moeda);

	//Imprime a saída
	printf("O valor consiste em %d moedas de 1 real\n", qtdas_moeda[0]);
	for (int i = 1; i < 5; i++) {
		printf("O valor consiste em %d moedas de %d centavos\n", qtdas_moeda[i],
															  valores_moeda[i]);
	}
	printf("O valor consiste em %d moedas de 1 centavo\n", qtdas_moeda[5]);

	return 0;
}