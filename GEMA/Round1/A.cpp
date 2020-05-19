//Confere MEGA-SENA
#include <bits/stdc++.h>
using namespace std;

int main() {
	char cartela[6][10];
	int marcados[6];

	int k = 0;
	for (int i = 0, num = 1; i < 6; i++) {
		for (int j = 0; j < 10; j++, num++) {
			cin  >> cartela[i][j];

			if (cartela[i][j] == 'x') {
				marcados[k] = num; 
				k++;
			}
		}
	}

	int sorteados[6];
	for (int i = 0; i < 6; i++) cin >> sorteados[i];

	int acertos = 0;
	for (int i = 0; i < 6; i++) {
		if (marcados[i] == sorteados[i]) acertos++;
	}

	if (acertos == 6) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}