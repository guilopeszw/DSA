#include <stdlib.h>
#include <stdio.h>

struct no {
    int info;
    struct no* prox;
};

typedef struct no No;

No* create_no(int info) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return NULL;

    novo->info = info;
    novo->prox = NULL;
    
    return novo;
}

int inserir_inicio(No** head, int info) {
    No* novo = create_no(info);
    if (!novo) return 0;

    if (*head == NULL) {
        *head = novo;
        return 1;
    }
    novo->prox = *head;
    *head = novo;
    return 1;
}

No* buscar_info(No* head, int info) {
    if (head == NULL) return NULL;
    No* aux = head;
    
    while (aux != NULL) { // a comparação do while é para ele percorrer todos os nós até encontrar o NULL, que indica que não tem mais nós
        if (aux->info == info) return aux; // percorre os nós até encontrar a info desejada, retornando o ponteiro do nó que contém a informação desejada
        // é possível, até mesmo, alterar a informação usando isso, pois o ponteiro do nó permite que tenhamos acesso à info
        aux = aux->prox;
    }
    return NULL;
}

No* busca_indice(No* head, int index) {
    if (head == NULL) return NULL;
    No* aux = head;
    int i = 0;

    while (aux != NULL) {
        if (i == index) return aux;
        i += 1;
        aux = aux->prox;
    }
}