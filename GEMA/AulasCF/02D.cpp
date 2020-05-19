 //Programa que soluciona um problema de lógica 	
#include <bits/stdc++.h>
using namespace std;

int main() {

	 //Declara e recebe o nº de cartas
	int numdcartas;
	cin >> numdcartas ;
	 
	 /*Declara vetor os valores das cartas, e o a variavel resposta...
	incializando-a*/
	int valdcartas[numdcartas], i = 0, resposta = 0;
	 //Entrada dos valores para as cartas
	for (;i < numdcartas; i++){
		cin >> valdcartas[i] ;
		 //Incrementa 'resposta' para cada carta a ser virada(pares 0+ e 0-)
		if (valdcartas[i] % 2 == 0){		
			resposta++;
		}
	}

	 //Imprime a resposta
	cout << resposta << "\n";

	return 0;
}
