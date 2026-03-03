#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "vetorDin.h"

VetorDin* vd_cria(void) {
    VetorDin* vd = (VetorDin*) malloc(sizeof(VetorDin));
    vd->n = 0; // num de elementos no vetor dinâmico
    vd->nmax = 4; // dimensão do vetor
    vd->v = (float*) malloc(vd->nmax* sizeof(float)); // vetor dos elementos

    if (vd == NULL) return NULL;
};

static void realoca ( VetorDin* vd) {
/*
    A função que insere um elemento no final do vetor precisa verificar a
    necessidade de realocação. Vamos usar uma função interna auxiliar para a
    realocação
*/

vd -> nmax *= 2; // dobra a dimensão multiplicando nmax por 2
vd ->v = (float *) realloc(vd ->v, vd -> nmax*sizeof(float)); // usa função da biblioteca padrão para realocar essa memória para o novo nmax

/*
    Em algumas aplicações, a estratégia de dobrar o espaço a cada
    realocação pode significar um uso excessivo de memória.

    Outros fatores de incremento (como aumentar por 25%) também funcionam. Usar um fator multiplicador reduz o número de realocações (ao preço de
    um eventual uso excessivo de memória)
*/
}

void vd_insere(VetorDin* vd, float x)
{
if (vd ->n == vd -> nmax) //  verifica se capacidade se esgotou, ou seja, n = nmax
realoca(vd);
vd ->v[vd ->n++] = x; // insere elemento final fazendo um incremento de um à n
}

int vd_tam(VetorDin* vd) {
    return vd->n;
}

float vd_acessa(VetorDin* vd, int i) {
    assert(i>=0 && i<vd->n); // assegura que i é maior igual à 0 e i é menor que o numero de elementos do vetor
    return vd->v[i]; // retorna o i quando i for >= n ou <0
}
void vd_libera(VetorDin* vd) {
    free(vd->v); // libera vetor dos floats
    free(vd); // libera o próprio vetor dinâmico
}

VetorDin* le_valores(char* arquivo) {
    FILE* f = fopen(arquivo ,"rt");
    if (f == NULL) return NULL;
    VetorDin* vd = vd_cria();
    float x;
    while (fscanf("f, %f", &x) == 1) vd_insere(vd, x);
    fclose(f);
    return vd;

    // Uma função que recebe o nome do arquivo como parâmetro e retorna um vetor preenchido com os valores do arquivo
}