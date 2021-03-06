/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 > Programa que analisa um arquivo com strings de acordo com padrões
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define TAMANHOINICIAL 1024

// Struct que organiza os dados sobre cada palavra
typedef struct {
	char *conteudo;
	int tam;
} String;

// Struct com todo conteúdo do arquivo analisado
typedef struct {
	String *palavras;
	int qtdaPalavras;
	int posCurta;
	int posLonga;
} Arquivo;

// Struct com todo conteúdo de entrada
typedef struct {
	char* nomeDoArq;
	char* padraoReg1;
	char* padraoReg2;
	char* padraoReg3;
	char* palavraW;
} Input;

char *recebeString(FILE *ptr) {
    int tam = TAMANHOINICIAL;
    char *string = (char *) malloc(tam * sizeof(char));

    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tam) {
        	tam *= 2;
        	string = (char *) realloc(string, tam * sizeof(char));
        }

    	// Recebe caracter por caracter
        string[i] = fgetc(ptr);

        // Lê o '\n' pós '\r'
        if(string[i] == '\r') string[i] = fgetc(ptr);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

void recebeEntrada(Input *in) {
	in->nomeDoArq = recebeString(stdin);
	in->padraoReg1 = recebeString(stdin);
	in->padraoReg2 = recebeString(stdin);
	in->padraoReg3 = recebeString(stdin);
	in->palavraW = recebeString(stdin);
}

void leArquivo(Arquivo *arq, Input *in) {
	FILE *ptrArq = fopen(in->nomeDoArq, "rb");

	// Inicializa a struct para os dados do arquivo
	arq->qtdaPalavras = TAMANHOINICIAL;
	arq->palavras = (String *) malloc(arq->qtdaPalavras * sizeof(String));
	arq->posCurta = 0;
	arq->posLonga = 0;

	// Lê as linhas não vázias do arquivo
	int i = 0;
	while (!feof(ptrArq)) {
		// Realoca caso necessário
		if (i == arq->qtdaPalavras) {
			arq->qtdaPalavras *= 2;
			arq->palavras = (String *) realloc(arq->palavras, arq->qtdaPalavras * sizeof(String));
		}

		// Inicializa conteúdo para a struct de cada palavra
		arq->palavras[i].conteudo = recebeString(ptrArq);

		// Ignora as linhas sem palavras
		if (strcmp(arq->palavras[i].conteudo, "")) i++;
		else {
			free(arq->palavras[i].conteudo);
			continue;
		}

		// Guarda tamanho da palavra lida na volta atual
		arq->palavras[i - 1].tam = strlen(arq->palavras[i - 1].conteudo);

		// Armazena o indice das palavra mais curta e da mais longa
		if (arq->palavras[i-1].tam < arq->palavras[arq->posCurta].tam) arq->posCurta = i - 1;
		if (arq->palavras[i-1].tam > arq->palavras[arq->posLonga].tam) arq->posLonga = i - 1;
	}

	// Realoca para o tamanho ideal
	arq->qtdaPalavras = i;
	arq->palavras = (String *) realloc(arq->palavras, arq->qtdaPalavras * sizeof(String));
	fclose(ptrArq);
}

int contaPalindromos(Arquivo *arq) {
	// Analisa todas as palavras do arquivo
	int cont = arq->qtdaPalavras;
	for (int i = 0; i < arq->qtdaPalavras; i++) {

		// Verifica se a palavra não é palíndromo e decrementa o contador(inicialmente 
		//igual a quantidade total de palavras)
		int inicio = 0, fim = arq->palavras[i].tam - 1;
		while (inicio < fim) {

			if (arq->palavras[i].conteudo[inicio] != arq->palavras[i].conteudo[fim]) {
				cont--;
				break;
			}

			inicio++;
			fim--;
		}
	}

	return cont;
}

int contaOcorrenciasRegex(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Verifica se a palavra não obedece o padrão e decrementa o contador(inicialmente
	//igual a quantidade total de palavras)
	int cont = arq->qtdaPalavras, naoEstaNoPadrao = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		naoEstaNoPadrao = regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0);
		if (naoEstaNoPadrao) cont--;
	}
	regfree(&regex);

	return cont;
}

int encontraMaiorPalavraRegex(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Verifica dentre as palavras que atendem o padrão qual é a mais longa
	int posLonga = 0, estaNoPadrao = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		estaNoPadrao = !regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0);
		if (estaNoPadrao) {
			if (arq->palavras[i].tam > arq->palavras[posLonga].tam) posLonga = i;
		}
	}
	regfree(&regex);

	return posLonga;
}

int comparaNomes(const void *a, const void *b){
	return (strcmp((*(char* *)a), (*(char* *)b)));
}

