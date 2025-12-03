#include "ponto.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159

typedef struct Circulo {
    Ponto* centro;
    float raio;
} Circulo; 


Circulo* circ_cria(float x, float y, float r) {
    Circulo* circ = (Circulo*) malloc(sizeof(Circulo));
    if (circ == NULL) return NULL;

    Ponto* centro = pto_cria(x, y);
    circ->centro = centro;
    circ->raio = r;

    return circ;
    }

void circ_libera(Circulo* c) {
    free(c);
}

float circ_area(Circulo* c) {
    return (PI * pow(2, (c->raio)));
}

int circ_interior(Circulo* c, Ponto* p) {
    float d = sqrt(pow(2, ((p->x) - (c->centro->x)) - pow(2, (p->y) - (c->centro->y))));
    
    if (d < c->raio) return 1;
    else return 0;
}