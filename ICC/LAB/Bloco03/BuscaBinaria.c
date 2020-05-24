/******************************************************************************
|                        USP-Universidade de São Paulo                        |
|            ICMC-Instituto de Ciências Matemáticas e de Computação           |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2020/1                                    |
|                                                                             |
|                        Autor: Guilherme Rios(1122839)                       |
*******************************************************************************
>Programa que realiza uma busca binária
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SIM 1
#define NAO 0
#define AUSENTE -1

//Função que recebe inteiros para um vetor
//Parâmetros:
//	-um ponteiro que endereça o vetor
//  -um inteiro com o tamanho do vetor
//Retorno:
//	-não há retorno
void recebeVetor(int *vetor, int tam) {

    //Laço que lê a entrada
    for (int i = 0; i < tam; i++) scanf("%d ", &vetor[i]);
}

//Função que ordena um vetor de inteiros com um bubble sort
//Parâmetros:
//	-um ponteiro que enderça o vetor original
//  -um inteiro com o tamanho do vetor  
//Retorno:
//	-o mesmo ponteiro endereçando o vetor alterado para o estado de ordenação
void ordenaVetor(int *vetor, int tam) {

    //Bubble sort
    int ordenado;
    int i, j, temp;
    do {

        ordenado = SIM;

        for(i = 0, j = i + 1; j < tam; i++, j++) {

            if (vetor[i] > vetor[j]) {
                ordenado = NAO;
                
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
        tam --;

    }while (ordenado == NAO);
}

//Função recursiva que realiza uma busca binária em um vetor de inteiros
//Parâmetros:
//	-um inteiro com a chave buscada
//  -um ponteiro que endereça o vetor já ordenado
//  -um inteiro com o índice inicial
//  -um inteiro com o índice final(que no primeiro laço é o tamanho do vetor)
//Retorno:
//	-um inteiro com o resultado da busca
int buscaBinaria(int chave, int *vetor, int inicio, int fim) {
    
    int meio = inicio + (fim - inicio) / 2;
    //Caso para quando a chave não for encontrada
    if (inicio > fim) return AUSENTE;
    //Retornando a o índice da chave encontrada
    else if (vetor[meio] == chave) return meio;

    //Chama a recursão enquanto a busca binária não acabar
    else {

        if (vetor[meio] > chave) return buscaBinaria(chave, vetor, inicio, meio - 1);
        
        else return buscaBinaria(chave, vetor, meio + 1, fim);   
    }
}

//Função principal
int main() {

    //Recebe a quantidade de números no vetor e o inteiro que deve ser buscado nele
    int tamVetor, chaveBuscada;
    scanf("%d %d\n", &tamVetor, &chaveBuscada);

    //Recebe os inteiros do vetor
    int *vetor = (int *) malloc(tamVetor * sizeof(int));
    recebeVetor(vetor, tamVetor);

    //Ordena o vetor, preparando-o para uma busca binária
    ordenaVetor(vetor, tamVetor);

    //Procura a chave
    int resposta = buscaBinaria(chaveBuscada, *&vetor, 0, tamVetor);
    
    //Imprime o resultado da busca
    if (resposta == AUSENTE) printf("Chave inexistente\n");
    else printf("%d\n", resposta);

    free(vetor);
    return 0;
}