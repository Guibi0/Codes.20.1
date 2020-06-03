#include <bits/stdc++.h>
using namespace std; 

int main() {

	int n, m;
	cin >> n >> m;

	int matriz[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matriz[i][j];
		}
	}

	char resultado = 'N';
	int cont = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {

			if (matriz[i][j] == 0) {
				cont++; 
				break;
			}	
		}
	}

	if (cont == m) resultado = 'S';

	cout << resultado << endl;

	return 0;
}