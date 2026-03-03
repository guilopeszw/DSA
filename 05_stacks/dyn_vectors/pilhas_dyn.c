typedef struct pilha {
    int n;          // num de elementos (indica o topo)
    int dim;
    int* vet; // vetor onde os dados são armazenados
} Pilha;

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return;

    p->n = 0; // inicializamos com 0
    p->dim = 4; // valor base
    p->vet = (int*) malloc(p->dim * sizeof(int));
    if (!p->vet) return;

    return p;
}

void pilha_push(Pilha* p, int v) {
    if (!p) return;

    if (p->n == p->dim) {
        p->dim *= 2;
        p->vet = (int*) realloc(p->vet, p->dim * sizeof(int));
    }

    p->vet[p->n] = v;
    p->n++;
}

int pilha_pop(Pilha* p) {
    if (!p || p->n == 0) return 0;

    int removido = p->vet[p->n - 1]; // acessamos o elemento que está como último da pilha
    p->n--;
    
    if (p->dim / 4 > p->n) {
        p->dim /= 4;
        p->vet = (int*) realloc(p->vet, p->dim * sizeof(int));
    }

    return removido;
}

int pilha_vazia(Pilha* p) {
    if (!p) return -1;
    return (p->n == 0);
}

void pilha_libera(Pilha* p) {
    if (!p) return;

    free(p->vet);
    free(p);
}