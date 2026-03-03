#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex_nums.h"

#ifndef COMPLEX.C_
#define COMPLEX.C

struct Complexo {
    float a; // real
    float b; // imaginario
}; 
/* de um ponto de vista de compilação, fazer o struct no .c ou no .h não tem diferença. mas de um ponto de vista estrutural, 
voce tem mais liberdade colocando o struct no .c, porque voce nao precisa obrigatoriamente seguir a mesma estrutura em todos 
os códigos que implementam a interface */

comp* cpx_cria(float a, float b) {
    comp* cpx = (comp*) malloc(sizeof(comp));
    if (!cpx) return NULL;

    cpx->a = a;
    cpx->b = b;

    return cpx;
}

void cpx_libera(comp** cpx) {
    free(*cpx);
    *cpx = NULL; // precisa fazer isso porque é ponteiro de ponteiro
}

comp* cpx_soma(comp* cpx_1, comp* cpx_2){ 
    if (!cpx_1 || !cpx_2) return NULL;
    // (a + bi) + (c + di) = (a + c) + (b + d)i
    return cpx_cria((cpx_1->a + cpx_2->a), (cpx_1->b + cpx_2->b));
}

comp* cpx_sub(comp* cpx_1, comp* cpx_2) {
    if (!cpx_1 || !cpx_2) return NULL;
    // (a + bi) − (c + di) = (a − c) + (b − d)i
    return cpx_cria((cpx_1->a - cpx_2->a), (cpx_1->b - cpx_2->b));
} 

comp* cpx_mult(comp* cpx_1, comp* cpx_2) {
    if (!cpx_1 || !cpx_2) return NULL;
    // (a + bi)(c + di) = (ac − bd) + (bc + ad)i
    return cpx_cria((cpx_1->a * cpx_2->a - cpx_1->b * cpx_2->b), (cpx_1->b * cpx_2->a + cpx_1->a * cpx_2->b));
} 

comp* cpx_div(comp* cpx_1, comp* cpx_2) {
    if (!cpx_1 || !cpx_2) return NULL;
    // (a + bi)/(c + di) = (ac + bd)/(cˆ2 + dˆ2) + (bc - ad)/(cˆ2 + d^2)
    return cpx_cria(((cpx_1->a * cpx_2->a + cpx_1->b * cpx_2->b)/(cpx_2->a * cpx_2->a + cpx_2->b * cpx_2->b)), 
    (cpx_1->b * cpx_2->a - cpx_1->a * cpx_2->b)/(cpx_2->a * cpx_2->a + cpx_2->b * cpx_2->b));
}

void cpx_print(comp* cpx) {
    if (!cpx) return NULL;

    if (cpx->b >= 0) {
        printf("%.2f + %.2fi\n", cpx->a, cpx->b); // verifica se o b é pos ou neg
    }
    else {
        printf("%.2f - %.2fi\n", cpx->a, cpx->b);
    }
}

int cpx_get(comp* cpx, float* a, float* b) {
    if (!cpx || !a || !b) return 0;

    *a = cpx->a; // -> precisa passar um ponteiro para poder acessar o valor
    *b = cpx->b;
    return 1;
}

int cpx_set(comp* cpx, float a, float b) {
    if (!cpx) return 0;

    cpx->a = a;
    cpx->b = b;
    return 1;
}
#endif