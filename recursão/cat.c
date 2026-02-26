unsigned int cat(unsigned int n) {
    if (n == 0) return 1;

    return ((2 * (2 * n - 1)) * cat(n - 1))/(n + 1);
}