/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que substitui uma palavras em frases
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define sim 1
#define nao 0

//>Função que recebe uma string, incluindo espaços
//>Parâmetros: não há parâmetros
//>Retorno: um ponteiro que endereça a string
char *recebe_string() {
    
    char *string = (char *) malloc(8 * sizeof(char));
    int tamanho = 8;
     
    //Lê a string
    int i = 0;
    do {
        //Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	string = (char *) realloc(string, 2 * tamanho * sizeof(char));
        	tamanho *= 2;
        }
    	
    	//Recebe caracter por caracter
        string[i] = fgetc(stdin);
        i++;

    }while (string[i - 1] != '\n' && string[i - 1] != EOF);
    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

//>Função que confere se a existe uma palavra em um pedaço da frase 
//>Parâmetros: 2 ponteiros, um para a palavra outro para frase, e 2 ints com as 
//posições para o início da analise 		
//>Retorno: um int com a situação com a relação a presença
int confere_presenca(char *palavra, int pos_p, char *frase, int pos_f) {

	int resultado = sim;
	//Analisa char a char até o fim da palavra
	while (palavra[pos_p] != '\0' && resultado == sim) {

		if (palavra[pos_p] != frase[pos_f]) resultado = nao;
		
		pos_f++; 
		pos_p++;
	}

	//Analisa o char seguinte a palavra não é uma letra
	if (resultado == sim) {	
		resultado = nao;

		//Espaço, '\0', e pontuações
		char validos[] = {' ', '\0', ',', '.', '!', ';', ':', '?', '(', ')'};
		for (int i = 0; i < 11 && resultado == nao; i++) {
			if (frase[pos_f] == validos[i]) resultado = sim;
		}
	}

	return resultado;
}

//>Função que escreve a nova palavra na frase modificada
//>Parâmetros: 2 ponteiros, para a palavra e para frase, e 2 ints, com a posição 
//inicial da escrita e tamanho atual da frase
//>Retorno: um ponteiro com frase modificada
char *adciona_palavra_nova(char *palavra, char *frase, int pos_f, int tam) {

  	for (int i = 0; palavra[i] != '\0'; i++, pos_f++) {
    	//Realoca a string em um espaço maior caso necessário
        if (pos_f == tam) {
        	frase = (char *) realloc(frase, 2 * tam * sizeof(char));
        	tam *= 2;
        }

        //Escreve caracter por caracter
        frase[pos_f] = palavra[i];
    }	

	return frase;
}

//>Função que troca strings em uma frase
//>Parâmetros: 3 ponteiros, enderençando a frase e as palavras a serem trocadas
//>Retorno: 1 ponteiro com a nova frase
char *troca_string(char *p_antiga, char *p_nova, char *f_antiga) {
    
    //Declara string que receberá a nova frase
    char *f_nova = (char *) malloc(50 * sizeof(char));
    int tamanho = 50;
     
    //Cria a nova string
    int fa = 0;
    int fn = 0;
    while (f_antiga[fa] != '\0') {

    	//Realoca a string em um espaço maior caso necessário
        if (fa == tamanho) {
        	f_nova = (char *) realloc(f_nova, 2 * tamanho * sizeof(char));
        	tamanho *= 2;
        }

        //Detecta presença da palavra antiga
        int p_presente = nao;
        if (f_antiga[fa] == p_antiga[0]) {
        	if (fa == 0 || f_antiga[fa - 1] == ' ') {
        		p_presente = confere_presenca(p_antiga, 0, f_antiga, fa);
        	}
        }
        
        //Escreve a palavra nova caso necessário
        if (p_presente == sim) {
        	f_nova = adciona_palavra_nova(p_nova, f_nova, fn, tamanho);
        	
        	fa += strlen(p_antiga);
        	fn += strlen(p_nova);
        }else {
        	f_nova[fn] = f_antiga[fa];

        	fa++;
        	fn++;
        }
    }
    //Fecha a string
	f_nova[fn] = '\0';
  	f_nova = realloc(f_nova, (fn + 1) * sizeof(char));

    return f_nova;
}

//Funçãon principal
int main() {

	//Recebe as palavras e a frase 
	char *palavra_antiga = recebe_string();
	char *nova_palavra = recebe_string();
	char *frase_antiga = recebe_string();

	//Troca a palavra nova pela antiga, caso a primeira conste na frase
	char *nova_frase = troca_string(palavra_antiga, nova_palavra, frase_antiga);

	//Imprime a nova frase
	printf("%s\n", nova_frase);

	free(palavra_antiga);
	free(nova_palavra);
	free(frase_antiga);
	free(nova_frase);
	return 0;
}