// .c auxiliar a biblioteca "read.h"

#include "read.h"

int isBMP(String name, int turn) {
	if (turn == 1) {
		char type[] = {'.', 'b', 'm', 'p'};

		int size = strlen(name) - 1;
		for (int i = size, j = 3; j >= 0; i--, j--) {
			if (name[i] != type[j]) return FALSE;
		}
	}
	else if (turn == 2) {
		char type[] = {'B', 'M'};

		if (type[0] != name[0] || type[1] != name[1]) return FALSE;
	}
	return TRUE;
}

int readFile(Image *img, String name) {
	// Inicia o processo conferindo se o arquivo é do tipo devido e se existe
	if (!(isBMP(name, 1))) return NOBMP;
	else {
		FILE * imgPtr = fopen(name, "rb");
		if (imgPtr == NULL) return NOEXIST;
		else {

			fread(&img->fileData.signature, sizeof(img->fileData.signature), 1, imgPtr);
			fclose(imgPtr);

			if (!(isBMP(img->fileData.signature, 2))) return NOBMP;
			else {
				imgPtr = fopen(name, "rb");
				if (imgPtr == NULL) return NOEXIST;
				fseek(imgPtr, sizeof(img->fileData.signature), SEEK_SET);

				// Lê o cabeçalho de arquivo na struct
				fread(&img->fileData.fileSize, sizeof(img->fileData.fileSize), 1, imgPtr);
				fread(&img->fileData.reservedField, sizeof(img->fileData.reservedField), 1, imgPtr);
				fread(&img->fileData.displacement, sizeof(img->fileData.displacement), 1, imgPtr);

				// Lê o cabeçalho de mapa de bits na struct
				fread(&img->imgData.headerSize, sizeof(img->imgData.headerSize), 1, imgPtr);
				fread(&img->imgData.width, sizeof(img->imgData.width), 1, imgPtr);
				fread(&img->imgData.heigth, sizeof(img->imgData.heigth), 1, imgPtr);
				fread(&img->imgData.numPlanes, sizeof(img->imgData.numPlanes), 1, imgPtr);
				fread(&img->imgData.bitsPerPx, sizeof(img->imgData.bitsPerPx), 1, imgPtr);
				fread(&img->imgData.compression, sizeof(img->imgData.compression), 1, imgPtr);
				fread(&img->imgData.imgSize, sizeof(img->imgData.imgSize), 1, imgPtr);
				fread(&img->imgData.pxResolutionH, sizeof(img->imgData.pxResolutionH), 1, imgPtr);
				fread(&img->imgData.pxResolutionV, sizeof(img->imgData.pxResolutionV), 1, imgPtr);
				fread(&img->imgData.numUsedColors, sizeof(img->imgData.numUsedColors), 1, imgPtr);
				fread(&img->imgData.numImportantColors, sizeof(img->imgData.numImportantColors), 1, imgPtr);

				// Lê a paleta de cores na struct
				for (int i  = 0; i < PALLETSIZE; i++) {
					fread(&img->pallet[i], sizeof(img->pallet[i]), 1, imgPtr);
				}
				fclose(imgPtr); // Fecha o arquivo para evitar possíveis erros

				// Aloca a matriz para os valores de cada pixel
				int heigth = img->imgData.heigth;
				int padding = (img->imgData.width % 4) ? (4 - img->imgData.width % 4) : 0;
				int width = img->imgData.width + padding;
				img->pixels = (unsigned char **) malloc(heigth * sizeof(unsigned char *));
				for (int i = 0; i < heigth; i++) {
					img->pixels[i] = (unsigned char *) malloc(width * sizeof(unsigned char));
				}

				imgPtr = fopen(name, "r");
				if (imgPtr == NULL) return NOEXIST;
				// Coloca o ponteiro na posição correta tendo como base o final e voltando
				//a quantidade de pixels
				int numPixels = width * heigth;
				fseek(imgPtr, -numPixels * sizeof(unsigned char), SEEK_END);
				// Lê a área de dados da imagem na struct
				for (int i = 0; i < heigth; i++) {
					for (int j = 0; j < width; j++) {
						fread(&img->pixels[i][j], sizeof(unsigned char), 1, imgPtr);
					}
				}
				fclose(imgPtr);

				return NOERROR;
			}
		}
	}
}