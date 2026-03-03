#include <stdlib.h>

typedef struct listano {
    int info;
    struct listano* prox;
    struct listano* ant;
} ListaNo;

typedef struct fila {
    ListaNo* prim;
    ListaNo* ult;
} Fila;

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->prim = f->ult = NULL;
    return f;
}

void fila_insere(Fila* f, int v) {
    if (!f) return;
    
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo)); // cria novo nó
    novo->ant = f->ult; // anterior do novo nó será o ultimo
    novo->prox = NULL; // proximo do novo nó é NULL (não tem ninguém depois na fila)
    novo->info = v; // adiciona o int no novo nó
    
    if (!f->prim) f->prim = novo; // o primeiro vira o novo caso a fila seja uma fila vazia
    else f->ult->prox = novo; // o próximo do ultimo vira o novo

    f->ult = novo; // o ultimo vira o seu próximo, que é o novo nó
}

int fila_remove(Fila* f) {
    if (!f) return -1; // verifica se a fila está vazia
    if (!f->prim) return -1; // se a fila existir, mas o primeiro nó não, retorna o sentinela

    ListaNo* removido = f->prim; // guarda o primeiro nó (que será removido)
    int v = removido->info; // guarda o valor do primeiro nó
    f->prim = f->prim->prox; // faz o primeiro ser o próximo

    if (f->prim == NULL) f->ult = NULL; // se o primeiro agora for NULL (indicando que só tinha um nó), o ultimo nó da fila passa a ser NULL também (ela está vazia)
    else f->prim->ant = NULL; // caso contrário, o antecessor do novo primeiro (que era o antigo primeiro) aponta para NULL

    free(removido); // libera o espaço do antigo primeiro
    return v;
}

int fila_vazia(Fila* f) {
    if (!f) return -1;
    return (f->prim == NULL);
}

void fila_libera(Fila* f) {
    if (!f) return;

    ListaNo* p1 = f->prim;
    while (p1 != NULL) {
        ListaNo* p2 = p1->prox;
        free(p1);
        p1 = p2;
    }
    free(f);
}