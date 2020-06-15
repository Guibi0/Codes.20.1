// Biblioteca auxilar para escrita de arquivos do disco

// Garante que a biblioteca não seja declarada múltiplas vezes
#ifndef WRITE_H
#define WRITE_H

#include <stdio.h>
#include <string.h>
#include "data.h"

// >Função que aplica o filtro negativo na foto
// >Parâmetros:
//  	-um ponteiro endereçando os dados originais da paleta de cores
// >Retorno:
// 		-nãoo há retornos
void negativeFilter(Colors *pallet);

// >Função que aplica o filtro preto e branco na foto
// >Parâmetros:
//  	-um ponteiro enderençando os dados originais da paleta de cores
// >Retorno:
// 		-não há retornos
void blackAndWhiteFilter(Colors *pallet);

// >Função que cria um nome para o novo arquivo de acordo com o filtro utilizado
// >Parâmetros:
//  	-um ponteiro endereçando o nome original do arquivo
//  	-um int com o tipo do filtro aplicado 
// >Retorno:
//  	-um ponteiro endereçando o novo nome
String createNewName(String originalName, int typeFilter);

// >Função geral para escrita em disco da imagem alterada
// >Parâmetros:
//  	-um ponteiro endereçando a estrutura para os dados atuais da imagem
//  	-um ponteiro endereçando a string com o nome original do arquivo
//  	-um int com o tipo de filtro a ser aplicado
// >Retorno:
//  	-um ponteiro endereçando a string com o novo nome do arquivo alterado
String writeFile(Image *img, String originalName, int typeFilter);

#endif