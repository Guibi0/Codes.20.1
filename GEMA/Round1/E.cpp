//Qtda de polígonos possíveis de K lados dado N pontos
#include <bits/stdc++.h>
using namespace std;

int main () {								
	long long n, k;
	cin >> n >> k;

	long long resposta = 1;
	int cont = k;
	while (cont > 0) {
		resposta *= n;
		n--;
		cont--;
	}
	while (k > 0) {
		resposta /= k;
		k--;
	} 

	cout << resposta << endl;
}