#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifndef VETOR_DIN_ // se o ponto não estiver defindo, ele vai definir ponto_h_ como o struct VetorDin
#define VETOR_DIN_ // esse nome feio e estranho é para evitar conflitos de nomes em outros arquivos

typedef struct vetordin {
    int n; // num de elementos no vetor dinâmico
    int nmax; // dimensão do vetor
    float* v; // vetor dos elementos
} VetorDin;

VetorDin* vd_cria(void);
void vd_insere(VetorDin* vd, float x);
int vd_tam(VetorDin* vd);
float vd_acessa(VetorDin* vd, int i);
void vd_libera(VetorDin* vd);
#endif