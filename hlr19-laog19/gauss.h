/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#ifndef __GAUSS__
#define __GAUSS__

enum t_sistemas {SPD, SPI, SI, MAX_IT};

/* Calcula o sistema linear pelo método de Gauss com pivoteamento parcial */
enum t_sistemas gauss(int n, double **a, double *b, double *x);

#endif