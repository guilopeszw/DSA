#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

Ponto* pto_cria(float x, float y) {
    Ponto* pto = (Ponto*) malloc(sizeof(Ponto));
    if (pto == NULL) return NULL;

    pto->x = x;
    pto->y = y;
    return pto;
};

void pto_libera(Ponto* p) {
    free(p);
};

void pto_acessa(Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y; // estamos colocando nos ponteiros o valor de de x e y. utiliza-se p->x e p->y, pois, p é um struct
};

void pto_atribui (Ponto* p, float x, float y) {
    p->x = x;
    p->y = y;
};

float pto_distancia(Ponto* p1, Ponto* p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy); // fórmula de distancia (Pitágoras)
};