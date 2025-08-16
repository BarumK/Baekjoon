#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 500

// Function Definitions
void init();

// Global Variables
int N, numZeros;

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();

    // Print Result
    cout << numZeros;
}


// Function Implementations
void init() {
    // Read N
    cin >> N;

    // Initialize Variables
    numZeros = 0;

    // Calculate Number of 5's -> Number of Zeros Depends on # of 5's
    for (int i = 1; i <= N; i++)  {
        int temp = i;

        while (temp > 0) {
            if (temp % 5 == 0) {
                numZeros++;
                temp /= 5;
            }
            else break;
        }
    }
}