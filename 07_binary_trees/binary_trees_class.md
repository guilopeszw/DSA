# Árvores
- Principal utilidade: `fazer buscas`;
- A cada passo na árvore, diminui pela metade a busca (pois, se formos à esquerda, vamos buscar apenas pela esquerda, deixando a direita de lado **pun intended**);
- Folhas são os nós que não tem filhos (apontam para NULL);


# Análise assintótica:
- se tivermos k operações, o custo é k * n;
- Dizemos que essa função é O(n) -> tiramos o limite quando n vai para infinito;

- Se tivermos: f(n) = k * n + m, se m for muito maior que que n, vira O(m);
```c
for(n)
    for(m)
// O(m * n) = O(nˆ2)
```

# Árvores binárias

- Todos os nós possuem **NO MÁXIMO** dois filhos, mas não precisam sempre ter dois filhos;
    - Numa árvore binária, cada nó tem zero, um ou dois filhos. 
- A cada passo na árvore, diminui pela metade a busca (pois, se formos à esquerda, vamos buscar apenas pela esquerda, deixando a direita de lado **pun intended**);
- O número de comparações é ln2 n;

#### Árvore da expressão: (3 + 6) ∗ (4 − 1) + 5:


```
            (+)
       (*)        5
 (+)          (-)
3   6       4    1
```

Numa árvore binária, cada nó tem zero, um ou dois filhos. Podemos dizer que a árvore é representada pelo seu nó raiz e, de maneira recursiva, podemos definir a árvore como:

- uma árvore vazia (ponteiro para a raiz nulo);
    - por definição, o nível é (-1);
- um nó raiz tendo duas subárvores, identificadas como:
    - subárvore da direita (sad)
    - subárvore da esquerda (sae)

    - A raiz está no nível 0 (se tiver só um nó na árvore, ela terá nível 0);

### Níveis da árvore:    
os níveis das árvores começam do 0 (raiz) e incrementam de 1 em 1 conforme a árvore desce

**2ˆn, onde n é o nível e o resultado é o num de nós na árvore**

- Nível 0: 2ˆ0 = 1 nó;
- Nível 1: 2ˆ1 = 2 nós;
- Nível 5: 2ˆ5 = 32 nós;
    
    e assim por diante...

### Altura da árvore
- A altura da árvore é de acordo com o nível.
- Se temos uma árvore no 3o nível, temos altura = 3;

**Dica**: a altura indica quantos "passos" precisamos para sair da raiz e chegar no ponto mais distante

## Árvore binária de busca:
- Todos os elementos à esquerda são menores que o valor que está na raiz (organização);
- Todos os elementos à direita são maiores que o valor que está na raiz (organização);
- Percorremos o nó e vamos comparando que é maior que quem, pois a lógica acima não é exclusivo para a raiz;
- Existe a "regra" (extremamente flexível) de que não vamos receber valores iguais ao da raiz/último nó - logo, caso você receba, pode escolher se vai para a direita ou esquerda;

## Representação com vetor:
- i=0 do vetor é a raiz;
- o índice do filho esquerdo será 2 * indice do pai + 1;
- índice do filho direito será 2 * índice do pai + 2;
- ele utiliza o 2 * indice etc... para assegurar que todo nó poderá ter 2 filhos -> medida de proteção
- índice pai = [(indice_filho - 1)/2];
- Desvantagem: caso a árvore não esteja completa (todos os nós com 2 filhos), você vai desperdiçar memória alocando um vetor grande que não será totalmente utilizado

## Heap sort:
- A entrada é um vetor e a saída é um vetor ordenado
- É utilizado para ordenar um vetor e fazer uma árvore binária de busca;




# Árvores AVL

Um nó de uma árvore está balanceado quando o módulo de altura(f_esq) - altura(f_dir) <= 1.

Ou seja, quando o módulo da altura do nó esquerdo - altura do nó direito for -1, 0 ou 1, esse nó está balanceado.

Para que uma árvore esteja balanceada, **todos seus nós precisam estar balanceados**.

Uma árvore balanceada é uma árvore boa para pesquisa.

Exemplo:
Uma árvore com apenas um nó, terá apenas sua raiz.

A altura do filho esquerdo seria -1, indicando que ele não existe
A altura do filho direito seria -1, indicando que ele não existe

Logo, teríamos que B = |-1 - (-1)| = 0, está balanceada

Exemplo 2:

Uma árvore que é a raiz e um nó à esquerda:

B0 = |-1 - (-1)| = 0 -> a raiz está balanceada
B1 = |0 - (-1)| = 1 -> o nó à esquerda está balanceado
B2 = |-1 - (-1)| = 0 -> o nó à esquerda não tem filhos, logo, está balanceado pela conta

Exemplo 3 (não-balanceado):

Uma árvore com Raiz e 2 nós à esquerda

temos que:
    B0 = |-1 - (-1)| = 0, está balanceada
    B1 = |1 - (-1)| = 2, não está balanceado -> o lado esquerdo tem altura 1 e o direito -1, logo: não é balanceada

Exemplo 4:
