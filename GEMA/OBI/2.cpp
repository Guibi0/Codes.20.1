#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n, k, u;

int bb(vector<int> cartela, int a, int inicio, int fim) {

	int meio = (fim + inicio)/2;

	if (inicio > fim) return 0;
	if (cartela[meio] == a) return 1;
	
	if (cartela[meio] > a) return bb(cartela, a, inicio, meio - 1);
	if (cartela[meio] < a) return bb(cartela, a, meio + 1, fim);

	return 0;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> u;

	vector<vector<int>> cartelas(n, vector<int>(k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> cartelas[i][j]; 
		}
		sort(cartelas[i].begin(), cartelas[i].end());
	}

	int a, cabou = 0;
	vector<int> soma(n, 0);
	for (int i = 0; (i < u) && (!cabou); i++) {
		cin >> a;

		for (int j = 0; j < n; j++) {
			
			soma[j] += bb(cartelas[j], a, 0, k-1);
			if (soma[j] == k) {
				cabou = 1;
				cout << j + 1 << " ";
			}
		}
	}
	cout << "\n";

	return 0;
}