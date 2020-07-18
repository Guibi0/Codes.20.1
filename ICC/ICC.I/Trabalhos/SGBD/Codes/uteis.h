// Biblioteca com as funções centrais para o tratamento dos metadados/dados do programa
#ifndef UTEIS_H
#define UTEIS_H

#include <stdio.h>

#define ERRO -1
#define SUCESSO 0

#define SIM 1
#define NAO 0
#define TAMANHO_INICIAL 1024

char* leLinhaComRef(FILE*, void*, void*);
void realocaStringComCalloc(char**, int);
void adicionaEmString(char**, char*);

#endif