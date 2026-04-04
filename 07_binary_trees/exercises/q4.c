#include <stdlib.h>
#include <recursive.c>

/*
Implemente uma função que compare se duas árvores binárias são iguais. Essa função deve obedecer ao protótipo:
int igual (Arv* a, Arv* b);
*/



int compara_nos (ArvNo* a, ArvNo* b) {
    if (!a && !b) return 1; // caso ambos sejam nulos (ou seja, iguais)

    if (a == NULL || b == NULL) return 0; // caso um seja null e o outro não
    
    if (a->info != b->info) return 0; // caso as infos sejam diferentes

    return (compara_nos(a->esq, b->esq) && (compara_nos(a->dir, b->dir)));
}

int igual (Arv* a, Arv* b) {
    if (!a && !b) return 1; // caso ambos sejam arvores nulas, são iguais -> essa função tem que vir antes para não dar segmentation fault
    if (!a || !b) return 0; // se só uma for nula, são diferentes
    return compara_nos(a->raiz, b->raiz);
}