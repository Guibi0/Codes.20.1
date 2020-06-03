/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que simula um sistema de uma biblioteca
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIM 1
#define NAO 0

// Estrutura para os dados de cada livro
typedef struct {
	char *nome;
	int qtdaDeDias;
	int alugado;
} Dados;

// Estrutura para conjunto de lista de livros
typedef struct {
	Dados *obras;
	int qtda;	
} Lista;

// Estrutura para todas as informações para o atendimento de um usuário
typedef struct {
	Lista acervo;
	Lista alugados;
} Biblioteca;

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	 -não há parâmetros
// >Retorno: 
//	 -um ponteiro que endereça a string
char *recebeNome() {
    char *string = (char *) malloc(TAMANHOINICIAL * sizeof(char));
    int tamanho = TAMANHOINICIAL;
     
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
        if(string[i] == '\r') string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

// >Função que organiza o acervo da biblioteca
// >Parâmetros: 
//	 -um int com a quantidade de livros
// >Retorno: um ponteiro endereçando a lista de livros do acervo 
Dados *criaAcervo(int qtdaLivros) {

	Dados *obras = (Dados *) malloc(qtdaLivros * sizeof(Dados)); 

	// Define os dados de cada livro
	for (int i = 0; i < qtdaLivros; i++) {

		// Nome do livro
		obras[i].nome = recebeNome();

		// O tempo em dias pelo qual o livro pode ser alugado
		scanf("%d\r\n", &obras[i].qtdaDeDias);

		// Define, a priori, todos os livros como não alugados 
		obras[i].alugado = NAO;
	}

	return obras;
}	

// >Função que realiza o aluguel de um livro
// >Parâmetros: 
//	 -uma struct com o dados atuais da biblioteca
// >Retorno: 
//	 -a struct atualizada
Biblioteca alugarLivro(Biblioteca biblio) {
	
	// Recebe o livro procurado
	printf("Digite o livro que voce procura:\n");
	char *livroDesejado = recebeNome();

	// Procura o livro no acervo, verificando se já está alugado ou não 	
	int i, livroPresente = NAO, jaAlugado;
	for (i = 0; i < biblio.acervo.qtda; i++) {	
		if (strcmp(biblio.acervo.obras[i].nome, livroDesejado) == 0) {
			livroPresente = SIM;
			jaAlugado = biblio.acervo.obras[i].alugado;
			break;
		}
	}
		
	// Trata os casos	
	if (livroPresente == NAO) {
		printf("Livro nao encontrado na biblioteca\n");

	}else {
		// Avisa caso o limite de livros já tenha sido antingido
		if (biblio.alugados.qtda == 10) {
			printf("Voce ja tem 10 livros alugados\n");

		}else {
			if (jaAlugado != NAO) {
				printf("Livro ja alugado\n");

			}else {
				biblio.acervo.obras[i].alugado = SIM;

				// Guarda livro na lista de alugados, reajustando o tamanho
				biblio.alugados.obras[biblio.alugados.qtda] = biblio.acervo.obras[i];
				biblio.alugados.qtda++;

	 			printf("%s alugado com sucesso\n", livroDesejado);
			}
		}	
	}

	free(livroDesejado);
	return biblio;
}

// >Função que mostra a lista ordenada de livros alugados caso essa exista
// >Parâmetros: 
//	 -uma struct com os dados dos livros alugados
// >Retorno: 
// 	 -não há retornos
void mostrarAlugados(Lista alugados) {

	if (alugados.qtda == 0) printf("Voce nao tem livros alugados\n");
	else {
		printf("Voce tem %d livro(s) alugado(s)\n", alugados.qtda);

		for (int i = 0; i < alugados.qtda; i++) {
			printf("Livro nome: %s\n", alugados.obras[i].nome);
			printf("Devolve-lo daqui %d dias\n", alugados.obras[i].qtdaDeDias);
		}
	}
}

// >Função que realiza a devolução de um livro caso esse esteja alugado
// >Parâmetros: 
// 	 -uma struct com o dados atuais da biblioteca
// >Retorno: 
// 	 -a struct atualizada
Biblioteca devolverLivro(Biblioteca biblio) {

	// Recebe o livro procurado
	printf("Digite o livro que deseja devolver:\n");
	char *livroDevolvido = recebeNome();

	// Procura o nome na lista de alugados
	int livro_presente = NAO, posDevolvido = 0;
	while (posDevolvido < biblio.alugados.qtda) {

		if (strcmp(livroDevolvido, biblio.alugados.obras[posDevolvido].nome) == 0) {
			livro_presente = SIM;
			break;
		}

		posDevolvido++;
	}

	// Trata os casos
	if (livro_presente == NAO) printf("Voce nao possui esse livro\n");

	else {

		// Encontra o livro no acervo e muda o estado de aluguel dele
		int i = 0;
		while (i < biblio.acervo.qtda) {
			if (strcmp(livroDevolvido, biblio.acervo.obras[i].nome) == 0) {
				biblio.acervo.obras[i].alugado = NAO;
				break;
			}

			i++;		
		}
		printf("Livro %s foi devolvido com sucesso\n", biblio.acervo.obras[i].nome);

		// Atualiza a dados da lista de alugados 
		biblio.alugados.qtda--;
		biblio.alugados.obras[posDevolvido].alugado = NAO;

		// Rearranja de forma ordenada a lista de alugados em um novo ponteiro
		for (int nova = 0, ant = 0; nova < biblio.alugados.qtda; ant++) {

			if (biblio.alugados.obras[ant].alugado != NAO) {

				biblio.alugados.obras[nova] = biblio.alugados.obras[ant];
				nova++;
			}
		}	
	}

	free(livroDevolvido);
	return biblio;
}

// >Função fecha o programa e desaloca memória HEAP utilizada
// >Parâmetros: 
// 	 -uma struct com todos os dados atuais da biblioteca
// >Retorno: 
//	 -não há retornos
void saiEDesaloca(Biblioteca biblio) {

	// Printa "despedida"
	printf("Programa finalizado\n");

	// Desaloca as strings com os nomes dos todos os livros
	for (int i = 0; i < biblio.acervo.qtda; i++) {
		
		free(biblio.acervo.obras[i].nome);
	}

	// Desaloca as listas de dados do acervo e dos alugados
	free(biblio.acervo.obras);
	free(biblio.alugados.obras);
}

// Função principal
int main() {

	// Cria a biblioteca com uma struct com todas suas informações
	Biblioteca biblio;
	
	// Recebe dados sobre o acervo da biblioteca
	scanf("%d\r\n", &biblio.acervo.qtda);
	biblio.acervo.obras = criaAcervo(biblio.acervo.qtda);

	// Prepera lista guardar os livros alugados(máxixo=10) de forma ordena
	biblio.alugados.obras = (Dados *) malloc(10 * sizeof(Dados));
	biblio.alugados.qtda = 0;

	// Laço principal do programa
	int op = 0;
	while (op < 4) {

		// Recebe a operação
		scanf("%d\r\n", &op);

		// Trata as operação
		if (op == 1) {
			biblio = alugarLivro(biblio);

		}else if(op == 2) {
			mostrarAlugados(biblio.alugados);

		}else if (op == 3) {
			biblio = devolverLivro(biblio);
		}
	}

	saiEDesaloca(biblio);

	return 0;
}		