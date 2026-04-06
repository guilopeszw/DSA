# Árvores
- Estrutura recursiva que pode ser vazia
- Nós: Raiz e sub-árvores

Quando um nó não tem filhos, ele aponta para NULL.

- Critério de parada da recursão é o nó ser NULL

## Árvores binárias:
**REGRA**: Só podem ter, no máximo, 2 filhos.

```c
No* busca(No* raiz, int info) {
    if (!raiz) return NULL; // caso base

    if (raiz->info == info) return raiz; // se a info estiver na raiz atual da subárvore, retorna a raiz

    No* r = busca(raiz->esq, info); // cria um novo nó para buscar à esquerda
    if (r != NULL) return r; // se o nó retornar não nulo, retorna o nó
    return busca(raiz->dir, info); // busca à direita caso não tenha achado
    
    // a busca é feita na ordem raiz -> esq -> dir, logo, é uma busca pré-ordem
}

No* insere(No* raiz, int info) {
    if (raiz == NULL) {
        // quando alcança o ponto de inserção (vazio), cria o nó e o retorna
        No* novo = (No*)malloc(sizeof(No));
        novo->info = info;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (info < raiz->info) 
        raiz->esq = insere(raiz->esq, info); // pendura o retorno na esquerda
    else 
        raiz->dir = insere(raiz->dir, info); // pendura o retorno na direita

    return raiz; // retorna a raiz atual (com o novo filho pendurado)
}
```

## Árvore binária de busca:
- Elementos à esquerda são menores que o valor da raiz da subárvore e vice-versa.

```c
No* busca_binaria(No* raiz, int info) {
    if (!raiz) return NULL; // caso de quebra

    if (raiz->info == info) return raiz; // se a info está na raiz da subarvore

    if (raiz->info > info) return busca_binaria(raiz->esq, info); // busca à esquerda
    else return busca_binaria(raiz->dir, info); // busca à direita

    // também atua em pré ordem
}

No* insere_abb(No* raiz, int info) {
    // caso de quebra (achou o lugar vazio para inserir)
    if (raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No)); // aloca o novo nó
        novo->info = info;
        novo->esq = novo->dir = NULL;
        return novo; 
    }

    // lógica de decisão 
    if (info < raiz->info) {
        // vai para a esquerda
        raiz->esq = insere_abb(raiz->esq, info);
    } 
    else if (info > raiz->info) {
        // vai para a direita
        raiz->dir = insere_abb(raiz->dir, info);
    }

    // retorna a raiz atual para manter a árvore conectada
    return raiz;

    // a ideia é ir percorrendo e comparando os valores de 1 por 1 até chegarmos em um espaço vazio
    // depois disso, inserimos o nó. essa função também está em pre-ordem
}
```

# Árvores balanceadas
Para saber se uma árvore está balanceada ou não, temos a fórmula:

* **| h(esq) - h(dir)| ≤ 1**
ou seja, o módulo da subtração da altura máxima da esquerda e da altura máxima da direita deve ser menor igual à 1.

### Como balancear:
Temos uma tabela para ajudar à desbalancear

1. EE -> rotação simples à direita
Se o desbalanceamento vier de dois nós à esquerda, fazendo com que hmax(e) = 1 e hmax(dir) = -1, nossa fórmula ficaria:
| 1 - (-1) | = 2, ou seja, desbalanceada.

Para resolver, vamos reorganizar a subárvore para seguir esses passos:
*   O filho da esquerda vira raiz
*   O neto da raiz vira o filho esquerdo
*   A raiz vira o filho direito

2. DD -> rotação simples à esquerda
A mesma explicação do ponto 1, mas agora ao contrário, ou seja, a ordem inverte:
*   O filho da direita vira raiz
*   O neto da raiz vira o filho direito
*   A raiz vira o filho esquerdo

3. ED -> rotação dupla à direita
Se tivermos uma raiz com um filho à esquerda e com um neto (filho do filho) à direita, teremos que aplicar uma rotação dupla à direita:
*   O filho troca de lugar com o neto
*   Depois dessa troca, ficamos com uma EE
*   Aplicamos a mesma regra da EE e balanceamos

