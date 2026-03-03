/* 
ponto (x,y)


• cria : operação que cria um ponto com coordenadas (x, y).

• libera : operação que libera a memória alocada por um ponto.

• acessa : operação que retorna as coordenadas de um ponto.

• atribui : operação que atribui novos valores às coordenadas de um ponto.

• distancia : operação que calcula a distância entre dois pontos.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifndef PONTO_H_ // se o ponto não estiver defindo, ele vai definir ponto_h_ como o struct Ponto
#define PONTO_H_ // esse nome feio e estranho é para evitar conflitos de nomes em outros arquivos

typedef struct Ponto { // typedef cria um apelido para o struct Ponto, que agora pode ser chamado apenas de Ponto
    float x;
    float y;
} Ponto;

Ponto* pto_cria(float x, float y);
void pto_libera(Ponto* p);
void pto_acessa(Ponto* p, float* x, float* y);
void pto_atribui(Ponto* p, float x, float y);
float pto_distancia(Ponto* p1, Ponto* p2);
#endif

// as linhas acima são as declarações das funções, que serão implementadas no arquivo ponto.c