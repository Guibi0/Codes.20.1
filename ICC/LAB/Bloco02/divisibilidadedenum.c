 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que verifica divisibilidade entre números
 *******************************************************************************/
#include <stdio.h>

//Função que confere divisibilidade dentro de um vetor
//->Parâmetros: array de inteiros, N que define até onde vai até onde vai a
//conferência, e nº d referência para a divisibilidade 
//->Retorno: não há retorno
void divisibilidade_vetor(int vetor[], int N, int d) {
	
	//Confere quais dos N primeiros são divisíveis pelo número referência
	for (int i = 0;  i < N; i++) {
		//Imprime o número caso ele seja divisível
		if (vetor[i] % d == 0) printf("%d\n", vetor[i]);
	}
}

//Função principal
int main() {
 
	//Recebe a lista com 31 números
	int lista[31];
	for (int i = 0; i < 31; i++) {
		scanf("%d", &lista[i]);
	}

	divisibilidade_vetor(lista, 30, lista[30]);
	
	return 0;
}
