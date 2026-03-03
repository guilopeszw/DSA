/* matriz m por n TAD 

• cria : operação que cria uma matriz de dimensão m por n.

• libera : operação que libera a memória alocada para a matriz.

• acessa : operação que acessa o elemento da linha i e da coluna j da matriz.

• atribui : operação que atribui o elemento da linha i e da coluna j da matriz.

• linhas : operação que retorna o número de linhas da matriz.

• colunas : operação que retorna o número de colunas da matriz
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Matriz {
    int lin;
    int col;
    float** v; // ponteiro de um array de ponteiros (apropriado para matrizes 2D)
} Matriz;

Matriz* mat_cria(int m, int n);
void mat_libera(Matriz* mat);
float mat_acessa(Matriz* mat, int i, int j);
void mat_atribui(Matriz* mat, int i, int j, float valor);
int mat_linhas(Matriz* m);
int mat_colunas(Matriz* mat);
#endif