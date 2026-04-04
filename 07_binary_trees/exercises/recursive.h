#ifndef ARV_BUSCA_H
#define ARV_BUSCA_H

typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv* arv_cria(void);
void arv_libera(Arv* a);
void arv_insere(Arv* a, int v);
int arv_pertence(Arv* a, int v);
int arv_vazia(Arv* a);
int arv_altura(Arv* a);
void arv_imprime(Arv* a);

#endif