#include "recursive.h"
#include <stdlib.h>

/*
Pré-ordem (raiz-esq-dir), Em-ordem (esq-raiz-dir) e Pós-ordem (esq-dir-raiz)
*/

typedef struct arvno {
    int info;
    struct arvno* esq;
    struct arvno* dir;
} ArvNo;

typedef struct arv {
    ArvNo* raiz;
} Arv;

int pertence(ArvNo* r, int v) {
    if (r == NULL) 
        return 0; // não encontrado
    if (v < r->info) 
        return pertence(r->esq, v);
    else if (v > r->info) 
        return pertence(r->dir, v);
    else 
        return 1; // encontrado
}

int arv_pertence(Arv* a, int v) {
    return pertence(a->raiz, v);
}

ArvNo* insere(ArvNo* r, int v) {
    if (r == NULL) {
        r = (ArvNo*) malloc(sizeof(ArvNo));
        r->info = v;
        r->esq = r->dir = NULL;
    }
    else if (v < r->info)
        r->esq = insere(r->esq, v);
    else
        r->dir = insere(r->dir, v);
    return r;
}

void arv_insere(Arv* a, int v) {
    a->raiz = insere(a->raiz, v);
}

void libera(ArvNo* r) {
    if (r != NULL) {
        libera(r->esq); // visita esquerda
        libera(r->dir); // visita direita
        free(r);        // libera o nó atual
    }
    // pós ordem
}

void arv_libera(Arv* a) {
    libera(a->raiz);
    free(a); // libera a estrutura
}

void imprime(ArvNo* r) {
    if (r != NULL) {
        printf("%d ", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }
}

void arv_imprime(Arv* a) {
    imprime(a->raiz);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

static int altura_no(ArvNo* n) {
    if (n == NULL) {
        return -1; // caso de quebra: subárvore vazia tem altura -1
    }
    else {
        // a altura de um nó é 1 + a altura da sua maior subárvore
        return 1 + max(altura_no(n->esq), altura_no(n->dir));
    }
}

// função principal do TAD
int arv_altura(Arv* a) {
    if (a == NULL) {
        return -1;
    }
    return altura_no(a->raiz);
}