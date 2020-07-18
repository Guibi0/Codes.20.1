// .c auxiliar a biblioteca "busca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "uteis.h"
#include "metadados.h"
#include "busca.h"

int buscaChave(Index* idx, Info* chaveBuscada, int inicio, int fim, int tipo) {
	if (inicio > fim) return ERRO;
	int meio = (inicio + fim) / 2;

	if (tipo == INT) {
		if (idx[meio].chave.iInt == chaveBuscada->iInt) return idx[meio].offset;

		else if(idx[meio].chave.iInt > chaveBuscada->iInt) {
			return buscaChave(idx, chaveBuscada, inicio, meio - 1, tipo);
		}

		else return buscaChave(idx, chaveBuscada, meio + 1, fim, tipo);
	}

	else if (tipo == FLOAT) {
		if (idx[meio].chave.iFloat == chaveBuscada->iFloat) return idx[meio].offset;

		else if(idx[meio].chave.iFloat > chaveBuscada->iFloat) {
			return buscaChave(idx, chaveBuscada, inicio, meio - 1, tipo);
		}

		else return buscaChave(idx, chaveBuscada, meio + 1, fim, tipo);
	}

	else if (tipo == DOUBLE) {
		if (idx[meio].chave.iDouble == chaveBuscada->iDouble) return idx[meio].offset;

		else if(idx[meio].chave.iDouble > chaveBuscada->iDouble) {
			return buscaChave(idx, chaveBuscada, inicio, meio - 1, tipo);
		}

		else return buscaChave(idx, chaveBuscada, meio + 1, fim, tipo);
	}

	else {
		if (!strcmp(idx[meio].chave.iString, chaveBuscada->iString)) return idx[meio].offset;

		else if(strcmp(idx[meio].chave.iString, chaveBuscada->iString) > 0) {
			return buscaChave(idx, chaveBuscada, inicio, meio - 1, tipo);
		}

		else return buscaChave(idx, chaveBuscada, meio + 1, fim, tipo);
	}
}

void imprimeDadoDeArq(FILE* arqPtr, char* nomeDado, int tipo, int tamDado) {
	if (tipo == INT) {
		int dado;
		fread(&dado, tamDado, 1, arqPtr);
		printf("%s: %d\n", nomeDado, dado);
	}
	else if (tipo == FLOAT) {
		float dado;
		fread(&dado, tamDado, 1, arqPtr);
		printf("%s: %.2f\n", nomeDado, dado);
	}
	else if (tipo == DOUBLE) {
		double dado;
		fread(&dado, tamDado, 1, arqPtr);
		printf("%s: %.2lf\n", nomeDado, dado);
	}
	else if (tipo == STRING) {
		char* dado = (char*) malloc(tamDado * sizeof(char));
		fread(dado, tamDado, sizeof(char), arqPtr);

		printf("%s: %s\n", nomeDado, dado);
		free(dado);
	}
}

int imprimeFichaBuscada(Metadados* ref, int offset, char* nomeDoArq) {
	FILE* idxPtr = fopen(nomeDoArq, "rb");
	if (idxPtr == NULL) {
		perror("Erro na abertura do arquivo .reg para leitura");
		return ERRO;
	}
	fseek(idxPtr, offset, SEEK_SET);

	// Imprime a chave
	imprimeDadoDeArq(idxPtr, ref->nomeChave, ref->tipoChave, ref->tamChave);

	// Imprime os outros campos
	for (int i = 0; i < ref->qtdaDeCampos; i++) {
		imprimeDadoDeArq(idxPtr, ref->nomeCampos[i], ref->tipoCampos[i], ref->tamCampos[i]);
	}
	printf("\n");

	fclose(idxPtr);
	return SUCESSO;
}

int buscaFichaEImprimeFicha(Metadados* ref, char* nomeDoArq) {
	Info chaveBuscada;
	recebeInfo(&chaveBuscada, ref->tipoChave, CHAVE);

	int inicio = 0, fim = ref->qtdaNoIdx - 1;
	int offsetFichaBuscada = buscaChave(ref->idx, &chaveBuscada, inicio, fim, ref->tipoChave);

	if (offsetFichaBuscada != ERRO) {
		if (imprimeFichaBuscada(ref, offsetFichaBuscada, nomeDoArq) == ERRO) {
			if (ref->tipoChave == STRING) free(chaveBuscada.iString);
			return ERRO;
		}
	}
	// else printf("Chave não encontrada\n");

	if (ref->tipoChave == STRING) free(chaveBuscada.iString);
	return SUCESSO;
}