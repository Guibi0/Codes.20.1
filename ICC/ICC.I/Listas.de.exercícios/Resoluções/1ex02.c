//Calcular/indicar média de 2 notas e em seguida indicar situação do aluno
#include <stdio.h>
int main() {
    double nota1, nota2, media; //Entrada das variáves
    							//*'double' é um 'longfloat', variável decimal que aloca 8 bytes
	printf("Digite a nota 1:\n"); 
	scanf("%lf", &nota1); //Impreçaõ da msg indicando ação e recebimento das notas como entrada
	
	printf("Digite a nota 2:\n");
	scanf("%lf", &nota2);

	media = (nota1 + nota2) / 2; //Cálculo/impressão da média
	printf("Média: %.2lf\n", media);

	if(media >= 0 && media < 3) { //condições para tipos de 'situação do aluno'('&&' é 'e', juntando duas condições)
		printf("Reprovado\n");
    }else if(media >= 3 && media < 7) { //*usar 'else if' no meio e 'else' sem nada no fim
    	printf("Exame\n");
    }else{
    	printf("Aprovado\n");
    }
    return 0; 
	}
