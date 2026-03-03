/*

criavazia; : cria uma cadeia dinâmica inicialmente vazia.
criacopia; : cria uma cadeia dinâmica inicializada com uma cadeia
fornecida.
atribui; : reatribui (redefine) o valor da cadeia dinâmica.
concatena; : concatena a cadeia fornecida na cadeia dinâmica.
acessa; : retorna o ponteiro da cadeia efetivamente armazenada.
libera ;: libera memória da cadeia dinâmica. 
*/

#include <stdlib.h>
#include <stdio.h>
#ifndef STR_DIN_
#define STR_DIN_
typedef struct strdin {
    int n; // num de elementos no vetor dinâmico
    int nmax; // dimensão do vetor
    float* v; // vetor dos elementos
} StrDin;

StrDin* sd_criavazia(void);
StrDin* sd_criacopia(const char* s); // const é read-only, por isso faz sentido para uma cópia
StrDin* sd_atribui(StrDin* sd, const char* s);
void sd_concatena(StrDin* sd, const char* s);
const char* sd_acessa(StrDin* sd);
void sd_libera(StrDin* sd);
void sd_redimensiona(StrDin* sd);

/*
Nesta implementação, faremos uso do modificador de tipo const para ilustrar seu uso. Em especial, note que a função de acesso retorna uma 
cadeia constante, indicando que a cadeia não pode ser alterada pelo cliente. Isto é fundamental, pois assim a implementação do tipo abstrato 
tem controle assegurado do conteúdo da cadeia.
*/
#endif