#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n;
char f;
vector<vector<char>> mapa(500, vector<char>(500, '*'));

void lava(int x, int y) {

	if (((int)mapa[x][y] <= (int)f) && mapa[x][y] != '*') {
		mapa[x][y] = '*';

		if (x < n && y < n) {
			if (x < n - 1)lava(x+1,y);
			if (x > 0)lava(x-1,y);
			if (y < n - 1)lava(x,y+1);
			if (y > 0)lava(x,y-1);
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> f;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> mapa[i][j];
	}
	if ((int)mapa[0][0] > (int)f) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << mapa[i][j];
			cout << "\n";
		}
	}
	else {
		lava(0, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << mapa[i][j];
			cout << "\n";
		}
	}
	return 0;
}