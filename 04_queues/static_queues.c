#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // tamanho estático máximo da fila

typedef struct fila {
    int ini;          // index do primeiro elem
    int n;            // qtd de elem armazenados
    int vet[MAX];   // vetor que guarda os nums
} Fila;

/*
para as filas, é necessário que os vetores sejam circulares (ou seja, o próximo depois do último é o primeiro).

A ideia é que, quando o final da fila chega no último índice do vetor, o próximo elemento a ser inserido dá a volta e entra no índice 0 (se ele estiver vazio, claro).
*/

Fila* fila_cria() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->n = 0; // começa no indice 0
    f->n = 0; // começa com 0 elementos armazenados
    return f;
}

int fila_vazia(Fila* f) {
    return (f->n == 0); // verifica se o numero de elementos da fila é o mesmo que o inicializado (0)
}

int fila_cheia(Fila* f) {
    return (f->n == MAX); // verifica se o numero de elementos da fila é o mesmo que o tamanho do vetor inicializado
}

/*
Como descobrir em qual posição do vetor devemos inserir o próximo elemento (o índice do final da fila)?
só é necessário somar o início com a quantidade de elementos -> ini + n.

Mas e se ini = 98, n = 4 e nosso MAX = 100? A soma dá 102, que está fora do vetor. como resolvemos isso?
por meio da circularidade!
*/

/*
Para fazer o valor "dar a volta", usamos o operador de resto da divisão (%):

int fim = (f->ini + f->n) % MAX;
(Exemplo: 102 % 100 = 2. O elemento entra perfeitamente no índice 2)
*/

void fila_insere(Fila* f, int v) {
    if (!f) return;
    if (fila_cheia(f)) return; // verificamos se a fila está cheia. se estiver, retornamos

    int fim = ((f->ini + f->n) % MAX); // identificamos o fim da fila por meio do resto da divisão -> (Exemplo: 102 % 100 = 2. O elemento entra perfeitamente no índice 2)

    f->vet[fim] = v; // adiciona ao fim do vetor de numeros o elemento à ser inserido
    f->n++; // incrementa o numero de elementos
}

int fila_retira(Fila* f) {
    if (fila_vazia(f)) return -1; // verificamos se a fila está vazia

    int aux = f->vet[f->ini]; // armazenamos o início da fila
    f->ini = (f->ini + 1) % MAX; // incrementamos o início para remover o antigo primeiro, mantendo em mente o MAX

    /*
    f->ini = (f->ini + 1) % MAX;
    isso significa que: ele vai analisar o resto da divisão entre, por exemplo, 100 + 1 % MAX, que daria 1 (colocando no indice 1, que seria o próximo).

    fazer dessa maneira é o que permite a circularidade do vetor estático.
    */

    f->n--; // decrementamos da quantidade de elementos para mostrar que saiu alguém/algo da fila
    
    return aux; // retorna o valor retirado da fila
}