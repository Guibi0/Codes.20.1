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
		//periodo[n][2]: pessoa responsável(67=C e 74=J)
		int periodo[n][3] = {};
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < 2; b++) cin >> periodo[i][b];
		}
		for (int i = 0; i < n; i++) periodo[i][2] = 67;

		for (int i = 0; i < n; i++) {
			//"Desce" à procura de períodos sobrepostos
			for (int d = i + 1; d < n; d++) {


				cout << "________________________" << endl;
				cout << "i:" << i << " d:" << d << endl;
				cout << "------------------------" << endl;
				cout << "Comparando " << periodo[i][0] << " a " << periodo[i][1] << endl;
				cout << "Com " << periodo[d][0] << " a " << periodo[d][1] << endl << endl;
				

				//Encontro de 2 períodos sobrepostos
				int mudanca = 0;
				if (periodo[i][0] < periodo[d][0] && periodo[d][0] < periodo[i][1]) {


					cout << endl << "entrou1" << endl;


					if (periodo[i][2] == 67) {


						cout << endl << "mudou C > J" << endl;


						periodo[d][2] = 74;
						mudanca = 1;						
					}else {


						cout << endl << "mudou J > C" << endl;


						periodo[d][2] = 67;
						mudanca = 1;						
					}
				//2º	caso para 2 sobrepostos
				}else if (periodo[i][0] < periodo[d][1] && periodo[d][1] < periodo[i][1]) {


					cout << endl << "entrou2" << endl;


					if (periodo[i][2] == 67) {


						cout << endl << "mudou C > J" << endl;


						periodo[d][2] = 74;
						mudanca = 1;						
					}else {


						cout << endl << "mudou J > C" << endl;


						periodo[d][2] = 67;
						mudanca = 1;						
					}
				//3º caso para 2 sobrepospostos
				}else if (periodo[i][0] < periodo[d][0] && periodo[d][0] < periodo[i][1]) {


					cout << endl << "entrou1" << endl;


					if (periodo[i][2] == 67) {


						cout << endl << "mudou C > J" << endl;


						periodo[d][2] = 74;
						mudanca = 1;						
					}else {


						cout << endl << "mudou J > C" << endl;


						periodo[d][2] = 67;
						mudanca = 1;						
					}	
				//4º caso para 2 sobrepostos
				}else if (periodo[d][0] < periodo[i][1] && periodo[i][1] < periodo[d][1]) {


					cout << endl << "entrou3" << endl;


					if (periodo[i][2] == 67) {


						cout << endl << "mudou C > J" << endl;


						periodo[d][2] = 74;
						mudanca = 1;						
					}else {


						cout << endl << "mudou J > C" << endl;


						periodo[d][2] = 67;
						mudanca = 1;						
					}	
				//Caso de períodos iguais
				}else if (periodo[i][0] == periodo[d][0] && periodo[d][1] == periodo[i][1]) {


					cout << endl << "entrou5" << endl;


					if (periodo[i][2] == 67) {


						cout << endl << "mudou C > J" << endl;


						periodo[d][2] = 74;
						mudanca = 1;						
					}else {
					

						cout << endl << "mudou J > C" << endl;


						periodo[d][2] = 67;
						mudanca = 1;						
					}
				}
				/*Sempre que há troca de responsável é preciso conferir se o esse 
				já não possui compromisso no período*/
				if (mudanca == 1) {


					cout << endl << "subida" << endl;


					//"Sobe" verificando a existência de 3 períodos sobrepostos
					for (int s = d - 1; s >= 0; s--) {


						cout << "_  _  _  _  _  _ " << endl;
						cout << endl << "d:" << d << " s:" << s << endl;
						cout << "Comparando " << periodo[d][0] << "/" << periodo[d][1] << endl;
						cout << "com " << periodo[s][0] << "/" << periodo[s][1] << endl << endl;
				

						//Analisa só os casos já vistos como sobrepostos
						if (periodo[d][0] < periodo[s][0] && periodo[s][0] < periodo[d][1]) {
							
						
							cout << endl << "entrou1'" << endl;
							cout << periodo[s][2] << " e " << periodo[d][2] << " são iguais ??" << endl;


							/*Caso o reponsável seja o mesmo, temos 3 períodos sobrepostos,
							tornando impossível a resolução*/
							if (periodo[s][2] == periodo[d][2]) {


								cout << endl << "SIM" << endl;
								

								impossibilidade = 1;
								break;
							}		
						}else if (periodo[d][0] < periodo[s][1] && periodo[s][1] < periodo[d][1]) {

							
							cout << endl << "entrou2'" << endl;
							cout << periodo[s][2] << " e " << periodo[d][2] << " são iguais ??" << endl;


							if (periodo[s][2] == periodo[d][2]) {


								cout << endl << "SIM" << endl;


								impossibilidade = 1;
								break;
							}
						}else if (periodo[s][0] < periodo[d][0] && periodo[d][0] < periodo[s][1]) {
							
						
							cout << endl << "entrou1'" << endl;
							cout << periodo[s][2] << " e " << periodo[d][2] << " são iguais ??" << endl;


							/*Caso o reponsável seja o mesmo, temos 3 períodos sobrepostos,
							tornando impossível a resolução*/
							if (periodo[s][2] == periodo[d][2]) {


								cout << endl << "SIM" << endl;
								

								impossibilidade = 1;
								break;
							}	
						}else if (periodo[s][0] < periodo[d][1] && periodo[d][1] < periodo[s][1]) {

							
							cout << endl << "entrou4'" << endl;
							cout << periodo[s][2] << " e " << periodo[d][2] << " são iguais ??" << endl;


							if (periodo[s][2] == periodo[d][2]) {


								cout << endl << "SIM" << endl;


								impossibilidade = 1;
								break;
							}
						}	
					}	
				}
				if (impossibilidade == 1) break;
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