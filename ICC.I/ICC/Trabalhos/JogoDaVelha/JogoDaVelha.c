 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que executa um jogo da velha de 2 jogadores
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define sim 1
#define nao 0

//>Função que aloca e define a matriz para o jogo
char **define_matriz() {

	//Aloca 
	char **matriz = (char* *) malloc(3 * sizeof(char*));
	for (int i = 0; i < 3; i++) {
		matriz[i] = (char *) malloc(3 * sizeof(char));
	}

	//Define 
	char pos = '1';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++, pos++) matriz[i][j] = pos;
	}

	return matriz;
}

//>Função que libera uma matriz de inteiros na HEAP
void libera_matriz(char **matriz, int num_linhas) {
	
	for (int i = 0; i < num_linhas; i++) free(matriz[i]);
	free(matriz);	
}

//>Função que imprime o jogo 
void imprime_jogo(char **matriz) {

	//Imprime 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			printf("%c   |", matriz[i][j]);
		}

		printf("\n----+----+-----\n");
	}
}

//>Função que confere a validade de uma jogada 
int confere_validade(char **matriz, int posicao) {

	//Vai na posição e confere se ela já foi marcada
	int confere = posicao;
	int validade = nao;
 	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			confere --;
			
			if (confere == 0) {
				
				if (matriz[i][j] != 'X' && matriz[i][j] != 'O') {
					validade = sim;
				}
			}
		}
	} 

	return validade;
}

//>Função que recebe e confere a validade de um jogada 
int recebe_jogada(char **matriz) {
	
	//Recebe a jogada, até que essa seja válida
	int jogada_vale;
	int pos_da_jogada;
	do {
		scanf("%d", &pos_da_jogada); 

		jogada_vale = confere_validade(matriz, pos_da_jogada);

		if (jogada_vale == nao) {
			printf("Jogada inválida! Escolha outra casa.\n"); 
		}

	}while (jogada_vale == nao);
	
	return pos_da_jogada;		
}


//>Função que realiza jogada adcionando X's e O's ao jogo
char **roda_jogada(char **matriz, char jogador_da_vez) {

	//Introduz o jogador
	printf("Escolha um número para jogar, jogador %c!\n", jogador_da_vez);

	//Recebe uma jogada válida
	int jogada = recebe_jogada(matriz);

	//Realiza a jogada
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			jogada--;

			if (jogada == 0) matriz[i][j] = jogador_da_vez;
		}
	} 

	imprime_jogo(matriz);

	return matriz;
}	

//>Função que analisa as linhas 
char confere_linhas(char **matriz, char jogador_da_vez) {

	char resultado;
	
	for (int i = 0; i < 3; i++) {
		
		if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
			resultado = jogador_da_vez;
			break;

		}else resultado = 'i';
	}

	return resultado;
}

//>Função que analisa as colunas 
char confere_colunas(char **matriz, char jogador_da_vez) {

	char resultado;

	for (int j = 0; j < 3; j++) {
		
		if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j]) {
			resultado = jogador_da_vez;
			break;

		}else resultado = 'i';
	}

	return resultado;
}

//>Função que analisa as diagonais 
char confere_diagonais(char **matriz, char jogador_da_vez) {

	char resultado;

 	if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
 		resultado = jogador_da_vez;

	}else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
		resultado = jogador_da_vez;

	}else resultado = 'i';

	return resultado;
}

//>Função que verifica se alguém ganhou ou se deu velha
char confere_resultado(char **matriz, char jogador_da_vez) {

	char resultado;

	//Analisa as linhas
	resultado = confere_linhas(matriz, jogador_da_vez);

	if (resultado == 'i') {
		//Analisa as colunas
		resultado = confere_colunas(matriz, jogador_da_vez); 
		
		if (resultado == 'i') {	
			//Analisa as diagonais
			resultado = confere_diagonais(matriz, jogador_da_vez);
		}	
	}	

	return resultado;
}

//>Função que roda o jogo
char roda_o_jogo(char ** matriz) {

	//Roda o jogo, dando início as jogadas com a vez do jogador X
	int rodada = 1;
	char resultado = 'i'; //inexistente
	char jogador;
	while (resultado == 'i') {
		if (rodada % 2 == 1) jogador = 'X';
		else jogador = 'O';
		
		//Imprime inicialização
		if (rodada == 1) {
			imprime_jogo(matriz);
			printf("Jogo da velha!\n");
		}	

		//Roda uma jogada	
		matriz = roda_jogada(matriz, jogador);

		//Procura um vencedor		
		if (rodada >= 5) resultado = confere_resultado(matriz, jogador);

		//Passa para a próxima rodada trocando o jogador 
		rodada++;

		//Fim do jogo por "velha"	
		if (resultado == 'i' && rodada == 10) resultado = 'V';
	}

	return resultado;
}

//Função principal
int main() {

	//Aloca o jogo
	char **jogo = define_matriz();

	//Inicia o jogo em busca de um resultado
	char resultado = roda_o_jogo(jogo);

	//Imprime o resultado do jogo
	if (resultado == 'V') printf("Deu velha!\n");
	else printf("Fim do jogo! O jogador %c venceu!\n", resultado);

	libera_matriz(jogo, 3);
	return 0;
}