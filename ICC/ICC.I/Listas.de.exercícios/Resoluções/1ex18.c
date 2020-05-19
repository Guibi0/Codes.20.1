//Confirmação de maioridade ou não
#include <stdio.h>

int main() {
	float idade;
	
	printf("Digite sua idade:");
	scanf("%f", &idade); //Entrada da idade
		
 	if( idade >= 18) { //Conferência da idade 
		printf("Você é maior de idade\n");
	}else {
	 	printf("Você é menor de idade\n");			
	}
	
	return 0;
}