#include <stdlib.h>
#define _TAMANHO_MAX_ 10
typedef struct pilha {
    int valores[_TAMANHO_MAX_];
    int n;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) return NULL; // verifica se a alocação funciona
    p->n = -1; // indica que a pilha está vazia
    return p;
}

int esta_vazia(Pilha* p) {
    if (p == NULL) return NULL;

    if (p->n == -1) {
        return 1;
    }
    return 0;
}

int esta_cheia(Pilha* p) {
    if (p == NULL) return -1;

    if (p->n == (_TAMANHO_MAX_ - 1)) { // não pode acessar direto o TAD (p->valores)
        return 1;
    }
    return 0; // vazia
}

int tamanho (Pilha* p) {
    if (p == NULL) return NULL;

    return (p->n + 1);
}

void libera(Pilha** p) {
    if (p == NULL) return;

    free(*p);
    *p == NULL;

    // fazer a liberação com ponteiro duplo permite que você libere o p' que aponta para p, onde p aponta para a estrutura da pilha.
}

int push(Pilha* p, int n) {
    if (p == NULL) return 0;

    if (esta_cheia(p)) return 0;

    p->n++; // adiciona um índice ao tamanho de p
    p->valores[p->n] = n; // faz o novo índice de p ter o valor da informação inputada
    return 1;
}

int pop(Pilha* p, int* valor) {
    if (p == NULL || valor == NULL) return 0;
    if (esta_vazia(p)) return 0;

    *valor = p->valores[p->n]; // pega o valor final da pilha (LIFO)
    p->n--; // subtrai índice da pilha
    return 1;
}