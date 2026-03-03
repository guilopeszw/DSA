#include <stdlib.h> 

typedef struct fila {
    int ini;      // indice do primeiro elem
    int n;        // qtd de elem armazenados
    int dim;      // dimensão (capacidade atual) do vetor
    int* vet;     // ponteiro para o vetor dinâmico
} Fila;

/*
As fórmulas matemáticas do vetor circular (ini + n) % dim vão continuar exatamente as mesmas! Apenas trocamos o MAX pelo f->dim.
*/

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila)); // alocamos a fila
    if (!f) return NULL;

    f->dim = 4; // assumimos um valor base para a dimensão do vetor, à titulo de podermos alocar o ponteiro.
    
    f->vet = (int*) malloc(f->dim * sizeof(int)); // alocamos o ponteiro
    if (!f->vet) return NULL;

    f->ini = 0;
    f->n = 0;
    return f;
}

void fila_insere(Fila* f, int v) {
    if (!f) return; // verificação base

    if (f->n == f->dim) { // se o num de elementos for == dimensão
        f->dim *= 2; // dobra a dimensão
        f->vet = (int*) realloc(f->vet, f->dim * sizeof(int)); // realoca o vetor para a nova dimensão

        if (f->ini != 0) memmove(&f->vet[f->dim - f->ini], &f->vet[f->ini], (f->n - f->ini) * sizeof(int)); // copia a memória para outro lugar de maneira segura
        /*
        memmove(destino, origem, tamanho_em_bytes)
        o & utilizado é para descobrir a exata localização física de uma variável na RAM. já que estamos movendo um pedaço da memória pra outro, é o recomendado.

        
        - f->vet[f->ini] devolve o valor que está dentro da variável. Seria como perguntar "Quem mora nessa casa?"

        - &f->vet[f->ini] devolve o endereço da casa. Seria como perguntar "Qual é a coordenada exata dessa casa na rua?"
        */
    }

    // insere o elemento desejado na próxima posição livre do vetor.
    int fim = (f->ini + f->n) % f->dim; // pega o fim (próximo espaço livre)
    f->vet[fim] = v; // adiciona o valor desejado no próximo espaço livre
    f->n++; // incrementa o num de elementos
}

int fila_retira(Fila* f) {
    if (!f) return -1;

    float v = f->ini; // armazenamos o valor que vamos retirar

    f->ini = (f->ini + 1) % f->dim; // incrementa no início para remover o primeiro
    f->n--;
    
    return v;
}

int fila_vazia(Fila* f) {
    return (f->n == 0);
}

void fila_libera(Fila* f) {
    free(f->vet);
    free(f);
}