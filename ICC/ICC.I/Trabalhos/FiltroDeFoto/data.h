// Biblioteca base para a organização dos dados do disco no programa

#include <std.io>
#include <stdlib.h>

#define INITIALSIZE 1024
#define PALLETSIZE 256

typedef char * String;

// Estrutura para os dados do cabeçalho de arquivo
typedef struct {
	char signature[2]; // = ['B', 'M']
	int fileSize;
	int reservedField; // = 0
	int displacement;
} FileHeader;

// Estrutura para os dados do cabeçalho de arquivo
typedef struct {
	int headerSize;
	int width;
	int heigth;
	short numPlanes; // = 0
	short bitPerPx;
	int compression; // = 0
	int imgSize;
	int pxResolutionH;
	int pxResolutionV;
	int numUsedColors;
	int numImportantColors;
} BitsMapHeader;

// Estrutura para os dados de cada cor
typedef struct {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char reserved;
} Colors;

// Estrutura com todos os dados da imagem
typedef struct {
	FileHeader fileData;
	BitsMapHeader imgData;
	Colors *pallet;
	unsigned char **pixels;
} Image;

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//		-não há parâmetros
// >Retorno: 
//		-ponteiro que endereça a string
String readName();

// >Função que imprime os dados sobre as imagens na devida formatação
// >Parâmetros:
//  	-um ponteiro endereçando a struct com os dados atuais da imagem
//  	-um ponteiro endereçando a string com o nome do novo arquivo
// >Retorno:
// 		-não há retornos
void printData(Image *img, String newName);

// >Função quue desaloca memória HEAP utilizada no programa
// >Parâmetros:
//  	-um ponteiro endereçando a struct com os dados atuais da imagem
//  	-um ponteiro endereçando a string com o nome do arquivo original
//  	-um ponteiro endereçando a string com o nome do novo arquivo
// >Retorno:
//		-não há retornos
void dealloctace(Image *img, String originalName, String newName);