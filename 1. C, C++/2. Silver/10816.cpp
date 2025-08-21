#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_RANGE 10000000

// Function Definitions
void init();

// Global Variables
int N, M;
int hashMap[2 * MAX_RANGE + 1];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	// Initialize
	init();
}


// Function Implementations
void init() {
    // Initialization
    for (int i = 0; i < 2 * MAX_RANGE + 1; i++) hashMap[i] = 0;

    // Read N
    cin >> N;

    // Read Line
    for (int i = 0, temp; i < N && cin >> temp; i++) hashMap[temp + MAX_RANGE]++;

    // Read M
    cin >> M;

    // Print Result
    for (int i = 0, temp; i < M && cin >> temp; i++) cout << hashMap[temp + MAX_RANGE] << " ";
}