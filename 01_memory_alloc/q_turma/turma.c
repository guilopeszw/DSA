#include <stdlib.h>
#include <string.h>
#include "turma.h"

Turma* t_criavazia(void) {
    Turma* t = (Turma*) malloc(sizeof(Turma));
    if (t == NULL) return NULL;

    t->n = 0; // não temos alunos na turma ainda
    t->nmax = 0; // como não temos aluno, não é necessário alocar memória para uma turma sem alunos
    t->p = NULL; // como não temos alunos, o ponteiro Aluno** p vai ser nulo

    return t;
}

static void realoca (Turma* t) {
    if (t->n < t->nmax) return;

    if (t->nmax == 0) { // se nmax == 0, ele dá tamanho máx de 2; caso contrário, ele dobra o tamanho de nmax
        t->nmax = 2;
    }
    else {
        t->nmax *= 2;
    }

    t->p = (Aluno**) realloc(t->p, t->nmax * sizeof(Aluno*)); // estrutura: novo_ponteiro (t->p) = realloc(ponteiro_original, novo_tamanho_em_bytes);

    if (t->p == NULL) {
        exit(1); // fecha se faltar memória
    }
}

void t_insere(Turma* t, const char* nome, float p1, float p2, float p3) {
    realoca(t);

    if (t->n == t->nmax) return; // verifica se a realocação funcionou

    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (novo_aluno == NULL) return;

    strcpy(novo_aluno->nome, nome); // stringcopy: copia os chars de nome para novo_aluno->nome
    novo_aluno->p1 = p1;
    novo_aluno->p2 = p2;
    novo_aluno->p3 = p3;

    t->p[t->n] = novo_aluno; // conecta aluno à turma
    t->n++; // incrementa
}

void t_libera(Turma* t) {
    for (int i = 0; i != t->n; i++) {
        free(t->p[i]); // libera os alunos
    }
    free(t->p); // libera ponteiros de lista de alunos
    free(t); // libera a turma
}