# Grafos

### Grafos são um conjunto de tuplas com 2 nós:

- Nós = {A, B, C, D} -> vértices do grafo

- Arestas = {(A, B), (B, A), (B,C), (C, B), (B, D), (D, B), (A, C), (C, A), (C, D), (D, C)}

Os automatos representados em Linguagens Formais e Computabilidade são representados por grafos.

- OBS: Se um grafo não tiver ciclos, ele é acíclico.
- OBS2: Toda árvore é um grafo, mas nem todo grafo é uma árvore

Um grafo é dito **CONEXO** quando à partir de um nó, você consegue ir para qualquer outro nó.
Se tivermos um nó que está desconectado de todos os outros nós, é um grafo **DESCONEXO**.

## Importância de dados na computação:
- Modelar rotas (vértices são cidades e arestas são rodovias);
- Sugestões de conexões em redes sociais;
- Redes neurais (uma rede neural é uma árvore e, portanto, um grafo)

## Como representar um grafo:
**1. Utilizando matriz de adjacência:**
- Se houver uma ligação, marcamos 1 e, se não, 0;
- Mesmo esquema de tabela de genéticas do ensino médio;
- É um dicionário com as tuplas e um boolean que informa se ela existe ou não;
- Se um nó é cíclico, como por exemplo, se A for cíclico: {(A, A) : 1}
