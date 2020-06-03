#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int vetorV[n];
	for (int i = 0; i < n; i++) cin >> vetorV[i];

	int vetorQ[m];
	for (int i = 0; i < m; i++) {
		cin >> vetorQ[i];

		if (vetorQ[i] < vetorV[0]) cout << vetorV[0] << endl;

		else if (vetorQ[i] > vetorV[n - 1]) cout << vetorV[n - 1] << endl; 

		else {
			int o = 0, f = n - 1, quantidade = f - o + 1;
			
			int meio = (f-o)/2, pos = meio;
			int menor_distancia = vetorQ[i] - vetorV[meio];
			while (quantidade > 2) {

				menor_distancia = vetorQ[i] - vetorV[meio];
				pos = meio;

				if (menor_distancia < 0) f = meio;

				else if (menor_distancia > 0) o = meio;

				else break;

				meio = o + (f-o)/2;
				quantidade = f - o + 1;

			}

			if (menor_distancia == 0) cout << vetorV[pos] << endl;

			else {

				menor_distancia = vetorQ[i] - vetorV[o];
				pos = o;

				int distancia = vetorV[f] - vetorQ[i];
				if (distancia < menor_distancia) pos = f;

				cout << vetorV[pos] << endl;
			}
		}
	}

	return 0;
}
