#include <stdio.h>
#include <stdlib.h>

#include "lib/petest.h"

// declaração das funções
void usage(void);
void fatal(char *msg);


/*============================================================================*/
/** Apresenta uma dica (?)
 *
 * Par�metros: não há paramêtros.
 *
 * Valor de retorno: Sai da execução do pragrama.
 *                   */
void usage(void){
	printf("Uso: \n\treadpe <arquivo.exe>\n");
	exit (1);
}


/*============================================================================*/
/** Função para auxiliar no tratamento de erro.
 *
 * Par�metros: char* msg: ponteiro da string.
 *
 * Valor de retorno: finaliza a execução do programa
 *                    */
void fatal(char *msg){

	fprintf(stderr, "ERRO: %s\n", msg);

	exit (1);
}


int main(int argc, char *argv[]){
	// declaração da var responsável em abrir arquivo. 
	FILE *fh;
	// declaração do buffer que vai armanzenar os bytes do arquivo
	unsigned char buffer[32];
	
	if(argc != 2)
		usage();

	PE_FILE pe;

	pe.filepath = argv[1];
	puts(pe.filepath);

	petest_init(&pe);
	if(petest_ispe(&pe))
		printf("É um executável PE... continuando...\n");
	else
		fatal("Não é um executável PE\n");

	printf("FILE:      %s\n", pe.filepath);
	printf("MZ HEADER: %x\n", pe.hdr_dos->e_magic);
	printf("COFF header offset: %x\n", pe.hdr_dos->e_lfanew);

	petest_deinit(&pe);

	return 0;
}
