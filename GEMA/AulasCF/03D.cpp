 //Programa que descobre uma coordenada viável em um mapa de jogo
#include <bits/stdc++.h>
using namespace std;

int main() {

	int altura, largura;
	cin >> altura >> largura;

	char mapa[altura][largura];
	
	for(int i = 0; i < altura; i++) {
		cin >> mapa[i];	
	}

	int qtdespacos = 0, qtdvistapmonstro = 0;
	for (int i = 0; i < altura; i++) {
		for (int j = 0; j < largura; j++) {
			if (mapa[i][j] == '.' || mapa[i][j] == 'x') {
				qtdespacos++;
			}
			if (mapa[i][j] == 'D') {

				for (int d = i + 1; d < altura; d++) {

					if (mapa[d][j] == '.') {
						qtdvistapmonstro++;
						mapa[d][j] = 'x';	

					}else if (mapa[d][j] == 'x') {
						//faça nada
					}else {
						break;
					}
				}
			}
			if (mapa[i][j] == 'U') {
				for (int u = i - 1; u >= 0; u--) {
					if (mapa[u][j] == '.') {
						qtdvistapmonstro++;
						mapa[u][j] = 'x';		 
					}else if (mapa[u][j] == 'x') {
						//faça nada
					}else {
						break;
					}
				}
			}
			if (mapa[i][j] == 'R') {
				for (int r = j + 1; r < largura; r++) {
					if (mapa[i][r] == '.') {
						qtdvistapmonstro++;
						mapa[i][r] = 'x';		
					}else if (mapa[i][r] == 'x') {
						//faça nada
					}else {
						break;
					}
				}
			}
			if (mapa[i][j] == 'L') {
				for (int l = j - 1; l >=0; l--) {
					if (mapa[i][l] == '.') {
						qtdvistapmonstro++;
						mapa[i][l] = 'x';		
					}else if (mapa[i][l] == 'x') {
						//faça nada
					}else { 
						break;
					}
				}
			}
		}	
	}

	if (qtdespacos == qtdvistapmonstro) {
		cout << "NO SOLUTION" << endl;
	}else if (qtdespacos == qtdvistapmonstro + 1) {
		cout << "ONLY ONE SOLUTION" << endl;
	}else if (qtdespacos > qtdvistapmonstro + 1) {
		cout << "MULTIPLE SOLUTIONS" << endl;
	}

	return 0;
}