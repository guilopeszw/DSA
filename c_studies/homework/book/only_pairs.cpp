#include <iostream>
using namespace std;

int pares(int n, int* v) {
    int* pairs = (int*) malloc(n * sizeof(int));

    if (pairs == NULL) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pairs[count] = v[i];
            count++;
        }
    }
    free(pairs);
    return count;
}

int main() {
    int v[5] = {1, 8, 3, 4, 6};
    cout << pares(5, v) << endl;

    return 0;
}