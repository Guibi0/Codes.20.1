/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que compara palavras de cinco formas diferentes
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Função que converte letras de uma palavra qualquer para letras minúsculas 
//>Parâmetros: um ponteiro para a palavra inicial
//>Retorno: um ponteiro que aponta para a palavra convertida
char *converte_minuscula(char *P) {
	//Declara ponteiro que será retornado 
	char *p;
	p = malloc(30 * sizeof(char));
		
	//Conversão	
	int i = 0;
	int cont = 1;
	while (cont != 0) {
		cont = 0;
		if (P[i] != '\0') {
			cont ++;

			p[i] = tolower(P[i]);
		}	

		i++;
	}

	return p;
}

//Função que encontra a maior palavra
//>Parâmetros: dois ponteiros que apontam para as palavras na HEAP
//>Retorno: inteiro que referência a palavra resposta ou o empate
int maior_palavra(char *p1, char *p2) {
	//Declara inteiro que será retornado
	int maior;

	//Define "maior" de acordo com os três casos
	if (strlen(p1) > strlen(p2)) maior = 1;
	else if (strlen(p2) > strlen(p1)) maior = 2;	
	//Caso para mesmo tamanho
	else maior = 0 ;

	return maior;
}

//Função que encontra a palavra que vem primeiro na ordem alfabética
//>Parâmetros: dois ponteiros que apontam para as palavras na HEAP
//>Retorno: inteiro que referência a palavra resposta ou o empate
int ordem_alfab(char *P1, char *P2) {
	//Declara inteiro que será retornado 
	int primeira_afalb;

	//Garante que todas as letras analisadas serão minúsculas
	char *p1 = converte_minuscula(P1);
	char *p2 = converte_minuscula(P2); 
		
	//Define "primeira" de acordo com os 3 casos
	int i = 0;
	while (i >= 0) {
		//Caso para palavras iguais
		if (strcmp(p1,p2) == 0) {
			primeira_afalb = 0;
			break;
		}

		//Comparando letra a letra de acordo com os valores ASCII
		if (p1[i] < p2[i]) {
			primeira_afalb = 1;
			break;
		}else if (p2[i] < p1[i]) {
			primeira_afalb = 2;
			break;
		}
		//*obs1: essas condições valem para o '\0'(fim) pois em ASCII ele é 0

		i++;
	}

	free(p1);
	free(p2);
	return primeira_afalb;
}

//Função que encontra a palavra com maior soma(a=0 ... z=25)
//>Parâmetros: dois ponteiros que apontam para as palavras na HEAP	
//>Retorno: inteiro que referência a palavra resposta ou o empate
int maior_soma_ASCII(char *P1, char *P2) {
	//Declara inteiro que será retornado 
	int maior_soma;

	//Garante que todas as letras analisadas serão minúsculas
	char *p1 = converte_minuscula(P1);
	char *p2 = converte_minuscula(P2); 

	//Faz as somas dos valores referentes a cada letra usando ASCII
	int soma1 = 0, soma2 = 0;
	int i = 0, cont = 1;
	while (cont != 0) {
		cont = 0;

		//Garante que sejam somente letras 
		if (p1[i] != '\0') {
			soma1 += p1[i] - 97; 
			cont++;

		}if (p2[i] != '\0') {
			soma2 += p2[i] - 97;
			cont++;
		}

		i++;
	}
	
	//Define "maior_soma" de acordo com os 3 casos
	if (soma1 > soma2) maior_soma = 1;
	else if (soma2 > soma1) maior_soma = 2;
	//Caso para mesma soma
	else maior_soma = 0;

	free(p1);
	free(p2);
	return maior_soma;
}

