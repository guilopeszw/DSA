#include <stdlib.h>

typedef struct deque {
    int ini;      // índice do primeiro elemento
    int n;        // quantidade de elementos
    int dim;      // dimensão (capacidade atual)
    int* vet;     // o vetor de nums
} Deque;

Deque* fila2_cria(void) {
    Deque* d = (Deque*) malloc(sizeof(Deque));
    if (!d) return NULL;
    
    d->dim = 4; // valor base
    d->ini = 0;
    d->n = 0;

    d->vet = (int*) malloc(d->dim * sizeof(int));
    if (!d) return NULL;

    return d;
}

void fila2_insere_ini(Deque* d, int v) {
    if (!d || !d->vet) return; // se a deque não existir ou o vetor não existir, quebra

    if (d->n == d->dim) { // verifica se a capacidade está esgotada
        int nova_dim = d->dim * 2; // armazenamos a dimensão * 2 por segurança, antes de usarmos ela para criar o novo vetor
        int* novo_vetor = (int*) malloc(nova_dim * sizeof(int)); // criamos um novo vetor com o dobro de capacidade do original

        for (int i = 0; i < d->n; i++) {
            // para todo i menor que o numero de elementos, vamos reorganizá-los para que o início volte a ser o i=0 no vetor

            int pos_antiga = (d->ini + i) % d->dim; // acha a posição antiga percorrendo o vetor circular
            novo_vetor[i] = d->vet[pos_antiga]; // no novo vetor, em ordem, vamos adicionar as posições na ordem -> para que o inicio do vetor original
            // seja realmente o inicio da fila
        }
        free(d->vet);

        d->vet = novo_vetor; // o vetor da deque vira o nosso novo vetor reorganizado
        d->dim = nova_dim; // a dimensão da deque vira nossa nova dimensão (o dobro da original)
        d->ini = 0; // o inicio agora é 0. o vetor está perfeitamente alinhado
    }

    d->ini = (d->ini - 1 + d->dim) % d->dim; // damos um passo para trás
    /*
    ou seja, d->ini passa a ser o inicio -1. precisamos somar com a dimensão e fazer o módulo para garantir a circularidade do vetor (e seu funcionamento)
    */

    d->vet[d->ini] = v; // agora o inicio do vetor, que acabou de voltar uma casa, é o valor que desejamos inserir
    d->n++; // incrementamos o num de elementos para mostrar que temos mais um elemento no vetor agora.
}

int deque_retira_fim(Deque* d) {
    if (!d || !d->vet) return -1;

    int ultimo = d->vet[(d->ini + d->n - 1) % d->dim]; // ultimo valor do vetor, vamos utilizá-lo para retornar ao usuário o valor
    // LEMBRAR DE SEMPRE FAZER O D->VET!!!! se não é apenas um endereço
    d->n--; // decrementamos o valor de n

    /*
    por que não precisamos remover o valor do vetor em si?

    a remoção lógica por meio do decremento de n vai "anular" a existência desse valor, de forma que:
    quando formos inserir um valor, n vai apontar que aquele espaço onde acabamos de remover um numero, está vazio!

    por que (d->ini + d->n - 1)?

    porque (d->ini + d->n) vai nos dar o próximo valor livre, mas nós queremos na verdade retirar o valor que precede o próximo espaço livre, logo, -1
    */
    return ultimo;
}