void imprimeOcorrenciasRegexEmOrdemAlbetica(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Declara e aloca um ponteiro de endereços
	int qtdaPadrao = arq->qtdaPalavras;
	char **palavrasPadrao = (char* *) malloc(qtdaPadrao * sizeof(char *));

	// Guarda os endereços das palavras que atendem o padrão na região aloca acima
	int cont = 0, estaNoPadrao = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		estaNoPadrao = !regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0);
		if (estaNoPadrao) {
			palavrasPadrao[cont] = arq->palavras[i].conteudo;
			cont++;
		}
	}
	regfree(&regex);

	// Realoca para o tamanho ideal
	qtdaPadrao = cont;
	palavrasPadrao = (char* *) realloc(palavrasPadrao, qtdaPadrao * sizeof(char *));

	// Ordena a lista de encereços e imprime ultizando esses
	qsort(palavrasPadrao, qtdaPadrao, sizeof(char *), comparaNomes);
	for (int i = 0; i < qtdaPadrao; i++) printf("%s\n", palavrasPadrao[i]);
	free(palavrasPadrao);
}

void imprimePalavraMaisProxima(Arquivo *arq, char *palavraParametro) {
	// Declara e aloca um ponteiro com endereços auxiliar à procura da palavra mais similar
	int altura = strlen(palavraParametro);
	int **matrizDeSimilaridade = (int* *) malloc(altura * sizeof(int *));

	// Encontra o índice de proximidade para cada palavra do arquivo, guardando, 
	//ao fim do laço, o índice da menor palavra dentre as palavras que tem o índice
	//de similaridade máximo
	int posMaisProxima = 0, maiorIndiceDeSimilaridade = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {

		// Define uma nova largura para matriz
		int largura = arq->palavras[i].tam;
		for (int k = 0; k < altura; k++) {
			// Aloca iniciando com zeros a memória para a matriz auxiliar ao processo
			matrizDeSimilaridade[k] = (int *) malloc(largura * sizeof(int));

			// Compara char a char de cada palavra do arquivo com a palavra parâmetro
			//gerando o indice de similaridade
			for (int j = 0; j < largura; j++) {
				// Copia o valor do elemento anterior da diagonal para o atual
				matrizDeSimilaridade[k][j] = ((k && j) != 0) ? matrizDeSimilaridade[k - 1][j - 1] : 0;

				// Verifica se ocorreu coincidência entre os chars
				if (arq->palavras[i].conteudo[j] == palavraParametro[k]) {
					matrizDeSimilaridade[k][j]++;
				}

				// Guarda o indice da palavra mais próxima até o momento, analisando
				//o grau de similaridade e, quando este aparece mais de uma vez,
				//também o tamanho da palavra atual
				if (matrizDeSimilaridade[k][j] > maiorIndiceDeSimilaridade) {
					maiorIndiceDeSimilaridade = matrizDeSimilaridade[k][j];
					posMaisProxima = i;
				}
				else if (matrizDeSimilaridade[k][j] == maiorIndiceDeSimilaridade) {
					if (arq->palavras[i].tam < arq->palavras[posMaisProxima].tam) {
						posMaisProxima = i;
					}
				}
			}
		}
		for (int k = 0; k < altura; k++) free(matrizDeSimilaridade[k]);
	}
	free(matrizDeSimilaridade);

	// Imprime a palavra mais próxima
	printf("%s\n", arq->palavras[posMaisProxima].conteudo);
}

void liberaMemoria(Arquivo *arq, Input *in) {
	// Libera HEAP alocada para o input
	free(in->nomeDoArq);
	free(in->padraoReg1);
	free(in->padraoReg2);
	free(in->padraoReg3);
	free(in->palavraW);

	// Libera HEAP alocada para o dados do arquivo
	for (int i = 0; i < arq->qtdaPalavras; i++) free(arq->palavras[i].conteudo);
	free(arq->palavras);
}

int main() {
	Input entrada;
	recebeEntrada(&entrada);

	Arquivo arq;
	leArquivo(&arq, &entrada);

	// Executa ações do programa
	printf("%d\n", arq.qtdaPalavras);
	printf("%s\n", arq.palavras[arq.posCurta].conteudo);
	printf("%s\n", arq.palavras[arq.posLonga].conteudo);

	// Imprime a quantidade de ocorrências para o padrão P1
	printf("%d\n", contaOcorrenciasRegex(&arq, entrada.padraoReg1));

	// Imprime a quantidade de palavras que são palíndromos no arquivo
	printf("%d\n", contaPalindromos(&arq));

	// Imprime a maior palavra do arquivo que atende ao padrão P2
	int posLongaP2 = encontraMaiorPalavraRegex(&arq, entrada.padraoReg2);
	printf("%s\n", arq.palavras[posLongaP2].conteudo);

	imprimeOcorrenciasRegexEmOrdemAlbetica(&arq, entrada.padraoReg3);
	imprimePalavraMaisProxima(&arq, entrada.palavraW);

	liberaMemoria(&arq, &entrada);
	return 0;
}