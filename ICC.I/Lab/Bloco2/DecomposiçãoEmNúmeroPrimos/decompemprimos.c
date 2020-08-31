 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que decompõe um inteiro positivo em primos
 *******************************************************************************/
#include <stdio.h>

//Função que fatora um número 
//->Parâmetros: nº inteiro > 1
//->Retorno: não há retorno
void fatore(int numero) {
	
	//Laço que divide o nº até que as duvisões levem a 1, parando a fatoração
	for (int d = 2; numero > 1; d++) {
		/*Pula todo o processo para divisores não primos ou primos não presentes
		na fatoração, com os quais a divisão não dará exata*/
		if (numero % d != 0) continue;
		
		//Declara o contador para a quantidade de fatores de cada primo
		int qtdafatores = 0;

		//Contagem de para cada um dos fatores
		while (numero % d == 0) {
			numero /= d;         
			qtdafatores++;
		}

		//Imprime um primo presente na fatoração e a respectiva potência
		printf("%d %d \n", d, qtdafatores);
	}
}

//Função principal
int main() {

	//Recebe n
	int num;
	scanf("%d", &num);

	//Imprime a decomposição de n em primos
	fatore(num);

	return 0;
} 
