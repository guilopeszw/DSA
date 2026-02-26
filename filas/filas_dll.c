#include "filas_dll.h"
#include <stdlib.h>

typedef struct listano {
    struct listano* prox;
    struct listano* ant;
    int info;
} ListaNo;

typedef struct fila {
    ListaNo* inicio;
    ListaNo* fim;
} Fila;

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->fim = f->fim = NULL;
    return f;
}

int fila_insere(Fila* f, int v) {
    if (!f || v == NULL) return 0;

    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    if (!novo) return NULL;
    novo->info = v;

    if (f->fim != NULL) {
        // verificação para caso a lista esteja vazia
        novo->ant = f->fim; // o anterior do novo é f->fim
        f->fim->prox = novo; // o prox do f->fim é o novo
        f->fim = novo; // f->fim se torna o novo
        return 1;
    }
    f->inicio = f->fim = novo; // caso a fila esteja vazia, o início será o novo
    return 1;
}

int fila_retira(Fila* f) {
    if (!f) return -1;

    if (f->fim != NULL) {
        // vefifica se a fila não está vazia
        ListaNo* antigo_primeiro = f->inicio; // precisamos de um aux que armazene o antigo primeiro
        f->inicio = antigo_primeiro->prox; // o inicio aponta para o prox do antigo primeiro
        f->inicio->ant = NULL; // o novo primeiro aponta para NULL, indicando que o antigo primeiro saiu da fila
    
        antigo_primeiro->prox = NULL;
        free(antigo_primeiro);
        return 1;
    }
    return 0;
}



int fila_vazia(Fila* f) {
    if (f->inicio == NULL && f->inicio == f->fim) return 1;
    return 0;
}

void fila_libera(Fila* f);