#include <stdlib.h> 

typedef struct arvno {
    char info;
    struct arvno esq; // node direito
    struct arvno dir; // node esquerdo
} ArvNo;

typedef struct arv {
    ArvNo* raiz;
} Arv;

ArvNo* cria_arv(char c, ArvNo* esq, ArvNo* dir) {
    ArvNo* a = (ArvNo*) malooc(sizeof(ArvNo*));
    if (!a) return NULL;

    
}