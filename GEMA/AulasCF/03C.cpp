 //Programa que indentifica padrões em fileiras de árvores
#include <bits/stdc++.h>
using namespace std;

int main() {

	int qtdfileira, qtdcoluna;
	cin >> qtdfileira >> qtdcoluna;

	long long parque[qtdfileira][qtdcoluna];

	for (int i = 0; i < qtdfileira; i++) {
		for (int j = 0; j < qtdcoluna;j++)
			cin >> parque[i][j];
	}

	for (int j = 0; j < qtdcoluna; j++) {
		int cons = 0, cres = 0, decr = 0;
		for (int i = 1; i < qtdfileira;i++){
			if (parque[i][j] == parque[i-1][j]) {
				cons++;
			}else if (parque[i][j] > parque[i-1][j]) {
				cres++;
			}else if (parque[i][j] < parque[i-1][j]) {
				decr++;
			}
		}	
		if (cons == qtdfileira - 1 || cres == qtdfileira - 1 || decr == qtdfileira - 1) {
			cout << "S" << endl;
		}else {
			cout << "N" << endl;
		}	
	}
	 
	return 0;
}