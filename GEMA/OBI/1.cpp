#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll int dis;
	cin >> dis;

	if ((dis - 6) % 8 == 0) cout << 1 << "\n";
	if ((dis - 7) % 8 == 0) cout << 2 << "\n";
	if ((dis - 8) % 8 == 0) cout << 3 << "\n";

	return 0;
}