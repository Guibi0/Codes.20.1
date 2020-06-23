/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |                      
 |                        Autor: Guilherme Rios(1122839)                       | 
 *******************************************************************************
 > Programa que recebe uma string e a escreve como inteiros na tela
 *******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAMANHOINICIAL 100

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	-um ponteiro do tipo FILE que indica onde ocorre a leitura dos chars
// >Retorno: 
//	-ponteiro que endereça a string
char *recebeChars(FILE *ptr) {
    int tamanho = TAMANHOINICIAL;
    char *string = (char *) malloc(tamanho * sizeof(char));
     
    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	tamanho *= 2;
        	string = (char *) realloc(string, tamanho * sizeof(char));
        }
    	
    	// Recebe caracter por caracter
        string[i] = fgetc(ptr);

        // Pula leitura do '\n' e '\r'
        while(string[i] == '\r' || string[i] == '\n') string[i] = fgetc(ptr);

        i++;
    }while (string[i - 1] != 'x');

    string[i] = '\0';
    string = (char *) realloc(string, (i + 1)* sizeof(char));

    return string;
}
 
// >Função auxiliar à funcção "qsort"
int comparaChars(const void *a, const void *b){
	return ( *(char*)a - *(char*)b );
}

int main() {
	char *string = recebeChars(stdin);
	qsort(string, strlen(string), sizeof(char), comparaChars);
	int *caracteres = (int *)string;

	// Imprime como inteiros
	double tam = (double)strlen(string) / sizeof(int);
	for (int i = 0; i < tam; i++) {
		printf("%d\n", caracteres[i]);
	}

	free(string);
	return 0;
}