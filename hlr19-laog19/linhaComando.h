#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Lê os dados em argv. Se a opção presente for -o, abre o arquivo passado por argumento para escrita. Senão, retorna stdout para escrita.
*/
FILE * abreArquivo(int argc, char *argv[]);