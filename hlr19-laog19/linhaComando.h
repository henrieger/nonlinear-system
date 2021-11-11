/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#ifndef __LINHA_COMANDO__
#define __LINHA_COMANDO__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Lê os dados em argv. Se a opção presente for -o, abre o arquivo passado por argumento para escrita. Senão, retorna stdout para escrita.
*/
FILE * abreArquivo(int argc, char *argv[]);

#endif