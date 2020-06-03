#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int numN, numA, a, b;

int main() {

	cin >> numN >> numA >> a >> b;

	vector<vector<int>> lista(numN + 1);

	pair<int, int> ad;
	for(int i = 1; i <= numA; i++) {

		cin >> ad.f >> ad.s;

		lista[ad.f].pushB(ad.s); 
	}

	vector<int> aVisitar(1, a);
	vector<int> visitados(numN - 1, 0);
	int visitando;
	while(aVisitar.size() != 0) {

		visitando = aVisitar[aVisitar.size()-1];
		aVisitar.pop_back();

		it = find(visitados.begin(), visitados.end(), visitando);
		if (it != visitados.end()) continue;
		
		visitados.pushB(visitando);

		for (int i = 0; i < lista[visitando].size(); i++) aVisitar.pushB(lista[visitando][i]);
	}

	string resp;
	auto it = find(visitados.begin(), visitados.end(), b);
	if (it != visitados.end()) resp = "SIM";
	else resp = "NAO";

	cout << resp << endl;

	return 0;
}
// string percorre(vector<vector<int>> lista, vector<bool> passou, int inicio) {

// 	passou[inicio] = true;
// 	if (inicio == b) return "SIM";

// 	bool cabou = true;
// 	for (int i = 0; i < numN; i++) if (passou[i] == false) cabou = false;

// 	if (cabou == true) return "NAO";
// 	else {		

// 		if (lista[inicio].size() == 0) return percorre(lista, passou, inicio);

// 		else for(int i = 0; i < lista[inicio].size(); i++) return percorre(lista, passou, lista[inicio][i]);
// 	}
// }