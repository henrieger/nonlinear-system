/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "vetores.h"
#include <matheval.h>
#include <string.h>

void ** vetorFuncoes(int n, char * funcao) {
    void **f = (void **)malloc(n * sizeof(void*));
    for (int i = 0; i < n; i++) {
        scanf("%s", funcao);
        f[i] = evaluator_create(funcao);
    }
    return f;
}

double * vetorAproximacoes(int n) {
    double *aprox = (double *)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        scanf("%lf", &aprox[i]);
    return aprox;
}

char ** vetorVariaveis(int n, void ** f, int * tamVar) {
    char ** variaveis = malloc(n*sizeof(char *));
    for (int i = 0; i < n; i++) {
        variaveis[i] = malloc(4*sizeof(char));
        // variaveis[i] = "";
        sprintf(variaveis[i], "x%d", i+1);
    }
    // char ** aux;
    // int tamAux, tamVariaveis = 0;

    // /* Preenche vetor de variaveis */
    // for (int i = 0; i < n; i++) {
    //     evaluator_get_variables (f[i], &aux, &tamAux);
    //     for (int j = 0; j < tamAux; j++) {
    //         for (int k = 0; k < tamVariaveis; k++) {
    //             if (strcmp(variaveis[k], aux[j]) == 0) {
    //                 aux[j] = "";
    //                 k = tamVariaveis+1;
    //             }
    //         }
    //         if (strcmp(aux[j], "") != 0) {
    //             variaveis[tamVariaveis] = aux[j];
    //             tamVariaveis++;
    //         }
    //     }
    // }
    // free(aux);
    // *tamVar = tamVariaveis;
    
    return variaveis;
}

void *** jacobiana(void **f, int n, char **variaveis)
{
    void *** jac = (void ***)malloc(n * sizeof(void **));
    jac[0] = (void **)malloc(n * n * sizeof(void *));

    for (int i = 0; i < n-1; i++)
        jac[i+1] = jac[i]+n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            jac[i][j] = evaluator_derivative(f[i], variaveis[j]);
    }

    return jac;
}