## 1. Considere uma Árvore Binária de Busca (ABB) vazia. Se inserirmos os valores [50, 30, 70, 20, 40], qual será o valor do nó à extrema esquerda da árvore?
**RESPOSTA:** o valor é 20.

## 2. No protótipo int conta_nos(ArvNo* r) (função que conte o número de nós de uma árvore), qual é o caso base (condição de parada) e o que ele deve retornar?
**RESPOSTA:** a condição de parada deve ser o nó ser NULL. Caso ele seja NULL, retorna 0, indicando que não há nó ali.

## 3. O que define um grafo como "conexo"?
**RESPOSTA:** Um grafo conexo se diz quanto à possibilidade de chegarmos à qualquer ponto de um grafo a partir de qualquer outro ponto. 

## 4. Verdadeiro ou Falso: Toda árvore é um grafo, mas nem todo grafo é uma árvore. Explique.
**RESPOSTA:** Verdadeiro. Por definição, toda árvore representa um grafo conexo. Isso quer dizer que: A árvore é um caso especial de grafos que é conexo e não possui ciclos. Se um grafo tiver ciclos, ele permanece um grafo - mas deixa de ser uma árvore.

## 5. Implemente a lógica de uma função que retorne a altura de uma árvore binária.
```c
int h_no(ArvNo* r) {
    if (!r) return -1; // nó vazio

    return 1 + max(h_no(r->esq, r->dir)); // vai retornar o valor máximo da altura de um dos lados (que seria a altura total daquela subarvore)
}

int hmax(Arv* a) {
    if (!a) return -1;
    return h_no(a->raiz);
}
```

## 6. Em uma função de busca de nível em uma ABB, se o valor procurado x é maior que a info do nó atual, para qual lado a recursão deve seguir e por quê?
**RESPOSTA:** Devemos ir à direita, pois: Quando se trata de árvores binárias de busca, a organização diz que o valor maior que o do nó atual estará à direita e o menor à esquerda. Logo, aproveitando da eficiência de uma árvore binária de busca, sabemos que, se o valor x pertencer à árvore, devemos ir à direita.

## 7. Escreva uma função em C int soma_folhas(ArvNo* r) que retorne a soma apenas dos valores contidos em nós que são folhas.
```c
int soma_folhas(ArvNo* r) {
    if (!r) return 0;

    if (!r->esq && !r->dir) return r->info;

    return soma_folhas(r->esq) + soma_folhas(r->dir);
}
```

## 8. Um grafo com N vértices e N−1 arestas é obrigatoriamente uma árvore? Justifique.
**RESPOSTA:** Não. Um grafo só pode ser uma árvore se Nvertices = Narestas. Nesse caso, possivelmente é um grafo desconexo ou um grafo cíclico.

