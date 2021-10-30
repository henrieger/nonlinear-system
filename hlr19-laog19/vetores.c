#include "vetores.h"
#include <matheval.h>

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