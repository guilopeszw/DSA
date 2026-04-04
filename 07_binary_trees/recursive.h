#ifndef ARVORE_RECURSIVA_H
#define ARVORE_RECURSIVA_H

typedef struct arv Arv;

Arv* arv_cria (void); 
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
int arv_pertence (Arv* a, int c);
void arv_imprime (Arv* a);
int arv_altura(Arv* a);

#endif