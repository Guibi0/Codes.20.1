 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que calcula uma média harmônica com funções
 *******************************************************************************/
#include <stdio.h>

//Função que lê e retorna um número inteiro
//>Parâmetros: não há parâmetros
//>Retorno: um inteiro com a entrada recebida na leitura
int read_int() {
	//Recebe a entrada
	int entrada;
	scanf("%d", &entrada);

	return entrada;
}

//Função que lê e retorna um número real
//>Parâmetros: não há parâmetros
//>Retorno: um double com a entrada recebida na leitura
double read_double() {
	//Recebe a entrada
	double entrada;
	scanf("%lf", &entrada);

	return entrada;
}

//Função imprime um número real com duas casas decimais
//>Parâmetros: um double com o nº real 
//>Retorno: não há retorno
void print_double(double num_real) {
	
	printf("%.2lf\n", num_real);
}

//Função principal	
int main() {

	//Entrada da quantidade de trabalhos
	int n;
	n = read_int();
	
	//Entrada das notas dos trabalhos e calculo do divisor na média
	double notas[n], divisor = 0;
	for (int i = 0; i < n; i ++) {
		notas[i] = read_double();

		//Somatória dos inversos de 'notas+1', para todas as notas
		divisor += 1 / (notas[i] + 1);
	}

	//Imprime o resultado
	print_double((n/divisor) - 1);

	return 0;
}