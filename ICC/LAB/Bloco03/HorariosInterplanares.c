/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que converte segundos pra dias, horas, minutos planetas diferentes
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIM 1
#define NAO 0

//Define para guardar os valores em segundos da duração de um dia em cada planetas 
#define DIATERRA 24 * 60 * 60
#define DIAVENUS 243 * 24 * 60 * 60
#define DIAMERCURIO (58 * 24 + 16) * 60 * 60
#define DIAJUPITER (9 * 60 + 56) * 60

//Estrutura para o tempo convertido
typedef struct{
    int dias;
    int horas;
    int minutos;
    int segundos;
}Tempo;

//>Função que recebe uma string, incluindo espaços
//>Parâmetros: 
//  -Não há parâmetros
//>Retorno: 
//  -Um ponteiro que endereça a string
char *recebeNome() {
    
    char *string = (char *) malloc(8 * sizeof(char));
    int tamanho = 8;
     
    //Lê a string
    int i = 0;
    do {
        //Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
        	tamanho *= 2;
        	string = (char *) realloc(string, tamanho * sizeof(char));
        }
    	
    	//Recebe caracter por caracter
        string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != '\r' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

//>Função que realiza os cálculos do programa
//>Parâmetros:
//  -Um long int com a quantidade total de tempo em segundos
//  -Uma string com o nome do planeta que será o parâmetro
//>Retorno:
//  -Uma struct do tipo Tempo com os dados do tempo convertido
Tempo converteTempo(long int tempoSeg, char *planeta) {

    //Declara a estrura
    Tempo convertido;

    // Define a base de conversão de acordo com o planeta da entrada
    int base;
    if (strcmp(planeta, "Terra") == 0) base = DIATERRA;
    else if (strcmp(planeta, "Venus") == 0) base = DIAVENUS;
    else if (strcmp(planeta, "Mercurio") == 0) base = DIAMERCURIO;
    else if (strcmp(planeta, "Jupiter") == 0) base = DIAJUPITER;

    //Calcula, ultilizando divisão euclidiana, a quantidade de...
    //...dias
    convertido.dias = tempoSeg / base;
    tempoSeg %= base;
    
    //...segundos
    convertido.segundos = tempoSeg % 60;
    tempoSeg /= 60;

    //...minutos
    convertido.minutos = tempoSeg % 60;
    tempoSeg /= 60;

    //...horas
    convertido.horas = tempoSeg;

    return convertido;
}

//Função principal
int main() {

    // Recebe tempo total em segundos terráqueos
    long int tempoSegundos;
    scanf("%ld ", &tempoSegundos);

    // Recebe o nome do planeta referência para a conversão
    char *planeta = recebeNome();

    //Chama a função que calcula o resultado
    Tempo c = converteTempo(tempoSegundos, planeta);
    
    //Imprime a saída
    printf("%ld segundos no planeta %s equivalem a:\n", tempoSegundos, planeta);
    printf("%d dias, %d horas, %d minutos e %d segundos\n", c.dias, c.horas, c.minutos, c.segundos);

    free(planeta);
    return 0;
}