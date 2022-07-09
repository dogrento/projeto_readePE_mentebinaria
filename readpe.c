#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool ispe(const unsigned char *b){
	return(b[0] != 'M' && b[1] != 'Z'); // 'M' == 0x4d 'Z' == 0x5a
}

int main(int argc, char *argv[]){
	// declaração da var responsável em abrir arquivo. 
	FILE *fh;
	// declaração do buffer que vai armanzenar os bytes do arquivo
	unsigned char buffer[32];
	
	if(argc != 2)
		usage();

	// abrindo o arquivo com função fopen
	// argv[0] -> é o nome do proprio arquivo
	fh = fopen(argv[1], "rb");

	// teste se arquivo foi lido mesmo
	if(fh == NULL)
		fatal("Arquivo não encontrado ou sem permissão de leitura.");

	if (fread(buffer, 32, 1, fh)!= 1)
		fatal("Não foi possível ler os 32 bytes do arquivo.");
	
	if(!ispe(buffer))
		fatal("arquivo não é um executável PE.");


	return 0;
}
