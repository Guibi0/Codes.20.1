// .c auxilar a biblioteca "data.h"

#include "data.h"

String readName() {
    int size = INITIALSIZE;
    char *string = (char *) malloc(size * sizeof(char));

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
        if (string[i] == '\r') string[i] = fgetc(stdin);

        i++;
    }while (string[i - 1] != '\n' && string[i - 1] != EOF);

    string[i - 1] = '\0';
    string = (char *) realloc(string, i * sizeof(char));

    return string;
}

Colors *saveOriginalPallet(Colors *pallet) {
    Colors *originalPallet = (Colors *) malloc(PALLETSIZE * sizeof(Colors));
    for (int i = 0; i < PALLETSIZE; i++) originalPallet[i] = pallet[i];
    return originalPallet;
}

void printData(Image *img, Colors *originalPallet, String newName) {
    // Imprime cabeçalho
    printf("CABECALHO:\n");
    printf("Iniciais: %c%c\n", img->fileData.signature[0], img->fileData.signature[1]);
    printf("Tamanho do arquivo: %d\n", img->fileData.fileSize);
    printf("Reservado: %d\n", img->fileData.reservedField);
    printf("Deslocamento, em bytes, para o inicio da area de dados: %d\n", img->fileData.displacement);
    printf("Tamanho em bytes do segundo cabecalho: %d\n", img->imgData.headerSize);
    printf("Resolucao: %d x %d\n", img->imgData.width, img->imgData.heigth);
    printf("Numero de planos: %hd\n", img->imgData.numPlanes);
    printf("Bits por pixel: %hd\n", img->imgData.bitsPerPx);
    printf("Compressao usada: %d\n", img->imgData.compression);
    printf("Tamanho imagem: %d\n", img->imgData.imgSize);
    printf("Resolucao horizontal: %d pixel por metro\n", img->imgData.pxResolutionH);
    printf("Resolucao Vertical: %d pixel por metro\n", img->imgData.pxResolutionV);
    printf("Numero de cores usadas: %d\n", img->imgData.numUsedColors);
    printf("Numero de cores importantes: %d\n", img->imgData.numImportantColors);
    // Imprime paleta antiga e nova
    printf("PALETA ORIGINAL:\n");
    for (int i = 0; i < PALLETSIZE; i++) {
        printf("Paleta[%d]: R:%d G:%d B:%d\n", i, (int)originalPallet[i].red, (int)originalPallet[i].green, (int)originalPallet[i].blue); 
    }
    printf("PALETA NOVA:\n");
    for (int i = 0; i < PALLETSIZE; i++) {
        printf("Paleta[%d]: R:%d G:%d B:%d\n", i, (int)img->pallet[i].red, (int)img->pallet[i].green, (int)img->pallet[i].blue); 
    }
    // Imprime a soma de cada linha
    long long sum;
    int padding = (img->imgData.width % 4) ? (4 - img->imgData.width % 4) : 0;
    for (int i = img->imgData.heigth - 1; i >= 0; i--) {
        sum = 0; 
        for (int j = 0; j < img->imgData.width; j++) {
            sum += (int)img->pixels[i][j];
        }
        sum -= padding;
        printf("Soma linha %d: %lld\n", img->imgData.heigth - 1 - i, sum);
    }
    // Imprime o nome do arquivo gerado
    printf("%s\n", newName);
}

void deallocate(Image *img, Colors *originalPallet, String originalName, String newName) {
    // Pixels
    for (int i = 0; i < img->imgData.heigth; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);

    // Paletas
    free(originalPallet);

    // Imagens e nomes
    free(img);
    free(originalName);
    free(newName);
}
