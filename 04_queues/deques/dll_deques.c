#include <stdlib.h>

typedef struct listano2 {
    int info;
    struct listano2* ant;
    struct listano2* prox;
} ListaNo2;

typedef struct deque {
    ListaNo2* ini;
    ListaNo2* fim;
} Deque;

int fila2_retira_ini(Deque* d) {
    if (!d || !d->ini) return -1;

    ListaNo2* inicio = d->ini; // guardamos o inicio
    int v = inicio->info;

    d->ini = inicio->prox; // inicio vira o prox

    if (d->ini == NULL) d->fim = NULL; // verifica se, ao remover o inicio, a pilha fica vazia.
    else d->ini->ant = NULL; // caso a fila não esteja vazia, o anterior do início vai apontar para NULL

    inicio->prox = NULL; // antigo inicio para de apontar para o novo inicio (seu prox)
    free(inicio); // libera o nó que será removido

    return v;
}

int fila2_retira_fim(Deque* d) {
    if (!d || !d->ini) return -1;

    ListaNo2* fim = d->fim;
    int v = fim->info;

    d->fim = fim->ant; // fim da fila agora é o anterior
    
    if (d->fim == NULL) d->ini = NULL; // se a fila tiver ficado vazia, o inicio aponta para NULL
    else d->fim->prox = NULL; // caso não, o prox do fim aponta para NULL (removendo o antigo fim)

    fim->ant = NULL; // anterior do fim original aponta para NULL
    free(fim);

    return v;
}

void fila2_insere_ini(Deque* d, int v) {
    if (!d) return;

    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));
    novo->info = v; // aloca a info do novo nó para o que o usuário colocou
    novo->ant = NULL; // anterior do novo deve ser NULL (já que ele é o primeiro)
    novo->prox = d->ini; // o prox já recebe o antigo início (se for NULL, vai continuar a mesma coisa)

    if (d->ini == NULL) d->fim = novo; // se o inicio for NULL, o fim vai ser igual o novo também
    else d->ini->ant = novo; // caso não seja, o anterior do inicio será o novo

    d->ini = d->ini->ant; // agora fazemos o inicio apontar para seu anterior, ou seja, o novo nó
}