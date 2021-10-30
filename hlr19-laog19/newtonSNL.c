/*Henrique e Leon */
#include "linhaComando.h"
#include "vetores.h"

#include <math.h>
#include <matheval.h>

#define MAX 50

int main(int argc, char *argv[]) {
    /* Decide se escreve em um arquivo ou na stdout */
    FILE* arqout = abreArquivo(argc, argv);

    /* Declarações de variáveis e leitura dos dados */
    int dimensao, maxIt;
    char funcao[MAX];
    double epsilon;

    while (!feof(stdin)) {
        /* Lendo dimensão */
        scanf("%d", &dimensao);

        /* Declarando e lendo vetor de funções */
        void **f = vetorFuncoes(dimensao, funcao);

        /* Declarando e lendo vetor de aproximações */
        double *aprox = vetorAproximacoes(dimensao);

        /* Lendo epsilon */
        scanf("%lf", &epsilon);

        /* Lendo número máximo de iterações */
        scanf("%d", &maxIt);

        /* Resolver por método de Newton */

        /* Liberando memória */
        free(f);
        free(aprox);
    }
    
    fclose(arqout);
    return 0;
}