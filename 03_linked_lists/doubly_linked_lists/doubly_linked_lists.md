# Listas duplamente encadeadas
Cada elemento tem um ponteiro para o próximo elemento e um ponteiro para o elemento anterior.

Desta forma, dado um elemento, podemos acessar ambos os elementos adjacentes (o próximo e o anterior)

```c

typedef struct lista2 {
    ListaNo2* prim;
    ListaNo2* ult;
} Lista2;

typedef struct listano2 {
    int info;
    ListaNo2* ant;
    ListaNo2* prox;
} ListaNo2
```

Com base nessas definições, exemplificaremos a seguir a implementação de algumas funções que manipulam listas duplamente encadeadas. A função que cria uma lista vazia é simples:

```c
Lista2 * lst2_cria (void) {
    Lista2 * l = (Lista2*) malloc(sizeof(Lista2));
    l-> prim = NULL;
    l-> ult = NULL;
    return l;
    // cria uma lista vazia
}
```
No caso da lista duplamente encadeada, as inserções no início e no final são simples e eficientes. Note o encadeamento duplo dos novos elementos na lista:

```c
void lst2_insere_inicio(Lista2* l, int v) {
    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));
    novo->info = v;
    novo->prox = l->prim; // o próximo do primeiro se torna o primeiro da lista
    novo->ant = NULL;

    if (l->prim != NULL) { // testa se a lista é vazia
        l->prim->ant = novo; // o ponteiro anterior de anterior do ex-primeiro índice aponta para o novo primeiro índice
    }
    else {
        l->ult = novo; // novo também é último
        l->prim = novo; // novo é primeiro
    }
}

void lst2_insere_final(Lista2* l int v) {
    ListaNo2* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->info = v;
    novo->ant = l->ult; // anterior de novo é antigo ultimo
    novo->prox = NULL; // o prox aponta para NULL pois esse é o novo ultimo

    if (l->ult != NULL) {
        // testa se a lista é a vazia
        l->ult->prox = novo; // novo é o próximo do antigo ultimo;
    }
    else {
        l->prim = novo; // novo também é o primeiro
        l->ult = novo; // novo é o ultimo
        // isso acontece porque o único elemento existente na lista é o novo
    }
}
```

## Busca de elemento na lista duplamente encadeada

```c
ListaNo2* lst2_busca(Lista2* l, int v) {
    for (ListaNo2 *p = l->prim; p != NULL; p = p->prox) {
        // ponteiro inicial (i=0) aponta para o primeiro da Lista2*
        // enquanto p não for nulo, ele vai incrementar até o próximo p e testar novamente
        if (p->info == v) return p;
    return NULL; // não achou o elemento        
    }
}

// é a mesma lógica da busca na lista simplesmente encadeada.
```

Na busca, a única diferença é que seria possível fazer a busca de trás para frente, mas isso não necessariamente é melhor.

A função que retira um elemento da lista requer o acerto do encadeamento duplo. 

Em contrapartida, podemos retirar um elemento da lista conhecendo apenas o ponteiro para esse elemento.

Se p representa o ponteiro do elemento que desejamos retirar, para acertar o encadeamento devemos conceitualmente fazer:

```c
p->ant->prox = p->prox;
p->prox->ant = p->ant;

// o anterior passa a apontar para o próximo e o próximo passa a apontar para o anterior.
```

No entanto, se p for um elemento no extremo da lista, devemos considerar as condições de contorno. Se p for o último elemento, não podemos escrever p -> prox -> ant, pois p -> prox é NULL

Uma forma de retirar elementos é:

```c

void lst2_retira(Lista2* l, int v) {
    ListaNo2* p = lst2_busca(l, v);

    if (p == NULL) return; // se p for nulo, não dá para retirar

    if (p == l->prim) l->prim = p->prox; // se p for o primeiro, o primeiro passa a apontar para o próximo que se torna o novo primeiro

    else 
    p->ant->prox = p->prox; // faz anterior apontar para o próximo

    if (p == l->ult) l->ult = p->ant; 
    // testa se é o último elemento e atualiza
    else
    p->prox->ant = p->ant; // faz apontar para o anterior
    free(p); // libera memória do nó
}
```

Uma lista circular também pode ser construída com encadeamento
duplo. Porém, o que iria ser o último elemento da lista passa a ter o próximo como o primeiro, que, por sua vez, passa a ter o último como
anterior. Com essa construção podemos percorrer a lista nos dois sentidos, a partir do ponteiro para um elemento qualquer.

# Listas de tipos estruturados
Exemplos anteriores lidavam com situações simples. Logicamente, podemos deixar tudo mais difícil

Independente da informação armazenada e da forma como a informação é representada, o encadeamento dos elementos da lista não é alterado

As funções apresentadas para manipular listas de inteiros podem ser facilmente adaptadas para tratar de listas de outros tipos

Vamos supor que, em uma lista simplesmente encadeada, nós queremos representar um retangulo:

