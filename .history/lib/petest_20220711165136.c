#include "petest.h"


/*============================================================================*/
/** Verifica se é um executável PE 
 *
 * Par�metros: um buffer char 
 *
 * Valor de retorno: TRUE ou FALSE. 
 *                   */
bool petest_ispe(PE_FILE* pe){
	return(pe->hdr_dos->e_magic == 0x05a4d);
}

/*============================================================================*/
/** Abre o arquivo, aloca memoria para struct, lê o arquivo e fecha em seguida
 *
 * Par�metros: um buffer char 
 *
 * Valor de retorno: TRUE ou FALSE. 
 *                   */
bool petest_init(PE_FILE *pe){
	// abrir o arquiv
	FILE *f = fopen(pe->filepath, "rb");

	if(!f)
		return false;

	pe->hdr_dos = malloc(sizeof(IMAGE_DOS_HEADER));
	if(pe->hdr_dos == NULL)
		return false;
	
	//ler do arquivo para dentro da struct
	//destino = pe->hdr-dos
	//tamanho da leiura = sizeof(IMAGE_DOS_HEADER)
	//quantos elementos = 1
	//a partir do arquivo aberto (f)
	fread(pe->hdr_dos, sizeof(IMAGE_DOS_HEADER), 1, f);

	fclose(f);

	return true;
}
