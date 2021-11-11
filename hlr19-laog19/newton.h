/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

/* Calcula a matriz jacobiana */
void *** jacobiana(void **f, int n);

/* Calcula o sistema não-linear pelo método de Newton */
int newton(void **f, void ***j, int n, double **x, double epsilon, int max_it);

