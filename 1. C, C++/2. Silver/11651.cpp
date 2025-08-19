#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 100000

// Function Definitions
void init();

// Global Variables
int N;
pair<int, int> coordinates[MAX_N];

int main() {
    // Initial Setting
	ios::sync_with_stdio(false);

	// Initialize
	init();

    // Print Result
    for (int i = 0; i < N; i++) cout << coordinates[i].second << " " << coordinates[i].first << '\n';
}


// Function Implementations
void init() {
    // Read N
    cin >> N;

    // Read Coordinates
    for (int i = 0; i < N; i++) cin >> coordinates[i].second >> coordinates[i].first;

    // Sort Coordinates
    sort(coordinates, coordinates + N);
}