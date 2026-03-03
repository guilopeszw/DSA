# 1)
- a) Explique a diferença fundamental entre a política de acesso de uma Pilha (LIFO) e de uma Fila (FIFO).
- b) Dê um exemplo do mundo real (ou da computação) onde o uso de cada uma dessas estruturas é a escolha ideal.

```
Resposta:
a) LIFO (pilhas) e FIFO (filas), apesar de terem nomes parecidos, significam, respectivamente: "Last in, first out" e "First in, first out". O que isso significa? Traduzindo, literalmente, LIFO indica que o último elemento inserido em uma pilha será o primeiro a sair. Já FIFO indica que o primeiro elemento que entrou em uma fila será o primeiro a sair.

b) Um exemplo claro de LIFO/pilhas é uma pia com louça suja: Todo prato que você coloca na pia será empilhado em cima de outro que está logo abaixo (a não ser que a pia esteja vazia). Caso você queira pegar o primeiro prato que você colocou na pia, precisa antes retirar todos os pratos que estão em cima.

Um exemplo claro de FIFO/filas são filas por ordem de chegada em consultórios médicos: Se você chegar em um consultório de 8h da manhã e outro paciente chegar às 9h, você será atendido (em um cenário onde ambos irão entrar na mesma fila). Isso acontece porque temos uma ficha que indica nosso número de atendimento (que seria basicamente a distância que nós estamos do início da fila), e ela é responsável por enfileirar os pacientes à modo de organizar a estrutura da fila
```

# 2)
- a) Explique o que é o "caso base" (ou condição de parada) em uma função recursiva.
- b) O que acontece com a memória do computador (especificamente com a pilha de chamadas - call stack) se você esquecer de implementar o caso base em uma recursão?

```
Resposta:
a) O caso base em uma função recursiva é a condição que irá encerrar aquela iteração da recursão. Por exemplo, em um caso onde estamos fazendo um contador de quantas vezes um número aparece em um array, teremos dois casos base: a) o valor não está na posição atual do array, retornando 0; b) o valor está na posição atual do array, retornando 1;

Nesse exemplo, a recursão funcionaria como um for, onde ele iria verificar se o valor consta no array de índice por índice.

b) Se não adicionarmos caso de parada, a função entra em loop infinito, ocupando toda a memória alocada para o programa e dando o erro de stack overflow na pilha de instruções.
```

# 3) 
- Crie uma função recursiva em C que receba um vetor dinâmico de inteiros e o seu tamanho n. A função deve retornar a soma de todos os números pares contidos no vetor.
`(Atenção: A função não pode conter laços de repetição como for ou while)`.

```c
// resposta:

int soma_pares(int* v, int n) {
    if (!v) return -1;
    if (n == 0) return 0;
    
    if (v[n - 1] % 2 == 0) {
        return v[n - 1] + soma_pares(v, n - 1);
    }
    else {
        return soma_pares(v, n - 1);
    }
}

/*
v = [5, 4, 6];
n = 3

entrou na função:
n > 0? sim
continua pros outros ifs

v[n - 1] % 2 == 0? -> v[n - 1] = 6 -> é verdadeiro
return 6 + soma_pares(v, n - 1);
    agora n = 2;
    n > 0? sim

    v[n - 1] % 2 == 0? -> v[n - 1] = 4 -> é verdadeiro
    return 4 + soma_pares(v, n - 1);
        agora n = 1;
        n > 0? sim

        v[n - 1] % 2 == 0? -> v[n - 1] = 5 -> é falso
        return soma_pares(v, n - 1);
        agora n = 0;
        n > 0? não
        retorna pra recursão anterior
    não tem mais o que fazer, retorna pra recursão anterior
não tem mais o que fazer, retorna pra recursão anterior

não tem mais recursões, logo:

4 + 6 = 10 -> a soma dos pares do array v = [5, 4, 6] é 10;
```

# 4)
#### Implemente um TAD para uma Pilha de números inteiros utilizando vetores dinâmicos.
- a) Crie a struct da Pilha.
- b) Crie a função de inicialização (cria_pilha).
- c) Crie a função de inserção (push), garantindo que, se o vetor estiver cheio, ele utilize realloc para dobrar de capacidade.

