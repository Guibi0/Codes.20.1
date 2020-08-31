// .c auxiliar a biblioteca "indexacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "metadados.h"
#include "uteis.h"
#include "indexacao.h"

int comparaInts(const void* a, const void* b) {
	return (*(Index*)a).chave.iInt - (*(Index*)b).chave.iInt;
}

int comparaFloats(const void* a, const void* b) {
	float dif = (*(Index*)a).chave.iFloat - (*(Index*)b).chave.iFloat;
	return dif > 0 ? ceil(dif) : floor(dif);
}

int comparaDoubles(const void* a, const void* b) {
	double dif = (*(Index*)a).chave.iDouble - (*(Index*)b).chave.iDouble;
	return dif > 0 ? ceil(dif) : floor(dif);
}

int comparaStrings(const void* a, const void* b) {
	return strcmp((*(Index*)a).chave.iString, (*(Index*)b).chave.iString);
}

void ordenaIdx(Index* idx, int qtdaIdx, int tipo) {
	if (tipo == INT) qsort(idx, qtdaIdx, sizeof(Index), comparaInts);
	else if (tipo == FLOAT) qsort(idx, qtdaIdx, sizeof(Index), comparaFloats);
	else if (tipo == DOUBLE) qsort(idx, qtdaIdx, sizeof(Index), comparaDoubles);
	else if (tipo == STRING) qsort(idx, qtdaIdx, sizeof(Index), comparaStrings);
}

void geraNomeArqIdx(char** nomeIdx, char* nomeReg) {
	int tamNome = strlen(nomeReg) - strlen(".reg") + 1;
	*nomeIdx = (char*) malloc(tamNome * sizeof(char));

	int i = 0;
	while (nomeReg[i] != '.') {
		(*nomeIdx)[i] = nomeReg[i];
		i++;
	}
	(*nomeIdx)[i] = '\0';

	adicionaEmString(&*nomeIdx, ".idx");
}

int atualizaArquivoIdx(Metadados* ref) {
	FILE* idxPtr = fopen(ref->nomeDoArquivoIdx, "wb");
	if (idxPtr == NULL) {
		perror("Erro na abertura do arquivo .idx para escrita");
		return ERRO;
	}

	for (int i = 0; i < ref->qtdaNoIdx; i++) {
		escreveDadoNoArq(&ref->idx[i].chave, ref->tipoChave, ref->tamChave, idxPtr);
		fwrite(&ref->idx[i].offset, sizeof(int), 1, idxPtr);
	}
	fclose(idxPtr);

	return SUCESSO;
}

int atualizaIdx(Dados* base) {
	int qtdaIdx = base->qtdaDeFichas;
	base->ref.idx = (Index*) realloc(base->ref.idx, qtdaIdx * sizeof(Index));

	for (int i = base->ref.qtdaNoIdx; i < qtdaIdx; i++) {
		base->ref.idx[i].chave = base->dados[i].chave;
		base->ref.idx[i].offset = base->dados[i].offset;
	}

	ordenaIdx(base->ref.idx, qtdaIdx, base->ref.tipoChave);

	if (!base->ref.qtdaNoIdx) geraNomeArqIdx(&base->ref.nomeDoArquivoIdx, base->nomeDoArquivoReg);

	base->ref.qtdaNoIdx = qtdaIdx;
	if (atualizaArquivoIdx(&base->ref) == ERRO) return ERRO;

	return SUCESSO;
}