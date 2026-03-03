#ifndef PILHAS_LISTA_H
#define PILHAS_LISTA_H

typedef struct listano {
    int info;
    struct listano* prox;
} ListaNo;

typedef struct pilha {
    ListaNo* prim;
} Pilha;

Pilha* pilha_cria(void);
int pilha_push(Pilha* p, int n);
int pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);

#endif