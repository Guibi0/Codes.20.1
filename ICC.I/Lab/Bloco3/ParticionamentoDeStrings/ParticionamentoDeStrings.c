/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 > Programa que particiona uma frase e printa sua palavras
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHOINICIAL 1080
#define SIM 1
#define NAO 0

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	-não há parâmetros
// >Retorno: 
//	-ponteiro que endereça a string
char* recebeFrase(FILE* ptr) {
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

// >Função que particiona uma frase em várias palavras
// >Parâmetros:
//	-um ponteiro endereçando a frase completa
//	-um int com a quantidade de palavras na frase
//	-um int com o comando que determina se a primeira letra é minúscula ou não
// >Retorno:
//	-um ponteiro duplo endereçando as palavras
char** particionaFrase(char* frase, int qtdaPalavras, int ehMinuscula) {

	// Cria a matriz para guardar as palavras e recebe essas
	char** palavras = (char**) malloc(qtdaPalavras * sizeof(char*));
	int tamanhoPalavraAtual = 10;
	int i = 0, j = 0, k = 0;
	while (j < qtdaPalavras) {

		// Trata o inicio de palavras
		if (!k) {
			palavras[j] = (char*) malloc(tamanhoPalavraAtual * sizeof(char));
			if (ehMinuscula) palavras[j][k] = tolower(frase[i]);
			else palavras[j][k] = frase[i];
			i++;
			k++;
		}
		else {
			// Realoca caso necessário;
			if (k == tamanhoPalavraAtual) {
				tamanhoPalavraAtual *= 2;
				palavras[j] = (char*) realloc(palavras[j], tamanhoPalavraAtual * sizeof(char));
			}

			if (frase[i] != ' ' && frase[i] != '\0') {
				palavras[j][k] = frase[i];
				i++;
				k++;
			}
			else {
				palavras[j][k] = '\0';

				tamanhoPalavraAtual = k + 1;
				palavras[j] = (char*) realloc(palavras[j], tamanhoPalavraAtual * sizeof(char));

				i++;
				k = 0;
				tamanhoPalavraAtual = TAMANHOINICIAL;

				j++;
			}
		}
	}

	return palavras;
}

// Função auxiliar a função "qsort"
int comparaPalavras(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// >Função que imprime uma lista de palavras
// >Parâmetros:
//	-um ponteiro duplo endereçando a lista
//	-um int com a quantidade de palavras na lista
// >Retorno:
//	-não há retorno
void imprimePalavras(char** palavras, int qtdaPalavras) {
	for (int i = 0; i < qtdaPalavras; i++) printf("%s\n", palavras[i]);
}

int main() {
	// Recebe a frase e operação
	char* frase = recebeFrase(stdin);
	int op;
	scanf("%d", &op);

	// Conta a quantidade de palavras na frase
	int qtdaPalavras = 0, tamanho = strlen(frase);
	for (int i  = 0; i <= tamanho; i++) {
		if (frase[i] == ' ' || frase[i] == '\0') qtdaPalavras++;
	}

	// Gera a matriz de palavras
	int ehMinuscula = op == 2 ? SIM : NAO;
	char** palavras = particionaFrase(frase, qtdaPalavras, ehMinuscula);

	// Ordena caso necessário
	if (op == 2) qsort(palavras, qtdaPalavras, sizeof(char*), comparaPalavras);

	imprimePalavras(palavras, qtdaPalavras);

	for (int i = 0; i < qtdaPalavras; i++) free(palavras[i]);
	free(palavras);
	free(frase);

	return 0;
}