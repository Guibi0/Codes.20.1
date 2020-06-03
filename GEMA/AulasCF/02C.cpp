 //Programa que confere qual quantidade de pessoa/dia, apareceu com maior... 
//frequência
#include <bits/stdc++.h>
using namespace std;

int main() { 

	 //Entrada do número de dias
	int n;
	cin >> n;

	 /*Declara uma número n de vetores char, declara n vetores' int, associados... 
	pelo 'i' aos vetores char*/
	char dia[n][1001]; 		
	int numpessoas[n], freq[1001] = {}, i = 0;
	 //Entrada da quantidades de caracters cada vetor' char possui
	for (;i < n; i++) {
		cin >> dia[i];
		 //Inicializa a quantidade de pessoas por dias
		numpessoas[i] = strlen(dia[i]);
		 //Incrementa a frequência para a quantidade 'i'		
		freq[strlen(dia[i])]++;
	}

	 //Declara e define maior como o maior valor dentre todos os f[]'s
	int maior = freq[0];
	int resposta = 0;
	for (i = 0; i < 1001; ++i) {
		if (freq[i] > maior) {
			maior = freq[i];
			 //Define j igual a i para salvar a posição da maior frequência
			resposta = i;
		}		
		
	}

	 //Imprime o/ou um dos m[]/m[]'s com maior frequência
	cout << resposta << "\n";

	return 0;
}