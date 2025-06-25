#include <iostream>

using namespace std;

int main() {
    // Variables
    int num, T, P;
    int var[6];
    int result = 0;

    // Take Input
    cin >> num;
    for (int i = 0; i < 6; i++) cin >> var[i];
    cin >> T;
    cin >> P;

    // Calculate T-Shirt
    for (int i = 0; i < 6; i++) {
        if (var[i] % T == 0) result += (var[i] / T);
        else result += (var[i] / T) + 1;
    }

    // Print Result
    cout << result << endl;
    cout << num / P << " " << num % P << endl;
}