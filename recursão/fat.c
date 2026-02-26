unsigned int fatorial (unsigned int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// ele vai fazer a recursão até que n <= 1, que seria igual à 1.

// fatorial(5) -> 5 * fatorial(4) -> 5 * 4 * fatorial(3) -> 5 * 4 * 3 fatorial(2) -> 5 * 4 * 3 * 2 * fatorial(1) -> fatorial(1) retorna 1;
// essas chamadas são feitas em uma pilha.
