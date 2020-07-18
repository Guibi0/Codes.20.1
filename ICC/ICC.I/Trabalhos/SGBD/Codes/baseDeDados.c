// .c auxiliar a biblioteca "baseDeDados.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "uteis.h"
#include "metadados.h"
#include "insercao.h"
#include "indexacao.h"
#include "busca.h"
#include "baseDeDados.h"

// Guarda as informações do .dat em uma estrutura
int escrevePadrao(char* dadoAtual, Dados* base, FILE* datPtr) {
	// Verifica o que está sendo escrito
	if (!strcmp(dadoAtual, NOME_CAMPO)) {
		base->ref.tipoCampos = (int*) realloc(base->ref.tipoCampos, (base->ref.qtdaDeCampos + 1) * sizeof(int));
		base->ref.nomeCampos = (char**) realloc(base->ref.nomeCampos, (base->ref.qtdaDeCampos + 1) * sizeof(char*));
		base->ref.tamCampos = (int*) realloc(base->ref.tamCampos, (base->ref.qtdaDeCampos + 1) * sizeof(int));

		// Recebe em strings temporárias o nome de cada campo e o tipo dele
		char* nomeInfo = leLinhaComRef(datPtr, NULL, NULL);
		char* dadoLido = leLinhaComRef(datPtr, NULL, " ");

		if (!strcmp(dadoLido, TIPO_CAMPO)) {
			char* tipoInfo = leLinhaComRef(datPtr, NULL, NULL);

			int indice = base->ref.qtdaDeCampos;
			defineOTipo(tipoInfo, &base->ref.tipoCampos[indice]);
			base->ref.nomeCampos[indice] = nomeInfo;

			if (base->ref.tipoCampos[indice] == INT) base->ref.tamCampos[indice] = sizeof(int);

			else if (base->ref.tipoCampos[indice] == FLOAT) base->ref.tamCampos[indice] = sizeof(float);

			else if (base->ref.tipoCampos[indice] == DOUBLE) base->ref.tamCampos[indice] = sizeof(double);

			else if (base->ref.tipoCampos[indice] == STRING) {
				int tamanho = encontraTamanhoParaStrings(tipoInfo);
				base->ref.tamCampos[indice] = tamanho * sizeof(char);
			}

			base->ref.qtdaDeCampos++;

			free(dadoLido);
			free(tipoInfo);
		}
		// Caso o .dat não esteja com a formatação correta
		else {
			free(dadoLido);
			free(nomeInfo);
			return ERRO;
		}
	}
	else if (!strcmp(dadoAtual, NOME_ARQUIVO)) {
		base->nomeDoArquivoReg = leLinhaComRef(datPtr, NULL, NULL);
	}
	else if (!strcmp(dadoAtual, NOME_CHAVE)) {
		// Recebe em strings temporárias o nome da chave e o tipo dela
		char* nomeInfo = leLinhaComRef(datPtr, NULL, NULL);

		char* dadoLido = leLinhaComRef(datPtr, NULL, " ");
		if (!strcmp(dadoLido, TIPO_CHAVE)) {
			char* tipoInfo = leLinhaComRef(datPtr, NULL, NULL);
			defineOTipo(tipoInfo, &base->ref.tipoChave);
			base->ref.nomeChave = nomeInfo;

			if (base->ref.tipoChave == INT) base->ref.tamChave = sizeof(int);

			else if (base->ref.tipoChave == FLOAT) base->ref.tamChave = sizeof(float);

			else if (base->ref.tipoChave == DOUBLE) base->ref.tamChave = sizeof(double);

			else if (base->ref.tipoChave == STRING) {
				int tamanho = encontraTamanhoParaStrings(tipoInfo);
				base->ref.tamChave = tamanho * sizeof(char);
			}

			free(dadoLido);
			free(tipoInfo);
		}
		else {
			free(dadoLido);
			free(nomeInfo);
			return ERRO;
		}
	}
	return SUCESSO;
}

void liberaMemoriaMetadados(Dados* base) {
	free(base->nomeDoArquivoReg);
	free(base->ref.nomeChave);

	for (int i = 0; i < base->ref.qtdaDeCampos; i++) free(base->ref.nomeCampos[i]);
	free(base->ref.nomeCampos);
	free(base->ref.tamCampos);
	free(base->ref.tipoCampos);

	free(base);
}

