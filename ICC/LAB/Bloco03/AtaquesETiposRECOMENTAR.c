/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que simula uma IA
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Estrutura para os dados de um ataque
typedef struct {
	float dano;
	int indice;	
}Dados;

//>Função que encontra qual é o melhor tipo de ataque para uma dada situação
//>Parâmetros: dois ponteiros(um duplo), endereçando os dados do jogo e os dados de todos 
//os ataques disponíveis, e dois ints, um com a quantidade de ataques, e outro 
//com o tipo do inimigo da situação
//>Retorno: uma estrutura com os dados do melhor ataque;
Dados encontraMelhor(float **dados, Dados *ataques, int qtda, int inimigo) {

	Dados melhorAtaque;
	melhorAtaque.dano = ataques[0].dano * dados[ataques[0].indice][inimigo];
	melhorAtaque.indice = ataques[0].indice;

	//Procura o maior dano final e guarda os dados dele na estrutura de melhor ataque
	for (int i = 1; i < qtda; i++) {

		if (ataques[i].dano * dados[ataques[i].indice][inimigo] > melhorAtaque.dano) {

			melhorAtaque.dano = ataques[i].dano * dados[ataques[i].indice][inimigo];
			melhorAtaque.indice = ataques[i].indice;
		}
	}

	return melhorAtaque;
}

//Função principal
int main() {

	//Recebe a quantidade de tipos de ataques existentes no jogo
	int qtdaDeTipos;
	scanf("%d", &qtdaDeTipos);

	//Recebe a matriz com as informações sobre cada ataque
	float **matrizDeDados = (float* *) malloc(qtdaDeTipos * sizeof(float*));
	for (int i = 0; i < qtdaDeTipos; i++) {
		matrizDeDados[i] = (float *) malloc(qtdaDeTipos * sizeof(float));

		for (int j = 0; j < qtdaDeTipos; j ++) scanf("%f", &matrizDeDados[i][j]);
	}
	
	int tamanho = qtdaDeTipos;
	Dados *ataques = (Dados *) malloc(tamanho * sizeof(Dados));
	//Recebe os dados de ataque até a entrada de parada("-1")
	int i = 0;
	do {

		//Realoca caso necessário
		if (i == tamanho) {
			tamanho *= 2;
			ataques = (Dados *) realloc(ataques, tamanho * sizeof(Dados));
		}

		//Recebe o dano do ataque
		scanf("%f", &ataques[i].dano);

		//Recebe o tipo de ataque
		if (ataques[i].dano != -1) scanf("%d", &ataques[i].indice);

	}while (ataques[i++].dano != -1);
	//Realoca para o tamanho certo
	tamanho = i - 1;
	ataques = (Dados *) realloc(ataques, tamanho * sizeof(Dados));

	//Recebe o tipo de inimigo
	int inimigo;
	scanf("%d", &inimigo); 

	//Encontra o melhor ataque
	Dados melhor = encontraMelhor(matrizDeDados, ataques, tamanho, inimigo);

	//Printa as informações sobre o melhor ataque
	printf("O melhor ataque possui indice %d e dano %.2f\n", melhor.indice, melhor.dano);

	for (int i = 0; i < qtdaDeTipos; i++) free(matrizDeDados[i]);
	free(matrizDeDados);	
	free(ataques);
	return 0;
}