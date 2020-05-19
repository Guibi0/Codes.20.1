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

//Estrutura para os dados de cada obra
typedef struct {
	char *nome;
	int numero;
}Dados;

//Estrutura para a lista de registros
typedef struct {
	Dados *objetos;
	int qtda;
}Lista;

//>Função que recebe uma string, incluindo espaços
//>Parâmetros: não há parâmetros
//>Retorno: um ponteiro que endereça a string
char *recebeLinha() {
    
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

    //Coloca o '\0' depois dos finalizadores('\n', '\r', EOF), para via uso da 
    //função strlen se consiga se verificar qual foi o finalizador da linha(na 
    //função "criaRegistros"), a inserção do '\0' será tratada na próxima função
    string[i] = '\0';
    string = (char *) realloc(string, (i + 1) * sizeof(char));

    return string;
}

//>Função que coloca cada parte da linha de entrada no seu devido lugar
//>Parâmetros: dois ponteiros, um endereçando a linha de entrada e outro a struct
//que guardará os dados de entrada de forma organizada
//>Retorno: o ponteiro enderençando os dados
Dados organizaLinha(char *linha, Dados objeto) {

	//Encontra a posição do último espaço da linha, enquanto guarda o inteiro já
	//convertido de char para int no devido local da struct  
	int i = strlen(linha) - 1; //inicializa i com a
	int potencia = 0, algarismoConvertido;
	objeto.numero = 0;

	//Garante que a converção se inicie no final do numero 
	while(linha[i] < '0' || linha[i] > '9' ) i--;

	while (linha[i] != ' ') {
		
		if(linha[i] == '-') {
			objeto.numero = -objeto.numero;

		}else {
			//Lê o número do fim para o começo convertendo o algarismos de char para
			//decimal, e incrementa no devido lugar utilizando potências de 10
			algarismoConvertido = linha[i] - 48;
			objeto.numero += algarismoConvertido * pow(10, potencia); 	
		}	

		i--;
		potencia++;
	}
	//Guarda a posição do último espaço
	int pos = i;

	//Insere o '\0' no lugar correto e realloca o tamanho para a string, passando
	//a string para seu devido lugar
	linha[pos] = '\0';
	objeto.nome = (char *) realloc(linha, (pos + 1) * sizeof(char));

	return objeto;
}

//>Função que recebe todos os dados do registro
//>parâmetros: não há parâmetros
//>Retorno: uma struct com a lista de registros
Lista criaRegistros() {

	Lista registros;  
	registros.objetos = (Dados *) malloc(10 * sizeof(Dados));
	registros.qtda = 10;

	//Recebe as linhas de entrada uma a uma 
	int i = 0;
	char fim;
	do {
		if (i == registros.qtda) {
			registros.qtda *= 2;
			registros.objetos = (Dados *) realloc(registros.objetos, 
				                                registros.qtda * sizeof(Dados));
		}

		char *linha = recebeLinha();

		//Guarda o último char da linha pra verificar se é "EOF"
		fim = linha[strlen(linha) - 1];

		//Coloca cada parte da entrada no seu devido lugar 
		linha[strlen(linha) - 1] = '\0'; 
		registros.objetos[i] = organizaLinha(linha, registros.objetos[i]);

		i++;
	}while (fim != EOF);

	//Guarda o tamanho da lista
	registros.qtda = i;
	registros.objetos = (Dados *) realloc(registros.objetos, registros.qtda * sizeof(Dados));

	//É necessário esse tratamento manual devido as linhas de entrada serem do 
	//tipo "<string> <int>" é necessário fazer um tratamento manual para colocar
	//o nome e o número nos seus devidos espaços de memória

	return registros;
}

//>Função que ordena registros de acordo com a escolha do usuário
//>Parâmetros: um struct que contém o dados dos registros e um int com a operação
//>Retorno: uma struct com os resgistros ordenados
Lista ordenaRegistros(Lista registros, int escolha) {

	if (escolha == 1) {
		//Cocktail sort que ordena de acordo com o nome de cada objeto resgistrado
		int inicio = 0, fim = registros.qtda; 
		int i, j, ordenado;
		Dados temp;

		do {
			i = inicio;
			ordenado = SIM;

			for (j = i + 1; j < fim; i++, j++) {
				
				if (strcmp(registros.objetos[i].nome, registros.objetos[j].nome) > 0) {
					
					ordenado = NAO;
					temp = registros.objetos[i];
					registros.objetos[i] = registros.objetos[j];
					registros.objetos[j] = temp;
				}
			}
			i--;

			for (j = i + 1; j > inicio; i--, j--) {
				
				if (strcmp(registros.objetos[i].nome, registros.objetos[j].nome) > 0) {
					
					ordenado = NAO;
					temp = registros.objetos[i];
					registros.objetos[i] = registros.objetos[j];
					registros.objetos[j] = temp;
				}
			}

			inicio++;
			fim--;
		}while(ordenado == NAO);

	}else if (escolha == 2) {
		//Cocktail sort que ordena de acordo com o número de cada objeto registrado
		int inicio = 0, fim = registros.qtda; 
		int i, j, ordenado;
		Dados temp;

		do {
			i = inicio;
			ordenado = SIM;

			for (j = i + 1; j < fim; i++, j++) {
				
				if (registros.objetos[i].numero > registros.objetos[j].numero) {
					
					ordenado = NAO;
					temp = registros.objetos[i];
					registros.objetos[i] = registros.objetos[j];
					registros.objetos[j] = temp;
				}
			}
			i--;

			for (j = i + 1; j > inicio; i--, j--) {
				
				if (registros.objetos[i].numero > registros.objetos[j].numero) {
					
					ordenado = NAO;
					temp = registros.objetos[i];
					registros.objetos[i] = registros.objetos[j];
					registros.objetos[j] = temp;
				}
			}

			inicio++;
			fim--;
		}while(ordenado == NAO);
	}

	return registros;
}

//>Função que imprime os registros já ordenados
//>Parâmetros: uma struct com os dados registrados
//>Retorno: não há retorno
void imprimeRegistros(Lista registros) {

	//Imprime os registros ordenados
	for (int i = 0; i < registros.qtda; i++) {
		printf("%d\t", registros.objetos[i].numero);
		printf("%s\n", registros.objetos[i].nome);
	}
}

//Função principal
int main() {

	//Recebe o tipo de ordenação
	int op;
	scanf("%d\n", &op);

	//Entrada dos dados para registro
	Lista registros = criaRegistros();

	//Ordena os registros de acordo com a operação escolhida
	registros = ordenaRegistros(registros, op);

	imprimeRegistros(registros);

	for (int i = 0; i < registros.qtda; i ++) free(registros.objetos[i].nome);
	free(registros.objetos);
	return 0;
}

