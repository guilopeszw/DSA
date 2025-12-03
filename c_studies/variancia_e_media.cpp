#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> captura(float* x, int n) {
    vector<float> capturados;
    for (int i = 0; i < n; i++) {
        cout << "Insira um valor :\n";
        cin >> x[i];
    }
}

float media(float* x, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
}

float variancia(float* x, int n, float m) {
    float v;
    
    for (int i = 0; i < n; i++) {
        v += sqrt(x[i] - m);
    }
    
    return v/(n - 1);
}

int main() {
    cout << "Entre com a qtd de valores: ";
    int n;
    cin >> n;
    float* x = (float*) malloc (n * sizeof(float));
    if (x == NULL) {
        cout << "Memória insuficiente\n ";
        return 1;
    }

    captura(x, n);
    float m = media(x, n);
    float v = variancia(x, n, m);

    cout << "Média> " << m << " Variância: " << v << endl;
    return 0;
}