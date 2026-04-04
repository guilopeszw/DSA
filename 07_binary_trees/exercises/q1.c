/*
Considerando estruturas de árvores binárias que armazenam valores inteiros, 
implemente uma função que, dada uma árvore, retorne a quantidade de nós que 
guardam números pares. Essa função deve obedecer ao protótipo:

int pares (Arv* a);
*/

#include <stdlib.h>
#include <recursive.c>

int pares(Arv* a) {
    if (!a->raiz) return 0;

    if (a->raiz->info % 2 == 0) {
        return 1;
    }
    pares(a->raiz->esq);
    pares(a->raiz->dir);
}

int conta_pares_no(ArvNo* n) {
    if (n == NULL) {
        return 0; // caso base: subárvore vazia tem 0 pares
    }

    // o nó atual é par? se sim, atual_e_par = 1, se não, atual_e_par = 0
    int atual_e_par = (n->info % 2 == 0) ? 1 : 0;

    /*
    if (n->info % 2 == 0) atual_e_par = 1;
    else atual_e_par = 2;

    outra forma de escrever o if
    */

    // a contagem total é: atual_e_par + verifica filhos da esquerda + verifica filhos da direita
    return atual_e_par + conta_pares_no(n->esq) + conta_pares_no(n->dir);
}

int pares (Arv* a) {
    if (!a || !a->raiz) return 0;

    return conta_pares_no(a->raiz);
}