#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "turma.h"

int main(void) {
    Turma* t = t_criavazia();

    FILE* f = fopen("input.txt", "r"); // abre o arquivo input.txt como read-only
    if (f == NULL) {
        printf("Erro ao abrir o arquivo. \n"); // verificação importante para identificar erros
        return 0;
    } 

    char nome[81];
    float p1, p2, p3;

    /* Loop de leitura:
       scanf retorna o número de campos lidos com sucesso
       Tentamos ler o nome primeiro e, se não conseguir ler 1 item, acabou o arquivo.
    */

    /* " %[^\n]" -> O espaço inicial pula o \n da linha anterior. 
       %[^\n] lê tudo até encontrar um novo \n (lê string com espaço) */

    while (fscanf(f, " %[^\n]", nome) == 1) {
        fscanf(f, "%f %f %f", &p1, &p2, &p3);
        t_insere(t, nome, p1, p2, p3);
    }

    printf("Dados lidos e armazenados com sucesso!\n");
    printf("Total de alunos: %d\n", t->n); // Acessando direto para teste

    // Pequeno loop só para mostrar na tela o que foi guardado
    for(int i = 0; i < t->n; i++) {
        printf("Aluno %d: %s (%.1f, %.1f, %.1f)\n", // %d recebe i, %s recebe o string, %.1f recebe float com 1 ponto de precisão
            i, t->p[i]->nome, t->p[i]->p1, t->p[i]->p2, t->p[i]->p3);
    }

    t_libera(t);
    fclose(f);

    return 1;
}