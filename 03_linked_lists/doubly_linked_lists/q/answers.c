/*
Exercícios do livro "Introdução à Estrutura de Dados Com Técnicas de Programação em C", de Waldemar Celes, capítulo 14
*/

/*
Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que calcule o número de nós 
de uma lista. Essa função deve obedecer ao protótipo:
int comprimento (Lista* l);
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct listano {
    struct listano* prox; // precisa citar o struct aqui novamente, pois ele ainda não é ListaNo
    int info;
} ListaNo;

typedef struct lista {
    ListaNo* prim;
} Lista;

int comprimento (Lista* l) {
    if (l == NULL) return 0;

    int count = 0;
    for (ListaNo* p = l->prim; p != NULL; p = p->prox) {
        count += 1;
    }
    return count;
}

/*
Considerando listas encadeadas de valores inteiros, implemente uma função que retorne o número de nós da lista que possuem o campo info
com valores maiores do que x. Essa função deve obedecer ao protótipo: 
int maiores (Lista* l, int x);
*/

int maiores(Lista* l, int x) {
    if (l == NULL) return 0;

    int count = 0;
    for (ListaNo* p = l->prim; p != NULL; p = p->prox) {
        if (p->info > x) {
            count += 1;
        }
    }
    return count;
}

/*
Implemente uma função que retorne o último valor de uma lista encadeada de inteiros. Essa função deve obedecer ao protótipo:
int ultimo (Lista* l);
*/

int ultimo (Lista* l) {
    if (l == NULL) return 0;

    // aqui, precisa verificar se o valor existe dentro do nó

    if (l->prim == NULL) return 0;

    ListaNo* p = l-> prim; // precisa declarar antes para entrar no while
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p->info;
}

/*
Implemente uma função que receba duas listas encadeadas de valores reais e transfira para o final da primeira lista 
os elementos da segunda.
No final, a primeira lista representará a concatenação das duas listas e a segunda lista estará vazia. Essa função 
deve obedecer ao protótipo:
void concatena (Lista* l1 , Lista* l2 );
*/

void concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL || l2->prim == NULL) return;

    if (l1->prim == NULL) {
        l1->prim = l2->prim;
        l2->prim = NULL;
        return;
    }
    ListaNo* p = l1->prim;

    while (p->prox != NULL) {
        p = p->prox;
    }
    ListaNo* ult = p; // ultimo nó de l1
    
    ult->prox = l2->prim;
    l2->prim = NULL;
    // free(l2->prim); free é desnecessário pois as estruturas de l2 já foram atribuidas e agora l2->prim é null
}

/*
Considerando listas de valores inteiros, implemente uma função que receba como parâmetros uma lista encadeada e um valor inteiro x, e
retire da lista todas as ocorrências de x. Essa função deve obedecer ao protótipo:
void retira_n (Lista* l, int x);
*/

void retira_n(Lista* l, int x) {
    if (l == NULL || l->prim == NULL) return;
    
    while (l->prim != NULL && l->prim->info == x) {
        ListaNo* t = l->prim;   // guarda o nó prim 
        l->prim = t->prox;      // faz o nó prim virar o prox
        free(t);                // remove nó prim original
    }
    
    ListaNo* p = l->prim; // pegamos o primeiro item para varrer
    
    while (p->prox != NULL) {
        if (p->prox->info == x) {
            // código para remover
            ListaNo* remove = p->prox;
            p->prox = p->prox->prox;
            remove->prox = NULL;
            free(remove);
        }
        else {
            p = p->prox;
        }
    }
    return;
}

/*
Considerando listas de valores inteiros, implemente uma função que receba como parâmetro uma lista encadeada e um valor inteiro x e
divida a lista em duas, de tal forma que a segunda lista, criada dentro da função, comece no primeiro nó logo após a primeira 
ocorrência de x na lista original. A função deve ter como valor de retorno a lista criada, mesmo que ela seja vazia. 
Essa função deve obedecer ao protótipo:
Lista* separa (Lista* l, int x);
*/

Lista* separa(Lista* l, int x) {
    ListaNo* p = l->prim;
    Lista* l2 = (Lista*) malloc(sizeof(Lista));
    l2->prim = NULL;

    while (p != NULL) {
        if (p->info == x) {
            l2->prim = p->prox;
            p = p->prox = NULL;
        }
        else {
            p = p->prox;
        }
    }
    
    return l2;
}

