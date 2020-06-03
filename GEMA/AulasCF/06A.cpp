#include <bits/stdc++.h>
using namespace std;
#define sim 1
#define nao 0

typedef struct {
	int valor;
	int descartada;	
}Resistencias;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	Resistencias res[n];
	for (int i = 0; i < n; i++) {
		cin >> res[i].valor;
		res[i].descartada = nao;
	}

	int i = 0;
	while (m != 0) {

		int res_max = 0;	
	 
		i = i % n; 
		int inicio = i, maximo, a = 0;
		while (a < k && i < inicio + n) {

			if (res[i % n].descartada == nao) { 
				a++;

				if (res[i % n].valor > res_max) {
					res_max = res[i % n].valor;
					maximo = i % n;	 
				}
			}	

			i++;
		}
		res[maximo].descartada = sim; 

		cout << res_max << " ";

		m--;
	}
	cout << endl;

	return 0;
}