/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que recebe nomes e troca sobrenomes entre esses nomes
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//>Função que recebe uma string, incluindo espaços
//>Parâmetros: não há parâmetros
//>Retorno: um ponteiro que endereça a string
char *recebeNome() {
    
    char *string = (char *) malloc(8 * sizeof(char));
    int tamanho = 8;
     
    //Lê a string
    int i = 0;
    do {
        //Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	tamanho *= 2;
        	string = (char *) realloc(string, tamanho * sizeof(char));
        }
    	
    	//Recebe caracter por caracter
        string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != '\r' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}
//0	1 2  3  4 5 6 8 9  10
//D i o ' ' P e d r o '\0'

//>Função que adiciona o troca os sobrenomes entra as palavras simétricas
//>Parâmetros: um ponteiro duplo, endereçando a lista de nomes, e dois ints, com 
//a quantidade de trocas realizadas, e com o último índice da lista de nomes
//>Retorno: o ponteiro duplo endereçando a lista atualizada
char **trocaSobrenomes(char **lista, int qtdaDuplas, int fim) {

	//Laço que trata as linhas simétricas duas a duas, *¹guardando primeiramente 
	//o último sobrenome da primeira palavra, *²seguindo para a troca dos 
	//sobrenome, utilizando uma string temporária
	int primeira, segunda, temp;
	int tamSobrenome1, tamSobrenome2;

	for (int i = 0, j = fim; i < qtdaDuplas; i++, j--) {

	   //*¹//Iniciliza o processo no final do primeiro nome
		primeira = strlen(lista[i]) - 1;

		//Encontra a posição do começo do último sobrenome do nome da primeira 
		//palavra, enquanto conta o tamanho desse
		tamSobrenome1 = 0 ;
		while (lista[i][primeira] != ' ') {
			tamSobrenome1++;
			primeira--;
		} 
		primeira++;

		//Aloca uma string temporária que guarda o último sobrenome
		char *temporaria = (char *) malloc((tamSobrenome1 +  1) * sizeof(char));
		temporaria[tamSobrenome1] = '\0';

		//Escreve na string temporária
		temp = 0; 
		while (lista[i][primeira - 1] != '\0') {
			//Adiciona letra a letra(e o '\0') na string temporária
			temporaria[temp] = lista[i][primeira]; 

			temp++;
			primeira++;
		}
		//Volta o índice de zero para a primeira letra da último sobrenome
		primeira -= tamSobrenome1 + 1;

       //*²//Inicializa o processo no final da segundo nome
		segunda = strlen(lista[j]) - 1;
       	
		//Encontra a posição do começo do último sobrenome do nome da segunda 
		//palavra, enquanto conta o tamanho desse
		tamSobrenome2 = 0 ;
		while (lista[j][segunda] != ' ') {
			tamSobrenome2++;
			segunda--;
		} 
		segunda++;
		
		//Realoca os espaços para os novos nomes, com base em: tamanho antigo dos 
		//nomes, diferença entre os tamanhos do último sobrenome, e o '\0', 
		//colocando este no final da string
		int difTam = tamSobrenome1 - tamSobrenome2;
		int tamFinalNome1 = strlen(lista[i]) - difTam + 1; 
		int tamFinalNome2 = strlen(lista[j]) + difTam + 1;
		
		if (difTam < 0) difTam = -difTam;
		int tamTempNome1 = strlen(lista[i]) + difTam + 1; 
		int tamTempNome2 = strlen(lista[j]) + difTam + 1;

		lista[i] = (char *) realloc(lista[i], tamTempNome1 * sizeof(char));
		lista[j] = (char *) realloc(lista[j], tamTempNome2 * sizeof(char));
		
		//Coloca um ' ' na posição antiga do '\0', para bom procedimento do laço seguinte
		lista[i][strlen(lista[i])] = ' ';
		lista[j][strlen(lista[j])] = ' ';

		//Adiciona letra a letra(e o '\0') das trocas de sobrenome
		int qtdaTrocas = 2, contVoltas = 0;
		temp = 0; 
		while (qtdaTrocas > 0) {
			qtdaTrocas = 0; 
			
			//Adiciona o último sobrenome da segunda na primeira
			if (contVoltas < tamSobrenome2) {
				lista[i][primeira] = lista[j][segunda];
				qtdaTrocas++;
			}
			
			//Adiciona o último sobrenome da primeira na segunda
			if (contVoltas < tamSobrenome1) {
				lista[j][segunda] = temporaria[temp];
				qtdaTrocas++;
			}
				
			primeira++;
			segunda++;
			temp++;
			contVoltas++;
		}
		//Coloca o '\0' em seu devido lugar
		lista[i] = (char *) realloc(lista[i], tamFinalNome1 * sizeof(char));
		lista[j] = (char *) realloc(lista[j], tamFinalNome2 * sizeof(char));
		lista[i][tamFinalNome1 - 1] = '\0';
		lista[j][tamFinalNome2 - 1] = '\0';

		//Libera espaço de memória da string temporária
		free(temporaria);
	}

	return lista;
}

//Função principal
int main() {

	//Aloca memória na HEAP para a lista de nomes
	int qtdaNomes = 10;
	char **lista = (char* *) malloc(qtdaNomes * sizeof(char*)); 

	//Recebe a entrada de nomes até a presença do char de parada('$')
	int i = 0;
	char fim;
	do {

		//Realoca o espaço para a lista caso necessário
		if (i == qtdaNomes) {
			qtdaNomes *= 2;
			lista = (char* *) realloc(lista, qtdaNomes * sizeof(char*)); 
		}

		//Lê os nomes linha por linha
		lista[i] = recebeNome();

		//Guarda o último char de cada string para verificar se é o de parada
		fim = lista[i][strlen(lista[i]) - 1];

		//Retira o char de parada da última string
		if (fim == '$') {
			lista[i][strlen(lista[i]) - 1] = '\0';
			lista[i] = (char *) realloc(lista[i], (strlen(lista[i]) + 1) * sizeof(char));
		}

		i++;
	}while (fim != '$');
	//Realoca o espaço da lista para o tamanho certo
	qtdaNomes = i;
	lista = (char* *) realloc(lista, qtdaNomes * sizeof(char*));

	//Guarda o indice última linha da qual será copiado um sobrenome
	int qtdaDuplas = qtdaNomes / 2;

	//Adiciona os sobrenomes nos seu devidos lugares
	lista = trocaSobrenomes(lista, qtdaDuplas, qtdaNomes - 1);

	//Imprime os nomes alterados na ordem inicial
	for (int i = 0; i < qtdaNomes; i++) printf("%s\n", lista[i]);

	for (int i = 0; i < qtdaNomes; i++) free(lista[i]);
	free(lista);
	return 0;
}