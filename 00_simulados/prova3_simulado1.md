## Questão 1) Explique o funcionamento de árvores de busca e sua eficiência.

### Resposta:
Uma árvore de busca é um tipo de árvore binária que tem a seguinte estrutura: para cada nó, seu filho à esquerda é menor/igual e seu filho à direita é maior. Assim, a eficiência vem porque, ao percorrer uma árvore de busca, cada nó percorrido diminui em 50% o número de iterações necessárias para encontrar o valor desejado. Logo, se a árvore estiver balanceada, ela tem eficiência de O(log N) e O(n) se não estiver balanceada.

## Questão 2) Crie o TAD de uma árvore.
```c
typedef struct arv Arv;

Arv* arv_cria (int c, Arv* e, Arv* d); 
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
int arv_pertence (Arv* a, int c);
void arv_imprime (Arv* a);
```

## Questão 3) Implemente uma árvore recursivamente em C.
```c
typedef struct arvno {
    int info;
    struct arvno* esq;
    struct arvno* dir;
} ArvNo;

typedef struct arv {
    ArvNo* raiz;
} Arv;

Arv* cria_no(int v) {
    ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
    if (!novo) return NULL;

    novo->info = v;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

Arv* cria_arv (Arv* root) {
    if (!root) return NULL;

    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->raiz = root;

    return a;
}

void arvn_insere (ArvNo* a, ArvNo* sa) {
    // inserimos nós como sendo sub-arvores
    sa->dir = a->esq;
    a->esq = sa;
}

int arv_vazia (Arv* a) {
    return a == NULL;
}

int arv_pertence (Arv* a, int c) {
    // percore a árvore em pré ordem
    if (!a) return 0; // caso não haja árvore

    if (!a->raiz) return 0; // caso a raiz não exista -> caso de quebra

    if (a->raiz->info == c) {
        return 1; // caso achemos o valor
    }

    if (a->raiz->info >= c) {
        return arv_pertence(a->raiz->esq, c); // caso o valor seja menor que o do nó, vamos para a esquerda
    }
    else {
        return arv_pertence(a->raiz->dir, c); // se o valor for maior, vamos para a direita.
    }
}

void libera_nos(ArvNo* n) {
    if (n != NULL) {
        libera_nos(n->esq);  // libera esquerda
        libera_nos(n->dir);  // libera direita
        free(n);             // libera raiz
        // libera tudo em pós ordem
    }
}

void arv_libera(Arv* a) {
    if (a != NULL) {
        libera_nos(a->raiz); // inicia pela raiz
        free(a);             // libera a árvore no final
    }
}

void arv_imprime(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%d ", a->raiz->info);  // imprime a raiz
        arv_imprime(a->raiz->esq);    // visita esquerda
        arv_imprime(a->raiz->dir);    // visita direita
    
```