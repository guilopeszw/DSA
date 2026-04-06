#include <stdlib.h>
#include <recursive.c>
/*
Implemente uma função que retorne o nível do nó que contém a informação x 
numa árvore binária de busca. Essa função deve obedecer ao protótipo:
int nivel (Arv*a, int x);

*/

// o nível de uma árvore começa em 0 e sobre de 1 em 1, de acordo com o nó que descemos.
// logo, o ideal seria fazermos uma verificação que analiza se x está no nó. se não tiver, retorna 1 e busca à esquerda ou à direita
// quando encontrar, retorna 0. o fim da recursão nos dará o nível final dela.

int no_nivel(ArvNo* no, int x) {
    if (!no) return 0;

    int nivel = 0;

    if (no->info == x) {
        return nivel;
        // caso 1: encontramos o x na raiz atual
    }

    if (no->info < x) {
        return 1 + no_nivel(no->dir, x);
        // caso 2: o valor do nó é menor que x
    }
    if (no->info > x) {
        return 1 + no_nivel(no->esq, x);
        // caso 3: o valor do nó é maior que x
    }
}

int nivel(Arv* a, int x) {
    if (!a) return 0;
    return no_nivel(a->raiz, x);
}