/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |                      
 |                        Autor: Guilherme Rios(1122839)                       | 
 *******************************************************************************
 >Programa que cria um gráfico com base na frequência de termos em um vetor
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main() { 

	//Recebe as quantidades de barras e dados	
	int qtda_barras, qtda_dados;
	scanf("%d\n%d\n", &qtda_barras, &qtda_dados);

	//Declara vetores, um para contar a quantidade de cada rótulo(zerado, para 
	//incrementado depois) e outro para receber esses rótulos
	int *qtdarotulo = (int *) malloc(qtda_barras * sizeof(int));
	int *dados = (int *) malloc(qtda_dados * sizeof(int)); 

	//Iniciliza o vetor de contagem em zero
 	for (int i = 0; i < qtda_barras; i++) { 
 		qtdarotulo[i] = 0; 
 	}
	
	//Recebe os dados e increnta no vetor da quantidade de rótulos, de 
	//acordo com o rótulo recebido
	for (int i = 0; i < qtda_dados; i++) {
		scanf("%d", &dados[i]);
		qtdarotulo[dados[i]]++;
	}

	//Imprime o gráfico linha por linha, utilizando o vetor que armazena as 
	//quantidades para cada linha desse
	for (int i = 0; i < qtda_barras; i++) {
		//Imprime o índice para cada linha do gráfico
		printf("%d - ", i);
		//Imprime o gráfico
		for(; qtdarotulo[i] > 0; qtdarotulo[i]--){
			printf("#");
		}
		 //Quebra de linha
		printf("\n");	
	}

	free(qtdarotulo);
	free(dados);
	return 0;
}
