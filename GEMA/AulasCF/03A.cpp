 //Programa que acha o zero em uma matriz
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	 //Recebe o tamanho da matriz, e declara as coordenas do zero 
	int n, m, idozero = -1, jdozero = -1;	
	cin >> n >> m;

	 //Declara um vetor duplo para a matriz
	int matriz[n][m];

    /*Laço que recebe os termos da matriz, já conferindo qual é igual a zero e 
    armazenando suas coordenadas*/
    for (int i = 0; idozero == -1; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> matriz[i][j];

    		if (matriz[i][j] == 0) {
    			idozero = i;
    			jdozero = j;
    		} 
    	}
    }

     //Imprime a resposta
    cout << idozero << " " << jdozero << endl;

	return 0;
} 