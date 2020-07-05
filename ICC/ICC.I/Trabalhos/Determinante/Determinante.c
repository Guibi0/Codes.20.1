 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que calcula determinante para matrizes de ordem 1, 2 e 3
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//>Função que aloca uma matriz de inteiros usando na HEAP
//>Parâmetros: inteiros com as dimensões da matriz
//>Retorno: um ponteiro duplo endereçando a matriz
int **aloca_matriz(int num_linhas, int num_colunas) {
	
	//Aloca um vetor que guarda endereços de outros vetores
	int **matriz = (int **) malloc(num_linhas * sizeof(int*));
	//Aloca esse vetores
	for (int i = 0; i < num_linhas; i++){
		matriz[i] = (int *) malloc(num_colunas * sizeof(int));
	}
	
	return matriz;
}

//>Função que libera uma matriz de inteiros na HEAP
//>Parâmetros: um ponteiro duplo endereçando a matriz, e inteiro com a
//quantidade de linhas 
//>Retorno: não há parâmetros
void libera_matriz(int **matriz, int num_linhas) {
	
	for (int i = 0; i < num_linhas; i++) free(matriz[i]);
	free(matriz);	
}

//>Função que lê uma matriz de inteiros na HEAP
//>Parâmetros: um ponteiro duplo endereçando a matriz, e inteiros com as 
//dimensões da matriz
//>Retorno: a mesma matriz, agora com os valores recebidos
int **le_matriz(int **matriz, int num_linhas, int num_colunas) {
	
	//Lê a matriz
	for (int i = 0; i < num_linhas; i++) {
		for (int j = 0; j < num_colunas; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	return matriz;
}

//>Função que lê uma matriz de ordem de 1 à 3 e imprime o determinante dessa
//>Parâmetros:um ponteiro duplo endereçando a matriz, e um inteiro com a ordem 
//>Retorno: não há retorno
void imprime_det_matriz(int **matriz, int ordem) {

	matriz = le_matriz(matriz, ordem, ordem);
	
	//Calcula o determinante
	int det;
	if (ordem == 1) {
		//Define det como o único elemento da matriz
		det = matriz[0][0];

	}else if (ordem == 2) {
		//Define det somando e subtraindo, respectivamente, produtos dos	
		//elementos da diagonal principal(i=j) e da diagonal secundária(|i-j|=1) 
		det = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

	}else {
		//Calcula os produtos que serão somados: o dos elementos da diagonal 
		//principal(i=j), e os dos elementos das diagonais paralelas a essa	
		int soma = 0;
		for (int i = 0, j = 0; j < ordem; j ++) {
			int produto = 1;
			//Calcula os produtos se deslocando nas diagonais*
			for (int cont = 0; cont < 3; cont++) {
				produto *= matriz[i][j];

				i = (3 + (i + 1) % 3) % 3;
				j = (3 + (j + 1) % 3) % 3;
			}

			soma += produto;
		}

		//Calcula os produtos que serão subtraídos: o dos elementos da diagonal 
		//secundária(|i-j|=1), e os dos elementos das diagonais paralelas a essa
		int subtracao = 0;
		for (int i = 0, j = 2; j >= 0; j--) {
			int produto = 1;
			//Calcula os produtos se deslocando nas diagonais*
			for (int cont = 0; cont < 3; cont++) {
				produto *= matriz[i][j];

				i = (3 + (i + 1) % 3) % 3;
				j = (3 + (j - 1) % 3) % 3;
			}

			subtracao += produto;
		}	
		//*Obs: para o cálculo dos produtos o deslocamento nas diagonais se
		//baseou no teorema do resto		 

		//Define det 
		det = soma - subtracao;
	}

	//Imprime a resposta
	printf("O determinante da matriz de entrada equivale a %d e tem ordem %d\n", det, ordem);

}

//Função principal
int main() {
	
	//Recebe as dimensões da matriz
	int qtda_linhas, qtda_colunas;
	scanf("%d %d", &qtda_linhas, &qtda_colunas);
	
	//Cria essa matriz
	int **matriz = aloca_matriz(qtda_linhas, qtda_colunas);

	//Condições que analizam o formato da matriz, tratando matrizes quadradas 
	//e não quadradas, respectivamente
	if (qtda_linhas == qtda_colunas) {
		int ordem = qtda_linhas;
		//Trata das matrizes com ordem 1, 2, ou 3 
		if (ordem >= 1 && ordem <= 3) imprime_det_matriz(matriz, ordem);

		//Trata das matrizes com det que não pode ser calculado pelo programa
		else printf("Entradas invalidas!\n");

	}else printf("A matriz de entrada nao possui determinante!\n");	

	libera_matriz(matriz, qtda_linhas);
	return 0;
}