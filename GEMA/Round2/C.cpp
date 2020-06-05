#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

#define potMAX 29

int main() {
	
	int b, g;
	cin >> b >> g;

	vector<int> potB(30, 0);
	vector<int> potG(30, 0);
	int i = potMAX;
	while(b > 0 || g > 0){

		if (b >= pow(2, i)) {
			b -= pow(2, i);
			potB[i] = 1;
		}
		if (g >= pow(2, i)) {
			g -= pow(2, i); 
			potG[i] = 1;
		}
		
		i--;
	}

	int resp = 0;
	for(int i = 0; i < 30; i++) if (potB[i] != potG[i]) resp += pow(2, i);

	cout << resp << endl;
	return 0;
}