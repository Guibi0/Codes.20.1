/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Guilherme Rios(1122839)                       |
 *******************************************************************************
 >Programa que substitui uma palavras em frases
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIM 1
#define NAO 0
#define QTDAINICIAL 100
#define TAMANHOINICIAL 100

// >Função que recebe uma string, incluindo espaços
// >Parâmetros: 
//   -não há parâmetros
// >Retorno: 
//   -ponteiro que endereça a string
char *recebeString() {
    char *string = (char *) malloc(TAMANHOINICIAL * sizeof(char));
    int tamanho = TAMANHOINICIAL;
     
    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == tamanho) {
            tamanho *= 2;
            string = (char *) realloc(string, tamanho * sizeof(char));
        }
        
        // Recebe caracter por caracter
        string[i] = fgetc(stdin);

        // Lê o '\n' pós '\r'
        if(string[i] == '\r') string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

//>Função que confere se a existe uma palavra em um pedaço da frase 
//>Parâmetros: 
//  -ponteiro um para a palavra procurada
//  -int com a posição inicial na palavra
//  -ponteiro um para a frase onde ocerrerá a conferência
//>Retorno: 
//   -int com a situação com a relação a presença
int conferePresenca(char *palavra, int posP, char *frase, int posF) {

    int resultado = SIM;
    //Analisa char a char até o fim da palavra
    while (palavra[posP] != '\0' && resultado == SIM) {

        if (palavra[posP] != frase[posF]) resultado = NAO;
        
        posF++; 
        posP++;
    }

    //Analisa o char seguinte a palavra não é uma letra
    if (resultado == SIM) { 
        resultado = NAO;

        //Espaço, '\0', e pontuações
        char validos[] = {' ', '\0', ',', '.', '!', ';', ':', '?', '(', ')'};
        for (int i = 0; i < 11 && resultado == NAO; i++) {
            if (frase[posF] == validos[i]) resultado = SIM;
        }
    }

    return resultado;
}

//>Função que escreve a nova palavra na frase modificada
//>Parâmetros: 
//  -ponteiro um para a palavra que sera adicionada
//  -ponteiro um para a frase onde ocerrerá a adição
//  -int com a posição de partida na frase
//  -int com a tamanho atual da frase
//>Retorno: 
//  -ponteiro com frase modificada
char *adcionaPalavraNova(char *palavra, char *frase, int posF, int tam) {

    for (int i = 0; palavra[i] != '\0'; i++, posF++) {
        //Realoca a string em um espaço maior caso necessário
        if (posF == tam) {
            frase = (char *) realloc(frase, 2 * tam * sizeof(char));
            tam *= 2;
        }

        //Escreve caracter por caracter
        frase[posF] = palavra[i];
    }   

    return frase;
}

//>Função que troca strings em uma frase
//>Parâmetros: 
//   -um ponteiros enderençando a frase 
//   -um ponteiros enderençando a palavra antiga
//   -um ponteiros enderençando a palavra nova
//>Retorno: 
//   -um ponteiro com a nova frase
char *trocaString(char *pAntiga, char *pNova, char *fAntiga) {
    
    //Declara string que receberá a nova frase
    char *fNova = (char *) malloc(50 * sizeof(char));
    int tamanho = 50;
     
    //Cria a nova string
    int fa = 0;
    int fn = 0;
    while (fAntiga[fa] != '\0') {

        //Realoca a string em um espaço maior caso necessário
        if (fa == tamanho) {
            fNova = (char *) realloc(fNova, 2 * tamanho * sizeof(char));
            tamanho *= 2;
        }

        //Detecta presença da palavra antiga
        int pPresente = NAO;
        if (fAntiga[fa] == pAntiga[0]) {
            if (fa == 0 || fAntiga[fa - 1] == ' ') {
                pPresente = conferePresenca(pAntiga, 0, fAntiga, fa);
            }
        }
        
        //Escreve a palavra nova caso necessário
        if (pPresente == SIM) {
            fNova = adcionaPalavraNova(pNova, fNova, fn, tamanho);
            
            fa += strlen(pAntiga);
            fn += strlen(pNova);
        }else {
            fNova[fn] = fAntiga[fa];

            fa++;
            fn++;
        }
    }
    //Fecha a string
    fNova[fn] = '\0';
    fNova = realloc(fNova, (fn + 1) * sizeof(char));

    return fNova;
}

//Funçãon principal
int main() {

    //Recebe as palavras e a frase 
    char *palavraAntiga = recebeString();
    char *novaPalavra = recebeString();
    char *fraseAntiga = recebeString();

    //Troca a palavra nova pela antiga, caso a primeira conste na frase
    char *novaFrase = trocaString(palavraAntiga, novaPalavra, fraseAntiga);

    //Imprime a nova frase
    printf("%s\n", novaFrase);

    free(palavraAntiga);
    free(novaPalavra);
    free(fraseAntiga);
    free(novaFrase);
    return 0;
}