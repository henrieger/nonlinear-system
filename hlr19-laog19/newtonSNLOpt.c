/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "linhaComando.h"
#include "vetoresOpt.h"
#include "gaussOpt.h"
#include "newtonOpt.h"
#include "saida.h"
#include "utils.h"

#include <math.h>
#include <matheval.h>
#include <likwid.h>

#define MAX 50

int main(int argc, char *argv[]) {
    LIKWID_MARKER_INIT;
    
    /* Decide se escreve em um arquivo ou na stdout */
    FILE* arqout = abreArquivo(argc, argv);

    /* Declarações de variáveis e leitura dos dados */
    int dimensao, maxIt;
    char funcao[MAX];
    double epsilon, tempoTotal, tempoDerivada = 0, tempoJacobiana = 0, tempoSL = 0;

    /* Lê dimensão testando se entrada acabou */
    while (scanf("%d", &dimensao) != EOF) {

        /* Declarando e lendo vetor de funções */
        void **f = vetorFuncoes(dimensao, funcao);

        /* Declarando e lendo vetor de aproximações */
        double *aprox = vetorAproximacoes(dimensao);

        printSistema(arqout, f, dimensao);

        /* Lendo epsilon */
        scanf("%lf", &epsilon);

        /* Lendo número máximo de iterações */
        scanf("%d", &maxIt);

        /* Obtendo variáveis do sistema */
        char ** variaveis = vetorVariaveis(dimensao);

        /* Inicia cálculo do tempo total */
        tempoTotal = timestamp();

        /* Criando matriz de derivadas parciais (jacobiana) */
        void **j = jacobiana(f, dimensao, variaveis, &tempoDerivada);


        /* Resolver por método de Newton */
        LIKWID_MARKER_START("newton_opt");
        enum t_sistemas newtonRes = newton(f, j, dimensao, aprox, epsilon, maxIt, variaveis, arqout, &tempoJacobiana, &tempoSL);
        LIKWID_MARKER_STOP("newton_opt");


        /* Finaliza cálculo do tempo total */
        tempoTotal = timestamp() - tempoTotal;

        /* Checando tipo de sistema */
        switch (newtonRes) {
        case SPD:
            break;
        case MAX_IT:
            printSistema(stderr, f, dimensao);
            fprintf(stderr, "Limite de Iterações atingido\n\n");
            break;
        case SPI:
            printSistema(stderr, f, dimensao);
            fprintf(stderr, "Sistema Possível e Indeterminado\n\n");
            break;
        case SI:
            printSistema(stderr, f, dimensao);
            fprintf(stderr, "Sistema Impossível\n\n");
            break;
        }

        /* Imprime tempos */
        printTempos(arqout, tempoTotal, tempoDerivada, tempoJacobiana, tempoSL);

        /* Liberando memória */
        free(f);
        free(aprox);
        free(variaveis);
        free(j[0]);
        free(j);
    }
    
    fclose(arqout);

    LIKWID_MARKER_CLOSE;
    return 0;
}