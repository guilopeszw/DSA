/*
Um bom exemplo de aplicação de pilha é o funcionamento das calculadoras RNP (sigla em inglês para Notação Polonesa Reversa).

Elas trabalham com expressões pós-fixadas; 
então, para avaliar uma expressão como (1 − 2) ∗ (4 + 5),
podemos digitar 1 2 − 4 5 + ∗

Cada operando é empilhado numa pilha de valores. 

Quando se encontra um operador, desempilha-se o número apropriado de operandos
*/

#ifndef CALCULADORA_PONTO_H
#define CALCULADORA_PONTO_H

typedef struct calc Calc;

Calc* calc_cria(char* f);
void calc_operando(Calc* c, int v);
void calc_operador(Calc* c, char op);
void calc_libera(Calc* c);

#endif