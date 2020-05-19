 /*Dado três valores na entrada, imprima na saída os três valores ordenados
de maneira decrescente (Para melhor entendimento do problema, olhem os casos de teste)*/
#include <stdio.h>

int main() {
	int x, y,z;
	int a1, a2, a3;

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	for (int i = 0; i < 3; i++) {
		scanf("%d", &vet[i]);
	}

	int a1 = vet[0];
	int a2 = vet[1];
	int a3 = vet[2];

	for (int i = 0; i < 3; i++) {
		if (vet[i] < a1 ) {
			a1 = vet[i];
		}
	}  
	for (int i = 0; i < 3; i++) {
		if (vet[i] > a3 ) {
			a3 = vet[i];
		}
	}

	a2 = vet[0] + vet[1] + vet[2] - a1 - a3;
	
	printf("%d\n%d\n%d\n", a3, a2, a1);

	return 0;
}	

/*if (x < y && x < z) {
		a1=x;
		if(y<z){
			a2=y;
			a3=z;
		}else {
			a2=z;
			a3=y;
		}
	}else if(y < x && y < z) {
		a1=y;
		if(x<z){
		 	a2=x;
		 	a3=z;
		}else {
		 	a2=z;
		 	a3=x;
		}
	}else if(z < x && z < y) {
		a1=z;
		if(x<y){
		 	a2=x;
		 	a3=y;
		}else {
			a2=y;
			a3=z;
		}
	
}*/	
	 
