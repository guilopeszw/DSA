unsigned int fib(unsigned int n) {
    // fib(n) = fib(n - 1) + fib(n - 2) -> casos base: fib(1) = fib(0) = 1;
    if (n <= 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

//

long fib_n(int n) { 
    if (n < 0) return 0; 
    
    long p1 = 0; 
    long p2 = 1; 
    long prox = 0; 

    for (int i = 1; i <= n; i++) { 
        prox = p1 + p2; 
        p1 = p2; 
        p2 = prox; 
    } 

    return p1; 
}