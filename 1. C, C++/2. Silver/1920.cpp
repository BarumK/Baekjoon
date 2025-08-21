#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function Definitions
void init();

// Global Variables
int N, M;
unordered_set<int> exist;

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
    // Read N
    cin >> N;

    // Read Integers
    for (int i = 0, temp; i < N && cin >> temp; i++) exist.insert(temp);

    // Read M
    cin >> M;

    // Print Result
    for (int i = 0, temp; i < M && cin >> temp; i++) cout << (exist.find(temp) != exist.end() ? 1 : 0) << '\n';
}