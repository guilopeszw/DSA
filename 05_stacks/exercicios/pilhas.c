#include "pilhas.h"
#include <stdlib.h>
#include <stdio.h>


Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->prim = NULL; // inicializa a pilha vazia
    return p;
}

int pilha_push(Pilha* p, int n) {
    if (!p) return 0;
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    if (!novo) return -1;

    novo->info = n;
    novo->prox = p->prim;
    p->prim = novo;
    return 1;
}

int pilha_pop(Pilha* p) {
    if (!p) return 0;

    ListaNo* aux = p->prim; // armazena o topo da pilha
    p->prim = aux->prox; // faz o topo da pilha apontar para o prox
    int valor = aux->info;

    aux->prox = NULL;
    free(aux);
    return valor;
}

void pilha_libera(Pilha* p) {
    if (!p) return;
    ListaNo* q = p->prim;

    while (q != NULL) {
        ListaNo* t = q->prox; // o node local `t` vai armazenar o ponteiro do prox
        free(q); // liberamos o ponteiro atual
        q = t; // passamos o ponteiro para o prox
    }

    free(p);
}

int pilha_vazia(Pilha* p) {
    return (p->prim == NULL);
}