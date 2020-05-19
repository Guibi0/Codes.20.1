//Calcular/indicar média entre 4 notas e em seguida dar condição de aprovado ou ñ 
#include <stdio.h>

int main() {
	float nota1, nota2, nota3, nota4, media; //Entrada das variáveis
						    //*float é do tipo decimal e aloca 4 bytes 											 
	printf("Digite a nota 1:\n"); 
	scanf("%f", &nota1); //Impressão da msg instrutora e entrada do valor das respectivas notas
	
	printf("Digite a nota 2:\n");
	scanf("%f", &nota2);
    
    printf("Digite a nota 3:\n");
	scanf("%f", &nota3);
	
	printf("Digite a nota 4:\n");
	scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4; //Cálculo/impressão da média
	printf("Média: %.2f\n", media);

	if (media >= 7) { //Condição para aprovação, e por consequência para reprovação
		printf("Aprovado\n");
	}
	else {
		printf("Reprovado\n");
	};
    return 0; 
} 
