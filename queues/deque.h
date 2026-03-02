#ifndef FILA_DUPLA_H_
#define FILA_DUPLA_H_

typedef struct deque Deque;

Deque* fila2_cria(void);
void fila2_insere_ini(Deque* d, int v);
void fila2_insere_fim(Deque* d, int v);
void fila2_remove_ini(Deque* d);
void fila2_remove_fim(Deque* d);
int fila2_vazia(Deque* d);
void fila2_libera(Deque* d);

#endif