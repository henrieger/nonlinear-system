#include "linhaComando.h"

FILE * abreArquivo(int argc, char *argv[]) {
    FILE* arqout;
    int opcao = getopt(argc, argv, "o:");
    switch(opcao) {
        case 'o':
            arqout = fopen(optarg, "w");
            break;
        default:
            arqout = stdout;
            break;
    }

    if (arqout != NULL)
        return arqout;
    else {
        fprintf(stderr, "Foi impossível abrir o arquivo para escrita. Retornando dados para a saída padrão.\n");
        return stdout;
    }
}