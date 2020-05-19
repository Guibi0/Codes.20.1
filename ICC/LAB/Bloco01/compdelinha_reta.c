//Programa que mede o comprimento de uma linha reta composta por n pontos 
#include <stdio.h>
#include <math.h>

int main() {

	int n; //Aloca as variáveis para o número de pontos  

	scanf("%d\n", &n); //Entrada da quantidade de pontos 

	double x[n], y[n]; // Aloca vetores para as coordenadas


	int i; //Variável auxiliar do laço seguinte

	for (i = 0; i < n; i++) { //Entrada das coordenadas do n pontos

		scanf("%lf %lf", &x[i], &y[i]);
	}

	double ymin = y[0], ymax = y[0], xmin = x[0], xmax = x[0];  //Variáveis auxiliares do laço que acha coordenadas max e min, os extremos

	for (i = 0; i < n; i++) {

	  	if (y[i] < ymin ) { //Achando ymin, ymax, xmin, e xmax, respectivamente

	  		ymin = y[i];
	  	} 
		
		if (y[i] > ymax) {

			ymax = y[i];
		} 

		if (x[i] < xmin ) { 

	  		xmin = x[i];
	  	} 
		
		if (x[i] > xmax) {

			xmax = x[i];
		} 	
	}

	double comp; //Aloca variável para o comprimento

	//Condicionais para cada tipo de linha
	if (x[0] - x[1] == 0) { //Linha paralela às ordenadas, onde...
		comp = (ymax - ymin); //o comprimento é igual ao delta y

	}else if (y[0] - y[1] == 0) { //Linha paralela às abscissas, onde...
		comp = (xmax - xmin); //o comprimento é igual ao delta x

	}else if ((x[0] - x[1]) / (y[0] - y[1]) < 0) { //Linha decrescente, onde o comprimento é calculado...
		comp = sqrt(pow((xmax - xmin), 2) + pow((ymax - ymin), 2)); //pela fórmula da distância entre dois os dois pontos extremos

	}else if ((x[0] - x[1]) / (y[0] - y[1]) > 0) { //Linha crescente, onde o comprimento é calculado da mesma forma que na decrescente
		comp = sqrt(pow((xmax - xmin), 2) + pow((ymax - ymin), 2));		
	}

	if (comp < 0) { //Garante o valor absoluto da distância
		comp = -comp;
	}

	printf("%.4lf\n", comp); //Imprime a distância

	return 0;
}
