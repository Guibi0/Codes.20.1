 //Programa que descobre quantas letras são necessárias adicionar em uma...
//palavra para ela poder formar uma palíndromo
#include <bits/stdc++.h>
using namespace std;

int main() {

	 //Entrada da qtda de letras
	int numdletras;
	cin >> numdletras;

	 //Entrada da palavra
	char palavra[numdletras + 1];
	cin >> palavra;

	 //Declara uma variável para a resposta inicilizando-a
	int resposta = 0;

	 //Abertura em dois casos que pedem processos diferentes: nº de letra par...
	//ou ímpar, respectivamente
	if (numdletras % 2 == 0) {
		for (int i = 0; i < numdletras / 2; i++) {
			if (palavra[i] != palavra[numdletras - 1 - i]) {
				resposta++;
			}
		}
	}else if (numdletras % 2 == 1) {
		for (int i = 0; i <= numdletras / 2 - 1; i++) {
			if (palavra[i] != palavra[numdletras - 1 - i]) {
				resposta++;
			}
		}
	}

	 //Imprime resposta
	cout << resposta << endl;
	return 0;
}