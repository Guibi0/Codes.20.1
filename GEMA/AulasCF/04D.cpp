#include <bits/stdc++.h>
using namespace std;

int soma(int vetor[],int tam) {
	
	int soma = 0;
	for (int i = 0; i < tam; i++) soma += vetor[i];

	return soma; 
}

int quantosDaX(int apartir, int vet[], int tamvet, int num) {
	int soma = vet[apartir];
	if (tamvet == 1 && soma != num) return 0;
	for (int i = apartir; i < tamvet; ++i) {
		soma += vet[i];
	}//////////////
	apartir++;
	tamvet--;
	
	if (soma == num) return 1;
	
	return quantosDaX(apartir, vet, tamvet, num);  
}

int main() {
	int n, x;
	cin >> n >> x;

	int v[n];
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}

	int contador = 0;

	contador += quantosDaX(0, v, n, x);

	cout << contador << endl; 

	return 0;
}