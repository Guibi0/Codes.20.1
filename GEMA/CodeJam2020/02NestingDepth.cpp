#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	for (int a = 0; a < t; a++) {
		string s;
		cin >> s;

		char contabertos = '0';
		int tamstring = s.size();
		string resposta;
	
		for (int i = 0; i < tamstring; i++) {
			if (contabertos == s[i]) resposta += s[i];
			
			else if (contabertos < s[i]) {
				for (; contabertos <= s[i]; contabertos++) {
					if (contabertos == s[i]) {
						resposta += s[i];
						break;
					}resposta += '(';
				}
			}else if (contabertos > s[i]) {
				for (; contabertos >= s[i]; contabertos--) {
					if (contabertos == s[i]) {
						resposta += s[i];
						break;
					}
					resposta += ')'; 
				}
			}if (i == tamstring - 1) {
				for (; contabertos > '0'; contabertos--) {
					resposta += ')'; 
				}
			}
		}

        cout << "Case #" << a + 1 << ": " << resposta << endl;
	}

	return 0;
}