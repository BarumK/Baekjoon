#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 1000000

// Function Definitions
void init();

// Global Variables
int N;
int nums[2 * MAX_N + 1];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	// Initialize
	init();

    // Print Result
    for (int i = 0; i < 2 * MAX_N + 1; i++) {
        if (nums[i] == 1) cout << i - MAX_N << '\n';
    }
}


// Function Implementations
void init() {
    // Temporal Variables
    int temp;

    // Read N
    cin >> N;

    // Initialize Hash List
    for (int i = 0; i < 2 * MAX_N + 1; i++) nums[i] = 0;

    // Read & Mark Each Numbers
    for (int i = 0; i < N; i++) {
        cin >> temp;
        nums[temp + MAX_N] = 1;
    }
}