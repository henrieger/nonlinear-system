/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#ifndef __NEWTON__
#define __NEWTON__

#include "gauss.h"
#include "utils.h"
#include <stdio.h>

/* Calcula o sistema não-linear pelo método de Newton */
enum t_sistemas newton(void ** restrict f, void ** restrict j, int n, double * restrict x, double epsilon, int maxIt, char **variaveis, FILE *arqout, double * tempoJac, double * tempoSL);

#endif