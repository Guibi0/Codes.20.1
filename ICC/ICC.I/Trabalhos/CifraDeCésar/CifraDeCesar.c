/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |                      
 |                        Autor: Guilherme Rios(1122839)                       | 
 *******************************************************************************
 >Programa que trabalha com Cifra de César: "encriptando" e "desencriptando"
 *******************************************************************************/ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//>Função que lê uma string, incluindo espaços
//>Parâmetros: não há parâmetros
//>Retorno: um ponteiro que aponta para string na HEAP
char *read_line() {
    //Declara string que receberá a frase
    char *string = (char *) malloc(8 * sizeof(char));
    int tamanho = 8;
     
    //Lê a string
    int i = 0;
    do {
        //Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	string = (char *) realloc(string, 2 * tamanho);
        	tamanho *= 2;
        }
    	
    	//Recebe caracter por caracter
        scanf("%c", &string[i]);
        
        i++;

    }while (string[i - 1] != '\n' && string[i - 1] != EOF);
    string[i - 1] = '\0';
    string = realloc(string, i);

    return string;
}

//Função principal
int main() { 
	//Recebe o comando e a chave
	int comando, chave;
	scanf("%d\n%d\n", &comando, &chave);

	//Lê a string
	char *frase = read_line();

	//"Encriptando letras..."
	if (comando == 1) {
		 //For que percorre toda a string 'frase'
		for (int i = 0; i < 101 && frase[i] != '\0'; i++) {
			 //Tratando de maiúsculas com if e minúsculas com else if 
			if (frase[i] <= 'Z' && frase[i] >= 'A') {
				 /*Incrementa em cada letra a frase, tendo como base a tabela
				ASCII(a:97, z:122, A:65, e Z:90) e o conjunto do alfabeto*/ 
				frase[i] = 'A' + (frase[i] + chave - 'A') % 26;					       	    
			}else if (frase[i] <= 'z' && frase[i] >= 'a') {
				frase[i] = 'a' + (frase[i] + chave - 'a') % 26;
			}
		}
	}
	//"Desencriptando letras..."
	else if (comando == 2) {
		for (int i = 0; i < 101 && frase[i] != '\0'; i++) {
			 /*Analogamente ao bloco acima, porém, ao invés de incrementada, a
			chave é decrementada em cada letra*/  
			if (frase[i] <= 'Z' && frase[i] >= 'A') {			
				frase[i] = 'Z' - (('Z' + chave - frase[i]) % 26);
								 //'Z' -(frase[i] - chave)
			}else if (frase[i] <= 'z' && frase[i] >= 'a') {
				frase[i] = 'z' - (('z' + chave - frase[i]) % 26);
			}
		}
	}//*Caracteres que não são letras não são considerados, logo se mantém

	//*Obs.: foi utilizado o resto por 26 nos blocos acima para evitar que o 
	//processo evadisse o conjunto do alfabeto, indo antes de 65/97('A'/'a') ou 
	//depois de 90/122('Z'/'z'). As equações utilizadas fazem com que sempre some 
 	//à 'A'/'a' e subtraia de 'Z'/'z' um número entre 0 e 25

	//Impresssão da frase já criptografada
	printf("%s\n", frase);

	free(frase);
	return 0;
}