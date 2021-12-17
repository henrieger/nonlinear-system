/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "newtonOpt.h"

#include "saida.h"
#include <matheval.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

/* Devolve a norma do vetor a, de tamanho n */
double norma(double *a, int n) {
    double max = fabs(a[0]); 
    for (int i = 1; i < n; i++) {
        double valor = fabs(a[i]);
        max = (max > valor) ? max : valor;
    }
    return max;
}

/* Libera memória dos vetores auxiliares */
void limpaVetores(double *delta, double *f_eval, double **jac_eval) {
    free(delta);
    free(f_eval);
    free(jac_eval[0]);
}

enum t_sistemas newton(void ** restrict f, void ** restrict jac, int n, double * restrict x, double epsilon, int maxIt, char **variaveis, FILE *arqout, double * tempoJac, double * tempoSL) {
    /* Declaração de vetores auxiliares */
    double *delta = (double *)malloc(PAD(n) * sizeof(double)); /* Vetor delta */
    double *f_eval = (double *)malloc(PAD(n) * sizeof(double)); /* F(X) */

    /* Declaração de variáveis auxiliares para cálculo de tempo */
    double tempoJacAux;
    double tempoSLAux;
    
    /* J(X) */
    double *jac_eval[3];
    jac_eval[0] = (double *)malloc(3 * PAD(n) * sizeof(double));
    jac_eval[1] = jac_eval[0]+n;
    jac_eval[2] = jac_eval[0]+2*n;
    
    /* Iterações do método de Newton */
    for (int k = 0; k < maxIt; k++) {
        /* Imprime os resultados atuais do sistema na saida definida */
        printResultados(arqout, x, n, variaveis);

        /* Calcula os resultados do sistema encontrados até o momento e inverte para o cálculo do delta */
        for (int i = 0; i < n; i++)
            f_eval[i] = -evaluator_evaluate(f[i], n, variaveis, x);

        /* Checa condição de parada 1 */
        if (norma(f_eval, n) < epsilon) {
            limpaVetores(delta, f_eval, jac_eval);
            return SPD;
        }
        
        /* Calcula J(X) */
        tempoJacAux = timestamp();
        LIKWID_MARKER_START("matriz_jacobiana_opt");
            /* Cálculo da primeira linha */
            jac_eval[0][0] = evaluator_evaluate(jac[0], 1, variaveis, x);
            jac_eval[1][0] = evaluator_evaluate(jac[PAD(n)], 1, variaveis, x);

            /* Cálculo das linhas intermediárias */
            for (int i = 1; i < n-1; i++) {
                /* posição na diagonal de cima = i */
                jac_eval[0][i] = evaluator_evaluate(jac[0], 1, variaveis, x);

                /* posição na diagonal principal = PAD(n)+i */
                jac_eval[1][i] = evaluator_evaluate(jac[PAD(n)+i], 1, variaveis, x);

                /* posição na diagonal de baixo = 2*PAD(n)+i-1 */
                jac_eval[2][i-1] = evaluator_evaluate(jac[2*PAD(n)+i-1], 1, variaveis, x);
            }

            /* Cálculo da última linha */
            jac_eval[1][n-1] = evaluator_evaluate(jac[2*PAD(n) - 1], 1, variaveis, x);
            jac_eval[2][n-2] = evaluator_evaluate(jac[3*PAD(n) - 2], 1, variaveis, x);
        LIKWID_MARKER_STOP("matriz_jacobiana_opt");
        
        /* Cálculo de tempo da jacobiana */
        tempoJacAux = timestamp() - tempoJacAux;
        *tempoJac = *tempoJac + tempoJacAux;

        /* Calcula o sistema linear pelo método de Gauss */
        tempoSLAux = timestamp();
        LIKWID_MARKER_START("sistema_linear_opt");
        int sisLinear = gauss(n, jac_eval, f_eval, delta);
        LIKWID_MARKER_STOP("sistema_linear_opt");

        /* Cálculo de tempo do sistema linear */
        tempoSLAux = timestamp() - tempoSLAux;
        *tempoSL = *tempoSL + tempoSLAux;

        if (sisLinear != SPD) {
            limpaVetores(delta, f_eval, jac_eval);
            return sisLinear;
        }

        /* Adiciona os deltas à resolução do sistema */
        for (int i = 0; i < n; i++)
            x[i] = x[i] + delta[i];

        /* Checa condição de parada 2 */
        if (norma(delta, n) < epsilon) {
            printResultados(arqout, x, n, variaveis);
            limpaVetores(delta, f_eval, jac_eval);
            return SPD;
        }
    }

    printResultados(arqout, x, n, variaveis);
    limpaVetores(delta, f_eval, jac_eval);

    /* Retorna limite de iterações atingido */
    return MAX_IT;
}

