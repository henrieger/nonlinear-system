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
        variaveis[i] = malloc(12*sizeof(char));
        sprintf(variaveis[i], "x%d", i+1);
    }

    return variaveis;
}

/* */
void checkDerivative(void **jac, int i)
{
    if (jac[i] == NULL) {
        fprintf(stderr, "Houve um erro ao calcular as derivadas parciais. Encerrando o programa.\n");
        exit(1);
    }
}

void ** jacobiana(void **f, int n, char **variaveis, double * tempo) {
    void ** jac = (void **)malloc(3 * PAD(n) * sizeof(void *));

    *tempo = timestamp();
    LIKWID_MARKER_START("derivadas_parciais_opt");

    /* Cálculo da primeira linha */
    jac[0] = evaluator_derivative(f[0], variaveis[1]);
    checkDerivative(jac, 0);
    jac[PAD(n)] = evaluator_derivative(f[0], variaveis[0]);
    checkDerivative(jac, PAD(n));

    /* Cálculo das linhas intermediárias */
    for (int i = 1; i < n-1; i++) {
        /* posição na diagonal de cima = i */
        jac[i] = evaluator_derivative(f[i], variaveis[i+1]);
        checkDerivative(jac, i);

        /* posição na diagonal principal = PAD(n)+i */
        int posPrinc = PAD(n)+i;
        jac[posPrinc] = evaluator_derivative(f[i], variaveis[i]);
        checkDerivative(jac, posPrinc);

        /* posição na diagonal de baixo = 2*PAD(n)+i-1 */
        int posAbaixo = 2*PAD(n)+i-1;
        jac[posAbaixo] = evaluator_derivative(f[i], variaveis[i-1]);
        checkDerivative(jac, posAbaixo);
    }

    /* Cálculo da última linha */
    jac[2*PAD(n) - 1] = evaluator_derivative(f[n-1], variaveis[n-1]);
    checkDerivative(jac, 2*PAD(n) - 1);
    jac[3*PAD(n) - 2] = evaluator_derivative(f[n-1], variaveis[n-2]);
    checkDerivative(jac, 3*PAD(n) - 2);

    LIKWID_MARKER_STOP("derivadas_parciais_opt");
    *tempo = timestamp() - *tempo;

    return jac;
}