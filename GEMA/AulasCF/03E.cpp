 //Program que conta quantos números interessantes(...|x+1||x|) na base B
#include <bits/stdc++.h>
using namespace std;

int main() {

	 //Recebe nº máx de dígitos e a base dos números interessantes
	long long n, B;
	cin >> n >> B;

	cout << (n+1)*n/2 + n*(B-n) << endl;

	return 0;
}