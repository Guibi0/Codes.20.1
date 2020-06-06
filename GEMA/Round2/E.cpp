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
bool cicle = false;
vector<vector<int>> inimizades(100001);
vector<vector<bool>> grupo(2, vector<bool>(100001, false));

vector<bool> passado(100001, false);
vector<int> futuro;
int func() {

	int resp;
	int g = 0;
	grupo[g][1] = true;
	futuro.pushB(1);
	
	int presente;
	while(futuro.size()) {

		presente = futuro[0];

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
		cout << "\nentrando na função para o vértice > " << presente << endl; 
		futuro.erase(futuro.begin());

		if (grupo[0][presente]) g = 1;
		else g = 0;

		if (passado[presente]) {
			cicle = true; 
			break;
		}

		passado[presente] = true;

		for(int i = 0; i < inimizades[presente].size(); i++) {
			grupo[g][inimizades[presente][i]] = true;
			
			if (!passado[inimizades[presente][i]]) {
				auto it = find(futuro.begin(), futuro.end(), inimizades[presente][i]);
				if (it == futuro.end()) futuro.pushB(inimizades[presente][i]);
			}
		}
	}

	if (cicle) return -1;
	else {

		int isentoes = 0;
		for (int i = 1; i <= n; i++) {
			if (!(grupo[0][i] + grupo[1][i])) isentoes++;

			qtdG0 += grupo[0][i];
			qtdG1 += grupo[1][i];
		} 

		if (qtdG0 >= qtdG1) return qtdG0 + isentoes;
		else return qtdG1 + isentoes;
	}
}

int main() {
	
	cin >> n >> m;

	pair<int, int> ini;
	for(int i = 1; i <= m; i++) {

		cin >> ini.f >> ini.s;

		inimizades[ini.f].pushB(ini.s); 
		inimizades[ini.s].pushB(ini.f); 
	}
	
	int resp = func();

	cout << resp << endl;
	return 0;
}