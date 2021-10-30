/*Henrique e Leon */
#include "linhaComando.h"

#include <math.h>
#include <matheval.h>

#define MAX 50

int main(int argc, char *argv[]) {
    /* Decide se escreve em um arquivo ou na stdout */
    FILE* arqout = abreArquivo(argc, argv);
    
    fclose(arqout);
    return 0;
}