#include <stdlib.h>
#include <recursive.c>

/*
Implemente uma função que crie uma cópia de uma árvore binária. Essa função deve obedecer ao protótipo:

Arv* copia (Arv* a);
*/

// primeiro passo é alocar memória para essa nova árvore

ArvNo* copia_no(ArvNo* n) {
    if (!n) return NULL;

    ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
    novo->info = n->info;
    novo->esq = copia_no(n->esq);
    novo->dir = copia_no(n->dir);

    return novo;
}

Arv* copia(Arv* a) {
    if (!a) return NULL;

    Arv* nova = (Arv*) malloc(sizeof(Arv));
    nova->raiz = copia_no(a->raiz);

    return nova;
}