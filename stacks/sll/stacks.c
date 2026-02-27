#include "stacks.h"
#include <stdlib.h>

typedef struct no {
    int n;
    struct no* prox;
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

    novo->prox = p->prim;
    p->prim = novo;
}

int pilha_pop(Pilha* p) {
    if (!p || !p->prim) return -1;

    No* aux = p->prim; // armazenamos o p->prim em um aux
    int n = aux->n; // armazenamos o valor de n para retornar ao usuário
    p->prim = p->prim->prox; // p->prim agora aponta para o prox
    aux->prox = NULL; // desconectamos o p->prim original da pilha, fazendo o prox apontar para NULL
    free(aux); // liberamos a memória
    
    return n; // retorna o valor que tinha onde houve o pop
}

void pilha_libera(Pilha* p) {
    if (!p) return;

    while (p->prim != NULL) {
        pilha_pop(p);
    }
    free(p);
}