/*
Implemente uma função que construa uma nova lista, intercalando os nós de outras duas listas passadas como parâmetros. 
Essa função deve retornar a nova lista resultante, criada dentro da função

Ao final da função, as listas originais devem ficar vazias e ser liberadas. Se uma lista tiver mais elementos que a outra, 
os elementos excedentes são transferidos na mesma ordem para a nova lista. Essa função deve obedecer ao protótipo:
Lista* merge (Lista* l1 , Lista* l2 );
*/

Lista* merge(Lista* l1, Lista* l2) {
    Lista* lista_merged = (Lista*) malloc(sizeof(Lista));
    if (l1->prim == NULL || l2->prim == NULL) return;

    int menor = 0;
    if ((sizeof(l1) / sizeof(l1[0]) < (sizeof(l2) / sizeof(l2[0])))) menor = sizeof(l1) / sizeof(l1[0]);
    else
        menor = sizeof(l2) / sizeof(l2[0]);
    
    for (int i = 0; i< menor; i++) {
        lista_merged->prim = l1->prim;

    }
}

/*
Implemente uma função que construa uma nova lista, intercalando os nós de outras duas listas passadas como parâmetros. 
Essa função deve retornar a nova lista resultante, criada dentro da função

Ao final da função, as listas originais devem ficar vazias e ser liberadas. Se uma lista tiver mais elementos que a outra, 
os elementos excedentes são transferidos na mesma ordem para a nova lista. 
Essa função deve obedecer ao protótipo:
Lista* merge (Lista* l1 , Lista* l2 );
*/

Lista* merge(Lista* l1, Lista* l2) {
    // pipeline: vai intercalando até que uma das listas aponte para NULL.
    // se as duas apontarem para NULL, elas são de mesmo tamanho e já está tudo certo
    // se apenas uma aponta para NULL, significa que a outra é maior, então vamos só concatenar o resto para o fim da nova Lista*

    // if de verificação de null é diferente aqui. caso l1 seja NULL mas l2 não, retorna l2.

    Lista* intercalada = (Lista*) malloc(sizeof(Lista));
    intercalada->prim = NULL; // lista intercalada começa vazia
    
    // casos base de nulos
    if (l1 == NULL) {
        intercalada->prim = l2->prim;
        free(l2);
        return intercalada;
    }
    if (l2 == NULL) {
        intercalada->prim = l1->prim;
        free(l1);
        return intercalada;
    }
    if (l1->prim == NULL && l2->prim == NULL) {
        free(l1);
        free(l2);
        return intercalada;
    }
    if (l1->prim == NULL) {
        intercalada->prim = l2->prim;
        free(l1);
        free(l2);
        return intercalada;
    }
    if (l2->prim == NULL) {
        intercalada->prim = l1->prim;
        free(l2);
        free(l1);
        return intercalada;
    }
    
    ListaNo* p1 = l1->prim; // ponteiro para o primeiro elemento de l1
    intercalada->prim = p1;
    p1 = p1->prox; // garante que não vamos perder p1
    ListaNo* p2 = l2->prim; // ponteiro para o primeiro elemento de l2
    ListaNo* p3 = intercalada->prim;
    p3->prox = p2;
    p3 = p3->prox;
    p2 = p2->prox;

    while (p1 != NULL && p2 != NULL) {
        p3->prox = p1; // faz o prox de p3 virar p1
        p3 = p3->prox; // avança ponteiro de p3
        p1 = p1->prox; // armazena p1->prox
        p3->prox = p2; // faz o prox de p3 virar p2
        p3 = p3->prox; // avança ponteiro de p3
        p2 = p2->prox; // armazena p2->prox
    }
    
    if (p1 == NULL) {
        p3->prox = p2;
    }

    if (p2 == NULL) {
        p3->prox = p1;
    }
    free(l1);
    free(l2);
    return intercalada;
}

/*
Implemente uma função que receba como parâmetro uma lista encadeada e inverta o encadeamento de seus nós. Após a execução dessa
função, cada nó da lista vai estar apontando para o nó que originalmente era seu antecessor, 
e o último nó da lista passará a ser o primeiro nó da lista invertida

Essa função deve obedecer ao protótipo:
void inverte (Lista* l);
*/

void inverte (Lista* l) {
    // pipeline: final da lista vai virar l->prim
    // o ponteiro do início irá apontar para o prox, que será o novo item que está no final (que, originalmente, era o penultimo)
    // um ponteiro temp vai procurar até que o prox seja o final, aí ele vai adicionar o prox ao prox do inicio

    
    ListaNo* atual = l->prim->prox;
    ListaNo* final = l->prim;
    ListaNo* proximo = l->prim;

    while (final != NULL) {
        final = final->prox;
    }
    // precisamos que exista um ponteiro no final da lista

    
}