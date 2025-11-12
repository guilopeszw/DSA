#include <iostream>
using namespace std;

double gasPrices(double gallonPrice, double conversionTax) {
    double gallon = 3.7854;
    double brl = gallonPrice * conversionTax;
    return (brl / gallon);
}

int main() {
    double gallonPrice;
    double conversionTax;

    cout << "Informe o valor do galão de gasolina em USD: ";
    cin >> gallonPrice;
    cout << "Informe a taxa de conversão USD x BRL: ";
    cin >> conversionTax;
    
    cout << "BRL: R$: " << gasPrices(gallonPrice, conversionTax);
}