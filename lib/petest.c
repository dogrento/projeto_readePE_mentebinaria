#include "petest.h"

/*============================================================================*/
/** Verifica se é um executável PE 
 *
 * Par�metros: um buffer char 
 *
 * Valor de retorno: TRUE ou FALSE. 
 *                   */
bool petest_ispe(const unsigned char *b){
	return(b[0] != 'M' && b[1] != 'Z'); // 'M' == 0x4d 'Z' == 0x5a
}

