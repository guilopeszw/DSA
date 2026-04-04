#include <stdlib.h>
#include <recursive.c>

/*
Implemente uma função que retorne a quantidade de nós de uma árvore 
binária que possuem apenas um filho. Essa função deve obedecer ao protótipo:

int um_filho (Arv* a);
*/

int no_filho_unico(ArvNo* no) {
    if (!no) return 0;

    int is_filho_unico = 0;

    // if (no->dir == NULL && no->esq != NULL) {
    //     is_filho_unico = 1;
    // }
    // else if (no->dir != NULL && no->esq == NULL) {
    //     is_filho_unico = 1;
    // }

    
    is_filho_unico = ((no->dir == NULL && no->esq != NULL) || (no->dir != NULL && no->esq == NULL)) ? 1 : 0;

    // outra forma:
    // is_filho_unico = (no->dir == NULL) != (no->esq == NULL);
    // assim, temos que:
    // se no->dir == NULL e no->esq for diferente de NULL, is_filho_unico = 1 (e vice versa)
    return is_filho_unico + no_filho_unico(no->esq) + no_filho_unico(no->dir);
}

int um_filho(Arv* a) {
    if (!a || !a->raiz) return 0;
    return no_filho_unico(a->raiz);
}

