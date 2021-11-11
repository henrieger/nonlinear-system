/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "gauss.h" 

#include <math.h>

/* Encontra índice em a com maior valor na coluna j */
int encontraMax(int dimensao, double **a, int j)
{
    int max = j;
    for (int i = j+1; i < dimensao; i++)
        max = (fabs(a[i][j]) > fabs(a[i][max])) ? i : max;

    return max;
}

/* Troca linhas l1 e l2 de lugar em a e b */
void trocaLinhas(double **a, double *b, int l1, int l2)
{
    double *auxA = a[l1];
    double auxB = b[l1];

    a[l1] = a[l2];
    b[l1] = b[l2];

    a[l2] = auxA;
    b[l2] = auxB;
}

/* Calcula a retrossubstituição do sistema linear já transformado */
void retrossubstituicao(int dimensao, double **a, double *b, double *x)
{
    x[dimensao-1] = b[dimensao-1];
    for (int i = dimensao-2; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = dimensao-1; j > i; j--)
            x[i] -= a[i][j] * x[j];
        
    }
    
}

void gauss(int dimensao, double **a, double *b, double *x)
{
    for (int i = 0; i < dimensao; i++)
    {
        int iPivo = encontraMax(dimensao, a, i);
        if (iPivo != i)
            trocaLinhas(a, b, i, iPivo);

        for(int k = i+1; k < dimensao; k++)
        {
            double m = a[k][i] / a[i][i];
            a[k][i] = 0;
            
            for (int j = i+1; j < dimensao; j++)
                a[k][j] -= a[i][j] * m;
            b[k] -= b[i] * m;
            
        }  
    }

    retrossubstituicao(dimensao, a, b, x);
}