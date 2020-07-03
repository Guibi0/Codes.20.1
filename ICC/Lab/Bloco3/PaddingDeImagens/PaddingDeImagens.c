 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que adiciona simula a adição de bordas em uma imagem
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

// Estrutura para os dados de uma imagem
typedef struct {
	int **conteudo;
	int largura;
	int altura;	
}Imagem;

// >Função que cria a imagem com borda da seguinte maneira:
//   ********           ********
//   ********      |\   *pppppp* >'*' a composição da borda 
//   ********  ----- \  *pppppp*	
//   ********  ----- /  *pppppp* >'p' os pixels da imagem
//   ********      |/   *pppppp*
//   ********           ********
// >Parâmetros: 
//	-uma struct com a imagem original
//	-um int com o tamnanho da borda
// >Retorno:
//	-um ponteiro endereçando a imagem final
int **adicionaBorda(Imagem original, int tamBorda) {
	// Aloca uma matriz com tamanho ideal para borda preenchida com zeros
	int **final = (int* *) calloc(original.altura + 2 * tamBorda, sizeof(int*));
	for (int i = 0; i < original.altura + 2 * tamBorda; i++) {
		final[i] = (int *) calloc(original.largura + 2 * tamBorda, sizeof(int));
	}

	// Inicializa um laço a partir da posição onde a imagem deve ser colocada
	for (int a = 0, i = tamBorda; i < tamBorda + original.altura; a++, i++) {
		
		for (int b = 0, j = tamBorda; j < tamBorda + original.largura; b++, j++) {
			final[i][j] = original.conteudo[a][b];
		}
	}

	return final;
}

//> Função que cria a imprime a saída
//> Parâmetros: 
//	-uma struct com a imagem original
//	-um ponteiro duplo endereçando a imagem final
//	-um int com o tamanho da borda	
//> Retorno:
//	-não há retorno
void imprimeSaida(Imagem original, int **final, int tamBorda) {
	// Imprime a imagem com borda 
	for (int i = 0; i < original.altura + 2 * tamBorda; i++) {
		
		for (int j = 0; j < original.largura + 2 * tamBorda; j++) {
			printf("%d ", final[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	// Imprime a imagem original
	for (int i = 0; i < original.altura; i++) {
		
		for (int j = 0; j  original.largura; j++) {
			printf("%d ", original.conteudo[i][j]);
		}
		printf("\n");
	}
}

// Função principal
int main() {

	// Declara uma estrutura para a imagem
	Imagem imagem;

	// Recebe as dimensões da imagem
	scanf("%d\n%d", &imagem.largura, &imagem.altura);

	// Aloca e recebe o conteúdo da imagem
	imagem.conteudo = (int* *) malloc(imagem.altura * sizeof(int*));
	for (int i = 0; i < imagem.altura; i++) {
		
		imagem.conteudo[i] = (int *) malloc(imagem.largura * sizeof(int));
		for (int j = 0; j < imagem.largura; j++) scanf("%d", &imagem.conteudo[i][j]);
	}
	// Recebe o tamnho da borda a ser adicionada
	int tamBorda;
	scanf("%d", &tamBorda);

	// Cria a imagem final com borda	
	int **imagemFinal = adicionaBorda(imagem, tamBorda);

	// Imprime a imagem com borda seguida da imagem original
	imprimeSaida(imagem, imagemFinal, tamBorda);

	for (int i = 0; i < imagem.altura + 2 * tamBorda; i++) free(imagemFinal[i]);
	free(imagemFinal);
	free(imagem.conteudo);
	return 0;
}