#include <iostream>
#include <cmath>


int isPrime(int num) {
    if (num <= 1) {
        return true;
    }
    int div = num / 2;
    // int div = floor(sqrt(num)); // -> outra possibilidade

    if (num % 2 == 0) {
        return 0;
        }
    for (int i = 3 ; i <= div; i += 2) {
            if (num % i == 0) {
                return 0;
            }
    }
    return 1;
}

void findPrimesInRange(int end) {
    if (end > 1) {
        for (int i = 2; i <= end; i++) {
            if (isPrime(i) == 1) {
                std::cout << i << " ";
            }
        }

    }
}

int main() {
    int end;
    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    std::cout << "Prime numbers between 0 and " << end << " are: ";
    findPrimesInRange(end);
    std::cout << std::endl;
}