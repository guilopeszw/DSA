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
#ifndef PONTO_H_
#define PONTO_H_

typedef struct Ponto {
    float x;
    float y;
} Ponto;

Ponto* pto_cria(float x, float y);
void pto_libera(Ponto* p);
void pto_acessa(Ponto* p, float* x, float* y);
void pto_atribui(Ponto* p, float x, float y);
float pto_distancia(Ponto* p1, Ponto* p2);
#endif