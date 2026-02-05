#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifndef COMPLEX_NUMS_H
#define COMPLEX_NUMS_H
typedef struct Complexo comp;

comp* cpx_cria(float a, float b);
void cpx_libera(comp* cpx);
comp* cpx_soma(comp* cpx_1, comp* cpx_2); // (a + bi) + (c + di) = (a + c) + (b + d)i
comp* cpx_sub(comp* cpx_1, comp* cpx_2); // (a + bi) − (c + di) = (a − c) + (b − d)i
comp* cpx_mult(comp* cpx_1, comp* cpx_2); // (a + bi)(c + di) = (ac − bd) + (bc + ad)i
comp* cpx_div(comp* cpx_1, comp* cpx_2); // (a + bi)/(c + di) = (ac + bd)/(cˆ2 + dˆ2) + (bc - ad)/(cˆ2 + d^2)
void cpx_print(comp* cpx);
float cpx_get(comp* cpx, float* a, float* b);
int cpx_set(comp* cpx, float a, float b);
#endif