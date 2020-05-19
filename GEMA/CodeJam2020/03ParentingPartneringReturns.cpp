#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	for (int a = 0; a < t; a++){
		int impossibilidade = 0;

		int n;
		cin >> n;
		
		//periodo[n][0]: início
		//periodo[n][1]: fim
		//periodo[n][2]: pessoa responsável(C e J)
		int periodo[n][3] = {};
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < 2; b++) cin >> periodo[i][b];
		}
		for (int i = 0; i < n; i++) periodo[i][2] = 'C';

		for (int i = 0; i < n; i++) {
			//"Desce" à procura de períodos sobrepostos
			for (int d = i + 1 ; d < n; d++) {
				//Casos de períodos diferentes
				if (periodo[i][0] <= periodo[d][0] && periodo[i][1] > periodo [d][0]) {
					//Muda de C --> J
					if (periodo[i][2] == 'C') {
						periodo[d][2] = 'J';
					//Muda de J --> C							
					}else {
						periodo[d][2] = 'C';
					}
				}								
			}
		}
		//Conferência
		for (int i = 0; i < n; i++) {
			for (int d = i + 1; d < n; d++) {
				//Trata dos períodos sobrepostos			
				if (periodo[i][0] <= periodo[d][0] && periodo[i][1] > periodo [d][0]) {
					if (periodo[i][2] ==  periodo[d][2]) {
					break;
					}					
				}		
			}
			if (impossibilidade == 1) break;
		}

		if (impossibilidade == 1) {
			cout << "Case #" << a + 1 << ": IMPOSSIBLE" << endl;
		}else {
			//Conversão de decimal para caracter via ASCII
			char responsaveis[n];
			for (int i = 0; i < n; i++) responsaveis[i] = (char)periodo[i][2];

			cout << "Case #" << a + 1 << ": "; 
			for (int i = 0; i < n; i++) cout << responsaveis[i];
			cout << endl; 			
		}
	}

	return 0;
}