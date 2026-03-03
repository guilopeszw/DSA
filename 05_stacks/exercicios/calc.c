#include "calc.h"
#include "pilhas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct calc {
    char f[21]; // somente para formatação
    Pilha* p; // pilha dos operandos
};

Calc* calc_cria(char* f) {
    // a função recebe como parâmetro de entrada uma cadeia de caracteres
    // e inicializa-os no topo da pilha.


    Calc* c = (Calc*) malloc(sizeof(Calc));

    
    strcpy(c->f, f); // copia o char inputado para o char do struct calc
    c->p = pilha_cria();
    return c;
}

/*
A função operando coloca no topo da pilha o valor passado como parâmetro.

As operações válidas são: ’+’ para somar, ’-’ para subtrair, ’*’ para multiplicar e ’/’ para dividir. 
*/

void calc_operando(Calc* c, int v) {
    pilha_push(c->p, v); // empilha o operando
    printf(c->f, v); // imprime o topo da pilha
}

void calc_operador(Calc* c, char op) {
    int v2 = pilha_vazia(c->p) ? 0 : pilha_pop(c->p);
    int v1 = pilha_vazia(c->p) ? 0 : pilha_pop(c->p);

    int v;

    // operações acontecem dentro do switch
    switch(op) {
        case '+': v = v1 + v2; break;
        case '-': v = v1 - v2; break;
        case '*': v = v1 * v2; break;
        case '/': v = v1 / v2; break;
    }
    pilha_push(c->p, v); // empilha resultado
    printf(c->f, v); // imprime topo da pilha
}

void calc_libera(Calc* c) {
    pilha_libera(c->p);
    free(c);
}