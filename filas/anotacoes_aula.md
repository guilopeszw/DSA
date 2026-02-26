# Filas
### FIFO - First in, First out

**Entrada -> [] [] [] -> Saída**

### Fila com vetor estático:
```c
#DEFINE _TAM_10

typedef struct fila {
    int valores[_TAM_10];
    int inicio; 
    int n;
} Fila
```

Precisamos saber o início e o fim da fila. Podemos inserir no início e no fim.

Podemos também adotar a estratégia de armazenar o início e o tamanho. Assim, podemos também saber qual o fim da fila.

## Função de criar a fila:
```c
Fila* cria_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL; // verifica alocação

    f->inicio = 0;
    f-> n = 0; // a fila ainda está vazia
    return f;
}
```

## Função de destruir a fila:
```c
void destroi_fila(Fila** f) {
    if (!f) return;

    free(*f);
    *f = NULL;
    // essa estrutura é necessária pois temos um ponteiro duplo.
}
```

## Adicionar à fila:
```c
int insere_fila(Fila* f, int info) {
    if (!f) return -1;
    if (f->n == valores) return 0; // verifica se a fila está cheia

    f->n++;
    int i = (f->inicio + f->n) % _TAM_10;
    f->valores[i] = info;
    // usa n para adicionar à fila, deixando o início sendo sempre o índice 0 e marcando o primeiro elemento que entrou.
}
```

## Remove da fila:

```c
int remove_fila(Fila* f) {
    if (!f) return -1;
    if (f->n == 0) return 0;

    int v;
    v = f->valores[f->inicio];
    f->ini = (f->ini + 1) % f->n;
    f->n--;
    return v;
}

```