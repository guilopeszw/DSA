#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    cout << "Insira um número i: ";
    cin >> n;
    cout << "O i-ésimo número da sequencia de fibonacci é: " << fib(n) << ". ";
}
