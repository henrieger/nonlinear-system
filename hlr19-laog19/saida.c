/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "saida.h"

#include <matheval.h>

void printSistema(FILE *arqout, void **f, int n) {
    fprintf(arqout, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(arqout, "%s = 0\n", evaluator_get_string(f[i]));
}

void printResultados(FILE *arqout, double *x, int n, char **variaveis) {
    fprintf(arqout, "#\n");
    for (int i = 0; i < n; i++)
        fprintf(arqout, "%s = %lf\n", variaveis[i], x[i]);
}

void printTempos(FILE *arqout, double tempoTotal, double tempoDerivada, double tempoJacobiana, double tempoSL) {
    fprintf(arqout, "###########\n");
    fprintf(arqout, "# Tempo Total: %lf\n", tempoTotal);
    fprintf(arqout, "# Tempo Derivadas: %lf\n", tempoDerivada);
    fprintf(arqout, "# Tempo Jacobiana: %lf\n", tempoJacobiana);
    fprintf(arqout, "# Tempo SL: %lf\n", tempoSL);
    fprintf(arqout, "###########\n");
}