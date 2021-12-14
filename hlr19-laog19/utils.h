#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <sys/time.h>

/* Padding para evitar vetores com tamanhos em potências de 2 */
#define PAD(n) (((n & (n - 1)) == 0) ? (n+1) : n)


/*  Retorna tempo em milisegundos

    Forma de uso:
 
    double tempo;
    tempo = timestamp();
    <trecho de programa do qual se deseja medir tempo>
    tempo = timestamp() - tempo;
*/

double timestamp(void);

#endif // __UTILS_H__

