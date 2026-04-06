#include <stdlib.h>
#include <recursive.c>

/*
Implemente uma função que retorne o somatório dos valores entre x e y
(considerando x > y) armazenados numa árvore binária de busca de valores inteiros. Essa função deve obedecer ao protótipo:

int soma_xy (Arv*a, int x, int y);
*/

int verifica_no(ArvNo* node, int x, int y) {
    if (!node) return 0;

    if (node->info > y && node->info < x) {
        return node->info + verifica_no(node->dir, x, y) + verifica_no(node->esq, x, y);
        // caso 1: o nó está no intervalo
    }

    if (node->info <= y) {
        return verifica_no(node->dir, x, y);
        // caso 2: o nó é muito pequeno
    }

    if (node->info >= x) {
        return verifica_no(node->esq, x, y);
        // caso 3: o nó é muito grande
    }
}

int soma_xy(Arv* a, int x, int y) {
    if (!a) return 0;
    return verifica_no(a->raiz, x, y);
}