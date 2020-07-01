//Conferência se um nº é triangular e se sua soma com o próx. dá um nº quadrado
#include <stdio.h>
#include <math.h>

int main() {
	int numeroin; //Entrada do nº inicial
	scanf("%d", &numeroin);

	int subtraido = 0;
	int resultadosub = numeroin;  //Próx. nº na PA secundária

	while(resultadosub >= 0) { //Laço de repetição que vai subtraindo os N
		subtraido++;
		resultadosub = resultadosub - subtraido;

		if(resultadosub == 0) { //Se o resultado for 0 o número é triangular pois pode ser escrito como a soma de uma PA de razão 1
			printf("SIM\n");
			printf("%d\n", numeroin + subtraido + 1); //Impressão do próx. nº triangular
			break;
		}else if(resultadosub < 0) {
			printf("NAO\n");
			return 0;
		}	
	}
	
	if((double)sqrt(numeroin*2 + subtraido + 1) - (int)sqrt(numeroin*2 + subtraido + 1) == 0) { 	                      
		printf("SIM\n"); //Conferẽncia se a soma dos trinagulares da um quadrado	
	}else {
		printf("NAO\n");
	}
	return 0;
}