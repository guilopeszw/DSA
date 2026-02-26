unsigned int acherman(unsigned int n, unsigned int m) {
    if (m == 0) return (n + 1);
    if (m > 0 && n == 0) return acherman(m -1, m);
    if (m > 0 && n > 0) return acherman(m - 1, acherman(m, n - 1));
}