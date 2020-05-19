//Indicar o menor número dente dois número
#include <stdio.h>
int main () {
	float num1, num2;
	printf("Digite os dois números:\n"); //Msg instrutora e entrada dos dois números
	scanf("%f", &num1);
	scanf("%f", &num2);
	

	printf("\nO menor número é "); //Impressão da msg introdutória da saída
	if (num1 > num2) { //Condição entre os dois números, e impressão do menor
		printf("%.2f\n", num2);
	}else {
		printf("%.2f\n", num1);
	}	
	return 0;
}