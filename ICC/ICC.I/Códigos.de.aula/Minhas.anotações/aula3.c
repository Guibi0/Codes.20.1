#include <stdio.h>

/*   STACK (qtda de alocamento pré-definida)
	 
	 --------
	 |	49	| vector[10]     **guarda 10 variáveis(10*x bytes) 
	 |	49	|
	 |	49	|
	 |	48	|
	 |	49	|
	 |	49	|
	 |	0	|
	 |		|
	 |		|
	 |		|
	 --------
	 |		| temp
	 |		|
	 |		|
	 |		|
	 --------
	 |		| i
	 |		|
	 |		|
	 |		|
	 --------
	 |		| r
	 |		|
	 |		|
	 |		|
	 --------
	 |		| q
	 |		|
	 |		|
	 |		|
	 --------
 1000|		| number
	 |		|	
	 |		|
	 |		|
	 --------
*/
int main(int argc, char *argv[]) {
	int number; // Reserva 4 bytes na Stack
	int q, r, i;
	int temp; //temporária
	char vector[10]; //

	printf("Digite um número decimal: "); 
	/* %d
	->pela obrigatóriedade do dado ser int(eiro)
	->manipulção de até 4 bytes
	*/
	scanf("%d", &number);
	temp = number;


	//Conversão para base binária
	/*for (i = 0; i < 10; i++) {
		temp = number;
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\t r: %d\n", q, r);
		temp = q;
	}*/
	
	/*for (;;) { //for ever(já que ñ têm condições para o 'for' rodar)
		temp = number;
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\t r: %d\n", q, r);
		temp = q;
	}*/
	
	/*for (;;) {
		q = temp / 2;
		r = temp - q * 2;
		printf("q: %d\t r: %d\n", q, r);
		temp = q;
		if(q == 0) break;
	}*/	

	//for (q = -1; q != 0;) { //Rodar até o 'q' se igualar a zero/'q = -1' é pra atribuir valor a 'q' tirando qlqr lixo q houvesse lá
	/*for (; temp != 0; temp = q) {
		q = temp / 2;
		r =  temp % 2; //r = temp - q * 2;
		printf("q: %d\t r: %d\n", q, r);
	}*/
	
	for (q = number, i = 0; q != 0;) {
		r =  q % 2;
		vector[i++] = r == 0 ? '0' : '1'; //'if' ternário ** '?' --> 'if'  e ':' --> 'else if'
		// Tabela ASCII
		// 'A' = 65
		// 'B' = 66 ...
		// 'a' = 97
		// 'b' = 98 ...
		// '0' = 48
		// '1' = 49 ...
		q /= 2; // q = q / 2
		printf("q: %d\t r: %d\n", q, r);
	}
	vector[i++] = '\0'; //ou só "0";

	printf("Binário = %s\n", vector); // ** %s: imprime um a sequência de números

	/*q = number
	while(q ! 0) {
		r =  q % 2;
		q /= 2; // q = q / 2
		printf("q: %d\t r: %d\n", q, r)
	}*/

	/*q =  number
	do {
		r =  q % 2;
		q /= 2; // q = q / 2
		printf("q: %d\t r: %d\n", q, r);
	} while (q != 0);*/

	printf("Decimal = %d\n", number);
	
	return 0;
}

//ANOTAÇÕES(**)
	// Função FOR
	 //->('inicialização'; 'finalizção(condicional)'; 'operações durante o correr do laço de repetição(incremeto, ou decremento)')
	// Função WHILE
 	//->'Equanto se atende a condicional rode', é tipo um 'FOR' só com condicional(**inicialização deve ser colocada antes)
	//Função DO/WHILE
 	//->Similar ao WHILE, porém executa primeiro e só depois confere a condicional