//Programa que recebe uma senha
#include <stdio.h>

int main() {
	float senha;

	senha = -1;

	printf("Digite sua senha:");

	while(senha == -1) {
				
		scanf("%f", &senha); //Entrada da senha
		

		if( senha == 4531) {
			printf("ACESSO PERMITIDO\n");
		}else {
			printf("ACESSO NEGADO\n");
			printf("Senha incorreta, digite novamente:");
			senha = -1;			
		}
	}
	return 0;
}