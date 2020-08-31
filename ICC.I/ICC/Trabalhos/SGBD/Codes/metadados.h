// Biblioteca com as estruturas para o tratamento dos metadados/dados do programa
#ifndef METADADOS_H
#define METADADOS_H

#include <stdio.h>

// Defines que auxiliam na leitura do .dat
#define NOME_ARQUIVO "filename:"
#define NOME_CHAVE "key-name:"
#define TIPO_CHAVE "key-type:"
#define NOME_CAMPO "field-name:"
#define TIPO_CAMPO "field-type:"

#define INSERIR "insert"
#define INDEXAR "index"
#define BUSCAR "search"
#define SAIR "exit"

enum tipos {INT, FLOAT, DOUBLE, STRING};

enum dadosLidos {CHAVE, CAMPO};

typedef union {
	int iInt;
	float iFloat;
	double iDouble;
	char* iString;
} Info;

typedef struct {
	Info chave;
	int offset;
} Index;

typedef struct {
	int tipoChave;
	char* nomeChave;
	int tamChave;

	int* tipoCampos;
	char** nomeCampos;
	int* tamCampos;
	int qtdaDeCampos;

	char* nomeDoArquivoIdx;
	Index* idx;
	int qtdaNoIdx;
} Metadados;

typedef struct {
	int tamFicha;
	int offset;
	Info chave;
	Info* campos;
} Ficha;

typedef struct {
	char* nomeDoArquivoReg;
	Metadados ref;
	Ficha* dados;
	int qtdaDeFichas;
} Dados;

void defineOTipo(char*, int*);
int encontraTamanhoParaStrings(char*);
void recebeInfo(Info*, int, int);
void escreveDadoNoArq(Info*, int, int, FILE*);

#endif