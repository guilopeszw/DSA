#include "recursive.h"
#include <stdlib.h>

/*
Pré-ordem (raiz-esq-dir), Em-ordem (esq-raiz-dir) e Pós-ordem (esq-dir-raiz)
*/

typedef struct arvno {
    int info;
    struct arvno* esq;
    struct arvno* dir;
} ArvNo;

typedef struct arv {
    ArvNo* raiz;
} Arv;

Arv* cria_no(int v) {
    ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
    if (!novo) return NULL;

    novo->info = v;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Arv* cria_arv (Arv* root) {
    if (!root) return NULL;

    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->raiz = root;

    return a;
}

void arvn_insere (ArvNo* a, ArvNo* sa) {
    // inserimos nós como sendo sub-arvores
    sa->dir = a->esq;
    a->esq = sa;
}

int arv_vazia (Arv* a) {
    return a == NULL;
}

int arv_pertence (Arv* a, int c) {
    // percore a árvore em pré ordem
    if (!a) return 0; // caso não haja árvore

    if (!a->raiz) return 0; // caso a raiz não exista -> caso de quebra

    if (a->raiz->info == c) {
        return 1; // caso achemos o valor
    }

    if (a->raiz->info >= c) {
        return arv_pertence(a->raiz->esq, c); // caso o valor seja menor que o do nó, vamos para a esquerda
    }
    else {
        return arv_pertence(a->raiz->dir, c); // se o valor for maior, vamos para a direita.
    }
}

void libera_nos(ArvNo* n) {
    if (n != NULL) {
        libera_nos(n->esq);  // libera esquerda
        libera_nos(n->dir);  // libera direita
        free(n);             // libera raiz
        // libera tudo em pós ordem
    }
}

void arv_libera(Arv* a) {
    if (a != NULL) {
        libera_nos(a->raiz); // inicia pela raiz
        free(a);             // libera a árvore no final
    }
}

// imprime os elementos em pré-ordem
void arv_imprime(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%d ", a->raiz->info);  // imprime a raiz
        arv_imprime(a->raiz->esq);    // visita esquerda
        arv_imprime(a->raiz->dir);    // visita direita
    }
}

// função aux para percorrer
int altura_no(ArvNo* n) {
    if (n == NULL) {
        return -1; // caso de quebra: nó inexistente não contribui para a altura
    }
    else {
        // calcula a altura de cada subárvore separadamente
        int h_esq = altura_no(n->esq);
        int h_dir = altura_no(n->dir);
        
        // retorna a maior das alturas encontradas somando 1 (o próprio nó)
        if (h_esq > h_dir)
            return h_esq + 1;
        else
            return h_dir + 1;
    }
}

int arv_altura(Arv* a) {
    if (a == NULL || a->raiz == NULL) {
        return -1; 
    }
    return altura_no(a->raiz);
}

/*
o grande segredo para a recursão é tratar cada nó como sendo uma subárvore com apenas 3 nós e ir
acessando os nós filhos da mesma forma.

o caso de quebra mais comum é verificar se a árvore/subárvore está vazia.
*/
