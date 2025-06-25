#include <iostream>

using namespace std;

int main() {
    // Variables
    int N, K, max, min;
    int result = 1;

    // Take Input
    cin >> N;
    cin >> K;

    if (N - K > K) {
        max = N - K;
        min = K;
    }
    else {
        max = K;
        min = N - K;
    }

    // Calculate Factorial
    for (int i = N; i > max; i--) result *= i;
    for (int i = min; i > 1; i--) result /= i;

    cout << result;
}