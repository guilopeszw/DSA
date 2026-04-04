#include <stdlib.h>
#include <recursive.c>


/*
Implemente uma função que retorne a quantidade de folhas de uma árvore binária. 
Essa função deve obedecer ao protótipo:
int folhas (Arv* a);
*/ 

// temos que contar todos os filhos que não possuem filhos.

int folhas_no (ArvNo* no) {
    if (!no) return 0;

    int num_folhas = 0;

    if (no->esq == NULL && no->dir == NULL) { // precisa verificar se tanto o filho esquerdo quanto o direito são NULL
        num_folhas = 1;
    }
    else {
        num_folhas = 0;
    }

    return num_folhas + folhas(no->esq) + folhas(no->dir); // abre a recursão
}

int folhas(Arv* a) {
    if (!a || !a->raiz) return 0;
    return folhas_no(a->raiz);
}