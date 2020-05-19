 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |                      
 |                        Autor: Guilherme Rios(1122839)                       | 
 *******************************************************************************
 >Programa que converte número binário para decimal
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <math.h>

int main() {
	//Declara um vetor de caracteres para o nº binário e um inteiro para 
	//o nº decimal
	char *binario = (char *) malloc(31 * sizeof(char)); 
	int decimal = 0; 

	//Entrada do nº binário
	scanf("%s", binario); 
	
	//Declara um inteiro inicializando-o com o tamanho do nº binário
	int tamanho = strlen(binario);  

	//Laço se inicia no último bit do binário(tamanho-1, pois o último é um 
	//"\0") e finda no primeiro
	int j = -1;
	while (tamanho >= 0) { 
		tamanho--;
		j++;		

		if (binario[tamanho] == '1') {    
			//Incremento da respectiva potência de 2 sobre o decimal caso o bit 
			//seja 1
			decimal += pow(2, j); 
		}			             				  
	}

	//Impressão do nº binário já convertido para decimal
	printf("%d\n", decimal); 

	free(binario);
	return 0;	
}