//Função que encontra a palavra com maior nº de repetição de uma letra escolhida 
//>Parâmetros: dois ponteiros que apontam para as palavras na HEAP	
//>Retorno: inteiro que referência a palavra resposta ou o empate
int mais_repet_letra(char *P1, char *P2) {
	//Recebe a letra a ser analisada
	char L;
	scanf(" %c", &L);
	//Garante que a letra vai ser analisada na forma minúscula
	char l = tolower(L);

	//Garante que todas as letras analisadas serão minúsculas
	char *p1 = converte_minuscula(P1);
	char *p2 = converte_minuscula(P2); 

	//Declara inteiro que será retornado 
	int maior_rept;

	//Conta a quantidade de repetições da letra em cada palavra
	int qtd1 = 0, qtd2 = 0;
	int i = 0, cont = 1;
	while (cont != 0) {
		cont = 0;
		
		//Garante a leitura somente de letras, comparando via ASCII
		if (p1[i] != '\0') {
			cont++;

			if (p1[i] == l) qtd1++;		
		}
		if (p2[i] != '\0') {
			cont++;

			if (p2[i] == l) qtd2++;	
		}

		i++;
	}

	//Define "maior_rept" de acordo com os 3 casos
	if (qtd1 > qtd2) maior_rept = 1;
	else if (qtd2 > qtd1) maior_rept = 2;

	//Caso para a mesma quantidade 
	else maior_rept = 0;

	free(p1);
	free(p2);
	return maior_rept;
}

//Função que encontra a palavra na qual uma letra escolhida aparece primeiro
//>Parâmetros: dois ponteiros que apontam para as palavras na HEAP	
//>Retorno: inteiro que referência a palavra resposta ou o empate
int aparece_primeiro(char *P1, char *P2) {
	//Recebe a letra a ser analisada
	char L;
	scanf(" %c", &L);
	//Garante que a letra vai ser analisada na forma minúscula
	char l = tolower(L);

	//Garante que todas as letras analisadas serão minúsculas
	char *p1 = converte_minuscula(P1);
	char *p2 = converte_minuscula(P2); 

	//Declara inteiro que será retornado 
	int primeira_aparicao; 

	//Define "primeira_aparicao" de acordo com os 3 casos
	int i = 0, cont = 1, aparicaototal = 0;
	while (cont != 0) {
		cont = 0;

		//Declara inteiros que confere se houve aparicao da letra
		int aparece_em1 = 0, aparece_em2 = 0;	
		
		//Garante a leitura somente de letras, comparando via ASCII
		if (p1[i] != '\0') {
			cont++;

			if (p1[i] == l) {
				aparicaototal++;
				aparece_em1++;		
			}
		}
		if (p2[i] != '\0') {
			cont++;

			if (p2[i] == l) {
				aparicaototal++;
				aparece_em2++;	
			}
		}

		//Define a string analisando a quantidade de aparições por volta do laço	
		if (aparicaototal == 2) {
			primeira_aparicao = 0;
			break;
		}
		else if (aparicaototal == 1){
			if (aparece_em1 == 1) {
				primeira_aparicao = 1;
				break;
			}else if (aparece_em2 == 1) {
				primeira_aparicao = 2;
				break;
			}	
		}
		
		i++;
	}
	
	if (aparicaototal == 0) primeira_aparicao = 0;

	free(p1);
	free(p2);
	return primeira_aparicao;
}

//Função principal
int main() {
	//Recebe a operação a ser feita 
	int op;
	scanf("%d", &op);

	//Recebe as duas palavras a serem comparada 
	char *palavra1, *palavra2;  
	palavra1 = malloc(30 * sizeof(char));
	palavra2 = malloc(30 * sizeof(char));
	scanf("%s %s", palavra1, palavra2);

	//Declara um inteiro para a resultado da comparação
	int resultado;

	//Induz à operação escolhida, buscando um função para definir o resultado
	if (op == 1) resultado = maior_palavra(palavra1, palavra2);
	else if (op == 2) resultado = ordem_alfab(palavra1, palavra2);
 	else if (op == 3) resultado = maior_soma_ASCII(palavra1, palavra2);
 	else if (op == 4) resultado = mais_repet_letra(palavra1, palavra2);
 	else if (op == 5) resultado = aparece_primeiro(palavra1, palavra2);

	printf("%d\n", resultado);

	free(palavra1);
	free(palavra2);
	return 0;
}
