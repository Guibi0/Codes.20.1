//Programa que imprime a Sequência de Fibonacci
#include <stdio.h>

//Função que imprime fibonacci
//->Parâmetros: nº inteiro limitante
//->Retorno: não há retorno
void fibonacci (int limitante) {
	
	//Declara dois antecessores e o número atual da sequência
	int fib_antant = 0, fib_ant = 0, fib = 0;
	while (fib <= limitante){
		//Define o atual como a soma dos antecessores
		fib = fib_ant + fib_antant;

		//Imprime a sequência
		printf("%d ", fib);

		//Tratando do caso de ínicio, que é excessão
		if (fib == 0) fib_ant = 1;
		
		//*********************************
		//   faa  fa   f                  *
		//   v    v    v                  *
		//   a1   a2   a3   a4   a5       *
		//                                *
		//   faa_   fa_    f_ 			  *
		//	     \     \     \			  *	
		//   a1   ->a2  -> 3  -> a4   a5  * 
		//							      *
		//        faa  fa   f             *
		//   v    v    v                  *
		//   a1   a2   a3   a4   a5       *
		// ___ ___________________________*
		//    v 
		//Troca os antecessores para o prómixo laço
		fib_antant =  fib_ant;
		fib_ant = fib;
	}
}

//Função principal
int main(){
	
	//Recebe o número
	int numero;
	scanf("%d", &numero);	

	//Imprime Fibonacci
	fibonacci (numero);
	printf("\n");

	return 0;
}
