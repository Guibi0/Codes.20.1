//Programa que mede o comprimento de uma linha, não necessariamente reta, composta por n pontos 
#include <stdio.h>
#include <math.h>

int main() {

	 //Aloca as variáveis para o número de pontos  
	int n; 

	 //Entrada da quantidade de pontos 
	scanf("%d\n", &n); 

	 // Aloca vetores para as coordenadas
	double x[n], y[n]; 

	 //Variável auxiliar do laço seguinte
	int i; 
	 
	 //Entrada das coordenadas do n pontos
	for (i = 0; i < n; i++) { 
		scanf("%lf %lf", &x[i], &y[i]);
	}
	 
	 //Aloca variável para o comprimento
	double comp = 0; 
	
	 //Laço que calcula a distância entre os pares de pontos conseguintes na linha,...
	//e incrementa essa ao comprimento total, de acordo com o tipo de cada parte da linha
	for (i = 0; i < n - 1; i++) { 
		 //Parte paralela às ordenadas, onde o incremento do comprimento é igual ao delta y			
		if (x[i] - x[i + 1] == 0) { 
			if (y[i] - y[i + 1] < 0) {
				comp -= (y[i] - y[i + 1]);
			}else {
				comp += (y[i] - y[i + 1]);
			}
		 //Parte paralela às abscissas, onde o incremento do comprimento é igual ao delta x
		}else if (y[i] - y[i + 1] == 0) { 
			if (x[i] - x[i + 1] < 0) {
				comp -= (x[i] - x[i + 1]);
			}else {
				comp += (x[i] - x[i + 1]);
			} 
  		 //Parte decrescente, onde o incremento do comprimento é calculado pela fórmula da... 
		//distância entre dois os dois pontos extremos
		}else if ((x[i] - x[i + 1]) / (y[i] - y[i + 1]) < 0) { 
			comp += sqrt(pow((x[i] - x[i + 1]), 2) + pow((y[i] - y[i + 1]), 2));
		 //Parte crescente, onde o incremento do comprimento é calculado da mesma forma que na decrescente	 
		}else if ((x[i] - x[i + 1]) / (y[i] - y[i + 1]) > 0) {
			comp += sqrt(pow((x[i] - x[i + 1]), 2) + pow((y[i] - y[i + 1]), 2)); 		
		}
	}

	 //Imprime a distância
	printf("%.4lf\n", comp); 

	return 0;
}
