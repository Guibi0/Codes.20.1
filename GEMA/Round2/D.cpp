#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound


int main() {
	
	int n;
	cin >> n;
	vector<string> p(n);

	for (int i = 0; i < n; i++) cin >> p[i];

	sort(p.begin(), p.end());
	
	int resp = 1;
	for (int i = n; i > 0; i--) resp *= i;

	int i = 0, j = 0;
	while(i + 1 <= n) {
		i = j;
		j = i+1;
		
		int fat = 1, qtda = 1;
		while(p[i] == p[j]) {
			i++;
			j++;
			qtda++;
		}
		
		for (int i = qtda; i > 0; i--) fat *= i;
		resp /= fat;			
	}

	cout << resp << "\n";
	return 0;
}