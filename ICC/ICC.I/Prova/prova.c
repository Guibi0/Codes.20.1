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

#define SIM 1
#define NAO 0
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

// Função que lê strings
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
        if(string[i] == '\r') string[i] = fgetc(stdin);

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
		arq->palavras[i].tam = strlen(arq->palavras[i].conteudo);

		// Ignora as linhas sem palavras
		if (strcmp(arq->palavras[i].conteudo, "")) i++;

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
		int inicio = 0, fim = arq->palavras[i].tam - 1;
		
		// Verifica se a palavra não é palíndromo e decrementa o contador(inicialmente 
		//igual a quantidade total de palavras)
		while (inicio <= fim) {
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

//Função que conta quantas palavras atendem ao padrão P1
int regexP1(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Verifica se a palavra não obedece o padrão e decrementa o contador(inicialmente
	//igual a quantidade total de palavras)
	int cont = arq->qtdaPalavras;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		if (regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0)) cont--;
	}
	regfree(&regex);

	return cont;
}

//Função que encontra qual a maior palavra que atende a padrão P2
int regexP2(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Verifica dentre as palavras que atendem o padrão qual é a mais longa
	int posLonga = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		if (!regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0)) {
			if (arq->palavras[i].tam > arq->palavras[posLonga].tam) posLonga = i;
		}
	}
	regfree(&regex);

	return posLonga;
}

int comparaNomes(const void *a, const void *b){
	return (strcmp((*(char* *)a), (*(char* *)b)));
}

//Função que encontra quais palavras atendem a padrão P3, imprimindo-as em ordem alfabética
void regexP3(Arquivo *arq, char *padrao) {
	// Prepara a variável "regex" para as operações com a "regex.h"
	regex_t regex;
	regcomp(&regex, padrao, REG_EXTENDED);

	// Declara e aloca um ponteiro de endereços
	int qtdaPadrao = arq->qtdaPalavras;
	char **palavrasPadrao = (char* *) malloc(qtdaPadrao * sizeof(char *));
	// Guarda os endereços das palavras que atendem o padrão na região aloca acima
	int cont = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		if (!regexec(&regex, arq->palavras[i].conteudo, 0, NULL, 0)) {
			palavrasPadrao[cont] = arq->palavras[i].conteudo;
			cont++;
		}
	}
	regfree(&regex);

	// Realoca para o tamanho ideal
	qtdaPadrao = cont;
	palavrasPadrao = (char* *) realloc(palavrasPadrao, qtdaPadrao * sizeof(char *));

	// Ordena e imprime
	qsort(palavrasPadrao, qtdaPadrao, sizeof(char *), comparaNomes);
	for (int i = 0; i < qtdaPadrao; i++) printf("%s\n", palavrasPadrao[i]);
	free(palavrasPadrao);
}

void encontraPalavraMaisProxima(Arquivo *arq, char *palavraParametro) {
	// Declara e aloca um ponteiro com endereços auxiliar à procura da palavra mais similar
	int altura = strlen(palavraParametro);
	int **matrizDeSimilaridade = (int* *) calloc(altura, sizeof(int *));

	// Encontra o índice de proximidade para cada palavra do arquivo, guardando, 
	//ao fim do laço, o índice da menor palavra dentre as palavras que tem o índice
	//de similaridade máximo
	int posMaisProxima = 0, maiorIndiceDeSimilaridade = 0;
	for (int i = 0; i < arq->qtdaPalavras; i++) {
		// Define uma nova largura para matriz
		int largura = arq->palavras[i].tam;
		for (int k = 0; k < altura; k++) {
			// Aloca iniciando com zeros a memória para a matriz auxiliar ao processo
			matrizDeSimilaridade[k] = (int *) calloc(largura, sizeof(int));

			// Compara char a char de cada palavra do arquivo com a palavra parâmetro
			//gerando o indice de similaridade
			for (int j = 0; j < largura; j++) {
				// Copia o valor do elemento anterior da diagonal para o atual
				if (k != 0 && j != 0) {
					matrizDeSimilaridade[k][j] = matrizDeSimilaridade[k - 1][j - 1];
				}

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
	// Verifica a quantidade de ocorrências para o padrão P1
	printf("%d\n", regexP1(&arq, entrada.padraoReg1));
	// Conta e imprime a quantidade de palavras
	printf("%d\n", contaPalindromos(&arq));
	// Busca a maior palavra do arquivo que atende ao padrão P2
	int posLongaP2 = regexP2(&arq, entrada.padraoReg2);
	printf("%s\n", arq.palavras[posLongaP2].conteudo);
	// Imprime as palavras do arquivo que atendem ao padrão P3 em ordem alfabética
	regexP3(&arq, entrada.padraoReg3);
	// Encontra a palavra mais próxima da palavra W e imprime ela
	encontraPalavraMaisProxima(&arq, entrada.palavraW);

	liberaMemoria(&arq, &entrada);
	return 0;
}