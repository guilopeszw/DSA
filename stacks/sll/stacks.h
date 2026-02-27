#ifndef PILHA_PONTO_H
#define PILHA_PONTO_H

Pilha* criar_pilha(void); 
int push(Pilha* p, int n);
int pop(Pilha* p); 
int esta_vazia(Pilha* p);
int tamanho(Pilha* p);
void libera(Pilha* p);

#endif