#include <stdlib.h>
#include <recursive.c>

/*
Implemente uma função que retorne o número de nós folhas maiores do
que um valor x, considerando uma árvore binária de busca. 
Essa função deve obedecer ao protótipo:
int nfolhas_maiores (Arv*a, int x);
*/

int verifica_folha(ArvNo* folha, int x) {
    if (!folha) return 0;
    
    if (folha->info > x) {
        int folha_e_maior = (!folha->esq && !folha->dir) ? 1 : 0; // se não houverem filhos no nó, ou seja, ele é folha, folha_e_maior vai retornar 1
        return folha_e_maior + verifica_folha(folha->dir, x) + verifica_folha(folha->esq, x); // retornamos nossa variável e buscamos à esquerda e à direita
    }
    else return verifica_folha(folha->dir, x);
}

int nfolhas_maiores(Arv* a, int x) {
    if (!a) return 0;
    return verifica_folha(a->raiz, x);
}