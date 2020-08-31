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

#include "uteis.h"
#include "metadados.h"
#include "baseDeDados.h"

int main() {
	char* nomeArqBase = leLinhaComRef(stdin, NULL, NULL);

	Dados* base = lePadraoDosMetadados(nomeArqBase);

	menuDeOperacoes(base);

	liberaMemoriaTotal(base);
	return 0;
}