/*
Considere uma estrutura para representar os dados de um aluno:

typedef struct aluno Aluno;
struct aluno {
    char nome[81];
    float p1 , p2 , p3; // notas
};

Considere ainda uma árvore binária de busca que armazena informações
de alunos, ordenada por ordem alfabética dos nomes:

Considere ainda uma árvore binária de busca que armazena informações de alunos, ordenada por ordem alfabética dos nomes:

typedef struct arv Arv;
typedef struct arvno ArvNo;
struct arvno {
    Aluno info;
    ArvNo* esq;
    ArvNo* dir;
};
struct arv {
    ArvNo* raiz;
}
*/
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[81];
    float p1 , p2 , p3; // notas
} Aluno;


typedef struct arvno {
    Aluno info;
    ArvNo* esq;
    ArvNo* dir;
} ArvNo;

typedef struct arv {
    ArvNo* raiz;
} Arv;

/*
(a) Implemente uma função para criar uma árvore vazia: Arv* aa_cria(void);
*/

Arv* aa_cria(void) {
    Arv* a = (Arv*) malloc(sizeof(Arv));
    if (!a) return NULL;

    a->raiz = NULL;
    return a;
}

/*
(b)
Implemente uma função para inserir os dados de um novo aluno na estrutura:
void aa_insere (Arv* a, char * nome, float p1, float p2, float p3);
*/

ArvNo* aa_insere_rec(ArvNo* no, char* nome, float p1, float p2, float p3) {
    if (no == NULL) {
        ArvNo* node = (ArvNo*) malloc(sizeof(ArvNo));
        if (!node) return NULL;

        strcpy(node->info.nome, nome);
        node->info.p1 = p1;
        node->info.p2 = p2;
        node->info.p3 = p3;
        node->esq = NULL;
        node->dir = NULL;
        return node;
    }

    if (strcmp(nome, no->info.nome) < 0) {
        no->esq = aa_insere_rec(no->esq, nome, p1, p2, p3);
    } else {
        no->dir = aa_insere_rec(no->dir, nome, p1, p2, p3);
    }
    return no;
}

void aa_insere(Arv* a, char* nome, float p1, float p2, float p3) {
    a->raiz = aa_insere_rec(a->raiz, nome, p1, p2, p3);
}