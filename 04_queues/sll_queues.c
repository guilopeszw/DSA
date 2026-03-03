#include <stdlib.h>

typedef struct listano {
    int info;
    struct listano* prox;
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

void fila_insere(Fila* f, int n) {
    if (!f) return;

    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo)); // criamos o novo nó
    novo->info = n;
    novo->prox = NULL;

    if (f->prim == NULL) f->prim = novo; // se a fila estiver vazia, o novo nó será o primeiro (e, por conta do nosso struct, o ultimo)
    else f->ult->prox = novo; // caso não seja, o novo nó será o próximo do atual ultimo nó

    f->ult = f->ult->prox; // seria o equivalente à um incremento para que o ultimo agora seja o novo.
}

int fila_retira(Fila* f) {
    if (!f) return -1; // verifica se existe a fila
    if (!f->prim) return -1; // verifica se a fila não está vazia

    ListaNo* primeiro = f->prim; // armazenamos o primeiro da fila
    int v = primeiro->info; // armazenamos o valor do primeiro da fila
    f->prim = f->prim->prox; // o primeiro da fila vira o próximo

    if (f->prim == NULL) f->ult = NULL; // trata caso a fila só tivesse um nó
    
    primeiro->prox = NULL; // caso já não fosse NULL, o prox do antigo primeiro vira nulo para garantir 100% que não teremos resquícios na memória
    free(primeiro); // libera a memória do antigo primeiro
    return v;
}

int fila_vazia(Fila* f) {
    return (f->prim == NULL);
}

void fila_libera(Fila* f) {
    if (!f) return;

    ListaNo* p1 = f->prim; // usamos dois ponteiros para liberar a fila
    while (p1 != NULL) {
        ListaNo* p2 = p1->prox; // o p2 vai armazenar o proximo
        free(p1); // liberamos o p1
        p1 = p2; // igualamos o p1 ao p2 e assim continua até o fim da fila
    }
    free(f);
}