#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n, k;
vector p(100000);
int pulos(int max) {







}

int main() {
	
	cin >> n >> k;

	int m1 = 0;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		if (i > 0) {
			if (p[i] - p[i - 1] > m1) {
				m1 = p[i] - p[i - 1];
			}
		}
	}
	int resp = 0;
	if (k == n - 1) resp = m1;
	else resp = pulos(m1);


	cout << resp << "\n";
	return 0;
}