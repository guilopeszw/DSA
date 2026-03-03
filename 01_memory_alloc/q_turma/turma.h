#include <stdlib.h>
#include <stdio.h>

#ifndef TURMA_H_
#define TURMA_H_

typedef struct aluno {
    char nome[81];
    float p1, p2, p3; // notas
} Aluno;

typedef struct turma {
    Aluno** p; // ponteiro duplo pois: Aluno* vai apontar para o endereço de um aluno específico e Aluno** vai apontar para os alunos da turma
    int n; // tamanho atual da turma
    int nmax; // tamanho máx da turma
} Turma;

Turma* t_criavazia(void);
void t_insere(Turma* t, const char* nome, float p1, float p2, float p3);
void t_libera(Turma* t);

#endif
