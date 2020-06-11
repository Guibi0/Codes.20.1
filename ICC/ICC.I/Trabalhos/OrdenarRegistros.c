/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que ordena registro de forma lexicográfica e numérica
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIM 1
#define NAO 0
#define QTDAINICIAL 100
#define TAMANHOINICIAL 100

// Estrutura para os dados de cada obra
typedef struct {
	char *nome;
	int numero;
}Dados;

// Estrutura para a lista de registros
typedef struct {
	Dados *objetos;
	int qtda;
}Lista;

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//	 -não há parâmetros
// >Retorno: 
//	 -ponteiro que endereça a string
char *recebeLinha() {
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
        if(string[i] == '\r') string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

// >Função que coloca cada parte da linha de entrada no seu devido lugar
// >Parâmetros: 
//	 -ponteiro endereçando a linha de entrada
//	 -struct que guardará os dados de entrada de forma organizada
// >Retorno: 
//	 -a struct com os dados
Dados organizaLinha(char *linha, Dados objeto) {
	// Garante que a conversão se inicie no final do numero 
	int i = strlen(linha); // inicializa i com a posição do final da linha
	while (linha[i] < '0' || linha[i] > '9' ) i--;

	// Encontra a posição do último espaço da linha, enquanto guarda o inteiro já
	//convertido de char para int no devido local da struct  
	int potencia = 0, algarismoConvertido;
	objeto.numero = 0;
	while (linha[i] != ' ') {		
		if(linha[i] == '-') {
			objeto.numero = -objeto.numero;

		}else {
			// Lê o número do fim para o começo convertendo(com ) o algarismos de char 
			//para decimal, e incrementa no devido lugar utilizando potências de 10
			algarismoConvertido = linha[i] - '0';
			objeto.numero += algarismoConvertido * pow(10, potencia); 	
		}	

		i--;
		potencia++;
	}
	// Guarda a posição do último espaço
	int pos = i;

	// Insere o '\0' no lugar correto e realloca o tamanho para a string, passando
	// a string para seu devido lugar
	linha[pos] = '\0';
	objeto.nome = (char *) realloc(linha, (pos + 1) * sizeof(char));

	return objeto;
}

// >Função que recebe todos os dados do registro
// >Parâmetros: 
//	 -não há parâmetros
// >Retorno: 
//	 -struct com a lista de registros
Lista criaRegistros() {
	Lista registros;  
	registros.objetos = (Dados *) malloc(QTDAINICIAL * sizeof(Dados));
	registros.qtda = QTDAINICIAL;

	// Recebe as linhas de entrada uma a uma, até o fim do arquivo
	int i = 0;
	do {
		if (i == registros.qtda) {
			registros.qtda *= 2;
			registros.objetos = (Dados *) realloc(registros.objetos, registros.qtda * sizeof(Dados));
		}

		char *linha = recebeLinha();

		// Coloca cada parte da entrada no seu devido lugar 
		linha[strlen(linha)] = '\0'; 
		registros.objetos[i] = organizaLinha(linha, registros.objetos[i]);
		// É necessário esse tratamento manual(organizaLinha) devido as linhas de 
		//entrada serem do tipo "<string> <int>" é necessário fazer um tratamento 
		//manual para colocar o nome e o número nos seus devidos espaços de memória

		i++;
	}while (!feof(stdin));
	// Guarda o tamanho da lista
	registros.qtda = i;
	registros.objetos = (Dados *) realloc(registros.objetos, registros.qtda * sizeof(Dados));

	return registros;
}

// >Função auxiliar à função "qsort" para ordenação alfabética
int comparaNomes(const void *a, const void *b){
  return (strcmp((*(Dados*)a).nome, (*(Dados*)b).nome));
}

// >Função auxiliar à função qsort para ordenação numérica crescente
int comparaNumeros(const void *a, const void *b){
  return ((*(Dados*)a).numero - (*(Dados*)b).numero);
}

// >Função que imprime os registros já ordenados
// >Parâmetros: 
//	 -struct com os dados registrados
// >Retorno: 
//	 -não há retorno
void imprimeRegistros(Lista registros) {
	// Imprime os registros ordenados
	for (int i = 0; i < registros.qtda; i++) {
		printf("%d\t", registros.objetos[i].numero);
		printf("%s\n", registros.objetos[i].nome);
	}
}

// Função principal
int main() {
	// Recebe o tipo de ordenação
	int op;
	scanf("%d\n", &op);

	// Entrada dos dados para registro
	Lista registros = criaRegistros();

	// Ordena os registros de acordo com a operação escolhida
	if (op == 1) qsort(registros.objetos, registros.qtda, sizeof(Dados), comparaNomes);
	else if (op == 2) qsort(registros.objetos, registros.qtda, sizeof(Dados), comparaNumeros);

	imprimeRegistros(registros);

	for (int i = 0; i < registros.qtda; i++) free(registros.objetos[i].nome);
	free(registros.objetos);
	return 0;
}