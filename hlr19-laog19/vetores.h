/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#ifndef __VETORES__
#define __VETORES__

#include <stdio.h>
#include <stdlib.h>

/* Declara, aloca e lê o vetor de funções. */
void ** vetorFuncoes(int n, char * funcao);

/* Declara, aloca e lê o vetor de aproximações */
double * vetorAproximacoes(int n);

/* Declara, aloca e preenche o vetor de nomes de variáveis */
char ** vetorVariaveis(int n, void ** f, int * tamVariaveis);

#endif