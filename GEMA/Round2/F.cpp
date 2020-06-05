#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define popB pop_back
#define pushB push_back
#define lowB lower_bound
#define upperB upper_bound

int n, k;
vector<int> p(1000000, 0);

int main() {
	
	cin >> n >> k >> endl;

	int primo;
	for(int i = 0; i < n; i++) {
		cin >> primo;	
		p[primo]++;
	}
	
	int resp = 0;
	while (k != 0) {


	}

	cout << resp % (1000000000 + 7)<< endl;
	return 0;
}