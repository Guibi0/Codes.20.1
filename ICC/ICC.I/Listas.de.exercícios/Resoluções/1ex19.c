//Calculadora de peso ideal de acordo com sexo
#include <stdio.h>
#include <string.h>

int main () {

double altura;
char sexo[6];

printf("Indique sua altura em metros:");
scanf("%lf", &altura);
printf("Você é homem ou mulher?\n");
scanf("%s", sexo);

if (strcmp(sexo, "homem") == 0) {
	printf("Seu peso ideal é %.2lf kg\n", 62.1 * altura - 44.7);
}else if (strcmp(sexo, "mulher") == 0) {
	printf("Seu peso ideal é %.2lf kg\n", 72.7 * altura - 58);	
}

/*if (sexo[0] == 'm') {
	printf("Seu peso ideal é %.2lf kg\n", 62.1 * altura - 44.7);	
} else if(sexo[0] == 'h') {
	printf("Seu peso ideal é %.2lf kg\n", 72.7 * altura - 58);	
}*/

return 0;
}