#include <iostream>
using namespace std;

// questão 7.1 -> introdução à estrutura de dados -> walter celes

int* pares(int n, int* v) {
    int* pairs = (int*) malloc(n * sizeof(int));

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pairs[count] = v[i];
            count++;
        }
    }
    return pairs;
}

int main() {
    int v[8] = {1, 8, 6, 4, 6, 2, 10, 22};
    int arraySize = sizeof(v) / sizeof(v[0]);
    int* paresPtr = pares(arraySize, v);

    cout << "Pares: ";
    for (int i = 0; i < arraySize; i++) {
        cout << paresPtr[i] << " ";
    }
    free(paresPtr);
}