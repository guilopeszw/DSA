#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "calc.h"

int main(void) {
    Calc* calc = calc_cria("%.2d \n");

    while (1) {
        // lê o prox char não branco

        char c;
        scanf(" %c", &c);

        if (c=='+' || c=='-' || c=='*'|| c=='/') calc_operador(calc, c);

        else if (c == 'q') break; // aborta o programa
        
        else {
            int v;
            ungetc(c, stdin);
            if (scanf("%d", & v) == 1) calc_operando(calc, v);
            else {
                printf("Erro na leitura \n");
                exit(1);
            }
        }
    }
    calc_libera(calc);
    return 0;
}

/*
Esse programa cliente lê os dados fornecidos pelo usuário e opera a calculadora. 
Para tanto, o programa lê um caractere não branco e verifica se é um operador válido. 
Em caso negativo, o programa “devolve” o caractere lido para o buffer de leitura padrão ( stdin ), 
através da função ungetc , e tenta ler um operando. O usuário finaliza a execução do programa digitando q.
*/

