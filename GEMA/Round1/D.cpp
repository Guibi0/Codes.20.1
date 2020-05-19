//Menor pulo pra sair de um circunferência
#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, n;
	cin >> r >> n;

	double maior_distancia_do_centro = 0;
	for (int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;

		if (maior_distancia_do_centro < sqrt(pow(x, 2) + pow(y, 2))) {
			maior_distancia_do_centro = sqrt(pow(x, 2) + pow(y, 2));
		}
	}

	double resposta = r - maior_distancia_do_centro;

	printf("%.9lf\n", resposta);

	return 0;
}