#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Macros
#define MAX_N 300000

// Function Definitions
void init();

// Global Variables
int N, sum, idx;
int scores[MAX_N];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Initialization
    sum = 0;

    // Read N
    cin >> N;

    if (N != 0){
        // Read Each Scores
        for (int i = 0; i < N; i++) cin >> scores[i];

        // Sort
        sort(scores, scores + N);

        // Calculate Index
        idx = round((float) N * 0.15);

        // Calculate Sum
        for (int i = idx; i <= (N - 1 - idx); i++) sum += scores[i];
        sum = round((float) sum / (N - 2 * idx));
    }

    // Print Result
    cout << sum;
}