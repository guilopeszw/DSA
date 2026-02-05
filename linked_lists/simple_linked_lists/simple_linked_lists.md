# Listas encadeadas

O vetor não é uma estrutura de dados muito flexível
- Precisamos dimensioná-lo com um número máximo de elementos 

O uso de vetores dinâmicos, através de realocação da memória, ameniza o problema
- Mas não necessariamente é uma solução em todas as situações
- **O custo computacional para realocar um vetor é alto**

### Assim surgem as listas encadeadas
Estruturas de dados que cresçam/diminuam à medida que precisamos armazenar/remover elementos. 

**Estas estruturas dinâmicas fazem uma alocação de memória para cada novo elemento armazenado**

# Listas simplesmente encadeadas
Numa lista encadeada, para cada novo elemento inserido na estrutura,
alocamos um espaço de memória para armazená-lo.

`O espaço total de memória gasto pela estrutura é proporcional ao número de elementos nela armazenado`

**PORÉM**, não podemos assumir que os elementos armazenados ocuparão um espaço de memória parecido

A estrutura consiste numa sequência encadeada de elementos, em geral chamados de `nós da lista`

Um nó da lista é representado por uma estrutura que contém, conceitualmente, dois campos: 
- informação armazenada
- ponteiro para o próximo elemento da lista

**A partir do primeiro nó, podemos alcançar o segundo seguindo o encadeamento e assim por diante**

`O último nó da lista armazena, como próximo nó, um ponteiro inválido, com valor NULL sinalizando que não existe um próximo nó`

A lista em si, portanto, deve ser representada por um ponteiro para o primeiro nó.

```c
struct lista {
    ListaNo* prim;
} Lista;

struct listano {
    int info;
    ListaNo* prox;
} ListaNo;
```

Devemos notar que a estrutura que representa o nó da lista é uma **estrutura autoreferenciada**
- além do campo que armazena a informação (no caso, um número inteiro), **há um campo que é um ponteiro para uma próxima estrutura do mesmo tipo**

## Função de criação
A função que cria uma lista vazia deve ter como valor de retorno uma lista sem nenhum elemento

Como a lista armazena o ponteiro para o primeiro elemento, `uma lista vazia é representada por armazenar o valor NULL, pois não existem elementos na lista``
A função tem como valor de retorno o ponteiro para a estrutura de lista criada dinamicamente

Uma possível implementação da função de criação é mostrada a seguir (usamos o prefixo lst para indicar que tratam-se de funções para manipular listas encadeadas):

```c
// função de criação: retorna uma lista inicialmente vazia
Lista* lst_cria (void) {
    Lista* l = (Lista*) malloc(sizeof (Lista)); // aloca memória 
    l-> prim = NULL; // primeiro item da lista é nulo
    return l; // retorna ponteiro
}
```

## Função de inserção
Para cada elemento inserido na lista, devemos alocar dinamicamente a memória necessária para armazenar um novo nó e encadeá-lo na lista existente

```c
// INSERÇÃO NO INÍCIO DA LISTA
void lst_insere (Lista* l, int v)
{
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo -> info = v; // a informação
    novo -> prox = l-> prim; // o próximo nó da lista (se for NULL, o nó atual é o ultimo)
    l-> prim = novo; // coloca esse nó como sendo o prim na lista de nós
}
```

## Função que percorre os elementos da lista

```c
// função imprime: imprime valores dos elementos
void lst_imprime(Lista* l) {
    for ( ListaNo* p=l-> prim; p!= NULL; p=p-> prox)
    printf("info = %d \n", p->info);
}
// % informa que não é para printar literalmente
// %d informa que iremos deixar um buraco para um decimal que será passado em seguida
// o \n indica que depois de escrever o número, deve pular a linha
// o que vem depois da virgula é pegando o valor que será armazenado como decimal no buraco que deixamos
// -> "Siga esse ponteiro até a memória e entre na estrutura".
```

Para percorrer uma lista encadeada, a variável auxiliar tem que ser um ponteiro, usada para armazenar o endereço de cada elemento

Note ainda que só conseguimos percorrer os elementos do primeiro ao último, pois só temos o ponteiro para o próximo nó. E também que não temos acesso randômico aos elementos da lista

Para acessar determinado elemento, temos que percorrer a lista desde o início, `até que o elemento de interesse seja alcançado`. 

Outra função útil consiste em verificar se determinado elemento está presente na lista.

A função recebe a informação referente ao elemento que queremos buscar e fornece como valor de retorno 1 se o elemento for encontrado ou 0 se não for

```c
// função pertence: verifica se um elemento está na lista
int pertence (Lista* l, int v) {
    for (ListaNo* p = l->prim; p!= NULL; p=p->prox) { // percorre do primeiro elemento a lista até que o próximo seja NULL (fim da lista)
        if (p-> info == v)
        return 1; // encontrou o elemento
    }
    return 0; // não encontrou o elemento
}
```

## Manutenção da lista ordenada

Nós estamos apenas inserindo no início, mas se decidirmos inserir no meio da lista, essa função não é eficiente pois teríamos que percorrer a lista, elemento por elemento, para achar a posição de inserção.

`Se a ordem não importa, é preferível que a inserção seja no início, pois o custo computacional dessa operação independe do número de elementos da lista`

Porém, caso seja necessário manter a ordem:
- 1. Localizar elemento que irá preceder o novo elemento na lista;
- 2. O ponteiro de próximo do elemento que precede deve apontar para o novo ponteiro
- 3. O ponteiro de próximo do novo ponteiro deve apontar para o que, antes, era o próximo elemento do elemento que agora precede o novo elemento

```c
void lst_insere_no_meio(Lista* l, int v) {
    ListaNo* ant = NULL; // ponteiro para o elemento anterior
    ListaNo* p = l->prim; // ponteiro para percorrer a lista toda

    while (p != NULL && p->info < v) { // localiza posição de inserção
        ant = p; // elemento anterior vira o atual
        p = p->prox; // elemento atual vira o próximo
    }

    // cria elemento que será inserido
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->info = v; 

    if (ant == NULL) {
        novo->prox = l->prim; // o próximo novo se torna o primeiro do original
        l->prim = novo; // o primeiro do original se torna o novo
        // ponteiro do próximo do novo aponta para o precedente do original
        // ponteiro do precedente do antigo aponta para o novo
    }
}
```

## Função que retira um elemento da lista
A função para retirar um elemento da lista é similar à função que insere os elementos em ordem. 

Se descobrirmos que o elemento a ser retirado é o primeiro da lista, devemos fazer com que o valor do primeiro elemento da lista passe a ser o ponteiro para o segundo elemento, **e então podemos liberar o espaço alocado para o elemento que queremos retirar**

```c

