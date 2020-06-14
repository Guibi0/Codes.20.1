// .c auxilar a biblioteca "data.h"

#include "data.h"

String readName() {
    int size = INITIALSIZE;
    char *string = string = (char *) malloc(size * sizeof(char))

    // Lê a string
    int i = 0;
    do {
        // Realoca a string em um espaço maior caso necessário
        if (i == size) {
        	size *= 2;
        	string = (char *) realloc(string, size * sizeof(char));
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

void printData(Image *img, String newName) {
    // Imprime cabeçalho
    printf("CABECALHO:\n");
    printf("Iniciais: %c%c\n", img->fileData.signture[0], img->file.signture[1]);
    printf("Tamanho do arquivo: %d\n", img->fileData.fSize);
    printf("Reservado: %d\n", img->fileData.reservedField);
    printf("Deslocamento, em bytes, para o inicio da area de dados: %d\n", img->fileData.displacement);
    printf("Tamanho em bytes do segundo cabecalho: %d\n", img->imgData.headerSize);
    printf("Resolucao: %d x %d\n", img->imgData.width, img->imgData.heigth);
    printf("Numero de planos: %hd\n", img->imgData.numPlanes);
    printf("Bits por pixel: %hd\n", img->imgData.bitPerPx);
    printf("Compressao usada: %d\n", img->imgData.compression);
    printf("Tamanho imagem: %d\n", img->imgData.imgSize);
    printf("Resolucao horizontal: %d pixel por metro\n", img->imgData.pxResolutionH);
    printf("Resolucao Vertical: %d pixel por metro\n", img->imgData.pxResolutionV);
    printf("Numero de cores usadas: %d\n", img->imgData.numUsedColors);
    printf("Numero de cores importantes: %d\n", img->imgData.numImportantColors);
    // Printa paleta antiga e nova
    printf("PALETA ORIGINAL\n");
    for (int i = 0; i < SIZEPALLET; i++) {
        printf("Paleta[i]: R:%d G:%d B:%d\n", (int)img->pallet[i]->red, (int)img->pallet[i]->green, (int)img->pallet[i]->blue); 
    }
    printf("PALETA NOVA\n");
    for (int i = 0; i < SIZEPALLET; i++) {
        printf("Paleta[i]: R:%d G:%d B:%d\n", int(img->pallet[i]->red), int(img->pallet[i]->green), int(img->pallet[i]->blue)); 
    }
    // Printa a soma de cada linha
    long long sum;
    for (int i = img->imgData.heigth -1; i >= 0; i--) {
        sum = 0;
        for (int j = 0; j < img->imgData.width; j++) {
            sum += ((int)img->pixels[i][j] >= '0' && (int)img->pixels[i][j] <= '9') ? (long long)img->pixels[i][j] : -1;
        }
        printf("Soma linha %d: %lld\n", sum);
    }
    // Printa o nome do arquivo gerado
    printf("%s\n", newName);
}

void dealloctace(Image *img, String originalName, String newName) {
    // Pixels
    for (int i = 0; i < img->imgData.heigth; i++) {
        free(img->imgData.pixels[i]);
    }
    free(img->imgData.pixels);

    // Paleta
    free(img->pallet);

    // Imagens e nomes
    free(img);
    free(originalName);
    free(newName);
}
