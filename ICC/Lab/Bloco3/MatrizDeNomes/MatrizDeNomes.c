/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 > Programa que ordena 5 nomes recebidos na entrada e os imprime
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOINICIAL 1080
#define QTDADENOMES 5

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//    -não há parâmetros
// >Retorno: 
//    -ponteiro que endereça a string
char* recebeNome(FILE* ptr) {
    int tam = TAMANHOINICIAL;
    char* string = (char*) malloc(tam * sizeof(char));

    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tam) {
            tam *= 2;
            string = (char*) realloc(string, tam * sizeof(char));
        }

        // Recebe caracter por caracter
        string[i] = fgetc(ptr);

        // Lê o '\n' pós '\r'
        if(string[i] == '\r') string[i] = fgetc(ptr);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char*) realloc(string, i * sizeof(char));

    return string;
}

// Função auxiliar a função "qsort"
int comparaNomes(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {

    // Recebe nomes
    char **nomes = (char**) malloc(QTDADENOMES * sizeof(char*));
    for (int i = 0; i < QTDADENOMES; i++) nomes[i] = recebeNome(stdin);

    // Ordena nomes
    qsort(nomes, QTDADENOMES, sizeof(char*), comparaNomes);
    
    // Imprime os nomes e libera memória
    for (int i = 0; i < QTDADENOMES; i++) {
        printf("%s\n", nomes[i]);
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}