#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int* v = new int[n]; // aloca vetor dinamico de inteiros no heap -> equivalente a malloc(n * sizeof(int)) em C

    // acessa por índice com for
    for (int i = 0; i < n; i++) {
        v[i] = i * 10;   // equivalente a *(v + i)
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }

    delete[] v; // libera bloco inteiro -> equivalente a free(v) em C
    v = nullptr;
}


// A alocação dinâmica é essencial para estruturas como:
// listas encadeadas, árvores, filas, pilhas, grafos