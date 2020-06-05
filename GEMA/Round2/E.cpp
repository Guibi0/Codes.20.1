#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n, m;
vector<vector<int>> ini(100000);
vector<int> g(2);

int func(int a, int grupo) {

	if (a == n) {
		if (g[0] > g[1]) return g[0];
		else return g[1];
	}else {
		
	g[grupo] += ini[a].size();
	grupo++;

	for (int i = 0; i < ini[a].size(); i++) return func(ini[a][i], grupo % 2);
	}
}

int main() {
	
	cin >> n >> m;

	pair<int, int> ad;
	for(int i = 1; i <= m; i++) {

		cin >> ad.f >> ad.s;

		if (ad.f < ad.s) ini[ad.f].pushB(ad.s); 
		else ini[ad.s].pushB(ad.f); 
	}

	for (int i = 1; i < n; i++) {
		cout << i << "->";
		for (int j = 0; j < ini[i].size(); j++) cout << ini[i][j] << " "; 
		cout << endl;
	}

	vector<int> aVisitar(1, 1);
	vector<int> visitados(100000 - 1, 0);
	int visitando, cicle = 0;
	while(aVisitar.size() != 0) {

		visitando = aVisitar[aVisitar.size()-1];
		aVisitar.pop_back();

		auto it = find(visitados.begin(), visitados.end(), visitando);
		if (it != visitados.end()) {
			cicle = 1;
			break;
		}
		
		visitados.pushB(visitando);

		for (int i = 0; i < ini[visitando].size(); i++) aVisitar.pushB(ini[visitando][i]);
	}
	
	int resp = -1;
	if(cicle == 0) resp = func(1, 0);

	cout << resp << endl;
	return 0;
}