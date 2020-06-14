// .c auxiliar a biblioteca "read.h"

#include "read.h"
#include "data.h"

int isBMP(String name, int turn) {
	if (turn == 1) {
		char type = ['.', 'b', 'm', 'p'];

		int size = strlen(name) - 1;
		for (int i = size, j = 4; j >= 0; i--, j--) {
			if (name[i] != type[j]) return FALSE;
		}
	}
	else if (turn == 2) {

	}
	return TRUE;
}

int readFile(Image *img, String name) {
	// Inicia o processo conferindo se o arquivo é do tipo devido e se existe
	if (!(isBMP(name, 1))) return NOBMP;
	else {
		FILE * imgPtr = fopen(name, r);
		if (imgPtr == NULL) return NOEXIST;
		else {

			fread(&img->fileData.signature, sizeof(img->fileData.signature), 1, imgPtr);
			fclose(imgPtr);

			if (!(isBMP(&img->fileData.signature, 2))) return NOBMP;
			else {
				// Escreve o cabeçalho de arquivo
				imgPtr = fopen(name, rb);
				fseek(imgPtr, sizeof(img->fileData.signature), SEEK_SET);
				fread(&img->fileData.fileSize, sizeof(img->fileData.fileSize), 1, imgPtr);
				fread(&img->fileData.reservedField, sizeof(img->fileData.reservedField), 1, imgPtr);
				fread(&img->fileData.displacement, sizeof(img->fileData.displacement), 1, imgPtr);

				fclose(imgPtr);
				return NOERROR;
			}
		}
	}
}