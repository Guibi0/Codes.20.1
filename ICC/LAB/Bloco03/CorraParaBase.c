/******************************************************************************
|                        USP-Universidade de São Paulo                        |
|            ICMC-Instituto de Ciências Matemáticas e de Computação           |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2020/1                                    |
|                                                                             |
|                        Autor: Guilherme Rios(1122839)                       |
*******************************************************************************
>Programa que analisa a situação em um jogo de RPG
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main() {

    //Recebe o tamanho do mapa de jogo
    int numLinhas, numColunas;
    scanf("%d %d\n", &numLinhas, &numColunas);

    //Recebe os dados do jogador: coordenadas no mapa e o atributo de movimento
    int jogLinha, jogColuna;
    double movimento;
    scanf("%d %d %lf", &jogLinha, &jogColuna, &movimento);

    //Recebe a matriz do mapa, guardando as coordenadas da base que deve ser alcançada pelo jogador
    int mapa[numLinhas][numColunas];
    int baseLinha, baseColuna;
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            
            scanf("%d ", &mapa[i][j]);
            
            //Encontra a base
            if (mapa[i][j] == 1) {
                
                baseLinha = i;
                baseColuna = j;
            }
        }
    }

    //Realiza o cálculo da distância até a base
    double distancia = sqrt(pow(jogLinha - baseLinha, 2) + pow(jogColuna - baseColuna, 2));

    //Define o resultado da rodada
    if (movimento >= distancia) printf("Voce escapou!\n");
    else printf("Game Over!\n");

    return 0;
}