```c

// a)
typedef struct pilha {
    int n; // tamanho atual do vetor
    int dim; // dimensão do vetor;
    int* v; // vetor de inteiros
} Pilha;

// b)
Pilha* cria_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->dim = 4; // valor base para dimensão
    p->v = (int*) malloc(p->dim * sizeof(int));
    if (!p->v) return NULL;

    p->n = 0;
    return p;
}

// c)
void pilha_push(Pilha* p, int v) {
    if (!p || !p->vet) return;

    if (p->n == p->dim) {
        int nova_dim = p->dim * 2;
        p->vet = (int*) realloc(p->vet, nova_dim * sizeof(int));
        p->dim = nova_dim;
    }
    // agora, se o vetor estava cheio, tem espaço suficiente

    p->v[n + 1] = v; // o novo valor é inserido no vetor
    p->n++; // incrementa o numero de elementos -> incremento lógico
}
```

# 5)
#### Imagine um sistema de Fila de Impressão.
- a) Crie a struct do nó (representando o documento, contendo um ID de inteiro e um ponteiro para o próximo) e a struct da Fila (com os ponteiros para o início e o fim).
- b) Crie a função de inserção (enfileirar) para adicionar um novo documento no final da fila.

```c
// resposta:
// a)
typedef struct listano {
    int id;
    struct listano* prox;
} ListaNo;

typedef struct fila {
    ListaNo* prim;
    ListaNo* ult;
} fila;

// b)
void enfileira(Fila* f, int v) {
    if (!f) return;

    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    if (!novo) return;

    novo->id = v;
    novo->prox = NULL; // como é o ultimo da fila, não tem proximo

    // verificação se a fila está vazia
    if (f->prim == NULL) { 
        f->prim = novo; // o primeiro é o novo
    }
    else {
        f->ult->prox = novo; // o proximo do ultimo é o novo
    } 

    f->ult = novo; // fazemos isso para, independente dos ifs anteriores, o ultimo ser o novo
}
```

# 6)
- Escreva uma função que receba uma Pilha de inteiros (implementada com lista simplesmente encadeada) e um número inteiro X. A função deve retornar quantas vezes o número X aparece dentro da pilha.
`Restrição importante: Ao final da execução da função, a Pilha deve estar exatamente no mesmo estado e ordem original de quando foi recebida! (Dica: Você pode precisar usar uma estrutura auxiliar)`.

```c
// resposta:
int busca_x (Pilha* p, int x) {
    int contador = 0;
    Pilha* aux = (Pilha*) malloc(sizeof(Pilha));

    while (p->prim != NULL) {
        if (p->prim->n == x) {
            contador++;
            pilha_push(aux, pilha_pop(p));
        }
        else {
            pilha_push(aux, pilha_pop(p));
        }
    }
    /*
    agoar temos a pilha original vazia, o contador já verificou quantas vezes x apareceu na pilha e temos uma pilha aux que é a pilha original invertida

    precisamos fazer o mesmo processo de push/pop de volta para a original, para manter a ordem
    */

   while (aux->prim != NULL) {
    pilha_push(p, pilha_pop(aux));
   }
   
   pilha_libera(p);
   return contador;
} 
```

# 7)
- Escreva uma função que receba uma pilha de inteiros. A função deve remover todos os elementos da pilha original e distribuí-los em duas novas estruturas:

- 1. Uma pilha contendo apenas os números pares.

- 2. Uma nova pilha contendo apenas os números ímpares.
`(Assuma que as funções básicas de push, pop, insere_fila e retira_fila já existem e você pode apenas chamá-las)`.

```c
// resposta:

Pilha* separa_pares_impares(Pilha* p) {
    if (!p) return NULL;

    Pilha* pares = cria_pilha();
    Pilha* impares = cria_pilha();

    while (p->prim != NULL) {
        if (p->prim->n % 2) {
            pilha_push(pares, pilha_pop(p));
        }
        else {
            pilha_push(impares, pilha_pop(p));
        }
    }
    return pares, impares;
}

```

# 8)
- Crie uma função que receba um Deque de caracteres (char). A função deve esvaziar o Deque e retornar 1 se a palavra formada pelos caracteres for um palíndromo (lê-se igual de trás para frente, como "RADAR") e 0 caso não seja.
`(Dica: Como você pode retirar das duas pontas ao mesmo tempo para comparar?)`

```c
int palindromo(Deque* d) {
    if (!d) return -1;

    while (d->n > 1) {
        // enquanto tiverem pelo menos 2 caracteres

        char letra_ini = remove_ini(d);
        char letra_fim = remove_fim(d);

        if (letra_ini != letra_fim) {
            // é mais fácil verificar se são diferentes
            return 0;
        }
    }
    // se saiu do loop, não tivemos problemas com a verificação, logo, é palindromo
    return 1;
}
```