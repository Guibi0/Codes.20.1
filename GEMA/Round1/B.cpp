//Acha maior divisor ímpar
#include <bits/stdc++.h>
using namespace std;

long long maior_div_impar(long long numero) {
	long long maior_div_impar = 1;
	int cont = 0;

	do {
		if (numero % 2 != 0) {
			maior_div_impar *= numero;
			cont++;
		}
		else numero /= 2;

	} while (cont == 0);	

	return maior_div_impar;
}


int main() {
	long long numero;
	cin >> numero;

	long long maior_divisor_impar;
	maior_divisor_impar = maior_div_impar(numero);
	cout << maior_divisor_impar << endl;

	return 0;
}