#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

Ponto* pto_cria(float x, float y) {
    Ponto* pto = (Ponto*) malloc(sizeof(Ponto)); // aloca memória para o struct Ponto
    if (pto == NULL) return NULL; // verifica se a alocação foi bem sucedida

    pto->x = x; // para acessar o x do struct, usa-se a seta ->
    pto->y = y; // aqui estamos atribuindo que x e y do struct são iguais aos valores passados como parâmetro
    return pto;
};

void pto_libera(Ponto* p) {
    free(p);
};

void pto_acessa(Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y; // estamos colocando nos ponteiros o valor de de x e y (acessando o ponto). utiliza-se p->x e p->y, pois, p é um struct
};

void pto_atribui (Ponto* p, float x, float y) {
    p->x = x;
    p->y = y; // estamos atribuindo novos valores para x e y do ponto p
};

float pto_distancia(Ponto* p1, Ponto* p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy); // fórmula de distancia (Pitágoras)
};