// função retira: retira elemento da lista
void lst_retira(Lista* l, int v) {
    ListaNo* ant = NULL; // ponteiro para elemento anterior (inicia NULL)
    ListaNo* p = l-> prim; // ponteiro para percorrer a lista (inicia no primeiro nó da lista)
    
    while (p != NULL && p-> info != v) { // procura elemento na lista guardando o anterior

    // enquanto p não for nulo (indicando o fim da lista) e o valot da info de p não for igual ao desejado, o while fica ativo
        ant = p; // guarda p como anterior
        p = p-> prox; // faz o p virar o próximo nó
    }
    if (p != NULL) { // verifica se achou o elemento
        if (ant == NULL) { // retira elemento do inicio
            l-> prim = p-> prox;
        }
        else {
            ant->prox = p->prox; // retira elemento do meio da lista
        }
        free(p); // libera memória do elemento
    }
}
```

## Função para verificar se vazia e função para liberar
Pode ser útil implementar uma função para verificar se uma lista está vazia ou não.

A função recebe a lista e retorna 1 se estiver vazia ou 0 se não estiver vazia. Como sabemos, uma lista está vazia se seu primeiro elemento é NULL

```c
// função vazia: retorna 1 se vazia ou 0 se não vazia
int lst_vazia (Lista* l) {
    return (l->prim == NULL);
}

void lst_libera(Lista* l) {
    ListaNo* p = l->prim; // ponteiro para o início da lista

    while (p != NULL) {
        ListaNo* t = p->prox; // guarda ref para o próx elemento
        free(p); // libera memória de p
        p = t; // faz p apontar para o próximo elemento
    }
    free(l);
}
```

# Implementações recursivas
A estrutura de encadeamento de uma lista pode ser definida de maneira recursiva. Podemos dizer que o encadeamento é:
• Vazio (isto é, sem nenhum nó); ou
• Um nó seguido de um (sub) encadeamento.

No primeiro caso, o ponteiro que representa o primeiro nó da lista é NULL; no segundo caso, o ponteiro para o segundo, armazenado como próximo nó do primeiro, representa o primeiro nó do subencadeamento

```c
static void imprime_nos (ListaNo* p) {
    // função aux recursiva para imprimir encadeamento

    if (p != NULL) {
        printf("% d\ n", p->info); // vai carregar um numero (primeiro elemento)
        imprime_nos(p->prox); // imprime subencadeamento
    }
    // a lista imprime dentro dela mesma até que a condição (p != NULL) seja satisfeita (ou seja, p == NULL)
}

void lst_imprime_rec(Lista* l) {
    // função interface que usa aux recursiva
    imprime_nos(l->prim); 
}
```

Com a implementação recursiva, este problema é facilmente resolvido, basta inverter a ordem da impressão: primeiro imprimimos o subencadeamento (que irá imprimir os elementos em ordem inversa) e, em seguida, imprimimos o primeiro elemento:

```c
static void imprime_nos_rev(ListaNo* p) { 
    // função aux recursiva para imprimir o encadeamento
    if (p != NULL) {
        imprime_nos_rev(p->prox); // imprime subencadeamento
        printf("% d\ n", p->info); // imprime primeiro elemento
    }

    void lst_imprime_rev(Lista* l) {
        imprime_nos_rev(l->prim);
    }
}
```
A utilização de implementações recursivas para listas encadeadas é apenas uma opção. Em geral, a implementação não recursiva é mais eficiente do ponto de vista do esforço computacional dispensado, pois minimiza o número de chamadas de funções, que são operações relativamente caras.

# Listas circulares
Algumas aplicações necessitam representar conjuntos cíclicos. Por exemplo, as arestas que delimitam um polígono podem ser agrupadas por uma estrutura circular. Para esses casos, podemos usar listas circulares. Numa lista circular, **o último elemento tem como próximo o primeiro elemento da lista, formando um ciclo.**

Para percorrer os elementos de uma lista circular, visitamos todos os elementos a partir do ponteiro do elemento inicial até alcançar novamente esse mesmo elemento.

```c
void lcirc_imprime (Lista* l) {
    ListaNo* p = l->prim // aponta para o nó inicial
    if (p != NULL) do { // se não vazia, percorre:
        printf("% d\ n", p->info) // printa info do nó
        p = p->prox; // avança para o próximo nó
    } while (p != l->prim);

    // ou seja, ele aponta para o nó inicial e, caso ele não seja NULL, vai percorrer todos os nós - printando as infos
    // depois de printar a info, ele avança ao próx nó. isso vai acontecer até que p seja igual ao l->prim (primeiro nó da lista)
}
```