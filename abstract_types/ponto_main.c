#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

int main(void) {
    Ponto* p = pto_cria(2.0, 1.0);
    Ponto* q = pto_cria(3.4, 2.1);

    float d = pto_distancia(p, q);

    printf("Distancia entre os pontos: % f\ n", d);

    pto_libera(p);
    pto_libera(q);

    return 0;
};