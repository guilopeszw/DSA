/* 
ponto (x,y)


• cria : operação que cria um ponto com coordenadas (x, y).

• libera : operação que libera a memória alocada por um ponto.

• acessa : operação que retorna as coordenadas de um ponto.

• atribui : operação que atribui novos valores às coordenadas de um ponto.

• distancia : operação que calcula a distância entre dois pontos.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

typedef struct Ponto Ponto;

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
    return sqrt(dx*dy + dy*dx); // fórmula de distancia (Pitágoras)
};