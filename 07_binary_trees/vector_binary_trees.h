#define MAX 100
#ifndef BINARY_TREES_VECTOR_H_
#define BINARY_TREES_VECTOR_H_
#include <stdlib.h>

typedef struct arvore {
    int v[MAX];

} Arvore;

Arvore* cria_arvore(void) {
    Arvore* a = (Arvore*) malloc(sizeof(Arvore));
    if (!a) return NULL;

    for (int i = 0; i<MAX; i++) {
        a->v[i] = -1; // faz com que todos os nós comecem nulos
    }

    return a;
}

int insere_arvore(Arvore* a, int v) {
    if (!a) return;
    int raiz = 0;

    while (true) {
        if (a->v[raiz] == -1) {
            a->v[raiz] = v; // se não houver raiz, insere na raiz
            return 1;
        }
        else if (a->v[raiz] > v) {
            // se o valor que queremos inserir for menor que a raiz, vai para a esquerda
            raiz = (raiz * 2) + 1;
        }
        else {
            raiz = (raiz * 2) + 2;
        }
    }
    return 0;

    // atua como função recursiva onde a condição de parada é que a raiz seja -1, indicando posição livre e adicionando no vetor
    // essa é uma aplicação iterativa de recursão
}

int busca_arvore(Arvore* a, int v) {
    if (!a) return;
    int raiz = 0;

    while (true) {
        if (a->v[raiz] == v) {
            return raiz;
        }
        else if (a->v[raiz] > v) {
            raiz = (raiz * 2) + 1;
        }
        else {
            raiz = (raiz * 2) + 2;
        }
    }
    return -1;

    // mesmo esquema de inserção, mas a condição de parada recursiva é encontrar o valor inserido pelo usuário
}

void libera_arvore(Arvore** a) {
    if (!a) return;
    free((*a)->v);
    *a = NULL;
}

#endif