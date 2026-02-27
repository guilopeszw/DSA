#include "stacks.h"
#include <stdlib.h>

typedef struct no {
    int n;
    struct no* prox;
} No;

typedef struct pilha {
    No* prim;
} Pilha;

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->prim = NULL;
    return p;
}

void pilha_push(Pilha* p, int v) {
    if (!p) return;

    No* novo = (No*) malloc(sizeof(No));
    novo->n = v;

    novo->prox = p->prim;
    p->prim = novo;
}

int pilha_pop(Pilha* p) {
    if (!p || !p->prim) return -1;

    No* aux = p->prim; // armazenamos o p->prim em um aux
    int n = aux->n; // armazenamos o valor de n para retornar ao usuário
    p->prim = p->prim->prox; // p->prim agora aponta para o prox
    aux->prox = NULL; // desconectamos o p->prim original da pilha, fazendo o prox apontar para NULL
    free(aux); // liberamos a memória
    
    return n; // retorna o valor que tinha onde houve o pop
}

void pilha_libera(Pilha* p) {
    if (!p) return;

    while (p->prim != NULL) {
        pilha_pop(p);
    }
    free(p);
}


/*
15. q1)
(a) Implemente uma função que receba duas pilhas, p1 e p2, e passe todos os elementos da pilha p2 para o topo da pilha p1. 
A Figura 15.6 (Introdução à estrutura de dados com técnicas de programação em C - Waldemar Celes) ilustra essa concatenação de pilhas. Note que, ao final dessa função, a
pilha p2 vai estar vazia e a pilha p1 conterá todos os elementos das
duas pilhas.

void concatena_pilhas (Pilha* p1 , Pilha* p2 );
Implemente esta função de duas formas distintas: (i) usando uma função recursiva; (ii) usando uma terceira pilha auxiliar.
*/

void aux_concatena_pilhas(Pilha* p1, Pilha* p2) {
    if (!p1 || !p2) return;

    Pilha* aux = pilha_cria();

    while (p2->prim != NULL) {
        pilha_push(aux, pilha_pop(p2));
    }
    // agora p2 está invertido na pilha aux
    // ex: p2 = [3, 4, 9] -> p2 = []; aux = [9, 4, 3]

    while (aux->prim != NULL) {
        pilha_push(p1, pilha_pop(aux));
    }
    pilha_libera(aux);
    // agora esvaziamos a pilha aux em p1, invertendo a ordem novamente (voltando p/ original).
    /*
    p1 = [2, 4, 1], p2 = [7, 3, 9], aux = []
    p1 = [2, 4, 1], p2 = [], aux = [9, 3, 7]
    p1 = [7, 3, 9, 2, 4, 1], p2 = []
    */
}

void concatena_recursivo(Pilha* p1, Pilha* p2) {
    if (!p1 || !p2) return;
    if (p2->prim == NULL) return; // essa leitura é para verificarmos se p2 já está 100% vazia

    int v = pilha_pop(p2); // tira o topo de p2 e armazena em v (para evitar stack overflow)

    concatena_recursivo(p1, p2); // vai buscar o prox topo de p2;

    pilha_push(p1, v); // vai dar push no valor do pop para p1

    /*
    p2 = [30,20], p1 = [10, 5]

    1. verifica se p2 esta vazia -> ainda não está
    2. dá um pop armazena o topo de p2 em v, logo: v = 30;
    3. puxa a função novamente
        1. verifica se p2 está vazia -> ainda não está, temos 20 na pilha ainda
        2. dá um pop e armazena o topo de p2 em v, logo: v = 20;
        3. puxa a função novamente
            1. verifica se p2 está vazia -> agora está
            2. volta para a função "passada"
        4. da um push de v para p1, onde v = 20; -> p1 = [20, 10, 5];
        5. fecha a função e retorna
    4. dá um push de v para p1, onde v = 30; -> p1 = [30, 20, 10, 5];
    5. fecha a função e retorna

    terminamos com:
    p1 = [30, 20, 10, 5], p2 = [] -> mantemos p2 vazio pois é o que a questão pede
    */
}

/*
(b)
Implemente uma função que receba uma pilha como parâmetro e retorne o valor armazenado em seu topo, restaurando o conteúdo da pilha. 
Essa função deve obedecer ao protótipo: int topo (Pilha* p);
*/

int topo(Pilha* p) {
    return (p->prim->n);
}

int topo_funcoes(Pilha* p) {
    if (!p || p->prim == NULL) return -1;
    int v = pilha_pop(p);
    pilha_push(p, v);

    return v;
}

/*
(c)
Implemente uma função que receba uma pilha como parâmetro e retorne como resultado uma cópia dessa pilha. 
Essa função deve obedecer ao protótipo: Pilha* copia_pilha (Pilha* p);
Ao final da função copia_pilha , a pilha p recebida como parâmetro deve ter seu conteúdo original. 
Implemente duas versões desta função: usando recursão e usando uma pilha auxiliar.
*/

Pilha* copia_pilha_aux(Pilha* p) {
    if (!p || !p->prim) return NULL;

    Pilha* aux = pilha_cria();
    Pilha* copia = pilha_cria();

    while (p->prim != NULL) {
        pilha_push(aux, pilha_pop(p));
    }
    // agora, temos a pilha p vazia, a pilha copia vazia e todos os itens de p estão armazenados na ordem inversa na pilha aux

    while (aux->prim != NULL) {
        int v = pilha_pop(aux); // remove de aux e guarda o valor para darmos push em p e copia
        pilha_push(p, v);
        pilha_push(copia, v);
    }

    // v fica como variável temporária pois é declarada apenas dentro do while

    pilha_libera(aux);
    // esvaziamos aux, dando push no valor n do topo de aux para p e push no pop (removendo e atualizando o topo de aux) de aux para a copia.
    // no fim, teremos a pilha aux vazia e duas pilhas identicas (p e copia).
    return copia;
}

Pilha* pilha_copia_rec(Pilha* p) {
    if (!p) return NULL;

    if (p->prim == NULL) return pilha_cria(); // criamos a nova pilha que será preenchida na volta

    int v = pilha_pop(p); // armazenamos o pop

    Pilha* copia = pilha_copia_rec(p); // fazemos a chamada recursiva

    pilha_push(p, v); // quando saímos da chamada rec, damos push de v em p e em copia
    pilha_push(copia, v);

    return copia;
}