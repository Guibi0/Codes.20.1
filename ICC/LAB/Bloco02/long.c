 
/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que imprime os 8 bytes de um long byte a byte
 *******************************************************************************/
#include <stdio.h>

int main() {
	//Recebe a entrada
	long in;
	scanf("%ld", &in);	

	//Ponteiro que guarda o endereço 
	unsigned char *endereco = (unsigned char*) &in;

	//Imprime byte a byte partindo do byte mais significativo
	for (int i = 0; i < 8; i++) {
		printf("%x\n", endereco[i]);
	}

	return 0;
}