 //Programa que calcula a maior diferença dentre um conjunto de valores
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int valores[n]; 

	int i = 0;
	for (; i < n; i++) {
		cin >> valores[i];
	}

	int menor = valores[0], maior = valores[0];
	for (i = 0; i < n; i++) {
		if (valores[i] < menor) {
			menor = valores[i];
		}

		else if (valores[i] >  maior) {
			maior = valores[i];
		}
	}

	cout << maior - menor << "\n";
		
	return 0;
}