#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variables
    int result = 0;
    int temp;

    // Get Input
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        result += temp * temp;
    }

    // Take Modulo Operation
    result %= 10;

    // Print Result
    cout << result;
}