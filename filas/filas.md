# Filas

## FIFO (First in, first out)

Só podemos inserir um novo elemento no final da fila, é a ideia fundamental.

## Interface:
```c
typedef struct fila Fila;

Fila* fila_cria (void); // aloca dinamicamente e retorna ponteiro
void fila_insere (Fila* f, float v); // add novo elem
float fila_retira (Fila* f); // retira o elemento do inicio
int fila_vazia (Fila* f); // verifica se está vazia ou não
void fila_libera (Fila* f); // libera memória
```

## Fila com vetor
Se o número máximo de elementos a serem armazenados na fila for conhecido, podemos usar um vetor estático. Porém, vamos fazer com vetor dinâmico.

Para não termos que deslocar todos os elementos para frente quando sai um elemento, nós alteramos o ponteiro do início da fila.

Por conta disso, as filas precisam ser circulares, para permitir que não sejamos obrigados à adicionar necessariamente no final da fila. Podemos ter o início da fila em `(i-2)`e o final em `i=1`.

Para implementar isso, os índices do vetor são incrementados de maneira que seus valores progridam "circularmente". Isso pode ser dado por:

```c
i = (i == (dim - 1)) ? 0 : i + 1;
//ou
i = (i+1) % dim;
```
operador ternário:
- condição ? valor_se_verdadeiro : valor_se_falso

No nosso caso, a condição é se i chegou na ultima posicao possivel do array
- se sim, o próximo índice deve ser o primeiro
- se não, apenas avança para a próxima casa (i + 1)

O símbolo % é o operador de módulo (ou resto da divisão matemática). Ele divide o valor numérico da esquerda pelo da direita e retorna apenas o resto dessa divisão.

```c
i = (i+1) % dim;
```
- Se i = 2, temos (2 + 1) % 5, que resulta na conta 3 % 5.
- Se i = 4, temos (4 + 1) % 5, que resulta na conta 5 % 5.

## Struct de fila

- ini marca a pos do próximo elemento a ser retirado da fila
- fim marca a pos (vazia) na qual será inserido o próx elemento
- fim = (ini+n)% dim -> caso tenhamos ini e o num de elementos

```c
struct fila {
    int n; // num de elementos armazenados
    int ini; // início da fila
    int dim; // dimensão atual do vetor
    int* vet; // vetor de elementos
}
```

## Criar fila:
```c
Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dim = 4 // dimensão inicial
    f->vet = (int*) malloc(f->dim * sizeof(int));
    f->n = 0; // inicializa fila vazia
    f->ini = 0; // escolhe uma pos inicial

    return f;
}
```

## Inserir na fila

Para inserir um elemento na fila, usamos a próxima posição livre do vetor, indicada por fim. 

Devemos ainda garantir que há espaço para a inserção do novo elemento; 
    *caso necessário, devemos realocar o vetor.*

**A realocação, no entanto, pode exigir uma rearrumação dos elementos.** 

Se há necessidade de realocação, significa que o vetor está cheio. `No caso especial de o índice ini ser zero`, **não precisamos rearrumar os elementos**; 

qualquer valor de ini diferente de zero significa que os primeiros nini elementos da fila ocupam as últimas posições do vetor. Estes valores precisam ser deslocados para o final do novo vetor. Para fazer este deslocamento, usaremos a função memmove definida na biblioteca string .h. Esta função recebe três parâmetros: o endereço de memória destino da cópia, o endereço de memória origem e o número de bytes a ser movido (copiado). Note que, para a função memmove , o espaço de memória destino pode ter sobreposição com o espaço origem.

```c
void fila_insere(Fila* f, float v) {
    int fim;
    if (f->n == f->dim) {
        // se a qtd de elementos == dimensão
        // precisamos realocar, dobrando o tam da dim
        f->dim *= 2;
        f->vet = (int*) realloc(f->vet, f->dim*sizeof(int));
        // realocamos a memória para a nova dim

        if (f->ini != 0) memmove(& f->vet[f->dim - f->ini] /* end de destino*/
        , & f->vet[f->ini] /* end de origem*/,
        )
    }
}

```