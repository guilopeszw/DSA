#include "ponto.h"
#include "circulo.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

Circulo* circ_cria(float x, float y, float r) {
    Circulo* circ = (Circulo*) malloc(sizeof(Circulo));
    if (circ == NULL) return NULL;

    circ->centro = pto_cria(x, y);
    circ->raio = r;

    return circ;
    }

void circ_libera(Circulo* c) {
    pto_libera(c->centro); // precisa liberar o ponto do centro também`
    free(c);
}

float circ_area(Circulo* c) {
    return (PI * c->raio * c->raio);
}

int circ_interior(Circulo* c, Ponto* p) {
    float d = pto_distancia(c->centro, p);
    
    if (d < c->raio) return 1;
    else return 0;
}