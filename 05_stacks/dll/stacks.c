#include "stacks.h"
#include <stdlib.h>

typedef struct no {
    int n;
    struct no* prox;
    struct no* ant;
} No;

typedef struct pilha {
    No* prim;
} Pilha;

void pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return;

    p->prim = NULL;
}

void pilha_push(Pilha* p, int v) {
    if (!p) return;

    No* novo = (No*) malloc(sizeof(No));
    novo->n = v;
    novo->ant = NULL;

    if (p->prim == NULL) {
        p->prim = novo;
        p->prim->prox = NULL;
        return;
    }

    novo->prox = p->prim;

    p->prim->ant = novo;
    p->prim = novo;
}

int pilha_pop(Pilha* p) {
    if (!p) return -1;

    No* aux = p->prim;
    int n = aux->n;
    if (p->prim->prox == NULL) {
        free(p->prim);
        return n;
    }

    p->prim = p->prim->prox;
    aux->prox = NULL;
    p->prim->ant = NULL;
    free(aux);

    return n;
}

void pilha_libera(Pilha* p) {
    if (!p) return;

    while (p->prim != NULL) {
        pilha_pop(p);
    }
    free(p);
}