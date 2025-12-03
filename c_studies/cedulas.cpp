#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int valueToBills(int value) {
    // vector<int> bills = {100, 50, 20, 10, 5, 2, 1};

    int hundreds, fifties, twenties, tens, fives, twos, ones;
    while (value > 0) {
        if ((value % 100) > 0) {
            hundreds = value % 100;
            value -= hundreds * 100;
        }
        else if ((value % 50) > 0) {
            fifties = value % 50;
            value -= fifties * 50;
        }
        else if ((value % 20) > 0) {
            twenties = value % 20;
            value -= twenties * 20;
        }
        else if ((value % 10) > 0) {
            tens = value % 10;
            value -= tens * 10;
        }
        else if ((value % 5) > 0) {
            fives = value % 5;
            value -= fives * 5;
        }
        else if ((value % 2) > 0) {
            twos = value % 2;
            value -= twos * 20;
        }
        ones = value;
    }
    return hundreds, fifties, twenties, tens, fives, twos, ones;
}

int main() {
    int value;
    cout << "Insira o valor em R$: ";
    cin >> value;

    cout << "Cédulas: " << valueToBills(value);
}