/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que recebe nomes e adiciona sobrenomes em alguns desses nomes
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOINICIAL 100

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	-não há parâmetros
// >Retorno: 
//	-ponteiro que endereça a string
char *recebeNome() {
    int tamanho = TAMANHOINICIAL;
    char *string = (char *) malloc(tamanho * sizeof(char));
     
    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	tamanho *= 2;
        	string = (char *) realloc(string, tamanho * sizeof(char));
        }
    	
    	// Recebe caracter por caracter
        string[i] = fgetc(stdin);

        // Lê o '\n' pós '\r'
        if (string[i] == '\r') string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

// >Função que adiciona o último sobrenome de nomes de índice par de uma lista no
//final dos nomes de índice ímpar
// >Parâmetros: 
//	-um ponteiro duplo endereçando a lista de nomes
//	-um int com o número da última linha que tem um sobrenome copiado
// >Retorno: 
//	-o ponteiro duplo endereçando a lista atualizada
char **adicionaSobrenomes(char **lista, int ultima) {

	// Laço que trata as linhas duas a duas
	int j, k, tamanho;
	for (int i = 0; i < ultima; i += 2) {

		// Iniciliza o processo no final do nome de índice par
		j = strlen(lista[i]) - 1;

		// Encontra a posição do começo do último sobrenome do nome de índice par
		while (lista[i][j] != ' ') j--;
		j++;

		// Realoca o espaço para o nome de índice ímpar
		tamanho = strlen(lista[i + 1]) + 11;
		lista[i + 1] = (char *) realloc(lista[i + 1], tamanho * sizeof(char));;

		// Inicia com um ' ' no final do nome de índice ímpar
		k = strlen(lista[i + 1]);
		lista[i + 1][k++] = ' ';
		while (lista[i][j - 1] != '\0') {
			
			// Realoca caso necessário
			if (k == tamanho) {
				tamanho += 10;
				lista[i + 1] = (char *) realloc(lista[i + 1], tamanho * sizeof(char));;
			}

			// Adiciona letra a letra(e o '\0') do sobrenome na devida posição
			lista[i + 1][k] = lista[i][j]; 

			k++;
			j++;
		}
		// Realoca o espaço do nome para o tamanho certo
		tamanho = k;
		lista[i + 1] = (char *) realloc(lista[i + 1], tamanho * sizeof(char));
	}

	return lista;
}

// Função principal
int main() {
	// Aloca memória na HEAP para a lista de nomes
	int qtdaNomes = 10;
	char **lista = (char* *) malloc(qtdaNomes * sizeof(char*)); 

	// Recebe a entrada de nomes até a presença do char de parada('$')
	int i = 0;
	char fim;
	do {

		// Realoca o espaço para a lista caso necessário
		if (i == qtdaNomes) {
			qtdaNomes *= 2;
			lista = (char* *) realloc(lista, qtdaNomes * sizeof(char*)); 
		}

		// Lê os nomes linha por linha
		lista[i] = recebeNome();

		// Guarda o último char de cada string para verificar se é o de parada
		fim = lista[i][strlen(lista[i]) - 1];

		// Retira o char de parada da última string
		if (fim == '$') {
			lista[i][strlen(lista[i]) - 1] = '\0';
			lista[i] = (char *) realloc(lista[i], (strlen(lista[i]) + 1) * sizeof(char));
		}

		i++;
	}while (fim != '$');
	// Realoca o espaço da lista para o tamanho certo
	qtdaNomes = i;
	lista = (char* *) realloc(lista, qtdaNomes * sizeof(char*));

	// Guarda o indice última linha da qual será copiado um sobrenome
	int ultima;
	if (qtdaNomes % 2 == 0) ultima = qtdaNomes - 1;
	else ultima = qtdaNomes - 2;

	// Adiciona os sobrenomes nos seu devidos lugares
	lista = adicionaSobrenomes(lista, ultima);

	// Imprime os nomes alterados na ordem inicial
	for (int i = 0; i < qtdaNomes; i++) printf("%s\n", lista[i]);

	for (int i = 0; i < qtdaNomes; i++) free(lista[i]);
	free(lista);
	return 0;
}
