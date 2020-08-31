/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 > Programa que gera nomes bibliográficos a partir de um nome completo
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHOINICIAL 1080

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	-não há parâmetros
// >Retorno: 
//	-ponteiro que endereça a string
char* recebeNome(FILE* ptr) {
    int tam = TAMANHOINICIAL;
    char* string = (char*) malloc(tam * sizeof(char));

    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tam) {
            tam *= 2;
            string = (char*) realloc(string, tam * sizeof(char));
        }

        // Recebe caracter por caracter
        string[i] = fgetc(ptr);

        // Lê o '\n' pós '\r'
        if(string[i] == '\r') string[i] = fgetc(ptr);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char*) realloc(string, i * sizeof(char));

    return string;
}

void imprimeNomeBibliografico(char* nome) {
	int tamanho = strlen(nome);
	// Encontra a posição do último espaço
	int espaco = tamanho;
	while (nome[--espaco] != ' ');

	// Imprime nome no formato bibliográfico
	for (int i = espaco + 1; i < tamanho; i++) printf("%c", toupper(nome[i]));
	printf(", ");
	for (int i = 0; i < espaco; i++) printf("%c", nome[i]);
	printf("\n");
}

int main() {
	char* nome = recebeNome(stdin);

	imprimeNomeBibliografico(nome);

	free(nome);
	return 0;
}