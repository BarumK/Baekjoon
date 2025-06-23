#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int temp;
    while (true) {
        if (a % b == 0) return b;
        else {
            temp = a;
            a = b;
            b = temp % b;
        }
    }
}

int main() {
    // Variables
    int var[2];
    int gcd_val;

    // Take Input
    for (int i = 0; i < 2; i++) cin >> var[i];

    // Calculate GCD
    if (var[0] >= var[1]) gcd_val = gcd(var[0], var[1]);
    else gcd_val = gcd(var[1], var[0]);

    // Print Result
    cout << gcd_val << endl;
    cout << var[0] * var[1] / gcd_val << endl;
}