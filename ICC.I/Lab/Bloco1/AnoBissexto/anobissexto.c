//Programa para conferir se o ano é bissexto
#include <stdio.h>

int main (){ 
	int ano, resto; //resto da divisão do ano por 4 
	scanf("%d", &ano);

	resto = ano - ((ano / 4) * 4); //conta para obter resto(tb pode ser "ano % 4")

	if(resto == 0) { //condição para o ano ser bissexto
		printf("SIM\n");
 	}else { //caso contrário...
 		printf("NAO\n");
 	}
 	
 	return 0;	
 }