// .c auxilar a biblioteca "data.h"

#include "write.h"

void negativeFilter(Colors *pallet) {
	for (int i = 0; i < PALLETSIZE; i++) {
		pallet[i].red = (unsigned char)(RGBMAX - (int)pallet[i].red);
		pallet[i].green = (unsigned char)(RGBMAX - (int)pallet[i].green);
		pallet[i].blue = (unsigned char)(RGBMAX - (int)pallet[i].blue);
	}
}

void blackAndWhiteFilter(Colors *pallet) {
	int average;
	for (int i = 0; i < PALLETSIZE; i++) {
		average = ((int)pallet[i].red + (int)pallet[i].green + (int)pallet[i].blue) / 3;
		pallet[i].red = (unsigned char)average;
		pallet[i].green = (unsigned char)average;
		pallet[i].blue = (unsigned char)average;
	}
}

String createNewName(String originalName, int typeFilter) {
	String newName;
	// Cria o trecho a ser adicionado
	String add;
	if (typeFilter == 1) {
		newName = (char *) malloc((strlen(originalName) + 9) * sizeof(char));
		char aux[9] = {'N', 'e', 'g', 'a', 't', 'i', 'v', 'o', '\0'};
		add = aux;
	}
	else if (typeFilter == 2) {
		newName = (char *) malloc((strlen(originalName) + 12) * sizeof(char));
		char aux[12] = {'P', 'r', 'e', 't', 'o', 'B', 'r', 'a', 'n', 'c', 'o', '\0'};
		add = aux;
	}

	// Cria a novo nome por partes com base na estrutura inicial
	//   name    .bmp'\0'
	// |parte1| |-parte2-|
	int lengthPart1 = strlen(originalName) - 4;
	int i = 0, j = 0;
	while (j < strlen(originalName) + 1) {
		newName[i++] = originalName[j++];
		if (i == lengthPart1) {
			int k = 0;
			while (k < strlen(add)) {
				newName[i++] = add[k++];
			}
			continue;
		}
	}

	return newName;
}

String writeFile(Image *img, String originalName, int typeFilter) {
	// Aplica o filtro na paleta de cores
	if (typeFilter == 1) negativeFilter(img->pallet);
	else if (typeFilter == 2) blackAndWhiteFilter(img->pallet);

	// Cria o novo nome
	String newName = createNewName(originalName, typeFilter);

	// Cria um novo arquivo em disco para a imagem pós aplicação do filtro
	FILE *imgPtr = fopen(newName, "wb");
	if (imgPtr == NULL) {
		perror("Erro na abertura do arquivo para escrita");
		exit(EXIT_FAILURE);
	}

	// Escreve o cabeçalho de arquivo na struct
	// fwrite(&img->fileData, sizeof(img->fileData), 1, imgPtr);
	fwrite(&img->fileData.signature, sizeof(img->fileData.signature), 1, imgPtr);
	fwrite(&img->fileData.fileSize, sizeof(img->fileData.fileSize), 1, imgPtr);
	fwrite(&img->fileData.reservedField, sizeof(img->fileData.reservedField), 1, imgPtr);
	fwrite(&img->fileData.displacement, sizeof(img->fileData.displacement), 1, imgPtr);

	// Escreve o cabeçalho de mapa de bits na struct
	fwrite(&img->imgData.headerSize, sizeof(img->imgData.headerSize), 1, imgPtr);
	fwrite(&img->imgData.width, sizeof(img->imgData.width), 1, imgPtr);
	fwrite(&img->imgData.heigth, sizeof(img->imgData.heigth), 1, imgPtr);
	fwrite(&img->imgData.numPlanes, sizeof(img->imgData.numPlanes), 1, imgPtr);
	fwrite(&img->imgData.bitsPerPx, sizeof(img->imgData.bitsPerPx), 1, imgPtr);
	fwrite(&img->imgData.compression, sizeof(img->imgData.compression), 1, imgPtr);
	fwrite(&img->imgData.imgSize, sizeof(img->imgData.imgSize), 1, imgPtr);
	fwrite(&img->imgData.pxResolutionH, sizeof(img->imgData.pxResolutionH), 1, imgPtr);
	fwrite(&img->imgData.pxResolutionV, sizeof(img->imgData.pxResolutionV), 1, imgPtr);
	fwrite(&img->imgData.numUsedColors, sizeof(img->imgData.numUsedColors), 1, imgPtr);
	fwrite(&img->imgData.numImportantColors, sizeof(img->imgData.numImportantColors), 1, imgPtr);

	// Escreve a paleta de cores na struct
	for (int i  = 0; i < PALLETSIZE; i++) {
		fwrite(&img->pallet[i], sizeof(img->pallet[i]), 1, imgPtr);
	}

	int heigth = img->imgData.heigth;
	int padding = (img->imgData.width % 4) ? (4 - img->imgData.width % 4) : 0;
	int width = img->imgData.width + padding;
	// Escreve a área de dados da imagem na struct
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			fwrite(&img->pixels[i][j], sizeof(unsigned char), 1, imgPtr);
		}
	}
	fclose(imgPtr);

	return newName;
}
