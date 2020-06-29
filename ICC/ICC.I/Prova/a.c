
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define READLINE_BUFFER 4096

char *readLine(FILE *stream){
    char *string = 0;
    int i = 0;

    do{
        if(i % READLINE_BUFFER == 0){
            string = (char *) realloc(string,(i / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[i] = fgetc(stream);
        i++;
    } while(string[i-1] != '\n' && string[i-1] != EOF);

    if(i >= 2 && string[i-2] == '\r'){
        string[i-2] = '\0';
        string = (char *) realloc(string, i-1);
    } else {
        string[i-1] = '\0';
    }

    return string;
}

void findNumberOfWords(FILE *fp){
    char character = fgetc(fp);
    int numberOfWords = 0;

    do{
        if(character == ' ' || character == '\n'){
            numberOfWords++;
        }
        character = fgetc(fp);
    } while(character != EOF);
    
    printf("%d\n", numberOfWords);

    return;
}

int temCoisa(char *linha) {
    if (linha[0] == '\0') {
        return 0;
    }
    else return 1;
}

void findShortestWord(FILE *fp){
    rewind(fp);
    
    char *tempString = readLine(fp);
    char *shortestWord = (char *) malloc(50*sizeof(char));
    
    strcpy(shortestWord, tempString);
    free(tempString);

    while(!feof(fp)){
        tempString = readLine(fp);
        
        if (temCoisa(tempString)) {
            if(strlen(tempString) < strlen(shortestWord) && tempString[0] != '\0'){
                strcpy(shortestWord, tempString);
            }
        }
        
        free(tempString);
    }

    printf("%s\n", shortestWord);
    free(shortestWord);
    
    return;
}

void findLongestWord(FILE *fp){
    rewind(fp);
    
    char *tempString = readLine(fp);
    char *longestWord = (char *) malloc(50*sizeof(char));
    
    strcpy(longestWord, tempString);
    free(tempString);

    while(!feof(fp)){
        tempString = readLine(fp);
        
        if(temCoisa(tempString)){
            if(strlen(tempString) > strlen(longestWord)){
                strcpy(longestWord, tempString);
            }
        }
        
        free(tempString);
    }

    printf("%s\n", longestWord);
    free(longestWord);
    
    return;
}

void findFirstPatternOccurrences(FILE *fp, char *firstPattern){
    rewind(fp);

    char *tempString;
    int firstPatternOccurrences = 0;

    regex_t regex;
    int pattern = regcomp(&regex, firstPattern, REG_EXTENDED);

    while(!feof(fp)){
        tempString = readLine(fp);

        if(temCoisa(tempString)){
            pattern = regexec(&regex, tempString, 0, NULL, 0);
            if(!pattern){
                firstPatternOccurrences++;
            }
        }

        free(tempString);
    }

    printf("%d\n", firstPatternOccurrences);
    regfree(&regex);

    return;
}

int isPalindrome(char *tempString){
    for(int i = 0; i < strlen(tempString); i++){
        if(tempString[i] != tempString[strlen(tempString)-i-1]){
            return 0;
        }
    }
    return 1;
}

void findNumberOfPalindromes(FILE *fp){
    rewind(fp);
    
    char *tempString;
    int numberOfPalindromes = 0;

    while(!feof(fp)){
        tempString = readLine(fp);
        
        if(temCoisa(tempString)){
            if(isPalindrome(tempString)){
                numberOfPalindromes++;
            }
        }
        free(tempString);
    }

    printf("%d\n", numberOfPalindromes);

    return;
}

void findLongestSecondPatternWord(FILE *fp, char *secondPattern){
    rewind(fp);

    char *tempString = readLine(fp);
    char *longestSecondPatternWord = (char *) malloc(50*sizeof(char));
    
    strcpy(longestSecondPatternWord, tempString);
    free(tempString);

    regex_t regex;
    int pattern = regcomp(&regex, secondPattern, REG_EXTENDED);

    while(!feof(fp)){
        tempString = readLine(fp);

        if(temCoisa(tempString)){
            pattern = regexec(&regex, tempString, 0, NULL, 0);
            if(!pattern && strlen(tempString) > strlen(longestSecondPatternWord)){
                strcpy(longestSecondPatternWord, tempString);
            }
        }
        
        free(tempString);
    }

    printf("%s\n", longestSecondPatternWord);
    free(longestSecondPatternWord);
    regfree(&regex);

    return;
}

int comparator(const void *a, const void *b){
    return strcmp(*(const char **) a, *(const char **) b);
}

void findThirdPatternWords(FILE *fp, char *thirdPattern){
    rewind(fp);
    
    char *tempString;
    int numberOfWords = 0;
    
    regex_t regex;
    int pattern = regcomp(&regex, thirdPattern, REG_EXTENDED);

    while(!feof(fp)){
        tempString = readLine(fp);
        
        if(temCoisa(tempString)){
            pattern = regexec(&regex, tempString, 0, NULL, 0);
            if(!pattern){
                numberOfWords++;
            }
        }

        free(tempString);
    }
    
    char **thirdPatternWords = (char **) malloc(numberOfWords*sizeof(char *));
    int i = 0;
    
    rewind(fp);

    while(!feof(fp)){
        tempString = readLine(fp);
        
        if(temCoisa(tempString)){
            pattern = regexec(&regex, tempString, 0, NULL, 0);
            if(!pattern){
                thirdPatternWords[i] = tempString;
            } else {
                free(tempString);
            }
        } else {
        }
        i++;
    }

    qsort(thirdPatternWords, numberOfWords, sizeof(char *), comparator);

    for(int j = 0; j < numberOfWords; j++){
        printf("%s\n", thirdPatternWords[j]);
        free(thirdPatternWords[j]);
    }
    free(thirdPatternWords);
    regfree(&regex);

    return;
}

int **allocArray(int rows, int columns){
    int **array = (int **) calloc(rows, sizeof(int *));

    for (int i = 0; i < rows; i++){
        array[i] = (int *) calloc(columns, sizeof(int));
    }

    return array;
}

void freeArray(int **array, int rows){
    for (int i = 0; i < rows; i++){
        free(array[i]);
    }
    
    free(array);
    return;
}

int compareStrings(char *tempString, char *wordW){  
    int wordWLen = strlen(wordW);
    int tempStringLen = strlen(tempString);

    int **array = array = allocArray(wordWLen, tempStringLen);
    
    int similarity = 0;

    for(int i = 0; i < wordWLen; i++){
        for(int j = 0; j < tempStringLen; j++){
            if(wordW[i] == tempString[j]){
                if(i == 0 || j == 0){
                    array[i][j] = 1;
                }else{
                    array[i][j] = array[i-1][j-1] + 1;
                }
            }else if(wordW[i] != tempString[j] && i != 0 && j != 0){
                array[i][j] = array[i-1][j-1];
            }

            if(array[i][j] > similarity){
                similarity = array[i][j];
            }
        }
    }

    freeArray(array, wordWLen);
    return similarity;
}

void findClosestWordToW(FILE *fp, char *wordW){
    rewind(fp);
    
    char *tempString;
    char *closestWordToW = (char *) malloc(50*sizeof(char));

    int tempSimilarity = 0;
    int highestSimilarity = 0;

    while(!feof(fp)){
        tempString = readLine(fp);

        if(temCoisa(tempString)){
            tempSimilarity = compareStrings(tempString, wordW);

            if(tempSimilarity > highestSimilarity){
                strcpy(closestWordToW, tempString);
                highestSimilarity = tempSimilarity;
            }else if(tempSimilarity == highestSimilarity){
                if(strlen(tempString) < strlen(closestWordToW)){
                    strcpy(closestWordToW, tempString);
                }
            }
        }
        
        free(tempString);
    }

    printf("%s\n", closestWordToW);
    free(closestWordToW);

    return;
}

void freeProgram(char *fileName, char *firstPattern, char *secondPattern, char *thirdPattern, char *wordW){
    free(fileName);
    free(firstPattern);
    free(secondPattern);
    free(thirdPattern);
    free(wordW);

    return;
}

int main(int argc, char *argv[]){
    char *fileName = readLine(stdin);
    char *firstPattern = readLine(stdin);
    char *secondPattern = readLine(stdin);
    char *thirdPattern = readLine(stdin);
    char *wordW = readLine(stdin);

    FILE *fp;
    fp = fopen(fileName, "r");

    findNumberOfWords(fp);
    findShortestWord(fp);
    findLongestWord(fp);
    findFirstPatternOccurrences(fp, firstPattern);
    findNumberOfPalindromes(fp);
    findLongestSecondPatternWord(fp, secondPattern);
    findThirdPatternWords(fp, thirdPattern);
    findClosestWordToW(fp, wordW);

    freeProgram(fileName, firstPattern, secondPattern, thirdPattern, wordW);    
    fclose(fp);

    return 0;
}
