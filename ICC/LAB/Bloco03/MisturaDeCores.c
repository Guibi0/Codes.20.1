/******************************************************************************
|                        USP-Universidade de São Paulo                        |
|            ICMC-Instituto de Ciências Matemáticas e de Computação           |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2020/1                                    |
|                                                                             |
|                        Autor: Guilherme Rios(1122839)                       |
*******************************************************************************
>Programa que mistura cores de uma paleta   
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Função que recebe a paleta
//Parâmetros:
//	-um ponteiro duplo que endereça a matriz para a leitura das 6 possíveis cores da paleta
//Retorno:
//	-não há retorno
void recebePaleta(int **paleta) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) scanf("%d ", &paleta[i][j]);
    }
}

//Função que imprime a paleta
//Parâmetros:
//	-um ponteiro duplo que endereça a matriz com a paleta 
//Retorno:
//	-não há retornos
void imprimePaleta(int **paleta) {

    for (int i = 0; i < 6; i++) {
        
        printf("Color(%d): [", i);
        for (int j = 0; j < 3; j++) printf("\t%d", paleta[i][j]);
        printf("\t]\n");
    }
}

int main() {

    //Recebe as cores a serem misturadas e a posição da mistura resultante
    int cor1, cor2, posMistura;
    scanf("%d %d %d\n", &cor1, &cor2, &posMistura);

    //Recebe as cores iniciais da paleta
    int **paleta = (int* *) malloc(6 * sizeof(int*));
    for (int i = 0; i < 6; i++) paleta[i] = (int *) malloc(3 * sizeof(int));
    recebePaleta(paleta);

    //Imprime o estado inicial da paleta
    printf("Start:\n");
    imprimePaleta(paleta);

    //Mistura as cores
    for (int j = 0; j < 3; j++) {
     
        paleta[posMistura][j] += paleta[cor1][j] / 2 + paleta[cor2][j] / 2;

        //Garante que não sejam utilizadas tonalidades inexistentes
        if (paleta[posMistura][j] > 255) paleta[posMistura][j] = 255;
    }    
    
    //Imprime o estado final da paleta
    printf("\nResult:\n");
    imprimePaleta(paleta);

    for (int i = 0; i < 3; i++) free(paleta[i]);
    free(paleta);
    return 0;
}