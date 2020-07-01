#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Função que converte letras de uma palavra qualquer para letras minúsculas 
//>Parâmetros: um ponteiro para a palavra inicial
//>Retorno: um ponteiro que aponta para a palavra convertida
char *converte_minuscula(char *P) {
	//Declara ponteiro que será retornado 
	char *p = malloc(100 * sizeof(char));
		
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

int main(){
	char *palavra = malloc(100 * sizeof(char));
	scanf("%s", palavra);

	char *palavraMinuscula = malloc(100 * sizeof(char));
	palavraMinuscula = converte_minuscula(palavra);

	printf("%s\n", palavraMinuscula);

	free(palavra);
	free(palavraMinuscula);
	return 0;
}