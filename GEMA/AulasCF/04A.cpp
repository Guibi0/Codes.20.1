//Programa que apaga vogais consecutivas deixando só a primeira
#include <bits/stdc++.h>
using namespace std;

int main() {

	//Recebe a string de 'e'ntrada
	string e;
	cin >> e;

	//Produz a string de resposta
	string s; 
	for (int i = 0; i < e.size(); i++) {

		if (e[i]=='a'||e[i]=='e'||e[i]=='i'||e[i]=='o'||e[i]=='u') {
			s += e[i];

			//Pula as vogais consecutivas 
			int j = i + 1;
			while (e[j]=='a'||e[j]=='e'||e[j]=='i'||e[j]=='o'||e[j]=='u') {
				i++;
				j++;	
			}
		
		}else s += e[i];
	}

	cout << s << endl;

	return 0;
}