```c
typedef struct retangulo {
    float b;
    float h;
} Retangulo

typedef struct listano {
    Retangulo info;
    ListaNo* prox;
}

static ListaNo* aloca(float b, float h) {
    ListaNo* p = (ListaNo*) malloc(sizeof(ListaNo));
    p->info.b = b;
    p->info.h = h;
    return p;
}
````

Aqui, a informação volta a ser representada por um único campo (info), que é uma estrutura. 

Ainda mais interessante é termos o campo da informação representado por um ponteiro para uma estrutura, em vez da estrutura em si.

```c
typedef struct lista {
    Retangulo* info;
    ListaNo* prox;
}
```
Neste caso, para alocar um nó, temos que fazer duas alocações dinâmicas

Outra possibilidade seria a função já receber o ponteiro do retângulo que deve ser inserido na lista

```c
static ListaNo* aloca(float b, float h) {
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo)); // aloc ret

    ListaNo* p = (ListaNo*) malloc(sizeof(ListaNo)); // aloc nó

    r->b = b;
    r->h = h;
    p->info = r;
    p->prox = NULL;
    return p;
}
```

Dessa forma, o valor da base associado a um nó p seria acessado por: p -> info -> b

A vantagem disso é que, independente da informação armazenada na lista, a estrutura do nó é sempre composta por um ponteiro para a info e outro para o próximo nó da lista

**Isso mantém a estrutura info e ponteiro**

# Listas heterogêneas
A representação da informação por um ponteiro nos permite construir listas heterogêneas, isto é, listas em que as informações armazenadas diferem de nó para nó

```c
typedef struct retangulo {
    float b;
    float h;
} Retangulo;

typedef struct triangulo {
    float b;
    float h;
} Triangulo;

typedef struct circulo {
    float r;
} Circulo;
```

O nó da lista deve então ser composto por três campos:
- um identificador de qual objeto está armazenado no nó

- um ponteiro para a estrutura que contém a informação

- um ponteiro para o próximo nó da lista

É importante saber que a lista é homogênea no sentido de que todos os nós contém os mesmos campos (info, prox). O ponteiro da informação deve ser do tipo genérico, pois não sabemos para que ele aponta

Como identificador de tipos, podemos usar enum:

```c
typedef enum tipo {
    RET, 
    TRI, 
    CIRC
} Tipo;
```

Assim, na criação do nó, armazenamos o identificador de tipo correspondente ao objeto a ser representado. A estrutura que representa o nó pode então ser dada por

```c
typedef struct listanohet {
    Tipo tipo;
    void* info; // ponteiro genérico para info
    ListaNoHet* prox;
} ListaNoHet;

typedef struct listahet {
    ListaNoHet* prim;
} ListaHet;
```

Agora vamos criar os nós

```c
// cria retângulo
ListaNoHet* cria_ret(float b, float h) {
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo)); // aloc ret

    r->b = b;
    r->h = h;

    ListaNoHet* p = (ListaNoHet*) malloc(sizeof(ListaNoHet));
    p->tipo = RET;
    p->info = r; // aloca como info o ponteiro para o retangulo
    p->prox = NULL;
    return p;
}
// cria triângulo
ListaNoHet* cria_tri(float b, float h) {
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));

    t->b = b;
    t->h = h;

    ListaNoHet* p = (ListaNoHet*) malloc(sizeof(ListaNoHet));
    p->tipo = TRI;
    p->info = t;
    p->prox = NULL;
    return p;
}

// cria círculo
ListaNoHet* cria_circ(float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));

    c->r = r;

    ListaNoHet* p = (ListaNoHet*) malloc(sizeof(ListaNoHet));
    p->tipo = CIRC;
    p->info = c;
    p->prox = NULL;
    return p;
}
```

vamos implementar uma função que fornece como valor de retorno a maior área entre os elementos da lista

```c
#define PI 3.14159

static float area(ListaNoHet* p) {
    // aux calcula área correspondente ao nó

    switch (p->tipo) {
        case RET: {
        Retangulo* r = (Retangulo*) p->info; // acessa o retângulo
        return r->b * r->h;
        }
    break;
    case TRI: {
        Triangulo* t = (Triangulo*) p->info;
        return (t->b * t->h) / 2;
        }
    break;
    case CIRC: {
        Circulo* c = (Circulo*) p->info;
        return PI * c->r * c->r;
        }
    break;
    }
    // também podemos individualizar cada função dessas para que apenas chamemos a função apropriada para o respectivo tipo
}
```
Neste código, o tipo ListaHet representa a estrutura da lista heterogênea em si, com um ponteiro para o primeiro nó

```c
float max_area(ListaHet* l) {
    float amax = 0.0; // maior área
    for (ListaNoHet* p = l->prim; p != NULL; p = p->prox) {
        float a = area(p); // área do nó
        if (a > amax) amax = a;
    }
    return amax;
}
```