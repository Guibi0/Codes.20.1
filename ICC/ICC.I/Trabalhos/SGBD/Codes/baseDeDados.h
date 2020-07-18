// Biblioteca com as funções centrais para o tratamento dos metadados/dados do programa
#ifndef BASE_DE_DADOS_H
#define BASE_DE_DADOS_H

#include "metadados.h"

Dados* lePadraoDosMetadados(char*);
void menuDeOperacoes(Dados*);
void liberaMemoriaTotal(Dados*);

#endif