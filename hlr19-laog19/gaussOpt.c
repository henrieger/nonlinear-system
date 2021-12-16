/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "gaussOpt.h" 

#include <math.h>

/* Encontra índice em a com maior valor na coluna j */
int encontraMax(int n, double **a, int j) {
    int max = j;
    for (int i = j+1; i < n; i++)
        max = (fabs(a[i][j]) > fabs(a[i][max])) ? i : max;

    return max;
}

/* Troca linhas l1 e l2 de lugar em a e b */
void trocaLinhas(double ** restrict a, double * restrict b, int l1, int l2) {
    double *auxA = a[l1];
    double auxB = b[l1];

    a[l1] = a[l2];
    b[l1] = b[l2];

    a[l2] = auxA;
    b[l2] = auxB;
}

enum t_sistemas gauss(int n, double ** restrict a, double * restrict b, double * restrict x) {
    for (int i = 0; i < n-1; i++) {
        /* Calcula as transformações na matriz */
        double m  = a[2][i] /a[1][i];
        a[2][i] = 0.0;
        a[1][i+1] -= a[0][i] * m;
        b[i+1] -= b[i] * m;
    }

    /* Checa tipo de solução do sistema */
    if (a[1][n-1] == 0) {
        if (b[n-1] == 0)
            return SPI;
        return SI;
    }

    /* Faz a substituição */
    x[n-1] = b[n-1] / a[1][n-1];
    for (int i = n-2; i >= 0; i--) {
        x[i] = (b[i] - a[0][i] * x[i+1] / a[1][i]);
    }
    return SPD;
}