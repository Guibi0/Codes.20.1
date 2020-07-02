/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que indica para qual ponto cardeal um robô aponta após movimentos
 *******************************************************************************/
#include <stdio.h>

//Para a execução do programa os pontos cardeais Norte, Leste, Sul, e Oeste 
//serão referenciados pelos restos por 4: 0, 1, 2, e 3, respectivamente; assim, 
//tendo como base a teoria dos restos, os comandos podem ser tratados como +1   
//(para direita), ou -1 que culmina em +3(para esquerda) 
int main() {  

	//Declara uma variável para receber e passar os comandos
	char comando;
	
	//"Vetor de strings" para as respostas de acordo com a posição referência
	char pontos_cardeais[4][6] = {"Norte", "Leste", "Sul", "Oeste"};
	
	//Um inteiro que guarda a posição resposta, de acordo com o resto referência
	int resposta = 0; //'0' refere-se a "Norte", posição inicial 

	//Lê dos comandos e calcula o resto resposta
	do {
		//Leitura
		scanf("%c", &comando);
			
		//Cálculo
		if (comando == 'D') resposta = (resposta + 1) % 4; 
		else if (comando == 'E') resposta = (resposta + 3) % 4;

	}while (comando != '\n');

	//Imprime a resposta de acordo com a referência
	printf("%s\n", pontos_cardeais[resposta]);

	return 0;
}