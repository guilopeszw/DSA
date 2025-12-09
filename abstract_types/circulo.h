#include "ponto.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159

#ifndef CIRCULO_H_
#define CIRCULO_H_
typedef struct Circulo {
    Ponto* centro;
    float raio;
} Circulo; 

Circulo* circ_cria(float x, float y, float r);
void circ_libera(Circulo* c);
float circ_area(Circulo* c);
int circ_interior(Circulo* c, Ponto* p);
#endif