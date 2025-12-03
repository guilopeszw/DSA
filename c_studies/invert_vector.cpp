#include <iostream>
using namespace std;

// {2, 4, 3, 9, 1}
//        j
// {1, 9, 3, 4, 2}
//        i


int* inverte(int n, int* v) {
    // int* inverso = (int*) malloc(n * sizeof(int)); -> alocação dinamica em C
    int* inverso = new int[n];
    int j = n - 1;

    for (int i = 0; i < n; i++) {
        inverso[i] = v[j];
        j -= 1;
    }
    
    return inverso;
}

int main() {
    int v[5] = {2, 4, 3, 9, 1};
    int arraySize = sizeof(v) / sizeof(v[0]);

    cout << "vetor original: \n";
    for (int i = 0; i < arraySize; i++) {
        cout << v[i];
    }
    cout << endl;

    cout << "vetor invertido: \n";
    int* invertido = inverte(arraySize, v);
    for (int i = 0; i < arraySize; i++) {
        cout << invertido[i];
    }

    free(invertido);
}