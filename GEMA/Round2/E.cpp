#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n, m;
int qtdG0 = 0, qtdG1 = 0;
vector<vector<int>> inimizades(100001);
vector<vector<bool>> grupo(2, vector<bool>(100001, false));

int func() {

	int resp;
	
	int vertice = 1;
	int g = 0;
	grupo[g][vertice] = true;
	while(m) {

		if (inimizades[vertice].size()) {
			if(!(grupo[0][vertice] + grupo[1][vertice])) grupo[0][vertice] = true;
		}
		
		cout << "\nentrando na função para o vértice >" << vertice << endl;

		for(int i = 0; i < inimizades[vertice].size(); i++) {
			if (grupo[0][vertice]) grupo[1][inimizades[vertice][i]] = true, m--;
			if (grupo[1][vertice]) grupo[0][inimizades[vertice][i]] = true, m--;
		}
		cout << "\ngrupo 0 ta assim >>";
		for (int i = 1; i <= n; i++) {
			cout << grupo[0][i] << " ";
		}
		cout << endl;
		
		cout << "grupo 1 ta assim >>";
		for (int i = 1; i <= n; i++) {
			cout << grupo[1][i] << " ";
		}
		cout << endl;

		vertice++;
	}

	for (int i = 1; i <= n; i++) {

		if(grupo[0][i] & grupo[1][i]) return -1;

		qtdG0 += grupo[0][i];
		qtdG1 += grupo[1][i];
	} 

	if (qtdG0 < qtdG1) return n - qtdG0;
	else return n - qtdG1;
}

int main() {
	
	cin >> n >> m;

	pair<int, int> ini;
	for(int i = 1; i <= m; i++) {

		cin >> ini.f >> ini.s;

		if(ini.f < ini.s) inimizades[ini.f].pushB(ini.s); 
		else inimizades[ini.s].pushB(ini.f); 
	}

	for (int i = 1; i <= n; i++){
		cout << i << "->";
		for(int j = 0; j < inimizades[i].size(); j++){
			cout << inimizades[i][j] << " ";
		}
		cout << endl;
	}	

	if (!m) cout << n - 1 << "\n";
	else {
		cout << func() << endl;
	}

	return 0;
}