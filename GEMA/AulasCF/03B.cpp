 //Programa que calcula a distância percorrida por um elevador
#include <bits/stdc++.h>
using namespace std;

int main() {

	 //Recebe a quantidade de andares do caminho e o último andar do prédio
	int n, h;
	cin >> n >> h;

	 //Declara um vetor para a sequência de andares e a reposta
	int seq[n], resposta = 0;

	 /*Laço que recebe a sequência de andares e calcula a diferença de um andar  
	para o seguinte, multiplicando por 4 e incrementando na respota*/
 	for (int i = 0; i < n; i++) {
 		cin >> seq[i];
 		if (i > 0 && seq[i] >= seq[i - 1]) {
 			resposta += (seq[i] - seq[i - 1]) * 4;
 		}else if (i > 0 && seq[i] < seq[i - 1]) {
 			resposta -= (seq[i] - seq[i - 1]) * 4;
 		}
 	}

 	//Imprime a resposta
 	cout << resposta << endl;

	return 0;
}