4. DE -> rotação dupla à esquerda:
Mesma explicação do ponto 3, mas ao contrário

*   O filho troca de lugar com o neto
*   Depois dessa troca, ficamos com uma DD
*   Aplicamos a mesma regra da DD e balanceamos

## Percorrer uma árvore
Existem 3 ordens para percorrer uma árvore:
1. Pré-ordem: Raiz -> filho esquerdo -> filho direito (mais eficiente)
2. Em ordem: Filho esquerdo -> raiz -> filho direito 
3. Pós-ordem: Filho esquerdo -> filho direito -> raiz (melhor para destruir uma árvore)

# Grafos
Temos vértices (conexões) e arestas (pontos);

- Pode ser não direcionado ou direcionado
- Pode ser cíclico ou acíclico
- Existe uma matriz de adjacência (indica quais pontos se conectam com quais)
- Toda árvore, por definição, é um grafo conexo

Ex.:
```
(A) - (B)
 | 
(D) - (E) - (F)
```

(A) se conecta com B e D, logo, na matriz de adjacência, teríamos 1 (ao invés de 0) onde A e B/D se encontram

Porém, A não se encontra com E e F, logo, teremos 0 na matriz de adjacência.

## Busca por largura
- Na busca por largura, utilizamos filas (FIFO) para encontrar a ordem de busca e a árvore formada por ela:

Ex.:
```
(A) - (B)
 | 
(D) - (E) - (F)
```

Se começarmos por A, teremos que:
*   Já vimos: A
*   Fila: B, D (aqueles que se conectam com A)

Agora, vamos percorrer alfabeticamente aqueles que se conectam com A e ver com quem eles se conectam diretamente, adicionando-os na fila.

* Já vimos: A, B
* Fila: D 

Como B não se conecta à ninguém além de A (que já foi visto), não adicionamos nada à fila.

Vamos para D!
* Já vimos: A, B, D
* Fila: E

D se conecta com E e com A (que já vimos), então adicionamos o inédito à fila e continuamos.

Vamos para E!

* Já vimos: A, B, D, E
* Fila: F

Agora passamos por E, que se conecta com F e com D (que já vimos), então adicionamos F à fila e seguimos

Opa! Não tem mais nada. Então vamos tirar F da fila e colocá-lo como visto
- Já vimos: A, B, D, E, F
- Fila: 

Assim, nossa busca por largura nos resulto na ordem de:
A -> B -> D -> E -> F

Nossa árvore ficaria como:
```
    (A)
    / \
  (B) (D)
       |
      (E)
       |
      (F)
```

## Busca por profundidade
Aqui, a ideia é ir percorrendo, alfabeticamente, até o máximo que conseguimos chegar, utilizando uma **pilha**.

Ex.:
```
      (A)
     /   \
   (B)---(C)
    |
   (D)
```

Vamos percorrer partindo do A:
- Já vimos: A (estamos em A)
- Pilha: A

A enxerga B e C, mas B é menor alfabeticamente

- Já vimos: A, B (estamos em B)
- Pilha: A, B,

B enxerga C e D, mas C é menor alfabeticamente

- Já vimos: A, B, C (estamos em C)
- Pilha: A, B, C

C enxerga B e A, que já foram vistos, então desempilhamos C
- Já vimos: A, B, C (voltamos para B)
- Pilha: A, B

B enxerga C e D, mas C já foi visto, então vamos para D
- Já vimos: A, B, C, D
- Pilha: A, B, D

D enxerga só B, que já foi visto, então desempilhamos D
- Já vimos: A, B, C, D
- Pilha: A, B

B enxerga A e C, que já foram vistos, então desempilhamos B
- Já vimos: A, B, C, D
- Pilha: A

A enxerga B e C, que já foram vistos, então desempilhamos A
- Já vimos: A, B, C, D
- Pilha: 

Terminamos com uma pilha vazia e a ordem A -> B -> C -> D