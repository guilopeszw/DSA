#include <iostream>


bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2 ; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimesInRange(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
}

int main() {
    int start, end;
    std::cout << "Enter the start of the range: ";
    std::cin >> start;
    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    std::cout << "Prime numbers between " << start << " and " << end << " are: ";
    findPrimesInRange(start, end);
    std::cout << std::endl;
}