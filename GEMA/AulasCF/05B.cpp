#include <bits/stdc++.h>
using namespace std;

int main() {

	int origem = 1, fim = 10, chute = 5;
	int coretor = -1;

	while (coretor != 2) {

		cout << chute << endl;

		cin >> coretor;

		if (coretor == 1) origem = chute + 1;
		else if (coretor == 0) fim = chute - 1;
		
		chute = origem + (fim - origem)/2;
	}

	return 0;
}