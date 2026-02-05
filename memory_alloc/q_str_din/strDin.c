#include <stdlib.h>
#include <stdio.h>
#include "strDin.h"

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static void ajusta_memoria(StrDin* sd, int novo_tamanho_necessario) {

    /*
    Crescimento: max(needed, 2 * sd->nmax). 
    Isso garante que, se você concatenar algo gigantesco de uma vez, ele não vai alocar só o dobro (que seria pouco), ele vai alocar o necessário. 
    Mas se for um crescimento pequeno, ele dobra para garantir performance futura.

    Encolhimento: Se needed < nmax / 2, ele corta o array pela metade.
    */

    if (novo_tamanho_necessario > sd->nmax) {
        int dobro = sd->nmax * 2; // redimensiona para max(n, 2*nmax)
        int nova_capacidade = max(novo_tamanho_necessario, dobro);
        
        // se estava vazio (0), inicializa com o tamanho necessário
        if (sd->nmax == 0) nova_capacidade = novo_tamanho_necessario;

        char* novo_v = (char*) realloc(sd->v, nova_capacidade * sizeof(char));
        if (novo_v) {
            sd->v = novo_v;
            sd->nmax = nova_capacidade; // altera ponteiro e nmax da string
        }
    }
    // REGRA DE ENCOLHIMENTO (Se sobrar muito espaço) 
    // Se n < 0.5 * nmax, reduz para 0.5 * nmax
    else if (novo_tamanho_necessario < (sd->nmax / 2)) {
        int metade = sd->nmax / 2;
        
        // Segurança: nunca diminuir além do necessário para guardar o texto atual
        if (metade < novo_tamanho_necessario) metade = novo_tamanho_necessario;
        if (metade == 0) return; // Evita free acidental

        char* novo_v = (char*) realloc(sd->v, metade * sizeof(char));
        if (novo_v) {
            sd->v = novo_v;
            sd->nmax = metade;
        }
    }
}

StrDin* sd_criavazia(void) {
    StrDin* sd = (StrDin*) malloc(sizeof(StrDin));
    if (sd != NULL) {
        sd->n = 0;
        sd->nmax = 0;
        sd->v = NULL;
    }

    return sd;
}

StrDin* sd_criacopia(const char* s) {
    // const é read-only, por isso faz sentido para uma cópia
    StrDin* sd = sd_criavazia();
    if (s != NULL && sd != NULL) {
        sd_atribui(sd, s); /* Reutiliza a lógica de atribuição */
    }
    return sd;
}

StrDin* sd_atribui(StrDin* sd, const char* s) {
    if (sd == NULL || s == NULL) return sd;

    int len_s = (int) strlen(s); // verifica tam da string

    ajusta_memoria(sd, len_s + 1); // verifica memória necessária

    strcpy(sd->v, s); // copia o conteúdo
    sd->n = len_s;

    return sd; // retorna pelo enunciado da questão
}


void sd_concatena(StrDin* sd, const char* s) {
    if (sd == NULL || s == NULL) return;

    int len_s = (int) strlen(s);
    int novo_tamanho = sd->n + len_s + 1; // tamanho antigo + novo + 1

    ajusta_memoria(sd, novo_tamanho);

    strcat(sd->v, s);
    sd->n += len_s;
}

const char* sd_acessa(StrDin* sd) {
    if (sd == NULL || sd->v == NULL) return "";
    return sd->v;
}

void sd_libera(StrDin* sd) {
    free(sd->v);
    free(sd);
}

void sd_redimensiona(StrDin* sd) {

    /*
    Essa função ignora a regra de "sobra" (buffer) e força o vetor a ter o tamanho exato da string (n + 1). 
    É útil quando o usuário sabe que não vai mais mexer na string e quer economizar cada byte de RAM.
    */

    if (sd == NULL || sd->v == NULL) return;

    // Ajusta para o espaço estritamente necessário  + 1
    int tamanho_exato = sd->n + 1;

    char* novo_v = (char*) realloc(sd->v, tamanho_exato * sizeof(char)); // realoca o v para aumentar o tamanho
    if (novo_v) {
        sd->v = novo_v; // v atualiza
        sd->nmax = tamanho_exato; // nmax vira o tamano exato + 1
    }

}
