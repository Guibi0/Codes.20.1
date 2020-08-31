// .c auxiliar a biblioteca "baseDeDados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uteis.h"

// Recebe entrada tomando como referências os parametros de inicio e fim, para
//parâmetros nulos toma como referência ínicio ou fim da própria linha
char* leLinhaComRef(FILE* ptr, void* inicio, void* final) {
	int tam = TAMANHO_INICIAL;
	char* string = (char*) malloc(tam * sizeof(char));

	// Ignora parte indesejada
	int fim = NAO;
	if (inicio != NULL) {
		char lixo;

		do {
			lixo = fgetc(ptr);
			if (lixo == '\r') lixo = fgetc(ptr);
			if (lixo == '\n' || fim == EOF) fim = SIM;
		} while (lixo != *(char*)inicio && !fim);
	}

	// Lê a string
	char c;
	int i = 0;
	do {
		// Realoca a string em um espaço maior caso necessário
		if (i == tam) {
			tam *= 2;
			string = (char*) realloc(string, tam * sizeof(char));
		}

		c = fgetc(ptr);
		if(c == '\r') c = fgetc(ptr);

		if (final == NULL) fim = (c == '\n' || c == EOF);
		else if (!fim) fim = (c == '\n' || c == EOF || c == *(char*)final);

		// Adiciona caracter na string, ou '\0' caso encontre o final
		string[i] = fim ? '\0' : c;

		i++;
	} while (!fim);
	string = (char*) realloc(string, i * sizeof(char));

	return string;
}

void realocaStringComCalloc(char** str, int qtdaBytes) {
	char* novaStr = (char*) calloc(qtdaBytes, sizeof(char));

	int tamStr = strlen(*str) + 1;
	for(int i = 0; i < tamStr; i++) {
		novaStr[i] = (*str)[i];
	}

	free(*str);
	*str = novaStr;
}

void adicionaEmString(char** str, char* adicao) {
	int sizeStr = strlen(*str);
	int sizeAdicao = strlen(adicao);
	*str = (char*) realloc(*str, (sizeStr + sizeAdicao + 1) * sizeof(char));

	for (int i = sizeStr, j = 0; j <= sizeAdicao; i++, j++) (*str)[i] = adicao[j];
}