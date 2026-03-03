#define MAX 100 // tamanho máximo da pilha

typedef struct {
    int n;          // num de elementos (indica o topo)
    int vet[MAX]; // vetor onde os dados são armazenados
} Pilha;

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return;
    p->n = 0; // inicializamos com 0 elementos

    return p;
}

void pilha_push(Pilha* p, int v) {
    if(!p) return;

    if (p->n == MAX) return; // verifica se a pilha está cheia

    p->vet[p->n] = v; // o num v (input) é inserido no indice n do vetor
    // assim, utilizamos o ptr do vetor para fazer o push e o num de elem 
    // para saber aonde
    p->n++; // incrementamos o num de elementos para dizer que adicionamos +1
}

int pilha_pop(Pilha* p) {
    if (!p || p->n == 0) return 0;

    int v = p->vet[p->n - 1]; // armazenamos o valor do topo
    p->n--; // decrementamos o num de elem
    return v;

    /*
    não precisamos mudar nada no vetor vet em si, ele serve para 
    contarmos se estamos no limite ou não.
    */
}

int pilha_vazia(Pilha* p) {
    if (!p) return -1;
    return (p->n == 0);
}

void pilha_libera(Pilha* p) {
    if (!p) return;
    free(p);
}