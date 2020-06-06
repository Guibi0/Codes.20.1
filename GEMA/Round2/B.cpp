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

	int i = 16, resp = 0;
	while(n > 0) {

		if (n >= pow(2, i)) {
			n -= pow(2, i);
			resp++;
		}
		
		i--;
	}
	
	cout << resp << "\n";
	return 0;
}	
