// Biblioteca auxilar para leitura de arquivos do disco

// Garante que a biblioteca não seja declarada múltiplas vezes
#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

#define FALSE 0
#define TRUE 1
#define NOERROR 2
#define NOEXIST 3
#define NOBMP 4

typedef char * String;

// >Função que confere o tipo no final do nome do arquivo
// >Parâmetros:
//  	-um ponteiro endereçando o nome do arquivo
//  	-um int para o turno de conferência
// >Retorno:
// 		-um int com a resposta de conferência
int isBMP(String name, int turn);

// >Função geral para leitura em disco
// >Parâmetros:
//  	-um ponteiro endereçando a estrutura para os dados da imagem
//  	-um ponteiro endereçando a string com o nome do arquivo a ser lido
// >Retorno:
// 		-um int indicando a situação final do processo de leitura
int readFile(Image *original, String name);

#endif