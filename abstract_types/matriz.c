#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

Matriz* mat_cria(int m, int n) {
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));
    if (!matriz) return NULL;
    
    matriz->col = m;
    matriz->lin = n;
    
    
    matriz->v = (float**) malloc(m * sizeof(float**));
    if (!matriz->v) {
        free(matriz);
        return NULL;
    }
    for (int i = 0; i < m; i++) {
        matriz->v[i] = malloc(n * sizeof(float));
        if (matriz->v[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz->v[j]); // caso de algum erro, ele libera a memória alocada dinamicamente das linhas anteriores
            }
            free(matriz->v);
            free(matriz);
        }
    }
    return matriz;

    /* 
    matriz->v[i] é um array de float, ou seja, uma linha da matriz
    matriz->v[i][j] acessa diretamente cada elemento
    */
};

void mat_libera(Matriz* mat) {
    free(mat);
};

float mat_acessa(Matriz* mat, int i, int j) {
    return mat->v[i][j];
};

void mat_atribui(Matriz* mat, int i, int j, float valor) {
    mat->v[i][j] = valor;
}

int mat_linhas(Matriz* mat) {
    return mat->lin;
}

int mat_colunas(Matriz* mat) {
    return mat->col;
}