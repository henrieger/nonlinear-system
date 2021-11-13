/* Henrique Luiz Rieger - GRR20190357 - hlr19 */
/* Leon Augusto Okida Gonçalves - GRR20190365 - laog19 */

#include "linhaComando.h"
#include <string.h>

FILE * abreArquivo(int argc, char *argv[]) {
    FILE* arqout;
    int opcao, flag_o = 0;
    char arquivo[MAX];

    while ((opcao = getopt(argc, argv, "o:")) != -1)
        switch(opcao) {
            case 'o':
                flag_o = 1;
                strcpy(arquivo, optarg);
                break;
            default:
                fprintf(stderr, "Essa opção é desconhecida. A única opção aceita pelo programa é -o.\n");
                break;
        }
        
    if (flag_o)
        arqout = fopen(arquivo, "w");
    else
        arqout = stdout;

    if (arqout != NULL)
        return arqout;
    else {
        fprintf(stderr, "Foi impossível abrir o arquivo para escrita. Retornando dados para a saída padrão.\n");
        return stdout;
    }
}