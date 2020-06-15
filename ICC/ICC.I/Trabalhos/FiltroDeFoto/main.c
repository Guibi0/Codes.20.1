/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |                      
 |                        Autor: Guilherme Rios(1122839)                       | 
 *******************************************************************************
 > Programa que realiza a aplicação de filtros em imagens BMP
 *******************************************************************************/
 
#include "data.h"
#include "read.h"
#include "write.h"

int main() {
	// Recebe a entrada com nome do arquivo da foto e o tipo de filtro a ser aplicado
	String originalName = readName();
	int typeFilter;
	scanf("%d", &typeFilter);

	// Recebe os dados do arquivo original, caso ele exista e tenha o formato correto
	Image *img = (Image *) malloc(sizeof(Image));
	int error = readFile(img, originalName);

	// Verifica se há erros
	if (error == NOEXIST) {
		printf("Erro no arquivo\n");
		return 0;
	}
	else if (error == NOBMP) {
		printf("Arquivo não eh do formato BMP\n");
		return 0;
	}
	else if (error == NOERROR){
		// Salva a paleta original para imprimir os dados no final e chama a criação do novo arquivo
		Colors *originalPallet = saveOriginalPallet(img->pallet);
		String newName = writeFile(img, originalName, typeFilter); 
		
		printData(img, originalPallet, newName);
		
		deallocate(img, originalPallet, originalName, newName);
		return 0;
	}
}