// .c auxiliar a biblioteca "insercao.h"
#include <stdio.h>
#include <stdlib.h>
#include "uteis.h"
#include "metadados.h"
#include "insercao.h"

// Função que administra a criação do arquivo e .reg, e a inserção de dados nesse
int adicionaNoArquivoReg(char* nomeDoArq, Ficha* dados, Metadados* ref, int qtdaFichas) {
	FILE* regPtr;
	if (qtdaFichas) regPtr = fopen(nomeDoArq, "ab+");
	else regPtr = fopen(nomeDoArq, "wb");

	if (regPtr == NULL) {
		perror("Erro na abertura do arquivo .reg para escrita");
		return ERRO;
	}

	// Escreve chave
	escreveDadoNoArq(&dados->chave, ref->tipoChave, ref->tamChave, regPtr);

	// Escreve os outros campos
	for (int i = 0; i < ref->qtdaDeCampos; i++) {
		escreveDadoNoArq(&dados->campos[i], ref->tipoCampos[i], ref->tamCampos[i], regPtr);
	}
	fclose(regPtr);

	return SUCESSO;
}

// Função central para inserção de dados
int recebeDadosReg(Dados* base) {
	int pos = base->qtdaDeFichas;
	int offset = pos ? base->dados[pos - 1].tamFicha + base->dados[pos - 1].offset : 0;

	base->dados[pos].offset = offset;
	base->dados[pos].tamFicha = 0;

	int tipoCampo = base->ref.tipoChave, tamCampo = base->ref.tamChave;

	recebeInfo(&base->dados[pos].chave, tipoCampo, CHAVE);

	if (tipoCampo == STRING) {
		realocaStringComCalloc(&base->dados[pos].chave.iString, tamCampo);
	}
	base->dados[pos].tamFicha += tamCampo;

	base->dados[pos].campos = (Info*) malloc(base->ref.qtdaDeCampos * sizeof(Info));

	for (int i = 0; i < base->ref.qtdaDeCampos; i++) {
		tipoCampo = base->ref.tipoCampos[i];
		tamCampo = base->ref.tamCampos[i];

		recebeInfo(&base->dados[pos].campos[i], tipoCampo, CAMPO);
		base->dados[pos].tamFicha += tamCampo;

		if (tipoCampo == STRING) {
			realocaStringComCalloc(&base->dados[pos].campos[i].iString, tamCampo);
		}
	}

	return adicionaNoArquivoReg(base->nomeDoArquivoReg, &base->dados[pos], &base->ref, pos);
}