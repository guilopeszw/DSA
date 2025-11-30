#include <iostream>
using namespace std;

int main() {
    // new aloca no heap e retorna um ponteiro 
    int* p = new int;   // memória no heap -> equivalente ao malloc(sizeof(int)) em C
    *p = 42;            // atribuição indireta: *(p) 
    cout << *p << endl;

    delete p;           // libera memória do heap -> equivalente ao free(p) em C
    p = nullptr;        // evita ponteiro danificado (dangling)

    return 0;
}

// ponteiros permitem acessar memória indireta; 
// new apenas fornece uma área dinâmica para você usar esse ponteiro.