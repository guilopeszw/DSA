#include <iostream>
#include <ctime>
#include <format>

using namespace std;

string timestamp(int seconds) {
    int hours = seconds / 3600;
    seconds -= 3600 * hours;
    int minutes = seconds / 60;
    seconds -= 60 * minutes;

    return format("{:02d}:{:02d}:{:02d}", hours, minutes, seconds);
}

int main() {
    int seconds;

    cout << "Insira a quantidade de segundos: ";
    cin >> seconds;

    cout << "Tempo: " << timestamp(seconds) << endl;
}