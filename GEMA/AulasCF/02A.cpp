 /*Programa que descobre quantos depois de quantos anos um urso ultrapassa o
 outro em peso recebidos os pesos iniciais, dado que os ursos engordam em 
 velocidades diferentes*/ 	
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	int ano = 0;
	for (; b >= a; a = 3 * a, b = 2 * b) {
		ano++;
	}

	cout << ano << "\n";

	return 0;
}