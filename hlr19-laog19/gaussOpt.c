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
void trocaLinhas(double **a, double *b, int l1, int l2) {
    double *auxA = a[l1];
    double auxB = b[l1];

    a[l1] = a[l2];
    b[l1] = b[l2];

    a[l2] = auxA;
    b[l2] = auxB;
}

/* Calcula a retrossubstituição do sistema linear já transformado */
void retrossubstituicao(int n, double **a, double *b, double *x) {
    x[n-1] = b[n-1] / a[n-1][n-1];
    for (int i = n-2; i >= 0; i--) {
        double m = a[i][i];
        x[i] = b[i] / m;
        for (int j = n-1; j > i; j--)
            x[i] -= a[i][j] * x[j] / m;
    }
}

enum t_sistemas gauss(int n, double **a, double *b, double *x) {
    for (int i = 0; i < n; i++) {
        /* Pivoteamento parcial */
        int iPivo = encontraMax(n, a, i);
        if (iPivo != i)
            trocaLinhas(a, b, i, iPivo);

        /* Calcula as transformações na matriz */
        for (int k = i+1; k < n; k++) {
            double m = a[k][i] / a[i][i];
            a[k][i] = 0;
            
            for (int j = i+1; j < n; j++)
                a[k][j] -= a[i][j] * m;
            b[k] -= b[i] * m;
            
        }  
    }

    /* Checa tipo de solução do sistema */
    if (a[n-1][n-1] == 0) {
        if (b[n-1] == 0)
            return SPI;
        return SI;
    }

    /* Faz a substituição */
    retrossubstituicao(n, a, b, x);
    return SPD;
}