#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

const int mod = 1e9 + 7;

int n, k;
vector<int> qtd(1000001, 0);
vector<ll> primos;

int main() {
	
	cin >> n >> k;

	ll p;
	for(int i = 0; i < n; i++) {
		
		cin >> p;	
		if (!qtd[p]) primos.pushB(p);
		qtd[p]++;
	}

	sort(primos.begin(), primos.end());
	
	ll resp = 1;
	int i = 0;
	while (k != 0) {
		if(qtd[primos[i]]) {
			resp *= primos[i];
			resp %= mod;
			qtd[primos[i]]--; 
			k--;
		}

		i++;
		if(i == primos.size()) i = 0;
	}

	cout << resp % mod << "\n";
	return 0;
}