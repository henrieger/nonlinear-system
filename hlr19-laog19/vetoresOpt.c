/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "vetoresOpt.h"
#include "utils.h"
#include <matheval.h>
#include <string.h>
#include <likwid.h>

void ** vetorFuncoes(int n, char * funcao) {
    void **f = (void **)malloc(PAD(n) * sizeof(void*));
    int sucesso;
    for (int i = 0; i < n; i++) {
        sucesso = scanf("%s", funcao);
        if (sucesso) {
            f[i] = evaluator_create(funcao);
            if (f[i] == NULL) {
                fprintf(stderr, "Houve um erro durante o processamento da função. Encerrando o programa.\n");
                exit(1);
            }
        }
        else {
            fprintf(stderr, "Houve um erro na leitura da função. Encerrando o programa.\n");
            exit(1);
        }
    }
    return f;
}

double * vetorAproximacoes(int n) {
    double *aprox = (double *)malloc(PAD(n) * sizeof(double*));
    int sucesso;
    for (int i = 0; i < n; i++) {
        sucesso = scanf("%lf", &aprox[i]);
        if (!sucesso) {
            fprintf(stderr, "Houve um erro na leitura das aproximações iniciais. Encerrando o programa.\n");
            exit(1);
        }
    }
    return aprox;
}

char ** vetorVariaveis(int n) {
    char ** variaveis = malloc(PAD(n)*sizeof(char *));
    for (int i = 0; i < n; i++) {
        variaveis[i] = malloc(11*sizeof(char));
        sprintf(variaveis[i], "x%d", i+1);
    }

    return variaveis;
}

void ** jacobiana(void **f, int n, char **variaveis, double * tempo) {
    void ** jac = (void **)malloc(PAD(n * n) * sizeof(void *));
    *tempo = timestamp();
    LIKWID_MARKER_START("derivadas_parciais_opt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            jac[(i * n) + j] = evaluator_derivative(f[i], variaveis[j]);
            if (jac[(i * n) + j] == NULL) {
                fprintf(stderr, "Houve um erro ao calcular as derivadas parciais. Encerrando o programa");
                exit(1);
            }
        }
    LIKWID_MARKER_STOP("derivadas_parciais_opt");
    *tempo = timestamp() - *tempo;

    return jac;
}