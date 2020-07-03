/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 > Programa que simula um sistema de banco de dados
 *******************************************************************************/

#include "leitura.h"
#include "operacoes.h"

int main() {

	char *nomeArq = recebeNome(stdin);

	menu(nomeArq);

	exitAndFree(nomeArq);
	return 0;
}

