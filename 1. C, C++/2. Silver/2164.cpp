#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Macros
#define MAX_N 500000

// Function Definitions
void init();

// Global Variables
int N;
deque<int> queue;

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
    // Initialize Queue
    queue.clear();

    // Read N
    cin >> N;

    // Make Initial Queue
    for (int i = 1; i <= N; i++) queue.push_back(i);

    // Process
    for (int i = 0; queue.size() > 1; i = (i + 1) % 100) {
        // Pop Front
        int temp = queue.front();
        queue.pop_front();

        // Add to Back
        if (i % 2 == 1) queue.push_back(temp);
    }

    // Print Result
    cout << queue.front();
}