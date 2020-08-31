//Média de 4 nºs com descarte de 1
#include <stdio.h>

int main() {
	double vet[4]; //Definindo um vetor de tamanho 4, que é basicamente 4 varíaveis double(como inserido antes), para as 4 notas
                    //Um vetor aloca mais facilmente muitas variáveis de uma vez
	for(int i = 0; i < 4; i++){ //Função 'for' para iniciar um laço de repetição
		scanf("%lf", &vet[i]);  //Entrada nas 4 portas do vetor
	}
	
	double menor = vet[0]; //Denindo/associando a informação da 1ª casa(0-3) do vetor para a variável 'menor'
	
	for(int i = 1; i < 4; i++){ //Laço que confere qual é o menor número
		if(vet[i] < menor){
			menor = vet[i];
		}	 
	}

	printf("%.4lf\n", (vet[0] + vet[1] + vet[2] + vet[3] - menor) / 3); //Impressão da média já com o descarte

	return 0;
}