// .c auxiliar a biblioteca "metadados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "uteis.h"
#include "metadados.h"

void defineOTipo(char* tipoString, int* tipo) {
	if (tipoString[0] == 'i') *(tipo) = INT;
	else if (tipoString[0] == 'f') *(tipo) = FLOAT;
	else if (tipoString[0] == 'd') *(tipo) = DOUBLE;
	else if (tipoString[0] == 'c') *(tipo) = STRING;
}

// Busca na .dat o valor entre colchetes quando o tipo é string
int encontraTamanhoParaStrings(char* tipoStr) {
	int posUltimoAlgarismo = strlen(tipoStr) - 1;
	while (tipoStr[posUltimoAlgarismo] != ']') posUltimoAlgarismo--;
	posUltimoAlgarismo--;

	// Encontra o tamanho com base nas potências de 10
	int i = posUltimoAlgarismo, tamanho = 0, pot = 0;
	while (tipoStr[i] != '[') {
		tamanho += (tipoStr[i] - '0') * pow(10, pot);
		i--;
		pot++;
	}

	return tamanho;
}

void recebeInfo(Info* info, int tipo, int dadoLido) {
	char* infoStr;
	if (tipo != STRING) {
		if (dadoLido == CHAVE) infoStr = leLinhaComRef(stdin, NULL, ",");
		else if (dadoLido == CAMPO) infoStr = leLinhaComRef(stdin, " ", ",");
	}
	else infoStr = leLinhaComRef(stdin, "\"", "\"");
	
	if (tipo == INT) {
		info->iInt = atoi(infoStr);
		free(infoStr);
	}
	else if (tipo == FLOAT) {
		info->iFloat = atof(infoStr);
		free(infoStr);
	}
	else if (tipo == DOUBLE) {
		info->iDouble = atof(infoStr);
		free(infoStr);
	}
	else if (tipo == STRING) info->iString = infoStr;
}

void escreveDadoNoArq(Info* dado, int tipoDado, int tamDado, FILE* arqPtr) {
	if (tipoDado == INT) fwrite(&dado->iInt, tamDado, 1, arqPtr);

	else if (tipoDado == FLOAT) fwrite(&dado->iFloat, tamDado, 1, arqPtr);

	else if (tipoDado == DOUBLE) fwrite(&dado->iDouble, tamDado, 1, arqPtr);

	else if (tipoDado == STRING) fwrite(dado->iString, tamDado, sizeof(char), arqPtr);
}