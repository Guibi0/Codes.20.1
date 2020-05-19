 /*Programa que conta quantas vezes um algarimo k aparece nas unidades de uma 
 sequência de n nºs*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	 //Entrada de n
	int n;
	cin >> n;

	 //Entrada do algarismo
	int k;
	cin >> k;

	int resposta = 0; 
	 /*Como fn = 2^n, temos um ciclo nas unidades: 1->2->4->8->6->2->4->8->6 ...
	com isso, basta  olhar para os k's pertencentes à {1;2;4;8;6}*/
	if (k == 1) {
		if (n != 0){
			resposta++;
		}
	}else if (k == 2) {
		if ((n - 1) % 4 >= 1) {
			resposta = (n + 3) / 4;
 		}else {
 			resposta = (n - 1) / 4;
 		}
	}else if (k == 4) {
		if ((n - 1) % 4 >= 2) {
			resposta = (n + 3) / 4;
 		}else {
 			resposta = (n - 1) / 4;
 		}
	}else if (k == 8) {
		if ((n - 1) % 4 == 3) {
			resposta = (n + 3) / 4;
 		}else {
 			resposta = (n - 1) / 4;
 		}
	}else if (k == 6) {
 		resposta = (n - 1) / 4;	
	}

	 //Imprime a resposta
	cout << resposta << endl;

	return 0;

}