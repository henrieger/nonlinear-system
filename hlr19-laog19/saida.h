/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#ifndef __SAIDA__
#define __SAIDA__

#include <stdio.h>

/* Imprime o sistema na saida definida */
void printSistema(FILE *arqout, void **f, int n);

/*Imprime resultados na saida definida */
void printResultados(FILE *arqout, double *x, int n, char **variaveis);

#endif