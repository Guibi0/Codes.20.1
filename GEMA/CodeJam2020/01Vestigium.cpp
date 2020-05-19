#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
        
    for (int a = 0; a < t; a++) {
        
        int n;
        cin >> n;
        
        int matriz[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz[i][j];
            }
        }    

        //Vestígio = k
        int k = 0;
        for (int x = 0; x < n; x++) {
            k+= matriz[x][x];    
        }
        
        //Linha c/ rept = r
        int r = 0; 
        for (int i = 0; i < n; i++) {
            int rept = 0;
            for (int j = 0; j < n; j++) {
                for (int x = j; x < n; x++) {
                    if (matriz[i][j] == matriz[i][x]) {
                        if (x == j) {
                            continue; 
                        }
                        rept = 1;
                        break;
                    }
                } 
            }
            if (rept == 1) r++;
        }

        //Coluna c/ rept = c
        int c = 0;
        for (int j = 0; j < n; j++) {
            int rept = 0;
            for (int i = 0; i < n; i++) {
                for (int x = i; x < n; x++) {
                    if (matriz[i][j] == matriz[x][j]) {
                        if (x == i) {
                            continue;
                        }
                        rept = 1;
                        break;
                    }
                }
            }
            if (rept == 1) c++;          
        } 

        cout << "Case #" << a + 1 << ": " << k << " " << r << " " << c << endl;
    }
  
    return 0;
}