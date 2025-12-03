#include <iostream>
#include <cmath>
using namespace std;

double volume(double radius) {
    return double (4.0/3.0 * (M_PI) * (radius * radius * radius));
};
    
int main() {
    float radius;

    cout << "Informe o raio: ";
    cin >> radius;

    cout << "Volume: " << volume(radius);
}