// Guarda em uma estrutura o padrao com os tipos de dados a serem armazenados
Dados* lePadraoDosMetadados(char* nomeDoArqBase) {
	Dados* base = (Dados*) malloc(sizeof(Dados));

	FILE* datPtr = fopen(nomeDoArqBase, "r");
	if (datPtr == NULL) {
		free(nomeDoArqBase);
		free(base);

		perror("Erro na abertura do arquivo .dat para leitura");
		exit(EXIT_FAILURE);
	}
	else {
		base->ref.qtdaDeCampos = 0;
		base->ref.tipoCampos = NULL;
		base->ref.nomeCampos = NULL;
		base->ref.tamCampos = NULL;

		char* dadoAtual;
		do {
			// Lê até o espaço após os ':' de cada linha do .dat
			dadoAtual = leLinhaComRef(datPtr, NULL, " ");
			if(dadoAtual[0] == '\0') {
				free(dadoAtual);
				continue;
			}

			if (escrevePadrao(dadoAtual, base, datPtr) == ERRO) {
				free(dadoAtual);
				free(nomeDoArqBase);
				fclose(datPtr);
				liberaMemoriaMetadados(base);

				fprintf(stderr, "Erro no formato do arquivo .dat\n");
				exit(EXIT_FAILURE);
			}
			free(dadoAtual);
		} while(!feof(datPtr));

		fclose(datPtr);
	}

	free(nomeDoArqBase);
	return base;
}

// Função central para as quatro funções do programa
void menuDeOperacoes(Dados* base) {
	base->dados = NULL;
	base->qtdaDeFichas = 0;
	base->ref.idx = NULL;
	base->ref.qtdaNoIdx = 0;

	char* comando;
	int idxAtualizado = NAO;
	int fim = NAO;
	do {
		comando = leLinhaComRef(stdin, NULL, " ");
		if(comando[0] == '\0') {
			free(comando);
			continue;
		}

		if (!strcmp(comando, INSERIR)) {
			base->dados = (Ficha*) realloc(base->dados, (base->qtdaDeFichas + 1) * sizeof(Ficha));

			if (recebeDadosReg(base) == ERRO) {
				base->qtdaDeFichas++;
				free(comando);
				liberaMemoriaTotal(base);

				exit(EXIT_FAILURE);
			}
			base->qtdaDeFichas++;

			idxAtualizado = NAO;
		}
		else if (!strcmp(comando, INDEXAR) && !idxAtualizado) {
			if (!base->qtdaDeFichas) {
				// printf("Não há dados cadastrados\n");
				free(comando);
				continue;
			}

			if (atualizaIdx(base) == ERRO) {
				free(comando);
				liberaMemoriaTotal(base);

				exit(EXIT_FAILURE);
			}
			idxAtualizado = SIM;
		}
		else if (!strcmp(comando, BUSCAR)) {
			if (!base->qtdaDeFichas) {
				// printf("Não há dados cadastrados\n");
				free(comando);
				continue;
			}

			if (!idxAtualizado) {
				if (atualizaIdx(base) == ERRO) {
					free(comando);
					liberaMemoriaTotal(base);

					exit(EXIT_FAILURE);
				}
				idxAtualizado = SIM;
			}

			if (buscaFichaEImprimeFicha(&base->ref, base->nomeDoArquivoReg) == ERRO) {
				free(comando);
				liberaMemoriaTotal(base);

				exit(EXIT_FAILURE);
			}
		}
		else if (!strcmp(comando, SAIR)) fim = SIM;

		free(comando);
	} while (!fim);
}

void liberaMemoriaTotal(Dados* base) {
	free(base->nomeDoArquivoReg);

	free(base->ref.nomeChave);
	for (int i = 0; i < base->ref.qtdaDeCampos; i++) free(base->ref.nomeCampos[i]);
	free(base->ref.nomeCampos);
	free(base->ref.tamCampos);

	for (int i = 0; i < base->qtdaDeFichas; i++) {
		if (base->ref.tipoChave == STRING) free(base->dados[i].chave.iString);
		for (int j = 0; j < base->ref.qtdaDeCampos; j++) {
			if (base->ref.tipoCampos[j] == STRING) free(base->dados[i].campos[j].iString);
		}
		free(base->dados[i].campos);
	}
	free(base->ref.tipoCampos);
	free(base->dados);

	if (base->ref.qtdaNoIdx) {
		free(base->ref.nomeDoArquivoIdx);
		free(base->ref.idx);
	}

	free(base);
}