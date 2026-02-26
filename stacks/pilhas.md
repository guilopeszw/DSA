# Pilhas

## Regra: LIFO (Last in, first Out)

Todo acesso aos elementos de uma pilha deve ser feito através do topo

## Analogia
**Quando lavamos os pratos na pia, se quisermos retirar um prato do meio da pilha, precisamos tirar os que estão em cima primeiro. Assim como, caso queiramos colocar um prato novo, ele será colocado no topo da pilha**

# Pilhas com vetor dinâmico

Devemos ter um vetor para armazenar os elementos da pilha. Os elementos inseridos ocupam
as primeiras posições do vetor. Desta forma, se temos n elementos armazenados na pilha, o **elemento vet[n - 1] representa o elemento do topo**. Em aplicações computacionais que precisam de uma estrutura de pilha, `é comum saber de antemão o número máximo de elementos que podem estar armazenados simultaneamente na pilha`, isto é, a estrutura da pilha tem um limite conhecido. `Nestes casos, a implementação da pilha pode ser feita usando um vetor estático`, **mas é necessário verificar a capacidade da pilha para inserção**

## Interface do tipo pilha:

```c
typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, int v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
```

A função de criar *aloca dinamicamente* a estrutura da pilha e inicializa seus campos, retornando seu ponteiro

As funções push e pop inserem e retiram, respectivamente.

A função vazia informa se a pilha está ou não vazia; 

A função libera destrói a pilha, liberando toda a memória usada pela estrutura.

```c
struct pilha {
    int n; // num de elementos armazenados na pilha
    int dim; // dimensão atual do vetor
    float* vet; // vetor dos elementos
}
```

## Função de criar a pilha:
```c
Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;
    
    p->dim = 2; // definimos isso como dimensão inicial
    p->vet = (int*) malloc(p->dim * sizeof(int)); // alocamos de acordo com a dim
    p->n = 0; // começamos com 0 elementos
    
    return p;
}
```

## Função push:

```c
void pilha_push(Pilha* p, int v) {
    if (!p) return;

    if (p->n == p->dim) {
        // verifica se a capacidade do vetor já foi esgotada
        p->dim *= 2; // pratica comum, mas podemos fazer por 1.5 também.
        p->vet = (int*) realloc(p->vet, p->dim * sizeof(int)); // realoca o vetor de elementos
    }
    p->vet[p->n++] = v; // insere elemento na próxima posição livre
}
```

## Função pop:
```c
int pilha_pop(Pilha* p) {
    if (!p) return NULL;

    int v = p->vet[--p->n]; // retira elemento do topo
    return v;
}
```

Nestas duas ultimas funções, usamos operadores de incremento e decremento em expressões. 

Na função push , incrementamos o número de elementos após armazenar o elemento (operador pós-fixado): **o valor é armazenado no índice n, que depois é incrementado.**

Na função pop , decrementamos o número de elementos antes de acessar o vetor (operador prefixado): **assim, acessamos o vetor com o valor de n já decrementado.**

## Verificação de pilha vazia e liberação:

```c
int pilha_vazia(Pilha* p) {
    if (!p) return NULL;

    return (p->n == 0); // compara se o numero de elementos é 0
}

void pilha_libera(Pilha* p) {
    if (!p) return;

    free(p->vet);
    free(p);
}
```

# Implementação de pilha com lista encadeaeda

```c
typdef struct listano ListaNo;
struct listano {
    int info;
    ListaNo* prox;
}

struct pilha {
    ListaNo* prim;
};

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->prim = NULL; // inicializa a pilha vazia
    return p;
}
```

## Push com listas encadeadas:
```c
int pilha_push(Pilha* p, int n) {
    if (!p) return 0;
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    if (!novo) return -1;

    novo->info = n;
    novo->prox = p->prim;
    p->prim = novo;
    return 1;
}
```

## Pop com listas encadeadas
```c
int pilha_pop(Pilha* p) {
    if (!p) return 0;

    ListaNo* aux = p->prim; // armazena o topo da pilha
    p->prim = aux->prox; // faz o topo da pilha apontar para o prox

    aux->prox = NULL;
    free(aux);
    return 1;
}
```

```c
int pilha_vazia(Pilha* p) {
    return (p->prim == NULL); // verificação básica
}

```

## Liberação de pilha com listas encadeadas
Nesse caso, a função de liberar (free) precisa, antes, liberar TODOS os elementos.

```c
void pilha_libera(Pilha* p) {
    if (!p) return;
    ListaNo* q = p->prim;

    while (q != NULL) {
        ListaNo* t = q->prox; // o node local `t` vai armazenar o ponteiro do prox
        free(q); // liberamos o ponteiro atual
        q = t; // passamos o ponteiro para o prox
    }

    free(p);
}
```

