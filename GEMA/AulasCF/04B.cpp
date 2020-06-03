#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int, int> tam;

string f(vector<string> &sala, vector<string> &control, int l, int c) {

	if (l == -1 || l == tam.f || c == -1 || c == tam.s) return "AE MLK";
	if (control[l][c] == 'p') return "EOQ";

	control[l][c] = 'p';

	if (sala[l][c] == 'R') return f(sala, control, l, c + 1);
	if (sala[l][c] == 'L') return f(sala, control, l, c - 1);
	if (sala[l][c] == 'U') return f(sala, control, l - 1, c);
	if (sala[l][c] == 'D') return f(sala, control, l + 1, c);
}

int main() {

	cin >> tam.f >> tam.s;	
	vector<string> sala(tam.f);

	for (int i = 0; i < tam.f; i++) {

		cin >> sala[i];
	}
		
	pair<int, int> ini;
	cin >> ini.f >> ini.s;	

	vector<string> control(tam.f);
	control = sala;
	cout << f(sala, control, ini.f, ini.s) << endl;

	return 0;
}