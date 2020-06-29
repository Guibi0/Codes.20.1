// Alexandre Brito Gomes 11857323
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

// Realiza a leitura das linhas
char *readLine(FILE* input) {
    char *string = NULL;
    int counter = 0;
    char c;

    do {
        c = fgetc(input);
        if ( c != '\r'){
            string = (char*) realloc(string, sizeof(char) * (counter + 1));
            string[counter++] = c;
        }
    } while (c != '\n' && c != EOF);

    string[--counter] = '\0';
    return string;
}

// Retorna a palavra de menor tamanho
char *shortestWord(char **strings, int counter){ 
    char *word = strings[0];
    for (int i = 1; i < counter; i++){
        if (strlen(word) > strlen(strings[i])){
            word = strings[i];
        }       
    }
    return word;
}

// Retorna a palavra de maior tamanho
char *longestWord(char **strings, int counter){ 
    char *word = strings[0];
    for (int i = 1; i < counter; i++){
        if (strlen(word) < strlen(strings[i])){
            word = strings[i];
        }       
    }
    return word;
}

// Conta a quantidade de palíndromos
int countPalindromes(char **strings, int counter){
    int quantity = 0;
    // Percorre todas as palavras
    for (int i = 0; i < counter; i++){        
        int size = (strlen(strings[i])), isPalindrome = 1;
        // isPalindrome é uma flag, sendo 1 para palíndromo e 0 não
        for (int j = 0, k = size - 1; j < k; j++, k--){
            if (strings[i][j] != strings[i][k]){
                isPalindrome = 0;
            }
        }
        if (isPalindrome == 1){
            quantity++;
        }                 
    }
    return quantity;
}

// Verifica a quantidade de palavras pertencentes ao padrão P1
int isP1(char **strings,char *P1, int counter){
    int quantity = 0;
    regex_t regex;
    regcomp(&regex,P1,REG_EXTENDED); 
    for (int i = 0; i < counter; i++){
        if (!regexec(&regex,strings[i],0,NULL,0)){
            quantity++;
        }       
    }   
    regfree(&regex);
    return quantity;
} 

// Imprime a maior palavra pertencente ao padrão P2
void longestP2(char **strings, char *P2, int counter){ 
    int quantity = 0;
    char **p2Words = (char**) malloc(counter * sizeof(char*));
    char *longestWord;
    regex_t regex;
    regcomp(&regex,P2,REG_EXTENDED); 
    for (int i = 0; i < counter; i++){ //Obtem as palavras com padrão P2
        if (!regexec(&regex,strings[i],0,NULL,0)){
            p2Words[quantity] = strings[i];
            quantity++;      
        }       
    }

    longestWord = p2Words[0];
    for (int i = 1; i < quantity; i++){
        if (strlen(p2Words[i]) > strlen(longestWord)){
            longestWord = p2Words[i];
        }
        
    }
    free(p2Words);
    printf("%s\n",longestWord);

    regfree(&regex);
}

// Função que serve de como compare para o qsort()
int compare(const void *a,  const void *b){
    return (strcmp((*(char* *)a),(*(char* *)b)));
}

// Ordena utilizando qsort() e imprime todas as palavras pertencentes ao padrão P3
void orderAndPrintP3(char** strings, char *P3, int counter){
    int quantity = 0;
    char **p3Words = (char**) malloc(counter * sizeof(char*));;
    regex_t regex;
    regcomp(&regex,P3,REG_EXTENDED); 
    for (int i = 0; i < counter; i++){
        if (!regexec(&regex,strings[i],0,NULL,0)){
            p3Words[quantity] = strings[i];
            quantity++;
        }       
    }
    qsort(p3Words,quantity,sizeof(char *),compare);

    for (int i = 0; i < quantity; i++){
        printf("%s\n",p3Words[i]);
    }
    free(p3Words);
    regfree(&regex);
}

void similarWord(char *W, char **strings, int counter){

    char ***matrix = (char***) calloc(counter, sizeof(char **));
    int lengthW = strlen(W);
 
    int maxSimilarity = 0;
    int posSimilarWord = 0;
    // Percorre todas as palavras    
    for (int h = 0; h < counter; h++){
        matrix[h] = (char**) calloc(lengthW, sizeof(char *));

        int lengthWord = strlen(strings[h]);
        //Percorre linha e coluna da matriz das duas palavras
        for (int i = 0; i < lengthW; i++){
            matrix[h][i] = (char*) calloc(lengthWord, sizeof(char));

            for (int j = 0; j < lengthWord; j++){
                if ((i && j) != 0) {
                    matrix[h][i][j] = matrix[h][i - 1][j - 1];
                }
                if (W[h] == strings[h][j]) {
                    matrix[h][i][j]++;
                }

                if (matrix[h][i][j] > maxSimilarity){
                    printf("%s\n", strings[h]);
                    maxSimilarity = matrix[h][i][j];
                    posSimilarWord = h;
                }
                else if (matrix[h][i][j] == maxSimilarity){
                    printf(">>>>>>%s\n", strings[h]);
                    if (strlen(strings[h]) < strlen(strings[posSimilarWord])){
                        posSimilarWord = h;
                    }
                }
            }
        }
    }
    printf("%s\n", strings[posSimilarWord]);

    for (int h = 0; h < counter; h++){
        for (int i = 0; i < lengthW; i++) free(matrix[h][i]);
        free(matrix[h]);
    }
    free(matrix);

}


int main(){
    char *fileName = NULL;
    char **strings = NULL; // Armazena todas as linhas do arquivo
    int counter = 0;
    // Consistem em padrões de regex,  que serão lidos no arquivo .in,
    // e em uma palavra W para fins de busca por similaridade
    char *P1, *P2, *P3, *W;

    // Leitura dos parâmetros passados no arquivo .in    
    fileName = readLine(stdin);
    P1 = readLine(stdin);
    P2 = readLine(stdin);
    P3 = readLine(stdin);
    W = readLine(stdin);
    FILE *archive = fopen(fileName, "r"); // Abertura do arquivo

    // Lê o arquivo inteiro e conta a quantidade de palavras
    while (!feof(archive)){ 
        strings = (char**) realloc(strings, (counter + 1) * sizeof(char *));
        strings[counter] = readLine(archive);
        if (strings[counter][0] != '\0'){
            counter++;   
        }       
    }

    printf("%d\n", counter); 
    printf("%s\n",shortestWord(strings,counter));
    printf("%s\n",longestWord(strings,counter));
    printf("%d\n",isP1(strings, P1, counter));
    printf("%d\n", countPalindromes(strings,counter));
    longestP2(strings,P2,counter);
    // orderAndPrintP3(strings,P3,counter);
    similarWord(W, strings, counter);

    for (int i = 0; i < counter-1; i++){ //counter -1 pois a última linha é vazia
        free(strings[i]);
    }
    fclose(archive);
    free(P1);
    free(P2);
    free(P3);
    free(W);
    free(strings);
    free(fileName);
    return 0;
}
