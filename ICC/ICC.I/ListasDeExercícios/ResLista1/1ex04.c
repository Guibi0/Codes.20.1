//Indicar o maior números dentre três números
#include <stdio.h>
int main () {
	float num1, num2, num3;
	printf("Digite os três números:\n"); //Msg instrutora e entrada dos três números
	scanf("%f", &num1);
	scanf("%f", &num2);
	scanf("%f", &num3);
	
	printf("\nO maior número é ");
	if (num1 > num2 && num1 > num3) { //Condição entre os três números com partícula aditiva '&&', e impressão do maior
		printf("%.2f\n", num1);
	}else if (num2 > num1 && num2 > num3) {
		printf("%.2f\n", num2);
	}else {
		printf("%.2f\n", num3);
	}	
	return 0;
}
