/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "newton.h"

#include <matheval.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Devolve a norma do vetor a, de tamanho n */
double norma(double *a, int n)
{
    double max = fabs(a[0]); 
    for (int i = 1; i < n; i++)
    {
        double valor = fabs(a[i]);
        max = (max > valor) ? max : valor;
    }
    return max;
}

void *** jacobiana(void **f, int n, char **variaveis)
{
    void *** jac = (void ***)malloc(n * sizeof(void **));
    jac[0] = (void **)malloc(n * n * sizeof(void *));

    for (int i = 0; i < n-1; i++)
    {
        jac[i+1] = jac[i]+n;
        for (int j = 0; j < n; j++)
            jac[i][j] = evaluator_derivative(f[i], variaveis[j]);
    }

    return jac;
}

enum t_sistemas newton(void **f, void ***jac, int n, double *x, double epsilon, int max_it, char **variaveis)
{
    /* Declaração de vetores auxiliares */
    double *delta = (double *)malloc(n * sizeof(double)); /* Vetor delta */
    double *f_eval = (double *)malloc(n * sizeof(double)); /* F(X) */
    
    /* J(X) */
    double **jac_eval = (double **)malloc(n * sizeof(double *)); 
    jac_eval[0] = (double *)malloc(n * n * sizeof(double));    
    for (int i = 0; i < n-1; i++)
        jac_eval[i+1] = jac_eval[i]+n;
    
    /* Iterações do método de Newton */
    for (int k = 0; k < max_it; k++)
    {
        /* Calcula os resultados do sistema encontrados até o momento */
        for (int i = 0; i < n; i++)
            f_eval[i] = evaluator_evaluate(f[i], n, variaveis, x);

        /* Checa condição de parada 1 */
        if(norma(f_eval, n) < epsilon)
        {
            free(delta);
            free(f_eval);
            free(jac_eval[0]);
            free(jac_eval);

            return SPD;
        }
        
        for (int i = 0; i < n; i++)
        {
            /* Inverte valores de F(X) para cálculo do delta*/
            f_eval[i] = -f_eval[i];
            
            /* Calcula J(X) */
            for (int j = 0; j < n; j++)
                jac_eval[i][j] = evaluator_evaluate(jac[i][j], 1, variaveis, x);
        }

        /* Calcula o sistema linear pelo método de Gauss */
        int sisLinear = gauss(n, jac_eval, f_eval, delta);
        if(sisLinear != SPD)
        {
            free(delta);
            free(f_eval);
            free(jac_eval[0]);
            free(jac_eval);

            return sisLinear;
        }

        /* Adiciona os deltas à resolução do sistema */
        for (int i = 0; i < n; i++)
            x[i] = x[i] + delta[i];
            

        /* Checa condição de parada 2 */
        if(norma(delta, n) < epsilon)
        {
            free(delta);
            free(f_eval);
            free(jac_eval[0]);
            free(jac_eval);

            return SPD;
        }
    }
    
    /* Retorna limite de iterações atingido */
    free(delta);
    free(f_eval);
    free(jac_eval[0]);
    free(jac_eval);

    return MAX_IT;
}

